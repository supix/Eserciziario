public class AlberoBinario {
	private class Nodo {
		int elem;
		Nodo sin;
		Nodo des;
	}

	private Nodo root = null;

	public AlberoBinario() {
	} // costruttore di default

	public AlberoBinario(AlberoBinario a) {
		if (this != a)
			root = _copiaAlbero(root, a.root);
	}

	// Metodi privati ricorsivi di supporto
	private Nodo _copiaAlbero(Nodo dest, Nodo source) {
		// Questo metodo ricorsivo accetta in ingresso un
		// puntatore ad un albero sorgente (source) e restituisce
		// in uscita un puntatore ad un albero che viene costrui-
		// to ricopiando il primo.
		if (source == null) { // se la sorgente è l'albero vuoto
			return null; // anch'io sarò vuoto ed esco
			             // prematuramente
		}

		dest = new Nodo(); // creo un nuovo nodo
		dest.elem = source.elem; // assegno il contenuto della
		                         // sorgente alla destinazione

		// Ora bisogna ricreare il sottoalbero sinistro ed il
		// sottoalbero destro del nodo puntato da dest rico-
		// piando i rispettivi sottoalberi puntati da source.
		// Riflettendo, l'operazione desiderata è del tutto
		// analoga a quella già invocata a partire dalla ra-
		// dice. E' quindi possibile sfruttare la ricorsione
		// ed invocare lo stesso "servizio" _copiaAlbero()
		// considerando source->des e source->sin come radici
		// di due distinti alberi.
		// La ricorsione si interromperà quando, in corrispon-
		// denza di ogni foglia, ne copiamo i sottoalberi
		// entrando nel ramo (source == null).

		dest.sin = _copiaAlbero(dest.sin, source.sin);
		dest.des = _copiaAlbero(dest.des, source.des);

		return dest;
	}

	private Nodo _aggiungiElem(Nodo n, int elem) {
		if (n == null) {
			n = new Nodo(); // si crea un nuovo elemento
			n.elem = elem; // e lo si inizializza
		} else {
			if (elem > n.elem)
				n.des = _aggiungiElem(n.des, elem);
			else
				n.sin = _aggiungiElem(n.sin, elem);
		}

		return n;
	}

	private boolean _inAlb(Nodo n, int elem) {
		if (n == null) // se l'albero è vuoto...
			return false; // ...elemento assente, uscita anticip.

		if (n.elem == elem) // l'elemento cercato è nella radice?
			return true; // restituisco true

		if (elem > n.elem) // è maggiore del contenuto della
		                   // radice?
			return _inAlb(n.des, elem); // cerca nel sottoalbero
			                            // destro
		else
			return _inAlb(n.sin, elem); // cerca nel sottoalbero
			                            // sinistro
	}

	private void _sostituisci(Nodo n) {
		// Questo metodo riceve in ingresso un riferimento ad un
		// nodo n, radice di un albero. Vi cerca il massimo del
		// sottoalbero sinistro, ne ricopia il valore nella ra-
		// dice e lo rimuove dall'albero.
		Nodo q = n.sin; // q punta al sottoalbero sinistro di n

		if (q.des == null) { // se q non ha un sottoalbero destro
			n.elem = q.elem; // ricopio il valore di q nel valore
			                 // di n
			n.sin = q.sin; // imposto il sinistro di n al sinistro
			               // di q
			return; // ed ho finito
		}

		while (q.des.des != null)
			// scendo a destra in cerca del
			// massimo. Mi fermo quando
			// punto all'elemento "sopra"
			// il massimo
			q = q.des;

		n.elem = q.des.elem; // ricopio il massimo in n
		q.des = q.des.sin; // imposto il destro di q al sinistro
		                   // del massimo
	}

	private Nodo _elimina(Nodo n, int elem) {
		if (n == null) // Eliminare da un albero vuoto non produce alcuna
		               // operazione
			return n; // uscita anticipata

		if (n.elem == elem) {
			// cancella nodo corrente
			if (n.sin == null) // il ramo sinistro del nodo da eliminare è
			                   // vuoto?
				n = n.des; // sostituzione del nodo col suo sottoalbero destro
			else if (n.des == null) // il ramo destro del nodo da eliminare è
			                        // vuoto?
				n = n.sin; // sostituzione del nodo col suo sottoalbero sinistro
			else
				// il nodo da eliminare ha sia il sottoalbero sx che quello dx?
				_sostituisci(n); // chiamo il "servizio" _sostituisci()
		} else if (elem > n.elem)
			n.des = _elimina(n.des, elem);
		else
			n.sin = _elimina(n.sin, elem);

		return n;
	}

	private void _preOrdine(Nodo n, StringBuilder sb) {
		if (n != null) {
			sb.append(n.elem + " ");
			_preOrdine(n.sin, sb);
			_preOrdine(n.des, sb);
		}
	}

	private void _postOrdine(Nodo n, StringBuilder sb) {
		if (n != null) {
			_postOrdine(n.sin, sb);
			_postOrdine(n.des, sb);
			sb.append(n.elem + " ");
		}
	}

	private void _inOrdine(Nodo n, StringBuilder sb) {
		if (n != null) {
			_inOrdine(n.sin, sb);
			sb.append(n.elem + " ");
			_inOrdine(n.des, sb);
		}
	}

	/* Qui iniziano i metodi pubblici */

	public void aggiungiElem(int el) {
		root = _aggiungiElem(root, el);
	}

	public boolean inAlb(int el) {
		return _inAlb(root, el);
	}

	public void elimina(int el) {
		root = _elimina(root, el);
	}

	public void svuota() {
		root = null;
	}

	public String preOrdine() {
		StringBuilder sb = new StringBuilder();
		_preOrdine(root, sb);
		return sb.toString();
	}

	public String postOrdine() {
		StringBuilder sb = new StringBuilder();
		_postOrdine(root, sb);
		return sb.toString();
	}

	public String inOrdine() {
		StringBuilder sb = new StringBuilder();
		_inOrdine(root, sb);
		return sb.toString();
	}
}