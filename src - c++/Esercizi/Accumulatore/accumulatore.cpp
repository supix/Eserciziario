#include <iostream>

using namespace std;

class Accumulatore {
private:
  float a;
public:
  Accumulatore() { Reset(); };
  void Add(float val) { a += val; };
  void Reset() { a = 0; };
  float GetValue() const { return a; };
};

int main()
{
  Accumulatore a;
  float f;
  char ch;
    
  cout << "'a' add\n";
  cout << "'r' reset\n";
  cout << "'s' show\n";
  cout << "'e' exit\n";
  
  do {
    cin >> ch;
    switch (ch) {
      case 'a':
        cout << "Insert value: ";
        cin >> f;
        a.Add(f);
        cout << "Value added.\n";
        break;
      case 'r':
        a.Reset();
        cout << "Reset.\n";
        break;
      case 's':
        cout << "The value is " << a.GetValue() << endl;
        break;
      case 'e':
        break;  
      default:
        cout << "Invalid command.\n";
    }    
  } while (ch != 'e');

  return 0;
}
