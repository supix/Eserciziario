	public class MinMax {
		public int min;
		public int max;
	}

	public MinMax minMax() {
		if (first == null) // se la lista non contiene elementi
						   // non ha senso calcolare min e max
			return null; // e si restituisce null.

		MinMax mm = new MinMax();
		mm.min = first.el;
		mm.max = first.el;
		Record p = first.succ;

		while (p != null) {
			if (p.el < mm.min)
				mm.min = p.el;
			if (p.el > mm.max)
				mm.max = p.el;
			p = p.succ;
		}

		return mm;
	}