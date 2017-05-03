	private boolean _codaPariRic(Record p) {
		if (p == null)
			return false;

		if (p.succ != null)
			return _codaPariRic(p.succ);
		else
			return p.el % 2 == 0;
	}
	
	public boolean codaPariRic() {
		return _codaPariRic(first);
	}