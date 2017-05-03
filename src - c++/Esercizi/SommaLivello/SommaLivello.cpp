//Metodo privato

void AlberoBinario::_SommaLivello(const PNodo& n, unsigned int i) {
  if (n) {
    n->el += i;
    _SommaLivello(n->sin, i+1);
    _SommaLivello(n->des, i+1);
  }    
}

//Metodo pubblico

void AlberoBinario::SommaLivello() {
  _SommaLivello(root, 1);
}
