#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int Time;
typedef float Temp;

class TempPredictor {
private:
  Time time1;
  Time time2;
  Temp temp1;
  Temp temp2;
public:
  TempPredictor(Time time, Temp temp);
  void SetTemp(Time time, Temp temp);
  Temp EstimateTemp(Time time) const;
};

TempPredictor::TempPredictor(Time time, Temp temp):
                    time1(time-1), time2(time), temp1(temp), temp2(temp) {
//Impostare in questo modo le temp. ed i tempi significa imporre che le
//ultime _due_ letture della temperatura hanno fornito un risult. pari a temp
//e su queste ultime due letture bisogna estrapolare la stima.
}

void TempPredictor::SetTemp(Time time, Temp temp) {
  time1 = time2; //"sposta" l'ultima lettura nella penultima
  temp1 = temp2;
  time2 = time; //aggiorna l'ultima lettura con i dati proven. dall'utente
  temp2 = temp;
}

Temp TempPredictor::EstimateTemp(Time time) const {
  return ((temp2-temp1)/(time2-time1))*(time-time1) + temp1;
}

int main()
{
  cout << "Lettura: all'istante 0: la temperatura vale 14\n";

  //Posso costruire il predittore con questi dati.
  TempPredictor tp(0,14);

  cout << "Stima: la temperatura all'istante 10 sara' "
                                            << tp.EstimateTemp(10) << endl;
  cout << "Stima: la temperatura all'istante 20 sara' " 
                                            << tp.EstimateTemp(20) << endl;
  
  cout << "Lettura: all'istante 5: la temperatura vale 16\n";

  //Comunico la lettura al predittore
  tp.SetTemp(5, 16);
  
  cout << "Stima: la temperatura all'istante 10 sara' "
                                            << tp.EstimateTemp(10) << endl;
  cout << "Stima: la temperatura all'istante 12 sara' " 
                                            << tp.EstimateTemp(12) << endl;
  
  cout << "Lettura: all'istante 10: la temperatura vale 16\n";
  
  //Comunico la lettura al predittore
  tp.SetTemp(10, 16);
  
  cout << "Stima: la temperatura all'istante 15 sara' " 
                                            << tp.EstimateTemp(15) << endl;
  cout << "Stima: la temperatura all'istante 20 sara' "
                                            << tp.EstimateTemp(20) << endl;

  system("PAUSE");
  return 0;
}
