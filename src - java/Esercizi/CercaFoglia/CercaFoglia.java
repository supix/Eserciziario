	public class RisultatoRicercaFoglia {
		// classe immutabile
		private boolean trovato;
		private boolean foglia;

		public RisultatoRicercaFoglia(boolean trovato,
		        boolean foglia) {
			this.trovato = trovato;
			this.foglia = foglia;
		}

		public boolean getTrovato() {
			return trovato;
		}

		public boolean getFoglia() {
			return foglia;
		}
	}

	RisultatoRicercaFoglia _cercaFoglia(Nodo n, int el) {
		if (n == null) // Se n punta a null
			// uscita anticipata con false
			return new RisultatoRicercaFoglia(false, false);

		RisultatoRicercaFoglia rrf = null;

		// Cerco subito più "in basso".
		if (el > n.elem)
			rrf = _cercaFoglia(n.des, el);
		else
			rrf = _cercaFoglia(n.sin, el);

		if (rrf.trovato) // se in basso l'ho trovato...
			return rrf; // restituisco il verdetto.

		if (n.elem == el) { // se sono proprio io...
			rrf.trovato = true; // ...imposto trovato a true...
			rrf.foglia = eUnaFoglia(n); // ...e verifico se è
			                            // una foglia.
		}

		return rrf;
	}

	public class RisultatoRicercaNodo {
		// classe immutabile
		private boolean trovato;
		private boolean nodo;

		public RisultatoRicercaNodo(boolean trovato, boolean nodo) {
			this.trovato = trovato;
			this.nodo = nodo;
		}

		public boolean getTrovato() {
			return trovato;
		}

		public boolean getNodo() {
			return nodo;
		}
	}

	RisultatoRicercaNodo _cercaNodo(Nodo n, int el) {
		if (n == null)
			return new RisultatoRicercaNodo(false, false);

		if (n.elem == el) { // Se l'elemento corrente è pari ad
							// el...
			RisultatoRicercaNodo rrn = new RisultatoRicercaNodo(
			        false, false);
			rrn.nodo = (!eUnaFoglia(n)); // ...verifico se è un
			                             // nodo...
			rrn.trovato = true; // ...assegno risultato positivo.
			// E' infatti inutile procedere verso il basso.
			return rrn;
		} else // Se non l'ho trovato, cerco più "in basso".
		if (el > n.elem)
			return _cercaNodo(n.des, el);
		else
			return _cercaNodo(n.sin, el);
	}

	// Metodi pubblici
	public RisultatoRicercaFoglia cercaFoglia(int el) {
		return _cercaFoglia(root, el);
	}

	public RisultatoRicercaNodo cercaNodo(int el) {
		return _cercaNodo(root, el);
	}