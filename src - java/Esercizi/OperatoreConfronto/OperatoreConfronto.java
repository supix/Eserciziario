	private boolean _equals(Nodo n1, Nodo n2) {
		if (n1 == n2) // Se i puntatori alle radici coincidono,
			return true; // gli alberi sono uguali.
			             // E questo gestisce anche l'eventualità
			             // che gli alberi siano entrambi vuoti.

		// Se solo una delle due rad. è null (XOR)...
		if ((n1 == null) ^ (n2 == null))
			return false; // ...i due alberi non sono uguali
			              // (perché l'altra certamente non è
			              // null)

		// Appurato che nessuna delle due radici punta a zero...
		if (n1.elem != n2.elem) // ...se i due elem. puntati da n1
		                        // e n2 sono diversi...
			return false; // ...allora i due alberi non sono uguali.

		// Dunque, abbiamo due alberi non vuoti e contenenti elementi
		// di uguale valore nella radice.
		// Bisogna ora controllare se i loro sottoalberi sinistro e
		// destro sono uguali: ricorsione.
		return _equals(n1.sin, n2.sin)
		        && _equals(n1.des, n2.des);
	}

	public boolean equals(Object obj) {
		// se l'oggetto ricevuto non è un AlberoBinario
		if (!(obj instanceof AlberoBinario))
			return false; // certamente non siamo uguali

		// creiamo un altro riferimento, di tipo AlberoBinario
		// all'oggetto obj, che è di fatto un AlberoBinario.
		// Questa è un'operazione di casting di tipo.
		AlberoBinario alb = (AlberoBinario) obj;

		// confrontiamo i due alberi a partire dalla radice
		return (_equals(root, alb.root));
	}