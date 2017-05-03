public class ParcoPattini {
	private class Record {
		public StatoTaglia statoTaglia;
		public Record succ;
	}

	private Record first;
	private int tot;

	private Record getRecordByTaglia(int taglia) {
		// Questo metodo permette la gestione della lista come
		// tabella. Restituisce il punt. alla cella contenente
		// i pattini della taglia richiesta, oppure 0 se tale
		// cella non è nella lista.

		Record p = first;
		while (p != null)
			if (p.statoTaglia.taglia == taglia)
				return p;
			else
				p = p.succ;

		return null;
	}

	public void aggiungiPattini(int taglia) {
		Record p = getRecordByTaglia(taglia);

		if (p != null) {
			p.statoTaglia.totali++;
			p.statoTaglia.disponibili++;
		} else {
			p = new Record();
			p.statoTaglia = new StatoTaglia();
			p.statoTaglia.taglia = taglia;
			p.statoTaglia.totali = 1;
			p.statoTaglia.disponibili = 1;
			p.succ = first;
			first = p;
		}

		tot++;
	}

	public void svuota() {
		first = null;
		tot = 0;
	}

	public int numeroTotPattini() {
		return tot;
	}

	public boolean fitta(int taglia) {
		Record p = getRecordByTaglia(taglia);

		// ci sono pattini della taglia specificata, e se sì,
		// ce ne sono di disponibili?
		if ((p != null) && (p.statoTaglia.disponibili > 0)) {
			p.statoTaglia.disponibili--; // decrementa la
			                             // disponibilità
			return true;
		} else
			return false;
	}

	public int disponibilita(int taglia) {
		Record p = getRecordByTaglia(taglia);

		if (p != null)
			return p.statoTaglia.disponibili;

		return 0;
	}

	public int numeroPattini(int taglia) {
		Record p = getRecordByTaglia(taglia);

		if (p != null)
			return p.statoTaglia.totali;

		return 0;
	}

	public boolean restituzione(int taglia) {
		Record p = getRecordByTaglia(taglia);

		// ci sono pattini della taglia specif., e se sì,
		// ce ne sono di fittati?
		if ((p != null)
		        && (p.statoTaglia.disponibili < p.statoTaglia.totali)) {
			p.statoTaglia.disponibili++;
			return true;
		}

		return false;
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();
		Record p = first;

		while (p != null) {
			sb.append(p.statoTaglia.toString());
			sb.append(System.lineSeparator());
			p = p.succ;
		}

		return sb.toString();
	}
}