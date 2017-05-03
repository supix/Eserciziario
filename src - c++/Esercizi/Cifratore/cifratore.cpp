#include <iostream>
#include <stdlib.h>

using namespace std;

class Cifratore {
private:
  int chiave;
  char CifraCarattere(char c, bool cifra) const;
public:
  Cifratore(int c);
  void Cifra(char* str) const;
  void Decifra(char* str) const;
};

Cifratore::Cifratore(int c): chiave(c) {
}

char Cifratore::CifraCarattere(char c, bool cifra) const {
  if (cifra)
    return c + chiave;
  else
    return c - chiave;  
}

void Cifratore::Cifra(char* str) const{ 
  while (*str) {
    *str = CifraCarattere(*str, true);
    str++;
  }
}

void Cifratore::Decifra(char* str) const {
  while (*str) {
    *str = CifraCarattere(*str, false);
    str++;
  }  
}

int main()
{
  char str[100];
  int chiave;

  cout << "Inserisci la parola da cifrare: ";
  cin >> str;
  cout << "Inserisci la chiave di cifratura: ";
  cin >> chiave;
  
  Cifratore c(chiave);
    
  cout << "Stringa: " << str << endl; 
  c.Cifra(str);
  cout << "Cifratura: " << str << endl; 
  c.Decifra(str); 
  cout << "Decifratura: " << str << endl; 

  system("PAUSE");
  return 0;
}
