PRec Lista::getPuntCoda() const {
//Restituisce il puntatore alla coda della lista
  if (first) { //la lista è non-vuota?
    PRec p = first;
    while (p->succ)
      p = p->succ;
    
    return p;
  }
  else
    return 0; //se la lista è vuota non esiste una coda
}  

bool Lista::CodaPari() const {
  PRec p = getPuntCoda(); //restituisce il punt. alla coda, se c'è.
  if (p)
    return ((p->el % 2) == 0);
  else
    return false; //ritorna false per default;
}
