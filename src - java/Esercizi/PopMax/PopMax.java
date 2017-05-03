	private class MinMax {
		int min;
		int max;
	}

	// Il metodo seguente estrae n elementi e ne restituisce
	// il min ed il max
	private MinMax _popMinMax(int n) {
		MinMax mm = new MinMax();
		mm.min = mm.max = pop(); // Assegno min e max all'elemento di
		                         // testa

		int i = 1;
		// confronto con gli altri n-1 elementi seguenti: n-1
		// iterazioni (se la coda non si svuota prima)
		while ((i < n) && !empty()) {
			int el = pop();
			if (el < mm.min)
				mm.min = el;
			if (el > mm.max)
				mm.max = el;
			i++;
		}

		return mm;
	}

	// Il metodo seguente chiama _popMinMax() e restituisce il
	// massimo
	public int popMax(int n) {
		MinMax mm = _popMinMax(n);
		return mm.max;
	}

	// Il metodo seguente chiama _popMinMax() e restituisce il
	// minimo
	public int popMin(int n) {
		MinMax mm = _popMinMax(n);
		return mm.min;
	}