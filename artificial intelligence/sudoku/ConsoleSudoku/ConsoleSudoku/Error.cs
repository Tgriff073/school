using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/* File: Error.cs
 * Description: This class is used to make displaying errors in a board easier, error types are row errors, column errors, square errors, and a single error
 * a row error means an inconsistency was caused by a square in the same row as the modified square, column error is from same column, square is from same sub square 
 * and single error means that the specified square will cause an inconsistency in the future,meaning the cause is not currently observable
 * Last modified:5/8/2017
 * Class: Artificial Intelligence CS471 2017 Guillen
 * 
 */
namespace ConsoleSudoku
{
    
    class Error
    {
        
        public enum errType { rowErr, columnErr, squareErr, single };
        errType error;
        Square incon;
        //makes highlighting an inconsistent subCube easier
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
        List<int> errDomain = new List<int>();//keeps track of the coordinates of all the squares that are involved in the error.

        //ctor that takes an errtyp and a square, the errtype will help determine the errdomain and the square is used to find squares that are invloved in the error
        public Error(errType err, Square inc)
        {
            
            incon = inc.deepCopy();
            error = err;
            switch(error)
            {
                case errType.rowErr:
                    for(int i = 0; i < 9; i++)
                    {
                        int tempindex = incon.Y * 9 + i;
                        errDomain.Add(tempindex);
                    }
                    break;
                case errType.columnErr:
                    for (int i = 0; i < 9; i++)
                    {
                        int tempin = incon.X + (i * 9);
                        errDomain.Add(tempin);
                    }
                    break;
                case errType.squareErr:
                    int temp = incon.SubCube;
                    for (int i = 0; i < 9; i++)
                        errDomain.Add(cubeCoords[temp, i]);
                    break;
                case errType.single:
                    int index = incon.Y * 9 + incon.X;
                    errDomain.Add(index);
                    break;

            }
        }

        //ctor that only copies the square from its argument
        public Error(Square inc)
        {
            incon = inc.deepCopy();
        }

        //mutator for err
        public errType Err
        {
            get { return error; }
            set { error = value; }
        }

        //modifies the err of this error object and sets the domain of the error based on the type of the error
        public void setError(errType err)
        {
            switch (error)
            {
                case errType.rowErr://inconsistency caused by square in same row as specified square
                    for (int i = 0; i < 9; i++)
                    {
                        int index = incon.Y * 9 + i;
                        errDomain.Add(index);
                    }
                    break;
                case errType.columnErr://inconsistency caused by square in same column as specified square
                    for (int i = 0; i < 9; i++)
                    {
                        int index = incon.X + (i * 9);
                        errDomain.Add(index);
                    }
                    break;
                case errType.squareErr://inconsistency caused by square in same subCube as specified square
                    int temp = incon.SubCube;
                    for (int i = 0; i < 9; i++)
                        errDomain.Add(cubeCoords[temp, i]);
                    break;
                case errType.single://inconsistency caused by future incident
                    int tindex = incon.Y * 9 + incon.X;
                    errDomain.Add(tindex);
                    break;
            }//end switch
        }

        //mutator for errDomain
        public List<int> ErrDomain
        {
            get { return errDomain;}
            set {errDomain = value;}
        }
    }
}
