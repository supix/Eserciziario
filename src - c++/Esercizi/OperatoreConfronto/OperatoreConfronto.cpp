//Metodo privato
bool AlberoBinario::_uguale(const PNodo& n1, const PNodo& n2) const {
  if (n1 == n2) //Se i puntatori alle radici coincidono, gli alberi
    return true; //sono uguali.
                 //Abbiamo gestito anche l'eventualità che
                 //gli alberi siano entrambi vuoti.
  
  if ((!n1 || !n2) && (n1 || n2)) //Se solo una delle due rad. è 0 (XOR)...
    return false; //...i due alberi non sono uguali
                    //(perché l'altra certamente non è zero)

  //Appurato che nessuna delle due radici punta a zero...
  if (n1->el != n2->el) //...se i due elem. puntati da n1 e n2 sono diversi...
    return false;       //...allora i due alberi non sono uguali.
  
  //Dunque, abbiamo due alberi non vuoti e contenenti elementi
  //di uguale valore nella radice.
  //Bisogna ora controllare se i loro sottoalberi sinistro e
  //destro sono uguali: ricorsione.
  return _uguale(n1->sin, n2->sin) && _uguale(n1->des, n2->des);
}  

// Metodo pubblico
bool AlberoBinario::operator==(const AlberoBinario& rhs) const {  
  // Chiamo il metodo privato _uguale() e gli passo la mia radice
  // e la radice dell'albero rhs.
  return _uguale(root, rhs.root);
}  
