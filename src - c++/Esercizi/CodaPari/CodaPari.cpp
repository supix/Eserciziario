PRec Lista::getPuntCoda() const {
//Restituisce il puntatore alla coda della lista
  if (first) { //la lista � non-vuota?
    PRec p = first;
    while (p->succ)
      p = p->succ;
    
    return p;
  }
  else
    return 0; //se la lista � vuota non esiste una coda
}  

bool Lista::CodaPari() const {
  PRec p = getPuntCoda(); //restituisce il punt. alla coda, se c'�.
  if (p)
    return ((p->el % 2) == 0);
  else
    return false; //ritorna false per default;
}
