void Lista::Inserisci(TElem el) {
  //Inserimento in testa
  PRec p = new Record;
  p->el = el;
  p->succ = first;
  first = p;
  nelem++;
  
  //Se quello inserito è il primo elemento, bisogna aggiornare
  //il valore della coda.
  if (!first->succ)
    valoreCoda = el;
}

void Lista::SommaCoda() {
  if (first) {
    //Se la lista non è vuota, la variabile-membro contiene un val. corretto.
    //Lo sommo a tutti gli elementi.
    PRec p = first;
    while (p) {
      p->el = p->el + valoreCoda;
      p = p->succ;
    }
    
    //In questo punto, il valore dell'elemento di coda è raddoppiato.
    //Aggiorno la variabile-membro.
    valoreCoda = valoreCoda * 2;
  }
}
