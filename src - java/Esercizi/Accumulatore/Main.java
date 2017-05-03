import java.util.Scanner;

public class Main {
	// l'oggetto scanner aiuta a leggere dati inseriti sullo
	// standard-input (tastiera)
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.println("'a' add");
		System.out.println("'r' reset");
		System.out.println("'s' show");
		System.out.println("'e' exit");

		Accumulatore a = new Accumulatore();
		String line;

		do {
			line = scanner.nextLine();

			switch (line) {
			case "a":
				System.out.print("Inserisci valore: ");
				line = scanner.nextLine();
				float f = Float.parseFloat(line); 
				a.add(f);
				System.out.println("Valore aggiunto.");
				break;
			case "r":
				a.reset();
				System.out.println("Reset accumulatore.");
				break;
			case "s":
				System.out.println("Il valore accumulato è: "
				        + a.getValue());
				break;
			case "e":
				break;
			default:
				System.out.println("Scelta non valida");
				break;
			}
		} while (!line.equals("e")); //il metodo equals() della
									 //classe String confronta
									 //due stringhe
	}
}