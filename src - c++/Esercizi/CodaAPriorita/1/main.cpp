#include <iostream>
#include <stdlib.h>

#include "PriorityQueue.h"

using namespace std;

void stampaMenu();
void PushLow(PriorityQueue& c);
void PushHigh(PriorityQueue& c);
void Pop(PriorityQueue& c);
void Clear(PriorityQueue& c);
void Count(PriorityQueue& c);
void Empty(PriorityQueue& c);

int main()
{
  char c;
  PriorityQueue coda;
  
  do {
    stampaMenu();
    cin >> c;
    cin.ignore();

    switch (c) {
      case '1':
        PushLow(coda);
        break;
      case '2':
        PushHigh(coda);
        break;
      case '3':
        Pop(coda);
        break;
      case '4':
        Clear(coda);
        break;        
      case '5':
        Empty(coda);
        break;
      case '6':
        break;  
      default:
        cout << "Scelta non valida.\n";
        break;
    }    
  } while (c != '6');

  return 0;
}

void stampaMenu() {
  cout << endl;
  cout << "1. PushLow" << endl;
  cout << "2. PushHigh" << endl;
  cout << "3. Pop" << endl;
  cout << "4. Clear" << endl;  
  cout << "5. Empty" << endl;
  cout << "6. Esci" << endl;
  cout << endl;
  cout << "Scelta: ";
}

void PushLow(PriorityQueue& c) {
  TElem el;
  cout << "Inserire elemento a bassa priorita': ";
  cin >> el;
  c.PushLow(el);
  cout << "Elemento inserito.\n";
}

void PushHigh(PriorityQueue& c) {
  TElem el;
  cout << "Inserire elemento ad alta priorita': ";
  cin >> el;
  c.PushHigh(el);
  cout << "Elemento inserito.\n";
}

void Pop(PriorityQueue& c) {
  if (!c.Empty())
    cout << "Elemento di testa: " << c.Pop() << endl;
  else
    cout << "Coda vuota." << endl;  
}

void Clear(PriorityQueue& c) {
  c.Clear();
  cout << "Coda svuotata.\n";
}

void Empty(PriorityQueue& c) {
  if (c.Empty())
    cout << "True." << endl;
  else
    cout << "False." << endl;  
}
