using namespace std;

/*
Name:driver
Purpose:invokes all of the functions    
Parameters:none
Return:void
Pre-Condition:n/a
Post-Condition:n/a
Last Modification:11/17/14
*/ 
void driver();
/*
Name:openFile
Purpose: opens the file zip.dat in the file stream fin   
Parameters:ifstream by ref
Return:bool (true if file fails to open)
Pre-Condition:filestream should be declared prior 
Post-Condition:file is now open
Last Modification:11/17/14
*/ 
bool openFile(ifstream&);
/*
Name:closeFile
Purpose:closes the file in filestream fin  
Parameters:ifstream by ref
Return:void
Pre-Condition:filestream should be open 
Post-Condition:filesteam is closed
Last Modification:11/17/14
*/ 
void closeFile(ifstream&);
/*
Name:getZipNum
Purpose:counts the numbers of lines in a file and subtracts that number by four in order to give you the amount of actual zips in the file    
Parameters:int by ref and ifstream by ref
Return:void
Pre-Condition:filestream should be open and on first cursor and an int should be declared ready to be passed
Post-Condition:cursor is at eof
Last Modification:11/17/14
*/ 
void getZipNum(int&, ifstream&);
/*
Name:getInfo
Purpose:gets each line  that is a valid zip line and breaks it into zip code state city and whether it is a po box or not
Parameters:ZipInfo by ref ifstream by ref and 2 ints, one by ref
Return:void
Pre-Condition:all variables and struct should be declared prior to use and the file should be open
Post-Condition:cursor is at eof and the data in ZipInfo struct is modified as well as one of the ints
Last Modification:11/17/14
*/ 
void getInfo(ZipInfo&, ifstream&,int, int&);
/*
Name:display
Purpose:displays
Parameters:none
Return:void
Pre-Condition:n/a
Post-Condition:n/a
Last Modification:11/17/14
*/ 
void display(ZipInfo,int);

void driver()
{
  int numPo=0;
  ZipInfo zp;
  ifstream fin;
  int zipNum=0;
  if (openFile(fin))
 {  cout<<"File could not be opened, please make sure it has not been deleted or moved\n";
     closeFile(fin);
     return;
 }//end of if(displays error message if file fails to open
  getZipNum(zipNum,fin);
  zp.init(zp);
  getInfo(zp,fin,zipNum,numPo);
 // cout<<zipNum<<endl;
}//end of driver

bool openFile(ifstream& fin)
{
  fin.open("zip.dat");
  if(fin.fail())
    return true;
  else 
    return false;
}//end of openFile

void closeFile(ifstream& fin)
{
fin.close();
}//end of closeFile

void getZipNum(int& num,ifstream& fin)
{
string temp="";

while(!(fin.eof()))
 {
  getline(fin, temp);
  num++;
 }//end of loop(counting lines
num-=4;
}

void ZipInfo::init(ZipInfo& zp)
{
zp.state="";
zp.city="";
zp.zip="";
zp.po=APO;
zp.pc='a';
}//end of init

void getInfo(ZipInfo& zp,ifstream& fin,int num,int& numPo)
{
  
  string temp="";
  fin.close();
  fin.open("zip.dat");
  getline(fin, temp);
  getline(fin,temp);
    for(int i=0;i<num;i++)
   {
      getline(fin,temp);
      zp.zip=temp.substr(0,5);
      zp.state=temp.substr(5,2);
      zp.city=temp.substr(7,28 );
      zp.pc=temp[35];
      zp.work(zp,num,numPo);
     
    
   }
cout<<"There are "<<num<<" valid zip codes in the file"<<endl;
cout<<numPo<<" of them are PO box zip codes"<<endl;
}//end of getInfo

void ZipInfo::work(ZipInfo& zp,int numZip,int& numPo)
{ 
  
  if(zp.pc=='P')
 {  
    zp.po=Pobox;
    numPo++;
 } 
  else if(zp.pc=='U') 
    zp.po=Unique;
  else if(zp.pc=='M')
    zp.po=APO;
  else
    zp.po=Blank;
   
  switch(zp.po)
 {

  case APO:
  case Unique:
  case Blank:
    break;
  
  case Pobox:
    display(zp,numZip);

  
 }

}//end of work

void display(ZipInfo zp,int numZip)
{
  cout<<zp.city<<" | "<<zp.state<<" "<<zp.zip<<endl;
}//end of display

