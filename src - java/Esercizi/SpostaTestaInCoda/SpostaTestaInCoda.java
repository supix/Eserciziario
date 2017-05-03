	private Record getPuntCoda() {
		if (first == null) // se la coda è vuota...
			return null; // ...restituisce null

		Record p = first;
		while (p.succ != null)
			// altrimenti cerca la coda
			p = p.succ;

		return p; // e la restituisce
	}
	
	public boolean spostaTestaInCoda() {
		Record p = getPuntCoda(); // restituisce il punt. alla
									// coda se c'è
		if (p != null) {
			p.succ = first; // il successivo della coda è first
			first = first.succ; // first avanza di un elemento
			p.succ.succ = null; // il successivo della (vecchia)
								// coda punta a null
		}

		return (p != null);
	}