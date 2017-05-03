//Metodo privato

void AlberoBinario::_Somma(const PNodo& n, int i) {
  if (n && (i != 0)) {
    n->el += i;
    _Somma(n->sin, i);
    _Somma(n->des, i);
  }  
}

//Metodo Pubblico

void AlberoBinario::Somma(int i) {
  _Somma(root, i);
}
