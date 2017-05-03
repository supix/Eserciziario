	private int _contaNodi(Nodo n) {
		if (n != null)
			return 1 + _contaNodi(n.sin) + _contaNodi(n.des);
		else
			return 0;
	}

	private Nodo _cercaOccorrenzaMin(Nodo n, int el) {
		// Cerca nell'albero avente radice in n l'elemento il
		// cui valore è pari ad el ed il cui livello è minimo.
		// Ne restituisce il puntatore.
		if (n != null) {
			if (n.elem == el) // Se sono il nodo con l'elemento
			                  // cercato...
				return n; // ...restituisco il puntatore a me stesso...
			else if (n.elem < el) // ...altrimenti cerco "più giù"
				return _cercaOccorrenzaMin(n.des, el);
			else
				return _cercaOccorrenzaMin(n.sin, el);
		} else
			return null;
	}

	private Nodo _cercaOccorrenzaMax(Nodo n, int el) {
		// Cerca nell'albero avente radice in n l'elemento il
		// cui valore è pari ad el ed il cui livello è massimo.
		// Ne restituisce il puntatore.
		if (n != null) {
			Nodo result;
			if (n.elem < el) // Cerco prima "più giù"
				result = _cercaOccorrenzaMax(n.des, el);
			else
				result = _cercaOccorrenzaMax(n.sin, el);

			if (result != null) // Se l'ho trovato...
				return result; // ...lo restituisco...
			else if (n.elem == el) // ...altrimenti verifico di
			                       // non essere l'elem. cercato.
				return n; // Se sono io, restituisco il
				          // puntatore a me stesso...
			else
				return null; // ...altrimenti restituisco null.
		} else
			return null;
	}

	public int contaNodiSottoalb_Min(int el) {
		Nodo n = _cercaOccorrenzaMin(root, el);
		if (n != null) // C'è almeno un elemento pari ad el?
			return _contaNodi(n);
		else
			return 0;
	}

	public int contaNodiSottoalb_Max(int el) {
		Nodo n = _cercaOccorrenzaMax(root, el);
		if (n != null) // C'è almeno un elemento pari ad el?
			return _contaNodi(n);
		else
			return 0;
	}