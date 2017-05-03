	public int eliminaElementiPostoDispari() {
		if (first == null) // Se la lista è vuota
			return 0; // non c'è nulla da eliminare

		int n = 0; // accumulatore elementi eliminati
		Record p = first; // p punta al primo elemento (di
							// indice 0, quindi pari)

		// Se p punta ad un elemento, e questo ha un successivo...
		while ((p != null) && (p.succ != null)) {
			p.succ = p.succ.succ; // ...il successivo deve essere
									// eliminato. Lo faccio scol-
									// legandolo dalla catena.
			n++; // incremento l'accumulatore

			p = p.succ; // avanzo all'elemento successivo,
						// sempre di indice pari (nella lista
						// originale).
		}

		return n;
	}

	public int eliminaElementiPostoPari() {
		if (first == null) // Se la lista è vuota
			return 0; // non c'è nulla da eliminare

		int n = 0; // accumulatore elementi eliminati

		// Cancelliamo subito il primo elemento (indice 0).
		first = first.succ; // scolleghiamo il primo el. dalla
							// catena
		n++; // incremento l'accumulatore

		// essendo stata eliminata la testa, non resta che
		// eliminare tutti gli elementi di posto dispari
		// dell'attuale lista.
		n += eliminaElementiPostoDispari();

		return n;
	}