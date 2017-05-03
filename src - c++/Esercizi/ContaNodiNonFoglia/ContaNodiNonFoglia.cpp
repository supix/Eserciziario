//Metodo privato
unsigned int AlberoBinario::_ContaNodiNonFoglia(const PNodo& n) const {
  if (!n)
    return 0;
    
  unsigned int count = 0;
    
  //eventuale contributo sottoalbero sinistro
  if (n->sin)
    count = count + _ContaNodiNonFoglia(n->sin);

  //eventuale contributo sottoalbero destro
  if (n->des)
    count = count + _ContaNodiNonFoglia(n->des);
    
  //eventuale contributo del presente nodo
  if (n->sin || n->des)
    count++;
    
  return count;    
}
  
//Metodo pubblico
unsigned int AlberoBinario::ContaNodiNonFoglia() const {
  return _ContaNodiNonFoglia(root);  
}
