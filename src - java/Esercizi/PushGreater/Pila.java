public class Pila {
	private class Record {
		int elem;
		Record succ;
	}

	private Record top;
	private int numEl;

	public Pila() {
	}

	public void push(int el) {
		Record p = new Record();
		p.elem = el;
		p.succ = top;
		top = p;
		numEl++;
	}

	public boolean pushGreater(int el) {
		if (empty() || (el > top())) {
			push(el);
			return true;
		} else
			return false;
	}

	public int top() throws IllegalStateException {
		if (top != null)
			return top.elem;

		// Se siamo qui, la pila è vuota e non ha senso invocare
		// il metodo top. Non è sensato restituire un valore
		// intero convenzionale, che potrebbe essere scambiato
		// dal chiamante come il valore di testa. La cosa più
		// giusta da fare è sollevare un'eccezione.
		throw new IllegalStateException("Impossibile leggere "
		        + "una pila vuota");
	}

	public int pop() throws IllegalStateException {
		if (top != null) {
			int el = top.elem; // memorizza il valore di testa
			                   // per restituirlo alla fine

			top = top.succ;
			numEl--;
			return el;
		}

		// vedi commenti al metodo top()
		throw new IllegalStateException("Impossibile leggere "
		        + "una pila vuota");
	}

	public void svuota() {
		top = null;
		numEl = 0;
	}

	public int count() {
		return numEl;
	}

	public boolean empty() {
		return (numEl == 0);
	}
}