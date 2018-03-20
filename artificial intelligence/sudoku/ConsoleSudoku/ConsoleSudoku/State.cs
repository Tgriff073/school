using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Priority_Queue;

/* File: State.cs
 * Description: This class keeps track of the current state of the board and its member methods do the majority of the work of the program like checking if a state is consistent and modifying the board. 
 * Last modified:5/8/2017
 * Class: Artificial Intelligence CS471 2017 Guillen
 * 
 */
namespace ConsoleSudoku
{
    class State 
    {
        private List<Square> board = new List<Square>();//a list of square that represent the sudoku board
        
        private int placed;
        //a 2d array used to keep track of the coordinates of each square in a subsquare, makes restricting the domain of squares that share a subsquare easier
        public int[,] cubeCoords = new int[9, 9]{
        {0, 1, 2, 9, 10, 11, 18, 19, 20},
        {3, 4, 5, 12, 13, 14, 21, 22, 23},
        {6, 7, 8, 15, 16, 17, 24, 25, 26},
        {27, 28, 29, 36, 37, 38, 45, 46, 47},
        {30, 31, 32, 39, 40, 41, 48, 49, 50},
        {33, 34, 35, 42, 43, 44, 51, 52, 53},
        {54, 55, 56, 63, 64, 65, 72, 73, 74},
        {57, 58, 59, 66, 67, 68, 75, 76, 77},
        {60, 61, 62, 69, 70, 71, 78, 79, 80}
        };
        public List<Square> Board
        {
            get{return board;}
            set{board = value;}
        }
        public int Placed
        {
            get { return placed; }
            set { placed = value; }
        }
        
        //used to check if user input would create a final board that is consistent. Uses a priority queue to implement minimal remaining value algorithm 
        //on the list of squares that make up the board. Guesses when it comes to a square that cant be reduced to only one possible value. If a square has no possible 
        //values and the guessStack is empty then the state is consistent and an error that corresponds to the type of consistency error is returned. Otherwise if the board
        //can be completed in a valid state then null is returned.
        public Error checkConsistency(Square temp)
        {
            FastPriorityQueue<Square> testQueue = new FastPriorityQueue<Square>(81);//used for mrv algorithm
            Stack<unCert> guessStack = new Stack<unCert>(); //stack that keeps track of guessed states

            foreach (Square sq in this.Board)//populate priority queue with squares from the board
            {
                sq.genPossibles(this.Board);
                testQueue.Enqueue(sq, sq.Heur);
            }

            while (testQueue.Any())//loop until the queue is empty
            {
                if (testQueue.First.Given || temp == testQueue.First || testQueue.First.Solved)//if the square has been solved, is a given, or is user entered remove the sqaure from the queue
                    testQueue.Dequeue();
                else if (testQueue.First.Heur == 1)//if the square only has one possible value set it to that value and declare it as solved, remove it from the queue and update the board, and the domain of the squares that that square constrains
                {
                    testQueue.First.Number = testQueue.First.PossibleVals[0];
                    testQueue.First.Solved = true;
                    updateBoard(testQueue.First);
                    testQueue.Dequeue();
                    for (int i = 0; i < testQueue.Count; i++)//update the priority of the square in the queue based on the new number in the board
                    {
                        testQueue.UpdatePriority(testQueue.ElementAt(i), testQueue.ElementAt(i).Heur);
                    }

                }
                else if (testQueue.First.Heur == 0)//a square has no possible values so the current state is inconsistent( as proposed by ac3 algorithm)
                {
                    
                    if (guessStack.Count == 0)//no guesses have been made so the board is incosistent due to the user input so display an error
                    {
                        Error err = new Error(Error.errType.single, temp);
                        return err;
                    }
                    else//otherwise a guess caused an inconsistency so a correction needs to be made
                    {
                        
                        foreach (int x in guessStack.First().Guessed)//restrict the domain based on the guesses that have already been made, since those are wrong as they caused an inconsistency
                        {
                            guessStack.First().Gsquare.PossibleVals.Remove(x);
                            
                        }
                        if(guessStack.First().Gsquare.PossibleVals.Count == 0)//if there are no more values left in the guessed squares domain that means the bad guess occured on a previous square, pop this state and check the lower guess in the stack
                        {
                            guessStack.Pop();
                            guessStack.First().Prev.board[guessStack.First().Gsquare.Y * 9 + guessStack.First().Gsquare.X].Solved = false;
                            guessStack.First().Prev.board[guessStack.First().Gsquare.Y * 9 + guessStack.First().Gsquare.X].Heur = -1;


                            continue;
                        }
                        
                        if(guessStack.Count != 0)//as long as the stack isnt empty update the guessed square to be false again and set its heur value at -1 so it will be at the front of the queue, then reset the board to the backed up version
                        {
                            guessStack.First().Prev.board[guessStack.First().Gsquare.Y * 9 + guessStack.First().Gsquare.X].Solved = false;
                            guessStack.First().Prev.board[guessStack.First().Gsquare.Y * 9 + guessStack.First().Gsquare.X].Heur = -1;
                            foreach (Square sq in guessStack.First().Prev.board)
                                this.modBoard(sq);
                            this.Placed = guessStack.First().Prev.Placed;
                            testQueue.Clear();

                            foreach (Square sq in this.board)
                                testQueue.Enqueue(sq, sq.Heur);
                        }
                    }
                    
                }
                else if(testQueue.First.Heur > 1 || testQueue.First.Heur == -1)//a guess needs to be made as it has multiple possible values
                {
                    if (guessStack.Count == 0 || guessStack.First().Gsquare != testQueue.First())//if the guess stack is empty or the guess at the top of the stack doesnt correspond to the current square make a new guess object
                    {
                        
                        unCert tempCert = new unCert();
                        int guessing = 0;
                        tempCert.Gsquare = testQueue.First.deepCopy();
                        tempCert.Prev = this.deepCopy();
                        guessing = testQueue.First.PossibleVals[0];
                        testQueue.First.PossibleVals.Remove(0);
                        testQueue.First.Solved = true;
                        testQueue.First.Number = guessing;
                        tempCert.Guessed.Add(guessing);
                        
                        guessStack.Push(tempCert);
                        updateBoard(testQueue.First);
                        testQueue.Dequeue();
                        for (int i = 0; i < testQueue.Count; i++)
                        {
                            testQueue.UpdatePriority(testQueue.ElementAt(i), testQueue.ElementAt(i).Heur);
                        }
                    }
                    else//otherwise modify the guess object at the top of the guess stack and make a new guess, and update the board based on the new guess.
                    {
                        
                        guessStack.First().Gsquare = testQueue.First().deepCopy();
                        guessStack.First().Prev = this.deepCopy();
                        foreach (int x in guessStack.First().Guessed)
                            testQueue.First.PossibleVals.Remove(x);
                        if (testQueue.First.PossibleVals.Count == 0)
                            continue;
                        testQueue.First.Solved = true;
                        int guessing = testQueue.First.PossibleVals[0];
                        testQueue.First.Number = guessing;
                        guessStack.First().Guessed.Add(guessing);
                        updateBoard(testQueue.First);
                        testQueue.Dequeue();
                        for (int i = 0; i < testQueue.Count; i++)
                        {
                            testQueue.UpdatePriority(testQueue.ElementAt(i), testQueue.ElementAt(i).Heur);
                        }
                    }

                }
            }
            
            return null;//no errors encountered, state is consistent 
        }

