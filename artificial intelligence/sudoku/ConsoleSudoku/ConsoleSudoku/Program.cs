using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Priority_Queue;
/* File: Program.cs
 * Description: main driver for the program creates a user object and gets the user input for the difficulty. Creates a board based on the 
 * option they selected and than loops until the board is complete. During each loop the user is asked which square they would modify which they respond
 * to with coordiantes in the x,y format where x is the column and y is the row. Checks to see if the board would be consistent if the input were added, if
 * it would be consistent it will be added otherwise an error will be displayed. Loops till the board is solved.
 * Dependencies: Requires the fast Priority_Queue library available from nuGet https://www.nuget.org/packages/OptimizedPriorityQueue/
 * Last modified:5/8/2017
 * Class: Artificial Intelligence CS471 2017 Guillen
 * 
 */

namespace ConsoleSudoku
{
    class Program
    {

        static void Main(string[] args)
        {

            State state = new State();//local object to keep track of current state of board 
            Player user = new Player();//local object to allow user to make input into the program
            int count = 0;//temporary variable to keep track of what index the square being added to the board is
            int placed = 0;//keeps track of the total amount of givens
            
            
            string board = user.getBoard();//raw input from the board file is stored to a local variable board
            List<Square> tempBoard = new List<Square>();
            for (int i = 0; i < board.Length; i++)//board is then parsed and square objects are created based on the input 
            {
                if (board[i] == '\n' || board[i] == '\r')//skip to next iteration if current character is a formatting character
                    continue;
                Square tempSquare = new Square(count, board[i]);
                count++;
                tempBoard.Add(tempSquare);
                if (tempSquare.Number != 0)
                    placed++;

            }
            state.Board = tempBoard;
            state.Placed = placed;
            
            
            State temp = state.deepCopy();//creates a copy of the state object so temp can be modified with state being modified
            
           
            
            state.display(null);//displays the current, unedited board
            bool solved = false;//variable to keep track of whether the board is a solved one or not
            
            while (!solved)//loop until the board is solved
            {
                Square input = user.getInput(state);//chheck which square the user would like to modify
                temp.modBoard(input);//modify the temporary board with the new input
                State conCheck = temp.deepCopy();//make a new state for checking the consistency of the board
                Error check = conCheck.isConsistent(input);//check to see if there are any immediate errors based on the current board, without looking any deeper
                Error check2;
                if (check != null)// if there was an error display it and reset temp to the previous state of the board before the user modified it
                {
                    temp.display(check);
                    temp = state.deepCopy();
                }
                else if ((check2 = conCheck.checkConsistency(input)) != null)//otherwise check if the board can be completely solved, if an inconsistency is found an error will be returned 
                {
                    temp.display(check2);//display the error found by checking user input 
                    temp = state.deepCopy();//return state back to original form, before the user modified it
                }
                else//no inconsistencies detected from user input allow the input to be added to the main board, and display the new board 
                {
                    input.Solved = true;
                    state.modBoard(input);
                    state.display(null);
                }
                solved = state.solved();//check if the board is in the solved state
                Console.WriteLine("Press the enter key to continue");
                Console.ReadLine();
            }
            
            Console.WriteLine("Congratulations, you finished the puzzle!");
            Console.Read();
        }
    }
}


