public class Lista {
	private class Record {
		int el;
		Record succ;
	}

	private Record first;
	private int numEl;

	public Lista() {
	  /* Costruttore vuoto. Si vedano i commenti alla soluzione. */
	}

	public Lista(Lista l2) {
		// Questo costruttore deve creare la lista ad
		// immagine e somiglianza del modello l2.

		if (l2.first == null) // se il modello è una lista vuota,
		                      // ho già finito...
			return; // ...ed esco anticipatamente.

		inserisci(l2.first.el); // inserisco in this il primo el.
		                        // di l2
		Record p = this.first; // creo un puntatore al mio primo
		                       // elemento
		Record p2 = l2.first.succ; // creo un puntatore al
		                           // secondo elemento di l2
		                           // (che potrebbe essere anche
		                           // null)
		while (p2 != null) { // mentre l'elemento puntato in l2
			                 // non è null
			p.succ = new Record(); // creo un nuovo record e lo
			                       // imposto come successivo
			                       // dell'elemento puntato da p
			p.succ.el = p2.el; // gli assegno il valore
			p = p.succ; // sposto p in avanti per farlo puntare
			            // all'elemento appena creato
			p2 = p2.succ; // sposto p2 in avanti per puntare
			              // all'elemento di l2 successivo
		}
		this.numEl = l2.numEl; // imposto il mio numEl al numEl
		                       // di l2
	}

	public void inserisci(int el) {
		Record p = new Record(); // Creo una nuova area di
		                         // memoria nell'heap, destinata
		                         // a contenere un nuovo record
		p.el = el; // imposto il valore dell'elemento
		p.succ = first; // punto all'elemento successivo (che è
		                // il primo)
		first = p; // il "nuovo primo" è l'elemento appena
		           // creato.
		numEl++; // Incremento il numero degli elementi.
	}

	public int numeroElementi() {
		return numEl;
	}

	public void svuota() {
		// Lo svuotamento consiste nell'impostare il puntatore
		// first a null ed azzerare il numero degli elementi.
		first = null;
		numEl = 0;
	}

	public void elimina(int el) {
		// Questa versione di Elimina() elimina l'eventuale
		// prima occorrenza dell'elemento el.

		// Se la lista è vuota, esco senza far nulla
		if (first == null)
			return;

		// Si tratta diversamente il caso in cui l'elemento da
		// eliminare sia il primo da quello in cui è un
		// elemento successivo al primo.

		if (first.el == el) { // L'elemento da eliminare è il
			                  // primo?
			first = first.succ; // lo elimino!
			this.numEl--; // e decremento il numero degli
			              // elementi.
		} else { // altrimenti, scorro la lista in cerca
			     // dell'elemento
			Record p = first;
			while (p.succ != null)
				// mentre esiste un elemento
				// succ. a quello puntato...
				if (p.succ.el == el) { // ...se l'elemento
					                   // successivo è quello da
					                   // cancellare...
					p.succ = p.succ.succ; // ...lo rimuovo dalla
					                      // catena...
					this.numEl--; // ...decremento il numero
					              // degli elementi...
					break; // ...e interrompo il ciclo while.
				} else
					p = p.succ; // ...altrimenti punto con p
					            // all'elemento successivo.
		}
	}

	public String toString() {
		//La classe java.lang.StringBuilder ci consente di costruire
		//agevolmente la stringa contenente tutti gli elementi.
		StringBuilder sb = new StringBuilder();

		Record p = first; // punto con p al primo record
		while (p != null) { // mentre p punta ad un elemento...
			sb.append(p.el + " "); // ...lo stampo...
			p = p.succ; // ed avanzo con p al successivo elemento.
		} // Prima o poi p diventerà null.

		return sb.toString();
	}

	public boolean ricerca(int el) {
		Record p = first; // punto con p al primo record
		while (p != null)
			// mentre p punta ad un elemento...
			if (p.el == el) // ...se l'elem. è quello cercato...
				return true; // retrituisci subito true ed esci
				             // anticipatamente
			else
				p = p.succ; // altrimenti avanzo con p al
				            // successivo elemento.

		return false; // Se sono arrivato qui, p punta a null
		              // (fine della catena) e l'elemento non è
		              // stato trovato. Restituisco false.
	}
}