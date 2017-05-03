import Coda.Coda;

public class PriorityQueue {
	Coda coda_l;
	Coda coda_h;
	
	public PriorityQueue() {
		coda_l = new Coda();
		coda_h = new Coda();
	}

	public void pushLow(int el) {
		coda_l.push(el);
	}

	public void pushHigh(int el) {
		coda_h.push(el);
	}

	public int pop() {
		if (!coda_h.empty())
			return coda_h.pop();
		else
			return coda_l.pop();
	}

	public void clear() {
		coda_h.svuota();
		coda_l.svuota();
	}

	public boolean empty() {
		return coda_h.empty() && coda_l.empty();
	}
}