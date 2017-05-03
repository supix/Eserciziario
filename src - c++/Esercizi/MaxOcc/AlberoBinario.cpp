AlberoBinario::AlberoBinario(unsigned int max_occ): root(0),
                                                 maxocc(max_occ) {
}

//Metodo privato ricorsivo di supporto
bool AlberoBinario::_Inserisci(PNodo& n, const TElem& el, int curr_occ) {
  if (!n) { //se l'albero è vuoto inserisco certamente
    n = new Nodo;
    n->el = el;
    n->sin = 0;
    n->des = 0;
    return true;
  }
  else {
    if (el == n->el) { //se l'elemento corrente è pari ad el...
      curr_occ++; //...incremento curr_occ...
      if (curr_occ >= maxocc) //...e se ha raggiunto il limite...
        return false; //...esco con il valore false.
    }
    
    //Se sono qui il limite non è stato raggiunto.
    if (el > n->el)
      return _Inserisci(n->des, el, curr_occ);
    else  
      return _Inserisci(n->sin, el, curr_occ);
  }    
}

// Metodo pubblico Inserisci()
bool AlberoBinario::Inserisci(const TElem& el) {
  if (maxocc > 0) 
    return _Inserisci(root, el, 0);
  else
    return false;  
}
