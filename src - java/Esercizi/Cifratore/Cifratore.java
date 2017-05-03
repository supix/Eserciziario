public class Cifratore {
	public int chiave;

	public Cifratore(int _chiave) {
		chiave = _chiave;
	}

	private char cifraCarattere(char c, boolean cifra) {
		if (cifra)
			return (char) (c + chiave); // cifratura: aggiunge
		else
			return (char) (c - chiave); // decifratura: sottrae
	}

	public String cifra(String str) {
		// La classe String è immutabile. I suoi caratteri non
		// possono essere modificati. E' pertanto necessario
		// creare una nuova stringa contenente la sequenza dei
		// caratteri cifrati.
		// La classe StringBuilder del package java.lang
		// è utile a costruire stringhe in maniera incrementale.

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < str.length(); i++)
			sb.append(cifraCarattere(str.charAt(i), true));
		return sb.toString();
	}

	public String decifra(String str) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < str.length(); i++)
			sb.append(cifraCarattere(str.charAt(i), false));
		return sb.toString();
	}
}