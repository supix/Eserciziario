	private int _eliminaFoglie(Nodo n) {
		// Questo metodo accetta un puntatore alla radice di un
		// albero ed elimina tutte le sue foglie.
		// Non funziona se la radice è null o è foglia.
		// Chi lo invoca deve esserne cosciente.
		int eliminati = 0;
		if (n.sin != null) {
			if (eUnaFoglia(n.sin)) {
				n.sin = null;
				eliminati++;
			} else
				// n.sin non è null o foglia. Posso invocare la
				// ricorsione
				eliminati += _eliminaFoglie(n.sin);
		}

		if (n.des != null) {
			if (eUnaFoglia(n.des)) {
				n.des = null;
				eliminati++;
			} else
				// n.des non è null o foglia. Posso invocare la
				// ricorsione
				eliminati += _eliminaFoglie(n.des);
		}

		return eliminati;
	}

	public int eliminaFoglie() {
		if (root == null)
			return 0;

		if (eUnaFoglia(root)) {
			root = null;
			return 1;
		}

		// root non è null o foglia. Posso invocare la
		// ricorsione
		return _eliminaFoglie(root);
	}