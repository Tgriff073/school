using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class State
    {
        private List<Square> board;
        public List<Square> Board
        {
            get { return board; }
            set { board = value; }
        }
        public void display(Error err)
        {
            Console.Clear();
            if (err == null)
            {
                Console.Write(" ");//formating
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
                Console.Write(" ");//formating
                for (int i = 0; i < 9; i++)//display row index
                {
                    Console.Write(" {0}", i);
                }
                Console.WriteLine("\n");
                foreach (Square tmp in board)
                {
                    int index = tmp.Y * 9 + tmp.X;
                    if(err.ErrDomain.Contains(index))
                     Console.ForegroundColor = ConsoleColor.Red; 
                    tmp.display();
                    Console.ResetColor();
                }
            }
        }
        public State()
        {
            board = new List<Square>();
        }
        public void modBoard(int x, int y, int newVal)
        {
            int index = y * 9 + x;
            board[index].Val = newVal;
        }
        
    }
}
