	public void inserisci(int el) {
		Record p = new Record(); //Creo una nuova area di
								 //memoria nell'heap, destinata
								 //a contenere un nuovo record
		p.el = el; //imposto il valore dell'elemento
		p.succ = first; //punto all'elemento successivo (che �
						//il primo)
		first = p; //il "nuovo primo" � l'elemento appena
				   //creato.
		numEl++; //Incremento il numero degli elementi.
		
		//Se quello inserito � il primo elemento, bisogna
		//aggiornare il valore della coda.
		if (first.succ == null)
			valoreCoda = first.el;
	}
	
	public void sommaCoda() {
		if (first != null) {
			//Se la lista non � vuota, la variabile-membro
			//valoreCoda contiene il valore della coda.
			//Lo sommo a tutti gli elementi.
			
			Record p = first;
			while (p != null) {
				p.el += valoreCoda;
				p = p.succ;
			}
			
			//Anche il valore della coda sar� stato incrementato;
			//aggiorno la variabile-membro
			valoreCoda *= 2;
		}
	}