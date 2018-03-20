#include <iostream>
#include <fstream>
using namespace std;

int main()
{
string f=" .txt";
ofstream fout;
for(int i=0;i<26;i++)
{

f[0]=65+i;
fout.open(f.data());
fout.close();
}

}