        //default ctor
        public State()
        {
            placed = 0;
        }

        //updates the square specified by the argument temp and updates the domain of all squares that temp constrains
        public void updateBoard(Square temp)
        {
            board[(temp.Y * 9) + temp.X] = temp.deepCopy();
            updatePossibles(temp);
        }

        //checks to see if a state is valid, meaning there arent two of the same numbers in any row, columnm, or sub cube
        public bool isValid()
        {
            List<int> temp = new List<int>();//this is the list that will be used, it will be reset after each check by setting temp = possible
            
            int index = 0;
            for(int l = 1; l < 10; l++)//populate list of possibbles with numbers 1-9
                temp.Add(l);
            
            for(int i = 0; i < 9; i++)//check every row to see if its valid
            {
                for(int j = 0; j < 9; j++)
                {
                    index = (i * 9) + j;
                    if (!temp.Contains(board[index].Number) && board[index].Number != 0)
                        return false;
                    else
                        temp.Remove(board[index].Number);
                }
                for (int l = 1; l < 10; l++)//populate list of possibbles with numbers 1-9
                    temp.Add(l);
            }
            for (int l = 1; l < 10; l++)//populate list of possibbles with numbers 1-9
                temp.Add(l);
            for (int i = 0; i < 9; i++)//check every column
            {
                for(int j = 0; j < 9; j++)
                {
                    index = (j * 9) + i;
                    if (!temp.Contains(board[index].Number) && board[index].Number != 0)
                        return false;
                    else
                        temp.Remove(board[index].Number);
                }
                for (int l = 1; l < 10; l++)//populate list of possibbles with numbers 1-9
                    temp.Add(l);
            }
            for (int l = 1; l < 10; l++)//populate list of possibbles with numbers 1-9
                temp.Add(l);
            for (int i =0; i < 9; i++)//check every small 3x3 square
            {
                for(int j = 0; j < 9; j++)
                {
                    index = cubeCoords[i,j];
                    if (!temp.Contains(board[index].Number) && board[index].Number != 0)
                        return false;
                    else
                        temp.Remove(board[index].Number);
                }
                for (int l = 1; l < 10; l++)//populate list of possibbles with numbers 1-9
                    temp.Add(l);
            }
            return true; //it made it through all checks, state is valid
        }
        public void updatePossibles(Square temp)
        {
            for(int i = 0; i < 9; i++)//update domain of all the squares in the same row as temp
            {
                board[(temp.Y * 9) + i].genPossibles(board);
            }
            for(int i = 0; i < 9; i++)//update domain of all the squares in the same column as temp
            {
                board[(9 * i) + temp.X].genPossibles(board);
            }
            for(int i =0; i < 9; i++)//update domain of all the squares in the same sub square as temp
            {
                board[cubeCoords[temp.SubCube, i]].genPossibles(board);
            }
        }

