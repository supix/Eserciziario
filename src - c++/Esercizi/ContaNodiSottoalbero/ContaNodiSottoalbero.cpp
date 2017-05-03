// Metodi privati ricorsivi di supporto
unsigned int AlberoBinario::_ContaNodi(const PNodo& n) const {
  if (n)
    return 1 + _ContaNodi(n->sin) + _ContaNodi(n->des);
  else
    return 0;  
}

PNodo AlberoBinario::_CercaOccorrenzaMin(const PNodo& n,
  const TElem& el) const {
//Cerca nell'albero avente radice in n l'elemento il cui valore è pari
//ad el ed il cui livello è minimo. Ne restituisce il puntatore.
if (n) {
    if (n->el == el) //Se sono il nodo con l'elemento cercato...
      return n; //...restituisco il puntatore a me stesso...
    else
      if (n->el < el) //...altrimenti cerco "più giù"
        return _CercaOccorrenzaMin(n->des, el);
      else
        return _CercaOccorrenzaMin(n->sin, el);
  } else
    return 0;  
}  

PNodo AlberoBinario::_CercaOccorrenzaMax(const PNodo& n,
  const TElem& el) const {
//Cerca nell'albero avente radice in n l'elemento il cui valore è pari
//ad el ed il cui livello è massimo. Ne restituisce il puntatore.
  if (n) {
    PNodo result;
    if (n->el < el) //Cerco prima "più giù"
      result = _CercaOccorrenzaMax(n->des, el);
    else
      result = _CercaOccorrenzaMax(n->sin, el);
      
    if (result) //Se l'ho trovato...
      return result; //...lo restituisco...
    else
      if (n->el == el) //...altrimenti verifico di non essere l'elem. cercato.
        return n; //Se sono io, restituisco il puntatore a me stesso...
      else
        return 0; //...altrimenti restituisco 0.
  } else
    return 0;  
}
  
// Metodi pubblici
unsigned int AlberoBinario::ContaNodiSottoalb_Min(const TElem& el) const {
  PNodo n = _CercaOccorrenzaMin(root, el);
  if (n) //C'è almeno un elemento pari ad el?
    return _ContaNodi(n);
  else
    return 0;
}
  
unsigned int AlberoBinario::ContaNodiSottoalb_Max(const TElem& el) const {
  PNodo n = _CercaOccorrenzaMax(root, el);
  if (n) //C'è almeno un elemento pari ad el?
    return _ContaNodi(n);
  else
    return 0;
}  
