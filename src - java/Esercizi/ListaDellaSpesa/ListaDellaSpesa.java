public class ListaDellaSpesa {
	private class Record {
		public Articolo a;
		public Record succ;
	}

	private Record first;
	private Record last;

	public ListaDellaSpesa() {
		//first = null;
		//last = null;
		//inizializzazioni superflue secondo lo standard Java
	}

	private Record ricerca(String nome) {
		// Questo metodo privato cerca l'articolo avente il nome
		// specificato e restituisce:
		// - il puntatore al corrispondente Record, se trovato;
		// - null, se non trovato.
		Record p = first;
		while (p != null) {
			if (p.a.getNome().equals(nome))
				return p;
			p = p.succ;
		}

		return null;
	}

	public boolean elimina(String nome) {
		if (first == null)
			return false;

		if (first.a.getNome().equals(nome)) {
			if (last == first) // se last e first sono sovrapposti
			                   // stiamo per cancellare l'unico
			                   // elemento. Quindi last deve
				last = null; // puntare a null.
			first = first.succ; // In ogni caso, first avanza
			                    // di una posizione in avanti.
			return true;
		}

		// Se siamo qui, l'elemento da eliminare, se c'è,
		// non è il primo.
		Record p = first;
		while (p.succ != null) {
			if (p.succ.a.getNome().equals(nome)) {
				if (last == p.succ) // se last punta all'elemento
				                    // da eliminare (p.succ) lo
				                    // facciamo arretrare di una
				                    // posizione. Punta quindi
				                    // a p.
					last = p;
				p.succ = p.succ.succ;
				return true;
			}

			p = p.succ;
		}

		return false;
	}

	public float aggiungi(String nome, float quantita) {
		Record p = ricerca(nome);
		if (p != null)
			return p.a.addQuantita(quantita);
		else {
			Articolo a = new Articolo(nome, quantita);
			p = new Record();
			p.a = a;
			p.succ = null;
			if (first == null)
				first = p;
			else
				last.succ = p;
			last = p;
			return quantita;
		}
	}

	public float getQuantita(String nome) {
		Record p = ricerca(nome);
		if (p != null)
			return p.a.getQuantita();
		else
			return 0;
	}

	public void svuota() {
		first = last = null;
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();
		Record p = first;
		while (p != null) {
			sb.append(p.a.getNome() + ": ");
			sb.append(p.a.getQuantita());
			p = p.succ;
			if (p != null)
				sb.append(", ");
		}
		
		return sb.toString();
	}
}
