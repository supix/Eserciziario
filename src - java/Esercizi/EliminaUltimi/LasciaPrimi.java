	public int lasciaPrimi(int n) {
		if (n >= numEl) // se n >= numEl, nessun elemento va
		                // eliminato, ed esco prematuramente.
			return 0;

		if (n == 0) { // se n = 0, tutti gli elementi vanno
			          // eliminati
			int nel = numEl;
			svuota();
			return nel;
		}

		Record p = first;

		// portiamo p a puntare all'ultimo elemento da tenere
		// nella lista; bisogna fare n-1 salti.
		for (int i = 1; i < n; i++)
			p = p.succ;

		p.succ = null; // scolleghiamo il resto della lista

		int eliminati = numEl - n; // calcolo quanti elementi
		                           // ho eliminato
		numEl = n; // aggiorno numEl

		return eliminati;
	}