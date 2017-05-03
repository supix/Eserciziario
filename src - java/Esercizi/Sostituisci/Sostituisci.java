	private int _sostituisci(Nodo n, int i, int j) {
		if (n == null)
			return 0;

		//variabile accumulatore delle sostituzioni
		int sostituzioni = 0;

		// Sostituisco prima nei sottoalberi...
		if (i > n.elem)
			sostituzioni += _sostituisci(n.des, i, j);
		else
			sostituzioni += _sostituisci(n.sin, i, j);

		// ...poi nella radice
		if (n.elem == i) {
			n.elem = j;
			sostituzioni++;
		}

		return sostituzioni;
	}

	public int sostituisci(int i, int j) {
		return _sostituisci(root, i, j);
	}