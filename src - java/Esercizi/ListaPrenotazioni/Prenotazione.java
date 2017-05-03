public class Prenotazione {
	private final int matricola;
	private final String nome;

	public Prenotazione(int matricola, String nome) {
		this.matricola = matricola;
		this.nome = nome;
	}

	public int getMatricola() {
		return matricola;
	}

	public String getNome() {
		return nome;
	}

	public String toString() {
		return matricola + ": " + nome;
	}
}