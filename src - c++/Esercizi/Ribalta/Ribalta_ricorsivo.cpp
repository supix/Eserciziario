//Versione ricorsiva del metodo Ribalta()

//Metodo privato
PRec Lista::_ribalta(PRec p) {
  if ((!p) || (!p->succ)) //se la lista è formata da 0 o 1 elementi
                          //non faccio niente
    return p;
  else {
    //memorizzo in vecchia_testa la vecchia testa
    PRec vecchia_testa = p;
    //memorizzo in vecchio_secondo il vecchio secondo elemento
    PRec vecchio_secondo = p->succ;
    //ribalto la sottolista con testa in vecchio_secondo...
    //...e memorizzo in nuova_testa la nuova testa.
    PRec nuova_testa = _ribalta(vecchio_secondo);
                                  
    //la vecchia testa diviene l'ultimo elemento (e quindi punta a 0)                                  
    vecchia_testa->succ = 0;
    //il vecchio secondo elemento punta alla vecchia testa
    vecchio_secondo->succ = vecchia_testa;
    
    return nuova_testa; //restituisco la nuova testa
  }    
}    

//Metodo pubblico
void Lista::Ribalta() {
  first = _ribalta(first);
}
