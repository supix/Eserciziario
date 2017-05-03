public class AgenziaMatrimoniale {
	private class Record {
		public Persona persona;
		public Record succ;
	}

	private Record first;

	public AgenziaMatrimoniale() {
		// first = null;
		// inizializzazione superflua secondo
		// lo standard Java
	}

	private Record cerca(String nome) {
		// Cerca nella lista la persona avente il nome
		// specificato. Restituisce il puntatore alla
		// corrispondente cella se esiste, null altrim.
		Record p = first;
		while (p != null) {
			if (p.persona.getnome().equals(nome))
				return p;
			p = p.succ;
		}

		return null;
	}

	public boolean aggiungiPersona(String nome, boolean maschio) {
		if (cerca(nome) != null)
			return false;

		// Inserimento in testa
		Record p = new Record();
		p.persona = new Persona(nome, maschio);
		p.succ = first;
		first = p;

		return true;
	}

	public boolean sposa(String nome1, String nome2) {
		Record p1 = cerca(nome1);

		// se il primo nome non è stato trovato
		if (p1 == null)
			return false; // restituisco false

		Record p2 = cerca(nome2);

		// se il secondo nome non è stato trovato
		if (p2 == null)
			return false; // restituisco false

		return p1.persona.setConiuge(p2.persona);
		// la chiamata al metodo setConiuge() forza tutti i
		// controlli richiesti per il matrimonio tra due
		// persone
	}

	public class RicercaConiugato {
		public boolean trovato;
		public boolean coniugato;

		public RicercaConiugato(boolean trovato,
		        boolean coniugato) {
			this.trovato = trovato;
			this.coniugato = coniugato;
		}
	}

	public RicercaConiugato coniugato(String nome) {
		Record p = cerca(nome);

		if (p == null)
			return new RicercaConiugato(false, false);

		return new RicercaConiugato(true, p.persona.coniugato());
	}

	public int numeroSposi() {
		int numero = 0;
		Record p = first;
		while (p != null) {
			if (p.persona.coniugato())
				numero++;
			p = p.succ;
		}

		return numero;
	}

	public int numeroCoppie() {
		return numeroSposi() / 2;
	}

	public void svuota() {
		first = null;
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();
		Record p = first;
		while (p != null) {
			sb.append((p.persona.toString(true)));
			sb.append(System.lineSeparator());
			p = p.succ;
		}
		
		return sb.toString();
	}
}