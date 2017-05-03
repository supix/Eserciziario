//Metodo privato

//Il metodo seguente estrae n elementi e ne restituisce il min ed il max
void Coda::_PopMinMax(unsigned int n, TElem& min, TElem& max) {
  min = max = Pop(); //Assegno min e max all'elemento di testa
  
  unsigned int i = 1;
  //confronto con gli altri n-1 elementi seguenti: n-1 iterazioni
  //(se la coda non si svuota prima)
  while ((i < n) && !Empty()) {
    TElem el = Pop();
    if (el < min)
      min = el;
    if (el > max)
      max = el;
    i++;
  }
}  

//Metodi pubblici

//Il metodo seguente chiama _PopMinMax() e restituisce il massimo
TElem Coda::PopMax(unsigned int n) {
  TElem min, max;
  _PopMinMax(n, min, max);
  return max;
}
  
//Il metodo seguente chiama _PopMinMax() e restituisce il minimo
TElem Coda::PopMin(unsigned int n) {
  TElem min, max;
  _PopMinMax(n, min, max);
  return min;
}
