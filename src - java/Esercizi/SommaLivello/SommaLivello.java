	private void _sommaLivello(Nodo n, int i) {
		if (n != null) {
			n.elem += i;
			_sommaLivello(n.sin, i + 1);
			_sommaLivello(n.des, i + 1);
		}
	}

	public void sommaLivello() {
		_sommaLivello(root, 1);
	}