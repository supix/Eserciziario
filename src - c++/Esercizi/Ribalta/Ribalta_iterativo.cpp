//Versione iterativa del metodo Ribalta()

//Metodo Pubblico
void Lista::Ribalta() {
  if (first && first->succ) { //se la lista contiene almeno 2 elementi
    PRec p1 = first; //memorizzo in p1 il primo
    PRec p2 = p1->succ; //memorizzo in p2 il secondo
    p1->succ = 0; //p1, diventando l'ultimo elemento, deve puntare a zero
    
    while (p2->succ) { //se p2 non è l'ultimo elemento
      PRec temp = p2->succ; //memorizzo in temp il successivo di p2
      p2->succ = p1; //il successivo di p2 è ora p1
      
      p1 = p2; //p1 diventa p2;
      p2 = temp; //p2 diventa temp
    }

    //in questo punto del codice p1 e p2 puntano agli ultimi
    //due elementi della lista.
    p2->succ = p1; //il successivo di p2 è ora p1
    first = p2; //p2 ora è la nuova testa
  }  
}
