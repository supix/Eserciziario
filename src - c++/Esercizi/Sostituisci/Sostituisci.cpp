//Metodo privato 

unsigned int AlberoBinario::_Sostituisci(PNodo& n, TElem i, TElem j) {
  unsigned int sostituzioni = 0;  
  
  if (n) {    
    //Sostituisco prima nei sottoalberi...
    if (i > n->el)
      sostituzioni = sostituzioni + _Sostituisci(n->des, i, j);
    else
      sostituzioni = sostituzioni + _Sostituisci(n->sin, i, j);
      
    //...poi nella radice
    if (n->el == i) {
      n->el = j;
      sostituzioni++;
    }
  }
  
  return sostituzioni; 
}
  
// Metodo pubblico

unsigned int AlberoBinario::Sostituisci(TElem i, TElem j) {
  return _Sostituisci(root, i, j);
}
