unsigned int Lista::LasciaPrimi(unsigned int n) {
  if (n >= nelem) //se n >= nelem, nessun elemento va eliminato
    return 0;

  if (n == 0) { //se n = 0 tutti gli elementi vanno eliminati
    unsigned int nel = nelem;
    Svuota();
    return nel;
  }  
    
  PRec p = first;
      
  //portiamo p a puntare all'ultimo elemento da tenere nella lista
  //bisogna fare n-1 salti
  for (unsigned int i = 1; i < n; i++)
    p = p->succ;
        
  PRec last = p; //facciamo puntare da last l'elemento che diverrà l'ultimo
  p = p->succ; //p punta al primo da eliminare
  last->succ = 0; //l'elemento puntato da last punta ora a zero:
                  //la porzione della lista che va elimin. è ora scollegata
      
  unsigned int eliminati = nelem - n;    

  //p può ora essere immaginato come la testa di una lista da svuotare
  while (p) {
    PRec tbd = p;
    p = p->succ;
    delete tbd;
  }  
  
  nelem = n;
  return eliminati;
}
