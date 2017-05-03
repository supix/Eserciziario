unsigned int Lista::EliminaUltimi(unsigned int n) {
  if (n >= nelem) { //se n >= nelem la lista va svuotata
    unsigned int n = nelem;
    Svuota();
    return n;
  } else //altrimenti implement. questo metodo nei termini di LasciaPrimi()
      return LasciaPrimi(nelem - n);
}
