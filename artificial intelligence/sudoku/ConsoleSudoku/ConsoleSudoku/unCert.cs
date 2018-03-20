using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/* File: unCert.cs
 * Description: This class keeps track of an uncertain state. If the program needs to guess at any point, meaning a square can not be reduced to only one possible value in its domain, the current state and square before the guess is made is backed up. 
 * It also keeps track of all the numbers it has guessed for a particular square. The states are pushed on to a stack, if a variable has no possibly values and the stack is empty that means the state is inconsistent(user input was bad).
 * Last modified:5/8/2017
 * Dependencies: This class inherits from the priority queue class so it can be used as a node in a priority queue
 * Class: Artificial Intelligence CS471 2017 Guillen
 * 
 */
namespace ConsoleSudoku
{
    class unCert
    {
        State prev;//backup of state before guess
        List<int> guessed;//list of numbers guessed for current square
     
        Square gSquare;//backup of square before guess
        //ctor for uncert object, takes a state object as an argument and sets prev equal to a copy of the object. 
        public unCert(State t )
        {
            prev = new State();
            guessed = new List<int>();
            gSquare = new Square();
            prev = t.deepCopy();
       
        }

        //mutator for guessed
        public List<int> Guessed
        {
            get { return guessed; }
            set { foreach (int x in value) guessed.Add(x); }
        }

        //mutator for gsquare
        public Square Gsquare
        {
            get { return gSquare; }
            set { gSquare = value.deepCopy(); }
        }
        //mutator for prev
        public State Prev
        {
            get { return prev; }
            set { prev = value.deepCopy(); }
        }

        //default ctor for unCert, prevents null reference error
        public unCert()
        {
            prev = new State();
            guessed = new List<int>();
            gSquare = new Square();
        }

        //allows for copies of the uncert object to be made, so that the copy wont modify the original
        public unCert deepCopy()
        {
            unCert other = new unCert();
            other.prev = this.prev.deepCopy();
            gSquare = this.gSquare.deepCopy();
            other.guessed = new List<int>();
            foreach (int x in this.guessed)
                other.guessed.Add(x);
            return other;
        }
    }
}
