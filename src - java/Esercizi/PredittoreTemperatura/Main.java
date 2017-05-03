public class Main {

	public static void main(String[] args) {
		System.out.print("Lettura: all'istante 0: ");
		System.out.println("la temperatura vale 14");

		// Posso costruire il predittore con questi dati.
		TempPredictor tp = new TempPredictor(0, 14);

		System.out.print("Stima: la temperatura all'istante ");
		System.out.println("10 sarà " + tp.estimateTemp(10));
		;
		System.out.print("Stima: la temperatura all'istante ");
		System.out.println("20 sarà " + tp.estimateTemp(20));

		System.out.print("Lettura: all'istante 5: ");
		System.out.println("la temperatura vale 16");

		// Comunico la lettura al predittore
		tp.setTemp(5, 16);

		System.out.print("Stima: la temperatura all'istante ");
		System.out.println("10 sarà " + tp.estimateTemp(10));

		System.out.print("Stima: la temperatura all'istante ");
		System.out.println("12 sarà " + tp.estimateTemp(12));

		System.out.print("Lettura: all'istante 10: ");
		System.out.println("la temperatura vale 16");

		// Comunico la lettura al predittore
		tp.setTemp(10, 16);

		System.out.print("Stima: la temperatura all'istante ");
		System.out.println("15 sarà " + tp.estimateTemp(15));

		System.out.print("Stima: la temperatura all'istante ");
		System.out.println("20 sarà " + tp.estimateTemp(20));
	}
}