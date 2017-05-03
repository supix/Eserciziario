public class Persona {
	private final String nome;
	private final boolean maschio;
	Persona coniuge;

	public Persona(String nome, boolean maschio) {
		this.nome = nome;
		this.maschio = maschio;
		coniuge = null;
	}

	public String getnome() {
		return nome;
	}

	public boolean getMaschio() {
		return maschio;
	}

	public Persona getConiuge() {
		return coniuge;
	}

	public boolean coniugato() {
		return coniuge != null;
	}

	public boolean setConiuge(Persona coniuge) {
		// in questo metodo, coniuge è la variabile locale,
		// mentre this.coniuge si riferisce alla variabile
		// membro privata della classe.
		// Anche se hanno lo stesso identificativo, sono due
		// riferimenti completamente indipendenti.

		// il coniuge non può essere null
		if (coniuge == null)
			return false;
		// non è dunque previsto il divorzio

		// se io o il coniuge siamo già sposati
		if ((this.coniuge != null) || (coniuge.coniuge != null))
			return false; // questo matrimonio non s'ha da fare

		// se io e il coniuge siamo dello stesso sesso
		if (maschio == coniuge.maschio)
			return false; // questo matrimonio non s'ha da fare
		// non è dunque previsto il matrimonio egualitario.

		this.coniuge = coniuge; // coniuge diventa mio coniuge e
		coniuge.coniuge = this; // io divento coniuge di coniuge
		return true; // auguri e figli maschi!
	}

	public String toString(boolean ancheConiuge) {
		StringBuilder sb = new StringBuilder();
		sb.append(nome);
		sb.append(" - ");
		sb.append(maschio ? "maschio " : "femmina ");
		if ((ancheConiuge) && (coniuge != null)) {
			sb.append(" - Coniugat" + (maschio ? "o" : "a")
			        + " con: ");
			sb.append(coniuge.toString(false));

			// nota che scrivere 'true' nella riga di
			// sopra innescherebbe una ricorsione infinita
			// in caso di stampa di persona coniugata.
		}

		return sb.toString();
	}
}