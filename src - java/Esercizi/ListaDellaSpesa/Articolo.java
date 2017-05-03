public class Articolo {
	private final String _nome;
	private float _quantita;

	public Articolo(String nome, float quantita) {
		_nome = nome;
		_quantita = quantita;
	}

	public String getNome() {
		return _nome;
	}

	public float getQuantita() {
		return _quantita;
	}

	public float addQuantita(float q) {
		_quantita += q;
		return _quantita;
	}
}