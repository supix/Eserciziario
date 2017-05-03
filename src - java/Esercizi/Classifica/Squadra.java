public class Squadra {
	private final String nome;
	private final int punteggio;
	
	public Squadra(String nome, int punteggio) {
		this.nome = nome;
		this.punteggio = punteggio;
	}
	
	public String getNome() {
		return nome;
	}
	
	public int getPunteggio() {
		return punteggio;
	}
	
	public String toString() {
		return nome + ": " + punteggio;
	}
}