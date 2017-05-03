	//Versione ricorsiva del metodo ribalta()

	//Metodo privato
	private Record _ribalta(Record p) {
		// Se la lista contiene 0 o 1 elementi, non faccio nulla.
		if (p == null || p.succ == null)
			return p;

		// memorizzo in vecchiaTesta la vecchia testa
		Record vecchiaTesta = p;
		// memorizzo in vecchioSecondo il vecchio sec. elemento
		Record vecchioSecondo = p.succ;
		// ribalto la sottolista con in testa il vecchio sec...
		// ...e memorizzo in nuovaTesta la nuova testa.
		Record nuovaTesta = _ribaltaRicorsivo(vecchioSecondo);

		// la vecchia testa diviene l'ultimo elemento (e quindi
		// punta a null)
		vecchiaTesta.succ = null;
		// il vecchio secondo elemento punta alla vecchia testa
		vecchioSecondo.succ = vecchiaTesta;

		return nuovaTesta; // restituisco la nuova testa
	}

	//Metodo pubblico
	public void ribalta() {
		first = _ribaltaRicorsivo(first);
	}
