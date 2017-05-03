public class Coda {
	private class Record {
		int elem;
		Record succ;
	}

	private Record head;
	private Record tail;
	private int posti;
	private int numEl;

	public Coda(int _posti) {
		posti = _posti;
	}

	public boolean push(int el) {
		// Se la coda ha esaurito i posti, l'inserimento
		// non avviene
		if (numEl == posti)
			return false;

		// Creo un nuovo elemento
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
		// al nuovo elemento: la coda, cioè, era vuota al
		// momento dell'inserimento
		if (head == null)
			head = temp;

		numEl++;
		return true;
	}

	public int top() {
		if (head != null)
			return head.elem;

		// Se siamo qui, la coda è vuota e non ha senso invocare
		// il metodo top. Non è sensato restituire un valore
		// intero convenzionale, che potrebbe essere scambiato
		// dal chiamante come il valore di testa. La cosa più
		// giusta da fare è sollevare un'eccezione.
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

	public int pop(int n) throws IllegalStateException {
		if (head != null) {
			int el = pop();

			// estrazione dei restanti elementi: si usa il
			// metodo Pop() (se la coda non è vuota);
			for (int i = 2; (i <= n) && (head != null); i++)
				pop();

			return el;
		}

		// vedi commenti metodo top()
		throw new IllegalStateException("Impossibile leggere"
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