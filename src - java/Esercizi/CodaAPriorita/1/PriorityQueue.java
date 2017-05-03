public class PriorityQueue {
	private class Record {
		int elem;
		Record succ;
	}

	Record head;
	Record tail; // puntatore alla coda
	Record tail_h; // puntatore alla coda della sottosequenza ad
	               // alta priorità

	public PriorityQueue() {
	}

	private void push(int el) {
		// Creo un nuovo elemento nell'heap
		Record temp = new Record();
		temp.elem = el;
		temp.succ = null;

		// se c'è un elemento di coda questo deve puntare al
		// nuovo elemento
		if (tail != null)
			tail.succ = temp;

		// in ogni caso la coda punterà al nuovo elemento
		tail = temp;

		// se la testa non punta ad un elemento, deve puntare
		// al nuovo elemento: la struttura, cioè, era vuota
		// al momento dell'inserimento
		if (head == null)
			head = temp;
	}

	public void pushLow(int el) {
		push(el); // si riduce ad un classico inserimento in coda
	}

	public void pushHigh(int el) {
		if (tail_h == null) {

			// non ci sono elementi ad alta priorità: aggiunta in
			// testa
			if (head == null) // la coda è vuota?
				push(el); // inserisco con push()
			else {
				Record temp = new Record();
				temp.elem = el;
				temp.succ = head;
				head = temp;
			}

			tail_h = head; // l'elemento inserito è in testa:
			               // tail_h deve puntarvi
		} else {
			// inserisco
			Record temp = new Record();
			temp.elem = el;
			temp.succ = tail_h.succ;
			tail_h.succ = temp;

			tail_h = temp; // aggiorno il puntatore tail_h

			// aggiorno tail se l'elemento aggiunto è in ultima
			// posizione
			if (tail_h.succ == null)
				tail = tail_h;
		}
	}

	public int pop() throws IllegalStateException {
		if (head != null) {
			Record temp = head;
			int el_temp = temp.elem;

			if (head == tail_h) // ho prelevato l'unico elemento
			                    // a priorità alta?
				tail_h = null; // allora non ce ne sono più

			// head passa a puntare all'elemento successivo
			head = head.succ;

			// se non punta a niente vuole dire che la coda
			// conteneva un solo elem. Anche tail quindi
			// deve puntare a null
			if (head == null) {
				tail = null;
				tail_h = null;
			}

			return el_temp;
		}

		// Se siamo qui, la coda è vuota e non ha senso invocare
		// il metodo top. Non è sensato restituire un valore
		// intero convenzionale, che potrebbe essere scambiato
		// dal chiamante come il valore di testa. La cosa più
		// giusta da fare è sollevare un'eccezione.
		throw new IllegalStateException("Impossibile leggere "
		        + "coda vuota.");
	}

	public void clear() {
		head = tail = tail_h = null;
	}

	public boolean empty() {
		return head == null;
	}
}