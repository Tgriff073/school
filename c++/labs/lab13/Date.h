using namespace std;
#include <string>

enum Day{Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
enum Month{January, February, March, April, May, June, July, August, September, November, December};

class Date
{
  private:
    Day day;
    Month month;
    int daym;
    int year;

  public:
    Date();
    Date(Day, int, Month, int);
    ~Date();
    int getYear();
    string getMonthShort();
    int getMonthInt();
    int getDateInt();
    string getDayOfWeekLong();
    string getDayOfWeekShort();
};
