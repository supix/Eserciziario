	public int somma() {
		int somma = 0; // accumulatore
		Record p = first; // inizializzo il puntatore al primo
		                  // elemento.
		while (p != null) { // Mentre p punta ad una cella...
			somma += p.el; // ...accumulo il valore puntato...
			p = p.succ; // ...ed avanzo all'elemento successivo
		}

		return somma; // restituisco il valore dell'accumulatore
	}