using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/* File: Player.cs
 * Description: This class is used to create an object that allows the user to interact with the program. It was simply used to clean up the driver and have input/input handling done somewhere else
 * Last modified:5/8/2017
 * Class: Artificial Intelligence CS471 2017 Guillen
 * 
 */
namespace ConsoleSudoku
{
    class Player
    {
        private int enteredVal;
        private int diff;
        //function asks user what difficulty they would like to play on and returns the board of that corresponding difficulty as a raw string, the board is parsed somewhere else
        public string getBoard()
        {
            string line ="";
            Console.WriteLine("Which difficulty would you like to play? Type the number corresponding to your option");
            Console.WriteLine("1)Easy\n2)Medium\n3)Difficult");
            diff = Convert.ToInt32(Console.ReadLine());
            switch(diff)
            {
                case 1: 
                    line = System.IO.File.ReadAllText("easy.txt");
                    break;
                case 2:
                    line = System.IO.File.ReadAllText("medium.txt");
                    break;
                case 3:
                    line = System.IO.File.ReadAllText("hard.txt");
                    break;
            }
            
            return line;
        }
        //function gets input from the user, it asks them which square they would like to modify and what number they would like to enter at that square
        //it takes the current State as an argument but the state is not modified. If it is determined that the user input is valid(theyre trying to modify a valid square
        // and the number is between 1 and 9) then the square made by their input is returned. 
        public Square getInput(State board)
        {
            board.display(null);
            string input;
            int val = 0;
            int x = 0, y = 0;
            char delim = ',';
            bool valid = false;
            string[] parsed;
            while (!valid)
            {
                Console.WriteLine("Where would you like to go enter coordintates as X,Y for example 1,8.");
                input = Console.ReadLine();
                parsed = input.Split(delim);
                if(parsed.Length < 2)
                {
                    Console.WriteLine("Incorrect format, remember to enter you input in the form of X,Y");
                    continue;
                }
                x = Convert.ToInt32(parsed[0]);
                y = Convert.ToInt32(parsed[1]);
                if (x > 8 || x < 0)
                {
                    Console.WriteLine("Please enter a valid number for X (between 0 and 8).");
                    continue;
                }//end x check
                else if(y > 8 || y < 0)
                {
                    Console.WriteLine("Please enter a valid number for Y (between 0 and 8).");
                    continue;
                }//end y check
                else if(board.occupied(x,y))
                {
                    Console.WriteLine("The selected square is occupied by a given, these can not be altered.");
                    continue;
                }
                valid = true;
            }//end position input loop
            valid = false;
            while(!valid)
            {
                Console.WriteLine("What value would you like to enter at {0}, {1}?", x, y);
                string inp = Console.ReadLine();
               
                val = Convert.ToInt32(inp);
                if(val > 9 || val < 1)
                {
                    Console.WriteLine("{0} you entered is invalid (please enter a value between 1 and 9)", val);
                    continue;
                }
                valid = true;
            }//end value input loop
            Square temp = new Square(x, y, val);// create a square that is at the x and y coordinates specified by the user with the value specified by the user
            
            return temp;
        }//end getInput
    }
}
