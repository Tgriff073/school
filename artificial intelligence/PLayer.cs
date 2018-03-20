using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Player
    {
        private int enteredVal;
        public State getInput(State board)
        {
            board.display(null);
            State temp = board;
            string input;
            int val = 0;
            int x = 0, y = 0;
            char delim = ',';
            bool valid = false;
            string[] parsed;
            while (!valid)
            {
                Console.WriteLine("Where would you like to go enter coordintates as X,Y for example 1,8");
                input = Console.ReadLine();
                parsed = input.Split(delim);
                x = Convert.ToInt32(parsed[0]);
                y = Convert.ToInt32(parsed[1]);
                if (x > 8 || x < 0)
                {
                    Console.WriteLine("Please enter a valid number for X (between 0 and 8)");
                    continue;
                }//end x check
                else if(y > 8 || y < 0)
                {
                    Console.WriteLine("Please enter a valid number for Y (between 0 and 8)");
                    continue;
                }//end y check
                valid = true;
            }//end position input loop
            valid = false;
            while(!valid)
            {
                Console.WriteLine("What value would you like to enter at {0}, {1}?", x, y);
                string inp = Console.ReadLine();
               
                val = Convert.ToInt32(inp);
                if(val > 9 || val < 0)
                {
                    Console.WriteLine("{0} you entered is invalid (please enter a value between 0 and 9)", val);
                    continue;
                }
                valid = true;
            }//end value input loop

            temp.modBoard(x, y, val);
            return temp;
        }//end getInput
    }
}
