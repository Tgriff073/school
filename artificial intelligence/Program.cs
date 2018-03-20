using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
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
        static void Main(string[] args)
        {
            int x = 0;
            int y = 0;
            Player user = new Player();
            int val = 0;
            State curr = new State();
            Random rnd = new Random();
            for (int i = 0; i < 81; i++)
            {
                Square temp = new Square(i % 9, i / 9, 0);
                curr.Board.Add(temp);
            }
            for (int i = 0; i < 9; i++)
            {
                    x = rnd.Next(0, 8);
                    y = rnd.Next(0, 8);
                    val = rnd.Next(0, 9);
                    curr.modBoard(x, y, val);
             }
                curr.display(null);
                user.getInput(curr);
                curr.display(null);
                Error err = new Error(Error.errType.squareErr, curr.Board[80]);
                curr.display(err);
                Console.Read();
        }
    }
}
