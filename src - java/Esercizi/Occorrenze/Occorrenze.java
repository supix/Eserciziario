	//Metodo privato
	private int _occorrenze(Nodo n, int elem) {
		if (n == null)
			return 0;

		int occ = 0; // accumulatore occorrenze

		if (n.elem == elem)
			occ++;

		if (elem > n.elem) // il segno > deve essere coerente con
		                   // la convenzione stabilita nel metodo
		                   // aggiungiElem()
			occ += _occorrenze(n.des, elem);
		else
			occ += _occorrenze(n.sin, elem);

		return occ;
	}

	//Metodo pubblico
	public int occorrenze(int elem) {
		return _occorrenze(root, elem);
	}