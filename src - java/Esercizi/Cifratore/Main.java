import java.util.Scanner;

public class Main {
	// l'oggetto scanner aiuta a leggere dati inseriti sullo
	// standard-input (tastiera)
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.print("Inserisci la parola da cifrare: ");
		String parola = scanner.nextLine();

		System.out.print("Inserisci la chiave di cifratura: ");
		String chiave_s = scanner.nextLine();
		int chiave = Integer.parseInt(chiave_s);

		Cifratore c = new Cifratore(chiave);

		System.out.println("Parola: " + parola);
		String parola_cifrata = c.cifra(parola);
		System.out.println("Cifratura: " + parola_cifrata);
		String parola_decifrata = c.decifra(parola_cifrata);
		System.out.println("Decifratura: " + parola_decifrata);
	}
}