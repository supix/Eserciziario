//Metodo privato

unsigned int AlberoBinario::_Occorrenze(const PNodo& n,
                                       const TElem& el) const {
  if (!n) //Se l'albero con radice in n è vuoto...
    return 0; //...il numero di occorrenze è pari a zero.
    
  int occ = 0;
  
  if (n->el == el)
    occ++;
  
  if (el > n->el) //il segno > deve essere coerente con la convenzione
                  //stabilita per l'inserimento degli elementi nell'albero
    occ = occ + _Occorrenze(n->des, el);
  else  
    occ = occ + _Occorrenze(n->sin, el);
  
  return occ;
}

//Metodo pubblico

unsigned int AlberoBinario::Occorrenze(const TElem& el) const {
  return _Occorrenze(root, el);  
}
