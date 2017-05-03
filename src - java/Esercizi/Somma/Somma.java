	private void _somma(Nodo n, int i) {
		if (n != null) {
			n.elem += i;
			_somma(n.sin, i);
			_somma(n.des, i);
		}
	}

	public void somma(int i) {
		if (i != 0)
			_somma(root, i);
	}