        //checks to see if a state is consistent based solely on the numbers that are already on the board, without checking future states, used as a preliminary to limit the amount of times guessing needs to be made
        public Error isConsistent(Square temp)
        {
            
            int index = 0;
            Error err = null;
            int x = (temp.Y * 9) + temp.X;
            if ((board[x].PossibleVals.Count) > 0 || board[x].Number > 0)
            {
                for (int i = 0; i < 9; i++)//update domain of all the squares in the same row as temp
                {
                    index = (temp.Y * 9) + i;
                    int checkIndex = temp.Y * 9 + temp.X;
                    if ((board[checkIndex].Number == board[index].Number) && (index != ((temp.Y * 9) + temp.X)))
                    {
                        err = new Error(Error.errType.rowErr, temp);
                        return err;
                    }
                }
                for (int i = 0; i < 9; i++)//update domain of all the squares in the same column as temp
                {
                    index = (9 * i) + temp.X;
                    if ((board[(temp.Y * 9) + temp.X].Number == board[index].Number) && (index != ((temp.Y * 9) + temp.X)))
                    {
                        err = new Error(Error.errType.columnErr, temp);
                        return err;
                    }
                }
                for (int i = 0; i < 9; i++)//update domain of all the squares in the same sub square as temp
                {
                    if ((board[cubeCoords[temp.SubCube, i]].Number == board[(temp.Y * 9) + temp.X].Number) && (cubeCoords[temp.SubCube, i] != ((temp.Y * 9) + temp.X)))
                    {
                        err = new Error(Error.errType.squareErr, temp);
                        return err;
                    }
                }
            }
            
            return err;
        }
       
        //since only consistent states can be made, a state can be determined as solved if each row adds up to 45
        public bool solved()
        {
            int sum = 0;
            for(int i =0; i < 81; i++)
            {
                sum += board[i].Number;
                if(i % 8 == 0 && i != 0)
                {
                    if (sum != 45)
                        return false;
                    else
                        sum = 0;
                }
                    
            }
            return true;
        }

        //displays the current board and displays an error if the argument is not null
        public void display(Error err)
        {
            Console.Clear();
            if (err == null)
            {
                Console.Write("  ");//formating
                for (int i = 0; i < 9; i++)//display row index
                {
                    Console.Write(" {0}", i);
                }
                Console.WriteLine("\n");
                foreach (Square tmp in board)
                {
                    tmp.display();
                }
            }
            else//the board contains error, display error appropriately
            {
                Console.Write("  ");//formating
                for (int i = 0; i < 9; i++)//display row index
                {
                    Console.Write(" {0}", i);
                }
                Console.WriteLine("\n");
                foreach (Square tmp in board)
                {
                    int index = tmp.Y * 9 + tmp.X;
                    if (err.ErrDomain.Contains(index))
                        Console.ForegroundColor = ConsoleColor.Red;
                    tmp.display();
                    Console.ResetColor();
                   
                }
                string messg ="";
                switch(err.Err)
                {
                    case Error.errType.rowErr:
                        messg = "row";
                        break;
                    case Error.errType.columnErr:
                        messg = "column";
                        break;
                    case Error.errType.squareErr:
                        messg = "square";
                        break;
                    case Error.errType.single:
                        messg = "sub sqaure";
                        break;
                }
                Console.WriteLine("Inconsistency was detected in the highlighted {0}", messg);
            }
        }
        

        //creates a copy of a state object that wont modify the original
        public State deepCopy()
        {
            State other = (State)this.MemberwiseClone();
            other.board = new List<Square>();
            for (int i = 0; i < this.board.Count; i++)
            {
                other.board.Add(this.board[i].deepCopy());
            }
            return other;
        }

        //modifies the square at the specifed x and y coordinates, sets it value to v
        public void modBoard(int x, int y, int newVal)
        {
            int index = y * 9 + x;
            board[index].Number = newVal;
        }

        //modifies the square that is at the same position as temp, creates a deepcopy of temp
        public void modBoard(Square temp)
        {
            int index = temp.Y * 9 + temp.X;
            board[index] = temp.deepCopy();
        }

        //checks if the square at x,y is modifiable(not a given square) returns true if the square is a given, false otherwise
        public bool occupied(int x, int y)
        {
            int index = y * 9 + x;
            if (board[index].Given)
                return true;
            return false;
        }
    }
}
