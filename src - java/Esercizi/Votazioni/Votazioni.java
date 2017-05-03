public class Votazioni {
	private class Votazione {
		private String codice;
		private int voti;

		public Votazione(String codice) {
			this.codice = codice;
		}

		public int getVoti() {
			return voti;
		}

		public int incrementaVoti() {
			return ++voti;
		}

		public String toString() {
			return codice + ": " + voti;
		}
	}

	private class Record {
		public Votazione votazione;
		public Record succ;
	}

	private Record first;
	int numVoti;

	Record cercaPartito(String codice) {
		// La struttura è gestibile con metodo tabellare: infatti
		// il codice partito rappresenta una chiave per la
		// tabella dei voti. Questo metodo restituisce il
		// puntatore alla cella avente codice pari a quello
		// specificato in ingresso se esistente.
		// null altrimenti.
		Record p = first;
		while (p != null) {
			if (p.votazione.codice.equals(codice))
				return p;
			p = p.succ;
		}

		return null;
	}

	public int aggiungiVoto(String codice) {
		numVoti++; // incremento il numero di voti complessivi
		Record p = cercaPartito(codice);

		if (p != null) {
			return p.votazione.incrementaVoti();
		} else {
			p = new Record();
			p.votazione = new Votazione(codice);
			int v = p.votazione.incrementaVoti();
			p.succ = first;
			first = p;
			return v;
		}
	}

	public void svuota() {
		first = null;
		numVoti = 0;
	}

	public int getVotiPartito(String codice) {
		Record p = cercaPartito(codice);

		if (p != null)
			return p.votazione.getVoti();

		return 0;
	}

	public int getNumeroVoti() {
		return numVoti;
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();
		Record p = first;

		while (p != null) {
			sb.append(p.votazione.toString()
			        + System.lineSeparator());

			p = p.succ;
		}

		return sb.toString();
	}
}