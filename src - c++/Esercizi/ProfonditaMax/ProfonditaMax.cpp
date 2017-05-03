int AlberoBinario::_Profondita(const PNodo& n, const TElem& el,
                                                 bool& foglia) const {
  if (n) { //se l'albero è vuoto esco subito
    int p;
    //decido se cercarlo a destra o a sinistra e...
    if (el > n->el) 
      //...uso il servizio che io stesso offro: ricorsione.
      p = _Profondita(n->des, el, foglia);
    else  
      p = _Profondita(n->sin, el, foglia);
    
    if (p != -1) //se l'ho trovato in profondità p al "piano di sotto"...
      return p + 1; //...la profondità dal mio punto di vista è p + 1.
    
    //se sono qui vuol dire che ancora devo trovarlo
    if (n->el == el) {  //se sono proprio io...
      //...se non ho figli l'elemento trovato è anche una foglia...
      foglia = (!n->sin && !n->des);
      return 1; //...e la profondità dal mio punto di vista è 1.
    }  
  }
  
  //se sono qui non l'ho trovato
  return -1;
}

int AlberoBinario::Profondita(const TElem& el, bool& foglia) const {
  return _Profondita(root, el, foglia);
}
