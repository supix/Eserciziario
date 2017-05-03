bool AlberoBinario::ProfMaggioreDiDue() const {
  return
    //c'è la radice e...
    //...o esiste il nodo di sinistra e questo ha almeno un figlio
    //oppure esiste il nodo di destra e questo ha almeno un figlio.
    //Tradotto in codice si ha:
    root && (
      (root->sin && (root->sin->sin || root->sin->des)) ||
      (root->des && (root->des->sin || root->des->des))
    );
}
