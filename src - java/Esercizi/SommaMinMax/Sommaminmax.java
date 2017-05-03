	public int sommaMinMax() {
	  int result = 0;
	  if (root != null) {
	    Nodo n;
	    
	    //Sommo il minimo
	    n = root;
	    //discendo l'albero verso sinistra finch� posso: minimo
	    while (n.sin != null)
	      n = n.sin;
	    result += n.elem;
	    
	    //Sommo il massimo
	    n = root;
	    //discendo l'albero verso destra finch� posso: massimo
	    while (n.des != null)
	      n = n.des;
	    result += n.elem;
	  }
	    
	  return result;
	}
