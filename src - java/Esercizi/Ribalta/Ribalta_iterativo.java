	//Versione iterativa del metodo ribalta()

	//Metodo Pubblico
	public void ribalta() {
		// Se la lista contiene 0 o 1 elementi, esco subito.
		if (first == null || first.succ == null)
			return;

		Record p1 = first; // memorizzo in p1 il primo...
		Record p2 = first.succ; // ...e in p2 il secondo
		p1.succ = null; // p1 diventa l'ultimo e punta a null

		while (p2.succ != null) {
			Record temp = p2.succ; // memorizzo in temp il
									// successivo di p2
			p2.succ = p1; // il successivo di p2 è ora p1

			p1 = p2; // p1 diventa p2
			p2 = temp; // p2 diventa temp
		}

		// in questo punto del codice p1 e p2 puntano agli ultimi
		// due elementi della lista
		p2.succ = p1; // il successivo di p2 è ora p1
		first = p2; // p2 ora è la nuova testa
	}