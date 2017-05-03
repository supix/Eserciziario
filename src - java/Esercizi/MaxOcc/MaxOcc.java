	private DatiAggiunta _aggiungiElem(Nodo n, int elem,
	        int occCorrenti) {
		if (n == null) { // Se l'albero è vuoto inserirò certamente
			n = new Nodo(); // si crea un nuovo elemento
			n.elem = elem; // e lo si inizializza

			// restituisco un'istanza di DatiAggiunta che contie-
			// ne il riferimento al nodo appena creato e il valo-
			// re true che indica l'avvenuta aggiunta.
			return new DatiAggiunta(n, true); // uscita anticipata
		}

		// L'albero non è vuoto e sono sul percorso dell'albero
		// cercando il punto di inserimento. Se lungo la strada
		// trovo un elemento uguale ad elem, incremento il con-
		// tatore delle occorrenze già individuate...
		if (elem == n.elem) {
			occCorrenti++;
			if (occCorrenti >= occMax) // ...e se ho superato il
			                           // valore max, esco anti-
				return new DatiAggiunta(n, false); // cipatamente
		}

		// Se sono qui il limite non è stato raggiunto
		DatiAggiunta da;
		if (elem > n.elem) {
			da = _aggiungiElem(n.des, elem, occCorrenti);
			n.des = da.nodo;
		} else {
			da = _aggiungiElem(n.sin, elem, occCorrenti);
			n.sin = da.nodo;
		}

		return new DatiAggiunta(n, da.aggiuntaEffettuata);
	}
	
	// Metodi pubblici
	public boolean aggiungiElem(int el) {
		if (occMax == 0) // se occMax è zero
			return false; // esco senza aggiungere alcunché.

		DatiAggiunta result = _aggiungiElem(root, el, 0);
		root = result.nodo;
		return result.aggiuntaEffettuata;
	}