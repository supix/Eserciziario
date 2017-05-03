public class AlberoBinarioOccMax {
	...
	private int occMax;
	...

	public AlberoBinarioOccMax(int occMax) {
		this.occMax = occMax;
	}

	// Questa classe è utile a convogliare dati all'esterno
	// della funzione _aggiungiElem().
	private class DatiAggiunta {
		// Costruttore con parametri
		public DatiAggiunta(Nodo nodo, boolean aggiuntaEffettuata) {
			this.nodo = nodo;
			this.aggiuntaEffettuata = aggiuntaEffettuata;
		}

		public Nodo nodo;
		public boolean aggiuntaEffettuata;
	}
	
	...
	
	//Metodo privato ricorsivo
	private DatiAggiunta _aggiungiElem(Nodo n, int elem,
	        int occCorrenti) {
		...
	}
	
	//Metodo pubblico
	public boolean aggiungiElem(int el) {
		...
	}
}