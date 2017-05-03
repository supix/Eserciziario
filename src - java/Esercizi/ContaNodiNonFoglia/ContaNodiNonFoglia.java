	private boolean eUnaFoglia(Nodo n) {
		// metodo di supporto che verifica se il nodo
		// puntato da n è o meno una foglia.
		return (n.sin == null) && (n.des == null);
	}
	
	private int _contaNodiNonFoglia(Nodo n) {
		if (n == null) // Se l'albero è vuoto
			return 0; // il conteggio è nullo

		int count = 0; // accumulatore

		// eventuale contributo sottoalbero sinistro
		if (n.sin != null)
			count = count + _contaNodiNonFoglia(n.sin);

		// eventuale contributo sottoalbero destro
		if (n.des != null)
			count = count + _contaNodiNonFoglia(n.des);

		// eventuale contributo del presente nodo
		if (!eUnaFoglia(n))
			count++;

		return count;
	}

	public int contaNodiNonFoglia() {
		return _contaNodiNonFoglia(root);
	}