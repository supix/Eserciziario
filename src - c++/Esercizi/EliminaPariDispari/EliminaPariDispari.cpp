unsigned int Lista::EliminaElementiPostoDispari() {
  int n = 0;
  if (first) {
    PRec p = first; //p punta al primo elemento (di indice 0, quindi pari)

    //Se p punta ad un elemento, e questo elemento ha un successivo...
    while (p && p->succ) {
      PRec tbd = p->succ; //...il successivo deve essere eliminato.
      p->succ = p->succ->succ; //Scollego l'elemento da canc. dalla catena,
      delete tbd; //lo distruggo,

      //p passa all'elemento successivo,
      //sempre di indice pari (nella lista originale).
      p = p->succ;
      n++;
    }
  }  
  
  return n;
}

unsigned int Lista::EliminaElementiPostoPari() {
  int n = 0;
  if (first) { //esci subito se la lista è vuota...
    //...altrimenti cancella subito il primo elemento (indice 0)
    PRec tbd = first;
    first = first->succ;
    delete tbd;
    n++;
    
    //essendo stata eliminata la testa non resta che
    //eliminare tutti gli elementi di posto dispari dell'attuale lista.
    n = n + EliminaElementiPostoDispari();
  }
  
  return n;
}
