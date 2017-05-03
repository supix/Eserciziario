	public int eliminaUltimi(int n) {
		if (n >= numEl) { // se n >= numEl la lista va
			              // svuotata
			int nel = numEl;
			svuota();
			return nel;
		} else { // altrimenti implemento questo metodo nei
			     // termini di lasciaPrimi().
			return lasciaPrimi(numEl - n);
		}
	}