public class Contenitore {
	private class Cella {
		public Oggetto elem;
		Cella succ;
	};

	Cella first;
	int capacita;
	int somma_pesi;
	int nelem;

	public Contenitore(int pesoMax) {
		// first = null;
		capacita = pesoMax;
		// somma_pesi = 0;
		// nelem = 0;
		// le inizializzazioni commentate
		// sono superflue secondo lo standard Java
	}

	public boolean inserisci(String nome, int peso) {
		if (peso <= capacita - somma_pesi) {
			Cella c = new Cella();
			c.elem = new Oggetto(nome, peso);
			c.succ = first;
			first = c;
			somma_pesi += peso; // il contenitore è ora più
			                    // pesante di p...
			nelem++; // ...e c'è un elemento in più.

			return true;
		}

		return false;
	}

	public void svuota() {
		first = null;
		somma_pesi = 0;
		nelem = 0;
	}

	public int pesoComplessivo() {
		return somma_pesi;
	}

	public int pesoResiduo() {
		return capacita - somma_pesi;
	}

	public int numElem() {
		return nelem;
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();
		Cella p = first;
		while (p != null) {
			sb.append(p.elem.getNome() + ": ");
			sb.append(p.elem.getPeso());
			p = p.succ;
			if (p != null)
				sb.append(", ");
		}
		
		return sb.toString();
	}
}