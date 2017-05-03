public class Classifica {
	private class Record {
		public Squadra squadra;
		public Record succ;
	}

	private Record first;
	private int nelem;

	private int elimina(String nome) {
		// Questo metodo elimina dalla struttura un eventuale
		// elem. avente nome pari ad n. In caso di esistenza
		// ne restituisce il punteggio, altrimenti restituisce 0.

		// E' il primo elemento?
		if ((first != null)
		        && (first.squadra.getNome().equals(nome))) {
			int punti = first.squadra.getPunteggio();
			first = first.succ;
			nelem--;
			return punti;
		}

		// E' un elemento successivo al primo?
		Record p = first;
		while ((p != null) && (p.succ != null)) {
			// controllo se il successivo di p deve essere eliminato
			if (p.succ.squadra.getNome().equals(nome)) {
				int punti = p.succ.squadra.getPunteggio();
				p.succ = p.succ.succ;
				nelem--;
				return punti;
			}

			p = p.succ;
		}

		// Elemento non trovato
		return 0;
	}

	private void inserimentoOrdinato(String nome, int punteggio) {
		// Questo metodo effettua un inserimento ordinato nella
		// struttura, in base al campo punteggio. Si procede
		// attraverso i seguenti passi:
		// - se la lista è vuota si ins. l'elem. e si esce;
		// - si controlla se ins. in testa: se sì, si ins.
		// e si esce;
		// - si cerca il punto di inserimento attraverso una
		// visita, si inserisce (eventualmente in coda) e
		// si esce.

		// In ogni caso alloco un nuovo record
		Record nuovo = new Record();
		nuovo.squadra = new Squadra(nome, punteggio);
		nelem++;

		if (first == null) { // Se la lista è vuota
			first = nuovo; // Inserisco alla testa
			nuovo.succ = null;
		} else {
			// Se il punteggio della nuova squadra è maggiore
			// di quello puntato dalla testa...
			if (punteggio >= first.squadra.getPunteggio()) {
				nuovo.succ = first; // ...inserisco in testa
				first = nuovo;
			} else { // Devo cercare il punto di inserzione
				Record p = first;
				while (p.succ != null) {
					// Devo inserire dopo l'elemento puntato da p?
					if (punteggio >= p.succ.squadra
					        .getPunteggio()) {
						nuovo.succ = p.succ;
						p.succ = nuovo;
						return;
					}

					p = p.succ;
				}

				// Se sono qui, non ho ancora inserito: inserim.
				// in coda, alla quale punta p
				p.succ = nuovo;
				nuovo.succ = null;
			}
		}
	}

	public Classifica() {
		// first = null;
		// nelem = 0;
		// inizializzazioni superflue secondo
		// lo standard Java
	}

	public int aggiungi(String nome, int punteggio) {
		// Elimina dalla lista l'elemento (se esiste)
		int p = elimina(nome);

		// Lo (re)inserisce al posto giusto
		inserimentoOrdinato(nome, punteggio + p);

		// Restituisce il giusto punteggio
		return punteggio + p;
	}

	public void svuota() {
		first = null;
		nelem = 0;
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();
		Record p = first;
		while (p != null) {
			sb.append(p.squadra.toString());
			// aggiungiamo un ritorno a capo
			sb.append(System.lineSeparator());
			p = p.succ;
		}

		return sb.toString();
	}

	public int count() {
		return nelem;
	}
}