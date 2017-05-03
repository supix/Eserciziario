//Metodo privato
bool AlberoBinario::_ProfMaggioreDi(const PNodo& n, unsigned int p) const {
  if (n) { //se l'albero è non vuoto...
    if (p == 0) //se il contatore è (sceso fino a) zero...
      return true; //...abbiamo superato la prof. richiesta...
    else //...altrimenti bisogna continuare la discesa nei sottoalberi decrement. p.
      return (_ProfMaggioreDi(n->sin, p-1) || _ProfMaggioreDi(n->des, p-1));
  }
  else //...altrimenti è falso.
    return false;
}  

// Metodo pubblico
bool AlberoBinario::ProfMaggioreDi(unsigned int p) const {
  return _ProfMaggioreDi(root, p);
}
