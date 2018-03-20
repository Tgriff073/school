using namespace std;

class Cell
{

private:
 
  string carrier;
  string phoneNumber;
  int color;

public:
 
  Cell(string,string,int);
  Cell();
  void setNumber(string);
  void setCarrier(string);
  void changeColor(int);
  string getColor() const;
  string getNumber() const;
  string getCarrier() const;

};
