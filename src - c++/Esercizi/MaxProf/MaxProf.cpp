bool AlberoBinario::_Inserisci(PNodo& n, const TElem& el,
                                                    unsigned int _maxDepth) {
  if (_maxDepth > 0) {
    if (!n) {
      n = new Nodo; //si crea un nuovo elemento dell'albero...
      n->el = el; //...e lo si inizializza.
      n->sin = 0;
      n->des = 0;
      
      return true;
    }
    else
      if (el > n->el)
        return _Inserisci(n->des, el, _maxDepth - 1);
      else  
        return _Inserisci(n->sin, el, _maxDepth - 1);
  }      
  
  return false;
}

// Metodi pubblici
AlberoBinario::AlberoBinario(unsigned int _maxDepth): root(0), 
                                                        maxDepth(_maxDepth) {
}

bool AlberoBinario::Inserisci(const TElem& el) {
  return _Inserisci(root, el, maxDepth);
}
