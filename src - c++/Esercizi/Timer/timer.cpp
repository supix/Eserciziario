#include <iostream>
#include <time.h>

using namespace std;

typedef int Time;

class Timer {
private:
  Time startTime;
  Time stopTime;
public:
  Timer();
  void start();
  void stop();
  void reset();
  Time getTime() const;
};

Timer::Timer() {
  reset();
}

void Timer::start() {
  startTime = time(0);
  stopTime = 0;
}

void Timer::stop() {
  stopTime = time(0);
}

void Timer::reset() {
  startTime = 0;
  stopTime = 0;
}

Time Timer::getTime() const {
  if (startTime == 0) //il timer è in stato di reset?
    return 0;
  
  if (stopTime == 0)  //il timer è in moto?
    return time(0) - startTime; //sì
  else
    return stopTime - startTime; //no
}

int main()
{
  Timer t;
  char ch;
  
  cout << "'s' start\n";
  cout << "'x' stop\n";
  cout << "'r' reset\n";
  cout << "'p' show timer\n";
  cout << "'e' exit\n";
  
  do {
    cin >> ch;
    switch (ch) {
      case 's':
        t.start();
        cout << "Timer started.\n";
        break;
      case 'x':
        t.stop();
        cout << "Timer stopped.\n";
        break;
      case 'r':
        t.reset();
        cout << "Timer reset.\n";
        break;
      case 'p':
        cout << "Timer shows: " << t.getTime() << endl;    
        break;
      case 'e':
        break;  
      default:
        cout << "Invalid command.\n";
    }    
  } while (ch != 'e');

  return 0;
}
