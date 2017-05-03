//Metodo privato
unsigned int AlberoBinario::_NumElem(const PNodo& n) const {
  if (n)
    return 1 + _NumElem(n->sin) + _NumElem(n->des);
  else
    return 0;
}

// Metodo pubblico
unsigned int AlberoBinario::NumElem() const {
  return _NumElem(root);
}
