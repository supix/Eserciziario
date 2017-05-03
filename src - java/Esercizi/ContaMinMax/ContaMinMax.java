	private int _contaMinMax(Nodo n, int min, int max) {
		if (n == null)
			return 0;

		int count = 0;

		// Se l'elemento puntato da elem è compreso tra
		// min e max...
		if ((n.elem >= min) && (n.elem <= max))
			count++; // ...incremento count.

		// Se l'elemento puntato da n è minore di max...
		if (n.elem < max) {
			// ...allora nel sottoalbero destro potrebbero esserci altri
			// elementi.
			count = count + _contaMinMax(n.des, min, max);
		}

		if (n.elem >= min) // E viceversa per il sottoalbero sinistro.
			count = count + _contaMinMax(n.sin, min, max);

		return count;
	}

	public int contaMinMax(int min, int max) {
		return _contaMinMax(root, min, max);
	}