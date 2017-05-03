//Metodo privato
unsigned int AlberoBinario::_ContaMinMax(const PNodo& n, TElem Min,
                                                      TElem Max) const {
  if (n) {
    int count = 0;
    //Se l'elemento puntato da el � compreso tra Min e Max...
    if ((n->el >= Min) && (n->el <= Max))
      count ++; //...incremento count.
      
    //Se l'elemento puntato da n � minore di Max...
    if (n->el < Max) {
      //...allora nel sottoalbero destro potrebbero esserci altri elementi.
      count = count + _ContaMinMax(n->des, Min, Max);
    }  
      
    if (n->el >= Min) //E viceversa per il sottoalbero sinistro.
      count = count + _ContaMinMax(n->sin, Min, Max);
    
    return count;
  } else
    return 0; //L'albero � vuoto.
}

//Metodo pubblico
unsigned int AlberoBinario::ContaMinMax(TElem Min, TElem Max) const {
  return _ContaMinMax(root, Min, Max);
}
