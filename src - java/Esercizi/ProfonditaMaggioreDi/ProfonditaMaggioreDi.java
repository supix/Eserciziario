	private boolean _profMaggioreDi(Nodo n, int p) {
		if (n == null)
			return false;

		if (p == 0) // se il contatore è (sceso fino a) zero...
			return true; // ...abbiamo superato la prof. richiesta...
		else
			// ...altrimenti bisogna continuare la discesa nei sottoalberi
			// decrementando p.
			return _profMaggioreDi(n.sin, p - 1)
			        || _profMaggioreDi(n.des, p - 1);
	}

	// Metodo pubblico
	public boolean profMaggioreDi(int p) {
		return _profMaggioreDi(root, p);
	}