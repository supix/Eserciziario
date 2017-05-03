public class Oggetto {
	private final String nome;
	private final int peso;

	public Oggetto(String nome, int peso) {
		this.nome = nome;
		this.peso = peso;
	}

	public String getNome() {
		return nome;
	}

	public int getPeso() {
		// si tratti il peso come valore intero (p.es. grammi)
		return peso;
	}
}