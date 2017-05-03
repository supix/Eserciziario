//Metodo Pubblico

TElem AlberoBinario::SommaMinMax() const {
  TElem result = 0;
  if (root) {
    PNodo p;
    
    //Sommo il minimo
    p = root;
    while (p->sin)
      p = p->sin;
    result += p->el;
    
    //Sommo il massimo
    p = root;
    while (p->des)
      p = p->des;
    result += p->el;
  }
    
  return result;
}
