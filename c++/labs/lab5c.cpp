#include <iostream>
#include <iomanip>
using namespace std;

void partTwo()
{
  char userCharacter=' ';
  cout<<"Please enter a character"<<endl;
  cin>>userCharacter;
  if( userCharacter=='*' || userCharacter=='/' || userCharacter=='%' || userCharacter=='+' || userCharacter=='-')
{   cout<<"Character was an arithmetic operator\n"<<endl;
}
  else  if( userCharacter=='<'||userCharacter=='>')
{ cout<<"Character was a relational operator\n";
} 
 else  if ( userCharacter=='&'|| userCharacter=='|' || userCharacter=='!'|| userCharacter =='^'||userCharacter=='~')
{    cout<<("Character was a logical operator\n ");
} 
 else if (userCharacter=='=')
{    cout<<("Character was the assignment operator\n");
} 
  else if (userCharacter=='?'||userCharacter=='.'||userCharacter==';'||userCharacter==':'||userCharacter=='"'||userCharacter==',')
{  cout<<"Character was a punctuation";
}
 else
{    cout<<"Character was not supported by c++\n";
}
  

}

void partThree()
{
 char userCharacter=' ';
 cout<<"Please enter a character";
 cin>> userCharacter;

  switch(userCharacter)
{
  case '*':
  case '/':
  case '%':
  case '+':
  case '-':
    cout<<"Character was an arithmetic operator";
  break;
  case '<':
  case '>':
    cout<<"Character was a relational operator";
  break;
  case '!':
  case '&':
  case '|':
  case '^':
  case '~':
    cout<<"Character was logical operator";
  break;
  case '=':
    cout<<"Character was the assignment operator";
  break;
  case '?':
  case '.':
  case ':':
  case ';':
  case ',':
    cout<<"Character was punctuation";
  break;
}
}



int main()
{
partTwo();
partThree();
return 0;

}
