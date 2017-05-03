public class DoubleLinkedList {
	private class Record {
		int el;
		Record prec;
		Record succ;
	}

	private Record first;
	private Record last;
	int numEl;

	public DoubleLinkedList() {
		//first = null;
		//last = null;
		//numEl = 0;

		// tutte queste inizializzazioni sarebbero in realtà
		// pleonastiche, poiché corrispondono ai valori
		// di default che il linguaggio assegna ai tipi
		// riferimento e intero secondo lo standard Java
		// in fase di loro inizializzazione.
	}

	public void inserisci(int el) {
		Record p = new Record();
		p.el = el;
		p.succ = null; // pleonastica
		p.prec = last;
		if (last != null) // se last punta ad una coda, il suo
			last.succ = p; // successivo diviene l'elelento
			               // appena creato
		last = p; // il puntatore last va aggiornato al nuovo el.

		if (first == null) // se first punta a null (lista vuota)
			first = p; // va aggiornato al nuovo elemento

		numEl++;
	}

	public void svuota() {
		first = last = null;
		numEl = 0;
	}

	public String stampaDiretta() {
		StringBuilder sb = new StringBuilder();
		Record p = first;
		while (p != null) {
			sb.append(p.el + " ");
			p = p.succ;
		}
		return sb.toString();
	}

	public String stampaInversa() {
		StringBuilder sb = new StringBuilder();
		Record p = last;
		while (p != null) {
			sb.append(p.el + " ");
			p = p.prec;
		}
		return sb.toString();
	}

	public String stampaAlternata() {
		StringBuilder sb = new StringBuilder();
		Record p = first;
		Record q = last;
		boolean done = false;

		while ((p != null) && !done) {
			sb.append(p.el + " ");
			if (q != p)
				sb.append(q.el + " ");

			// se p e q sono sovrapposti oppure consecutivi
			// abbiamo terminato
			if ((p == q) || (p.succ == q))
				done = true;

			p = p.succ;
			q = q.prec;
		}
		return sb.toString();
	}

	int numeroElementi() {
		return numEl;
	}

}