	public boolean eOrdinata() {
		for (int i = 0; i < numEl - 1; i++)
			if (v[i] > v[i + 1])
				return false; // esce prematuramente se trova
				              // un'inversione

		return true; // se non ha trovato inversioni, restituisce
		             // true.
	}