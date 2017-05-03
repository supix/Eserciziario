	public class InfoProf {
		int profondita;
		boolean foglia;
	}

	private InfoProf _profondita(Nodo n, int elem) {
		if (n == null) // se l'albero � vuoto
			return null; // esco subito

		// Siccome si richiede l'elemento a profondit� massima
		// verifico prima se nei miei sotto-alberi l'elemento
		// � presente.

		// Decido se cercarlo a destra o a sinistra e...
		InfoProf ip;
		if (elem > n.elem)
			// ...uso il servizio che io stesso offro: ricorsione.
			ip = _profondita(n.des, elem);
		else
			ip = _profondita(n.sin, elem);

		if (ip != null) { // se al "piano di sotto" c'era...
			ip.profondita++; // ...aggiungo 1 alla profondit�
			                 // vista dal "piano di sotto"
			return ip; // e restituisco "sopra".
		}

		// se sono qui vuol dire che "sotto" non c'�
		// e verifico se l'elemento sono proprio io.
		if (n.elem == elem) { // se sono proprio io...
			ip = new InfoProf();
			ip.profondita = 1; // ...dal mio punto di vista la
							   // profondit� � 1 e...
			// ...se non ho figli l'elemento trovato � anche
			// una foglia...
			ip.foglia = (n.sin == null) && (n.des == null);
		}

		return ip;
	}

	public InfoProf profondita(int elem) {
		return _profondita(root, elem);
	}