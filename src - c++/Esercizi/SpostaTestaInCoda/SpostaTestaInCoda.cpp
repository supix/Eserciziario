//Metodo privato

PRec Lista::getPuntCoda() const {
//Restituisce il puntatore alla coda della lista
  if (first) {
    PRec p = first;
    while (p->succ)
      p = p->succ;
    
    return p;
  }
  else
    return 0; //non esiste una coda se la lista � vuota
}  

//Metodo pubblico

bool Lista::SpostaTestaInCoda() {
  PRec p = getPuntCoda(); //restituisce il punt. alla coda, se c'�.
  if (p) {
    p->succ = first;
    first = first->succ;
    p->succ->succ = 0;
  }

  return (p != 0); //se p non � 0, lo spostamento � stato effettuato
}
