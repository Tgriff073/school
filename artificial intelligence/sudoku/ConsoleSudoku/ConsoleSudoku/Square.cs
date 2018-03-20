using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Priority_Queue;
/* File: Square.cs
 * Description: This class is used to create a square object. Each object represents a single cell in a sudoku board. The object keeps track of what values it could potentially be if it is unsolved. 
 * and which subcube of the sudoku board it lies within. It also has two bools, solved and given, to keep track of whether the square as a number in it and whether or not it was given at the start or not.
 * Last modified:5/8/2017
 * Dependencies: This class inherits from the priority queue class so it can be used as a node in a priority queue
 * Class: Artificial Intelligence CS471 2017 Guillen
 * 
 */
namespace ConsoleSudoku
{
    class Square : FastPriorityQueueNode
    {
        private int number;//value stored in the cell
        private int x;//x index of the square
        private int y;//y index of the square
        private bool given;//whether or not the square was given by the puzzle
        private int heur;//the heuristic value of the square, given by how many values it could possibly be 
        private int subCube;//the 3x3 subcube the square lies within
        private List<int> possibleVals = new List<int>();//domain of the square
        private bool solved;//whether or not the square has been filled

        //default ctor, just to initialize the list to an empty list to avoid null reference
        public Square()
        {
            possibleVals = new List<int>();
        }

        //overloaded == operator for the object, checks if the 2 squares are at the same position
        public static bool operator ==(Square temp,Square temp2)
        {
            return (temp.X == temp2.X && temp.Y == temp2.Y);

        }

        //overloaded != operator makes needed in c# if == is overloaded
        public static bool operator !=(Square temp, Square temp2)
        {
            return (temp.X != temp2.X || temp.Y != temp2.Y);

        }

        //mutator for X member 
        public int X
        {
            get{return x;}
            set{x = value;}
        }

        //mutator for subCube member 
        public int SubCube
        {
            get { return subCube; }
            set { subCube = value; }
        }

        //mutator for solved member 
        public bool Solved
        {
            get { return solved; }
            set { solved = value; }
        }

        //mutator for Y member 
        public int Y
        {
            get{return y;}
            set{y = value;}
        }

        //mutator for Number member 
        public int Number
        {
            get{return number;}
            set{number = value;}
        }

        //mutator for possibleVals member 
        public List<int> PossibleVals
        {
            get{return possibleVals;}
            set
            {
                for (int i = 0; i < value.Count; i++)
                    possibleVals.Add(value[i]);
            }
        }

        //mutator for given member 
        public bool Given
        {
            get {return given;}
            set {given = value;}
        }

        //overloaded Square ctor, raw is converted to x and y coordinates and input is converted to an int and set to number, subCube is determined based on X&Y coordinates
        public Square(int raw, char input)
        {
            x = raw % 9;
            y = raw / 9;

            number = input - '0';
            if(y < 3)
            {
                if (x < 3)
                    subCube = 0;
                else if (x < 6)
                    subCube = 1;
                else
                    subCube = 2;
            }
            else if(y < 6)
            {
                if (x < 3)
                    subCube = 3;
                else if (x < 6)
                    subCube = 4;
                else
                    subCube = 5;
            }
            else
            {
                if (x < 3)
                    subCube = 6;
                else if (x < 6)
                    subCube = 7;
                else
                    subCube = 8;
            }
            if (number > 0)
                given = true;
        }

        //overloaded Square ctor,x is set to xPos y is set to yPos and number is set to v, subCube determined based on X&Y coords
        public Square(int xPos, int yPos, int v)
        {
            x = xPos;
            y = yPos;
            number = v;
            given = true;
            if (y < 3)
            {
                if (x < 3)
                    subCube = 0;
                else if (x < 6)
                    subCube = 1;
                else
                    subCube = 2;
            }
            else if (y < 6)
            {
                if (x < 3)
                    subCube = 3;
                else if (x < 6)
                    subCube = 4;
                else
                    subCube = 5;
            }
            else
            {
                if (x < 3)
                    subCube = 6;
                else if (x < 6)
                    subCube = 7;
                else
                    subCube = 8;
            }
        }

