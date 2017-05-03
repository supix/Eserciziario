public class ListaStatica {
	// definizione della costante MAXEL che determina la
	// lunghezza del vettore che contiene gli elementi
	// della lista.
	private static final int MAXEL = 100;

	private int numEl; // questo elemento viene automaticamente
	                   // inizializzato al suo valore di default
	                   // (che è 0) all'atto della costruzione
	                   // della lista.
	private int[] v = new int[MAXEL];

	public void inserisciInCoda(int el) {
		v[numEl++] = el; // imposto l'elemento all'indice numEl
		                 // e, contestualmente, incremento numEl
		                 // dopo averne usato il valore (post-
		                 // incremento).
	}

	public void svuota() {
		numEl = 0;
		// come si può notare, lo svuotamento richiede solo di
		// impostare numEl a zero. Non è necessario, ma è anzi
		// inutile, sovrascrivere il valore degli elementi.
		// Questi non verranno mai letti nel seguito
		// del ciclo di vita dell'oggetto.
	}

	public int count() {
		return numEl;
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < numEl; i++)
			sb.append(v[i] + " ");
		return sb.toString();
	}
}