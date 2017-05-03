//Metodi privati
inline bool AlberoBinario::EUnaFoglia(const PNodo& n) const {
  return (!n->des && !n->sin);
}

//Metodi ricorsivi di supporto
bool AlberoBinario::_CercaFoglia(const PNodo& n, TElem el,
                                          bool& foglia) const {
  if (!n)
    return false;
    
  bool trovato;
    
  //Cerco subito più in basso.
  if (el > n->el)
    trovato = _CercaFoglia(n->des, el, foglia);
  else  
    trovato = _CercaFoglia(n->sin, el, foglia);
      
  if (!trovato) { //Se più in basso non l'ho trovato...
    if (n->el == el) { //...e sono proprio io...
      trovato = true; //...imposto trovato a true...
      foglia = EUnaFoglia(n); //...e verifico se è una foglia.
    }    
  }
      
  return trovato;
}

bool AlberoBinario::_CercaNodo(const PNodo& n, TElem el, bool& nodo) const {
  if (!n)
    return false;
    
  if (n->el == el) { //Se l'elemento corrente è pari ad el...
    nodo = (!EUnaFoglia(n)); //...verifico se è un nodo...
    return true; //...ed esco con risultato positivo.
                 //E' infatti inutile procedere verso il basso.
  }
  else //Se non l'ho trovato, cerco più in basso.
    if (el > n->el)
      return _CercaNodo(n->des, el, nodo);
    else  
      return _CercaNodo(n->sin, el, nodo);
}  

// Metodi pubblici
bool AlberoBinario::CercaFoglia(TElem el, bool& foglia) const {
  return _CercaFoglia(root, el, foglia);
}

bool AlberoBinario::CercaNodo(TElem el, bool& nodo) const {
  return _CercaNodo(root, el, nodo);
}
