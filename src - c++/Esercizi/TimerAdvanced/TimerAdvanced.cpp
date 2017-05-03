#include <iostream>
#include <time.h>

using namespace std;

typedef int Time;

class Timer {
private:
  Time storedTime;
  Time startTime;
  bool isRunning() const { return (startTime != 0); };
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
  if (!isRunning())
    startTime = time(0);
}

void Timer::stop() {
  if (isRunning()) {
    storedTime += time(0) - startTime; //accumula il tempo del cont. in corso
    startTime = 0; //ferma il conteggio
  }  
}

void Timer::reset() {
  storedTime = 0;
  startTime = 0;
}

Time Timer::getTime() const {
  Time t = storedTime;
  
  if (isRunning())
    t += time(0) - startTime; //aggiunge il contributo del cont. in corso
    
  return t;
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
