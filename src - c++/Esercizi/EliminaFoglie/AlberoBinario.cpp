//Metodi privati
inline bool AlberoBinario::EUnaFoglia(const PNodo& n) {
//metodo di supporto che verifica se il nodo
//puntato da n è o meno una foglia.
  return (!n->sin && !n->des);
}  

unsigned int AlberoBinario::_EliminaFoglie(PNodo& n) {
  if (n) {
    if (EUnaFoglia(n)) {
      delete n;
      n = 0;
      return 1;
    }
    else
      return _EliminaFoglie(n->sin) + _EliminaFoglie(n->des);
  }
  
  return 0;
}  

//Metodo pubblico
unsigned int AlberoBinario::EliminaFoglie() {
  unsigned int n = _EliminaFoglie(root);
  numelem = numelem - n;
  return n;
  
  //La stessa operazione può essere sintetizzata (a scapito
  //della leggibilità) con la seguente riga di codice:
  //  return (numelem -= _EliminaFoglie(root));
}
