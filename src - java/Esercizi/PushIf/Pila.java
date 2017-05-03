public Pila(int _maxPush) {
	maxPush = _maxPush;
}

private void _push(int el) {
	Record p = new Record();
	p.elem = el;
	p.succ = top;
	top = p;
	numEl++;
}

public boolean push(int el) {
	if (currPush < maxPush) {
		_push(el);
		currPush++;
		return true;
	}
	return false;
}

private int _pop() throws IllegalStateException {
	if (top != null) {
		int el = top.elem; // memorizza il valore di testa
		                   // per restituirlo alla fine
		top = top.succ;
		numEl--;
		return el;
	}
	
	throw new IllegalStateException();
}

public int pop() {
	currPush = 0;
	return _pop();
}

private void _svuota() {
	top = null;
	numEl = 0;
}

public void svuota() {
	currPush = 0;
	_svuota();
}