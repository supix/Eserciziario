	public boolean profMaggioreDiDue() {
		return
			(root != null) && // c'è la radice e...
			(
					// ...o esiste il nodo di sinistra e...
					((root.sin != null) && 
							// ...questo ha almeno un figlio...
							(
									(root.sin.sin != null) || 
									(root.sin.des != null)
							))
					
					|| //oppure
					
					// ...esiste il nodo di destra e...
					((root.des != null) &&
							// ...questo ha almeno un figlio.
							(
									(root.des.sin != null) || 
									(root.des.des != null)
							))
			);
	}