//Metodo privato
void AlberoBinario::_ContaNodi(const PNodo& n, unsigned int& zero,
                              unsigned int& uno, unsigned int& due) const {
  if (n) {
    _ContaNodi(n->sin, zero, uno, due);
    _ContaNodi(n->des, zero, uno, due);
    
    if (n->sin && n->des)
      due++;
    else
      if (!n->sin && !n->des)
        zero++;
      else
        uno++;
  }  
}

//Metodo pubblico
void AlberoBinario::ContaNodi(unsigned int& zero, unsigned int& uno,
                                                 unsigned int& due) const {
  zero = 0;
  uno = 0;
  due = 0;
  _ContaNodi(root, zero, uno, due);
}
