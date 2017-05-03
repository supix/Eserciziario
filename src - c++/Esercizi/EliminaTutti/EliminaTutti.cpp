int Lista::EliminaTutti(const TElem& el) {
  int j = 0;
  int count = 0;
  for (int i = 0; i < nelem; i++) {
    if (v[i] == el) //sono su un elemento da eliminare
      count++; //incremento il cont. delle eliminaz. e non ricopio l'elem.
    else {
      if (i != j) //i e j sono diversi? (è inutile ricopiare se i == j)
        v[j] = v[i]; //lo ricopio nel vettore ripulito
      j++; //il vettore ripulito ha ora un elemento in più
    }
  }    
  
  nelem = nelem - count;
  return count;
}
