	private Record getPuntCoda() {
		if (first == null) // se la coda è vuota...
			return null; // ...restituisce null

		Record p = first;
		while (p.succ != null)
			// altrimenti cerca la coda
			p = p.succ;

		return p; // e la restituisce
	}

	public boolean codaPari() {
		Record p = getPuntCoda();
		//Restituisco true se p è diverso da null AND
		//se l'elemento puntato è pari.
		//Sinteticamente...
		return (p != null) && (p.el % 2 == 0);
	}