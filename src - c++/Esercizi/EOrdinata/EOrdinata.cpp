bool Lista::EOrdinata() const {
  int i = 0;
  while (i < nelem - 1) {
    if (v[i] > v[i+1])
      return false; //esce subito se trova un'inversione
    i++;
  }
  return true; //esce senza aver trovato alcuna inversione: lista ordinata
}
