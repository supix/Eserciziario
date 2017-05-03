	public class ConteggioNodi {
		public int zero;
		public int uno;
		public int due;

		// Questo metodo di supporto somma membro a membro
		// due istanze di ConteggioNodi e ne restiutisce
		// il risultato in una nuova istanza.
		private ConteggioNodi somma(ConteggioNodi cn) {
			ConteggioNodi result = new ConteggioNodi();
			result.zero = this.zero + cn.zero;
			result.uno = this.uno + cn.uno;
			result.due = this.due + cn.due;

			return result;
		}
	}

	private ConteggioNodi _contaNodi(Nodo n) {
		// Creo subito l'istanza che restituirò
		ConteggioNodi cont = new ConteggioNodi();

		// Se n è null, il conteggio è zero ovunque
		if (n == null)
			return cont;

		// Chiedo al mio sottoalbero sinistro il suo conteggio
		ConteggioNodi cont_sin = _contaNodi(n.sin);
		// Chiedo al mio sottoalbero destro il suo conteggio
		ConteggioNodi cont_des = _contaNodi(n.des);

		// Calcolo il mio contributo
		if ((n.sin == null) && (n.des == null))
			cont.zero++;
		else if ((n.sin != null) && (n.des != null))
			cont.due++;
		else
			cont.uno++;

		// Sommo il contributo di cont_sin al valore corrente
		// di cont. Faccio puntare cont al risultato.
		cont = cont.somma(cont_sin);
		// Sommo il contributo di cont_des al valore corrente
		// di cont. Faccio puntare cont al risultato.
		cont = cont.somma(cont_des);

		return cont; // restituisco il conteggio
	}

	public ConteggioNodi contaNodi() {
		return _contaNodi(root);
	}