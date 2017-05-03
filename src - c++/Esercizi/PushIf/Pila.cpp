Pila::Pila(unsigned int maxpush):
  top(0), nelem(0), _maxpush(maxpush), _currpush(0) {
}

void Pila::_Push(const TElem& e) {
  //Classica Push() in una pila: metodo privato
  PRec p = new Record;
  p->el = e;
  p->succ = top;
  top = p;
  nelem++;
}  
  
bool Pila::Push(const TElem& e) {
  if (_currpush < _maxpush) {
    _Push(e); //Inserisce incondizionatamente nella pila
    _currpush++;
    return true;
  }  
  
  return false;
}

TElem Pila::Pop() {
  if (top) {
    //memorizza il valore di testa per restituirlo alla fine
    TElem e = top->el;

    //memorizza il puntatore alla testa: essa dovrà essere cancellata
    PRec p = top;
    top = top->succ; //porta la testa al successivo
    delete p; //elimina la vecchia testa
    
    nelem--;   
    _currpush = 0; //azzero il conteggio degli inserimenti
    return e;
  }
  
  //questo metodo restituisce un valore non
  //specificato nel caso la pila sia vuota
}

void Pila::Svuota() {
  while (top) {
    PRec p = top;
    top = top->succ;
    delete p;
  }
  nelem = 0;
  _currpush = 0; //azzero il conteggio degli inserimenti
}
