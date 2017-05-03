public class Accumulatore {
	private float a;

	public Accumulatore() {
		reset();
	}

	void add(float val) {
		a += val;
	}

	void reset() {
		a = 0;
	}

	float getValue() {
		return a;
	}
}