#include "timer.h"

int main(int args, char* argv[]) {
  Menu menu;
  menu.start();
  return 0;
}

Menu::Menu(void) : done(false) {}

void Menu::start(void) {
  //Stats stats;
  cout << "Welcome to code timer." << endl;
  //cout << "You have logged " << stats.today() << " today." << endl; 
  while (!done) {
    cout << "Type 'start' to start timer" << endl;
    cout << "Type 'stats' to view stats" << endl;
    cout << "Type 'quit' to quit timer" << endl;
    cin >> option;
    if (option == "start") {
      Timer timer;
      timer.start();
      timer.secsToFormat(timer.time_elapsed());
      timer.saveTime();
      cout << "Your session was ";
      timer.printfTime();
      cout << " long" << endl;
    } else if (option == "stats") {
      Timer timer;
      timer.loadTime();
      cout << timer.loadedTimeRaw  << endl; 
    } else if (option == "quit") {
      done = true;
    } else {
      cout << "Invalid Option" << endl;
    }
  }
}

//time_format Stats::today(void) {}
//time_format Stats::week(void) {}
//time_format Stats::month(void) {}
//time_format Stats::year(void) {}

void Timer::start(void) {
  time(&start_time);
  done = false;
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
  fTime.days = fTime.hours/24;
  fTime.hours -=fTime.days*24;
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

void Timer::loadTime(void) {
  string line;
  ifstream inStream("coding_time.txt");
  getline(inStream, line);
  int i = 0;
  while (line[i] != ':') {
    i++;
  }
  loadedTimeRaw = line;
  loadedTime.days = stoi(line.substr(0,i));
  loadedTime.hours = stoi(line.substr(i+1,2));
  loadedTime.minutes = stoi(line.substr(i+4,2));
  inStream.close();
}

void Timer::saveTime(void) {
  int temp;
  loadTime();
  time_format save_time;
  save_time.days = 0;
  save_time.hours = 0;
  save_time.minutes = 0;
  save_time.minutes = fTime.minutes + loadedTime.minutes;
  if (save_time.minutes >= 60) {
    save_time.minutes -= 60;
    save_time.hours = 1;
  }
  temp = fTime.hours + loadedTime.hours;
  save_time.hours += temp;
  if (save_time.hours >= 24) {
    save_time.hours -= 24;
    save_time.days = 1;
  }
  temp = fTime.days + loadedTime.days;
  save_time.days += temp;
  ofstream outStream;
  outStream.open("coding_time.txt");
  if (save_time.minutes < 10 && save_time.hours < 10) {
    outStream << to_string(save_time.days)+":0"+to_string(save_time.hours)+":0"+to_string(save_time.minutes) << endl;
  } else if (save_time.minutes < 10 && save_time.hours > 9) {
    outStream << to_string(save_time.days)+":"+to_string(save_time.hours)+":0"+to_string(save_time.minutes) << endl;
  } else if (save_time.minutes > 9 && save_time.hours < 10) {
    outStream << to_string(save_time.days)+":0"+to_string(save_time.hours)+":"+to_string(save_time.minutes) << endl;
  } else {
    outStream << to_string(save_time.days)+":"+to_string(save_time.hours)+":"+to_string(save_time.minutes) << endl;
  }
  outStream.close();
}







  




  
   
    




  
