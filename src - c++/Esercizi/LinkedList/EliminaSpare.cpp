void Lista::Elimina(const TElem& el) {
  if (first) { //la lista non è vuota
    PRec* pp = &first; //indirizzo della variabile first
    bool trovato = false;
    while ((*pp) && (!trovato)) {
      if ((*pp)->el == el) {
        PRec tbd = *pp;
        *pp = (*pp)->succ;
        delete tbd;

        trovato = true;
        count--;
      } else
        pp = &((*pp)->succ);
    }
  }  
}
