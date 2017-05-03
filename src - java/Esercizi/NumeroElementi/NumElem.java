	//Metodo privato
	private int _numEl(Nodo n) {
		if (n == null) // se l'albero è vuoto...
			return 0; // ...restituisci zero

		// altrimenti, restituisco 1 (il nodo n) più il risultato
		// di numEl() invocato sui miei sottoalberi sx e dx
		return 1 + _numEl(n.sin) + _numEl(n.des);
	}

	//Metodo pubblico
	public int numEl() {
		// invoco del metodo ricorsivo sulla radice
		return _numEl(root);
	}