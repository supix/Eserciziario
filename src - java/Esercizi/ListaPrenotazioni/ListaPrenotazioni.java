public class ListaPrenotazioni {
	private Prenotazione[] vp;
	private int posti;
	private int nelem;

	private int ricerca(int matr) {
		for (int i = 0; i < nelem; i++)
			if (vp[i].getMatricola() == matr) // se lo trovo
				return i; // ne restituisco l'indice

		return -1; // altrimenti restituisco -1
	}

	public ListaPrenotazioni(int posti) {
		this.posti = posti;
		this.vp = new Prenotazione[posti];
		// this.nelem = 0;
		// quest'ultima inizializzazione è superflua
		// secondo lo standard Java
	}

	public boolean prenota(int matr, String nome) {
		if ((getPostiDisponibili() > 0)
		        && !esistePrenotazione(matr)) {
			vp[nelem++] = new Prenotazione(matr, nome);
			return true;
		}

		return false;
	}

	public boolean eliminaPrenotazione(int matr) {
		int i = ricerca(matr);

		if (i >= 0) {
			for (int j = i; j < nelem - 1; j++)
				vp[j] = vp[j + 1];

			nelem--;

			return true;
		}

		return false;
	}

	public int getPostiDisponibili() {
		return posti - nelem;
	}

	public boolean esistePrenotazione(int matr) {
		return ricerca(matr) >= 0;
	}

	public void svuota() {
		nelem = 0;
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < nelem; i++) {
			sb.append(vp[i].toString());
			sb.append(" - ");
		}

		return sb.toString();
	}
}