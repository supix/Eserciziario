public class Coda {
	private class Record {
		int elem;
		Record succ;
	}

	private Record head;
	private Record tail;
	private int numEl;

	public Coda() {
	}

	public void push(int el) {
		// Creo un nuovo elemento
		Record temp = new Record();
		temp.elem = el;
		temp.succ = null;

		// se c'� un elemento di coda questo deve puntare al
		// nuovo elemento
		if (tail != null)
			tail.succ = temp;

		// in ogni caso la coda punter� al nuovo elemento
		tail = temp;

		// se la testa non punta ad un elemento, deve puntare
		// al nuovo elemento: la coda, cio�, era vuota al
		// momento dell'inserimento
		if (head == null)
			head = temp;

		numEl++;
	}

	public int top() throws IllegalStateException {
		if (head != null)
			return head.elem;

		// Se siamo qui, la coda � vuota e non ha senso invocare
		// il metodo top. Non � sensato restituire un valore
		// intero convenzionale, che potrebbe essere scambiato
		// dal chiamante come il valore di testa. La cosa pi�
		// giusta da fare � sollevare un'eccezione.
		throw new IllegalStateException("Impossibile leggere "
		        + "coda vuota.");
	}

	public int pop() throws IllegalStateException {
		if (head != null) {
			int el = head.elem;

			// head passa a puntare all'elemento successivo
			head = head.succ;

			// se head non punta a niente vuole dire che la coda
			// conteneva un solo elem. Anche tail quindi deve
			// puntare a null
			if (head == null)
				tail = null;

			numEl--;
			return el;
		}

		// vedi commenti metodo top()
		throw new IllegalStateException("Impossibile leggere "
		        + "coda vuota.");
	}

	public int somma() {
		int sum = 0;
		for (Record temp = head; temp != null; temp = temp.succ)
			sum += temp.elem;

		return sum;
	}

	public void svuota() {
		head = tail = null;
		numEl = 0;
	}

	public int count() {
		return numEl;
	}

	public boolean empty() {
		return numEl == 0;
	}
}