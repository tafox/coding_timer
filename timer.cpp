#include "timer.h"

int main(int args, char* argv[]) {
  Menu menu;
  menu.start();
  return 0;
}

Menu::Menu(void) : done(false) {}

void Menu::start(void) {
  Stats stats;
  Timer timer;
  cout << "Welcome to code timer." << endl;
  //cout << "You have logged " << stats.today() << " today." << endl; 
  while (!done) {
    cout << "Type 'start' to start timer" << endl;
    cout << "Type 'quit' to quit timer" << endl;
    cin >> option;
    if (option == "start") {
      timer.start();
      timer.secsToFormat(timer.time_elapsed());
      cout << "Your session was ";
      timer.printfTime();
      cout << " long" << endl;
    } else if (option == "quit") {
      done = true;
    } else {
      cout << "Invalid Option" << endl;
    }
  }
}

time_format Stats::today(void) {}
time_format Stats::week(void) {}
time_format Stats::month(void) {}
time_format Stats::year(void) {}

void Timer::start(void) {
  time(&start_time);
  string option;
  while (!done) {
    cout << "Type 'elapsed' to view elapsed time" << endl;
    cout << "Type 'stop' to stop timer" << endl;
    cin >> option;
    if (option == "elapsed") {
      secsToFormat(time_elapsed());
      cout << "Time elapsed: ";
      printfTime();
      cout << endl; 
    } else if (option == "stop") {
      done = true;
    } else {
      cout << "Invalid option" << endl;
    }
  }
}

double Timer::time_elapsed(void) {
  time(&elapsed);
  return difftime(elapsed,start_time);
}

void Timer::secsToFormat(double seconds) {
  fTime.minutes = seconds/60;
  fTime.hours = fTime.minutes/60;
  fTime.minutes -= fTime.hours*60;
}

void Timer::printfTime(void) {
  if (fTime.minutes < 10 && fTime.hours < 10) {
    cout << "0" << fTime.hours << ":0" << fTime.minutes;
  } else if (fTime.minutes < 10 && fTime.hours > 9) {
    cout << fTime.hours << ":0" << fTime.minutes;
  } else if (fTime.minutes > 9 && fTime.hours < 10) {
    cout << "0" << fTime.hours << ":" << fTime.minutes;
  } else {
    cout << fTime.hours << ":" << fTime.minutes;
  }
}
  
   
    




  
