public class AlberoBinario {
	...
	
	// Questa classe è utile a convogliare dati all'esterno
	// della funzione _inserisci().
	private class DatiAggiunta {
		// Costruttore con parametri
		public DatiAggiunta(Nodo nodo, boolean aggiuntaEffettuata) {
			this.nodo = nodo;
			this.aggiuntaEffettuata = aggiuntaEffettuata;
		}

		public Nodo nodo;
		public boolean aggiuntaEffettuata;
	}

	private Nodo root = null;
	private int maxDepth;

	public AlberoBinarioMaxProf(int _maxDepth) {
		this.maxDepth = _maxDepth;
	}
	
	...

	private DatiAggiunta _inserisci(Nodo n, int elem,
	        int _maxDepth) {
		if (_maxDepth > 0) {
			if (n == null) {
				n = new Nodo();
				n.elem = elem;

				return new DatiAggiunta(n, true);
			} else {
				DatiAggiunta da;
				if (elem > n.elem) {
					da = _inserisci(n.des, elem, _maxDepth - 1);
					n.des = da.nodo;
				} else {
					da = _inserisci(n.sin, elem, _maxDepth - 1);
					n.sin = da.nodo;
				}

				return new DatiAggiunta(n, da.aggiuntaEffettuata);
			}
		}

		//se sono qui, non ho inserito perché _maxDepth è
		//stato decrementato lungo la discesa ricorsiva fino
		//a diventare nullo
		return new DatiAggiunta(n, false);
	}
	
	...

	public boolean inserisci(int el) {
		DatiAggiunta da = _inserisci(root, el, maxDepth);
		root = da.nodo;
		return da.aggiuntaEffettuata;
	}
}