        //mutator for heur
        public int Heur
        {
            get { return heur; }
            set { heur = value; }
        }

        //restricts the domain of the square based on the squares that constrain the specified square(meaning the squares in the same row, column, and subCube
        public void genPossibles(List<Square> board)
        {
            List<int> poss = new List<int>();
            
            for (int i = 1; i < 10; i++)
                poss.Add(i);

            poss.Remove(number);//remove itself from possible numbers

            for (int i = 0; i < 9; i++)
                poss.Remove(board[((x)+(9*i))].number);//remove all numbers in the same column as it

            for (int i = 0; i < 9; i++)
                poss.Remove(board[(y*9) + i].number);//remove all values from same row
         
            
            
            if (y < 3)//check for large sqaures 1-3
            {
                if (x < 3)//square 1
                {
                    for (int i = 0; i < 3; i++)
                    {
                        for(int j = 0; j < 3; j++)
                        {
                            poss.Remove(board[j + (i * 9)].Number);
                        }
                    }
                }
                else if (x < 6)//square 2
                {
                    for(int i = 0; i < 3; i++)
                    {
                        for(int j = 3; j < 6; j++)
                        {
                            poss.Remove(board[j + (i * 9)].Number);
                        }
                    }
                }
                else//square 3
                {
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 6; j < 9; j++)
                        {
                            poss.Remove(board[j + (i * 9)].Number);
                        }
                    }
                }
            }
            else if(y < 6)//checks for sqaures 4-6
            {
                if (x < 3)//square 4
                {
                    for (int i = 3; i < 6; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            poss.Remove(board[j + (i * 9)].Number);
                        }
                    }
                }
                else if (x < 6)//square 5
                {
                    for (int i = 3; i < 6; i++)
                    {
                        for (int j = 3; j < 6; j++)
                        {
                            poss.Remove(board[j + (i * 9)].Number);
                        }
                    }
                }
                else//square 6
                {
                    for (int i = 3; i < 6; i++)
                    {
                        for (int j = 6; j < 9; j++)
                        {
                            poss.Remove(board[j + (i * 9)].Number);
                        }
                    }

                }
            }
            else//checks for squares 7-9
            {
                if (x < 3)//square 7
                {
                    for (int i = 6; i < 9; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            poss.Remove(board[j + (i * 9)].Number);
                        }
                    }
                }
                else if (x < 6)//square 8
                {
                    for (int i = 6; i < 9; i++)
                    {
                        for (int j = 3; j < 6; j++)
                        {
                            poss.Remove(board[j + (i * 9)].Number);
                        }
                    }
                }//end square 8 check
                else//square 9
                {
                    for (int i = 6; i < 9; i++)
                    {
                        for (int j = 6; j < 9; j++)
                        {
                            poss.Remove(board[j + (i * 9)].Number);
                        }
                    }
                }//end square 9 check
            }//end square 7-9 check
            
            possibleVals = poss;
            heur = possibleVals.Count;
        }//end genPossibles

        //creates a copy of the object that calls this method so the copy doesnt modify the original
        public Square deepCopy()
        {
            Square other = (Square)this.MemberwiseClone();
            other.possibleVals = new List<int>();
            for(int i = 0; i < this.possibleVals.Count; i++)
            {
                other.possibleVals.Add(this.possibleVals[i]);
            }
            return other;
        }
        //displays the square that calls this method if its the first square in a row it would display the row number first
        public void display()
        {
            if (x == 0)
                Console.Write("{0}  ", y);
            Console.Write("{0} ", number);
            if (x == 8)
                Console.WriteLine("");
        }

        //removes x from the domain of the square
        public void remove(int x)
        {
            possibleVals.Remove(x);
        }
    }//end Square
}//end Sudoku
