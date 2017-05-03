//Metodi privati
inline bool AlberoBinario::EUnaFoglia(const PNodo& n) {
//metodo di supporto che verifica se il nodo
//puntato da n è o meno una foglia.
  return (!n->sin && !n->des);
}  

bool AlberoBinario::_EliminaFoglia(PNodo& n, const TElem& el) {
  if (n) { //se n punta ad un nodo (e non a zero)
    //se l'elemento puntato è el e il nodo è una foglia
    if ((n->el == el) && EUnaFoglia(n)) {
      delete n; //elimina l'elemento
      n = 0; //azzera il puntatore
      return true;
    } else
      if (el > n->el)
        //ripeti l'operazione nel sottoalb. destro
        return _EliminaFoglia(n->des, el);
      else  
        //ripeti l'operazione nel sottoalb. sinistro
        return _EliminaFoglia(n->sin, el);
  }
  
  return false;  
}  

//Metodo pubblico
bool AlberoBinario::EliminaFoglia(const TElem& el) {
  if (_EliminaFoglia(root, el)) {
    numelem--;
    return true;
  } else
    return false;  
}
