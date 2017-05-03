	private boolean eUnaFoglia(Nodo n) {
		// metodo di supporto che verifica se il nodo
		// puntato da n � o meno una foglia.
		return (n.sin == null) && (n.des == null);
	}

	private boolean _eliminaFoglia(Nodo n, int el) {
		// Questo metodo accetta un puntatore alla radice di un
		// albero ed elimina un'eventuale foglia dal valore
		// specificato in el. Non funziona se la radice � null
		// oppure se la foglia � proprio la radice. Chi lo invoca
		// deve esserne cosciente.
		if (el > n.elem) { // l'elem � potenzialmente a destra?
			if (n.des != null) {
				if ((n.des.elem == el) && (eUnaFoglia(n.des))) {
					n.des = null;
					return true;
				}

				// di certo n.des non � null e non � una foglia
				// da eliminare. Posso invocare il metodo
				// ricorsivo _eliminaFoglia() senza problemi.
				return _eliminaFoglia(n.des, el);
			}
		} else {
			if (n.sin != null) {
				if ((n.sin.elem == el) && (eUnaFoglia(n.sin))) {
					n.sin = null;
					return true;
				}

				// di certo n.sin non � null e non � una foglia
				// da eliminare. Posso invocare il metodo
				// ricorsivo _eliminaFoglia() senza problemi.
				return _eliminaFoglia(n.sin, el);
			}
		}

		return false;
	}

	public boolean eliminaFoglia(int el) {
		if (root == null) // se l'albero � vuoto, esco anticipa-
			return false; // tamente con false

		// Se in root c'� l'elemento da eliminare e
		// root � l'unico nodo...
		if ((root.elem == el) && eUnaFoglia(root)) {
			root = null; // lo cancello
			return true; // ed esco con true
		}

		// Ora sono sicuro che l'albero non � vuoto,
		// n� la radice � da eliminare. Posso invocare
		// il metodo ricorsivo _eliminaFoglia() senza problemi.
		return _eliminaFoglia(root, el);
	}