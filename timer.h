#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

struct time_format {
  int hours;
  int minutes;
};

class Menu {
  public:
    Menu(void);
    void start(void);
  private:
    string option;
    bool done;
};

class Stats {
  public:
    time_format today(void);
    time_format week(void);
    time_format month(void);
    time_format year(void);
};

class Timer {
  public:
    void start(void);
    double time_elapsed(void);
    void secsToFormat(double seconds);
    void printfTime(void);
  private:
    time_t start_time;
    time_t elapsed;
    time_format fTime;
    bool done;
};
 
