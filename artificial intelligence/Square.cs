using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Square
    {
        private int val;
        private int x;
        private int y;
        private int subSq;
        private List<int> domain;
        bool given;
        public int X
        {
            get { return x; }
            set { x = value; }
        }
        public int SubSq
        {
            get { return subSq; }
            set { subSq = value; }
        }
        public int Y
        {
            get { return y;}
            set { y = value; }
        }
        public int Val
        {
            get { return val; }
            set { val = value; }
        }
        public List<int> Domain
        {
            get { return domain; }
            set { domain = value; }
        }
        public void limitDomain()
        {
            List<int> poss = new List<int>();
            poss.AddRange(Enumerable.Range(0,9));
            domain = poss;
        }
        public Square(int xPos, int yPos, int v)
        {
            x = xPos;
            y = yPos;
            val = v;
            given = true;
            if(y < 3)
            {
                if (x < 3)
                    subSq = 0;
                else if (x < 6)
                    subSq = 1;
                else
                    subSq = 2;
            }
            else if(y < 5)
            {
                if (x < 3)
                    subSq = 3;
                else if (x < 6)
                    subSq = 4;
                else
                    subSq = 5;
            }
            else
            {
                if (x < 3)
                    subSq = 6;
                else if (x < 6)
                    subSq = 7;
                else
                    subSq = 8;
            }
        }
        public void display()
        {
            if (x == 0)
                Console.Write("{0} ",y);
            Console.Write("{0} ", val);
            if (x == 8)
                Console.WriteLine("");
        }
           
    }
}
