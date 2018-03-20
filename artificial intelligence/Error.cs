using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    
    class Error
    {
        int[,] subSquares = new int[9, 9]{
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
        public enum errType { rowErr, columnErr, squareErr };
        errType error;
        Square incon;
        List<int> errDomain = new List<int>();
        public Error(errType err, Square inc)
        {
            incon = inc;
            error = err;
            switch(error)
            {
                case errType.rowErr:
                    for(int i = 0; i < 9; i++)
                    {
                        int index = incon.Y * 9 + i;
                        errDomain.Add(index);
                    }
                    break;
                case errType.columnErr:
                    for (int i = 0; i < 9; i++)
                    {
                        int index = incon.X + (i * 9);
                        errDomain.Add(index);
                    }
                    break;
                case errType.squareErr:
                    int temp = incon.SubSq;
                    for (int i = 0; i < 9; i++)
                        errDomain.Add(subSquares[temp, i]);
                    break;

            }
        }
        public void displayError(State curr)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            if(error == errType.rowErr)
            {
                for (int i = 0; i < 9; i++)
                {
                    int y = incon.Y + 2;
                    //int x = i + ;
                }
                
            }
            Console.ResetColor();
        }
       
        public List<int> ErrDomain
        {
            get { return errDomain;}
            set {errDomain = value;}
        }
    }
}
