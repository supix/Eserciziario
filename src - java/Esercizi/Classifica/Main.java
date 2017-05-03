import java.util.Scanner;

public class Main {
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		String line;
		Classifica c = new Classifica();

		do {
			stampaMenu();
			System.out.print("Scelta: ");
			line = scanner.nextLine();
			switch (line) {
			case "1":
				inserisci(c);
				break;
			case "2":
				svuota(c);
				break;
			case "3":
				stampa(c);
				break;
			case "4":
				count(c);
				break;
			case "5":
				break;
			default:
				System.out.println("Scelta non valida.");
				break;
			}
		} while (!line.equals("5"));
	}

	private static void stampaMenu() {
		System.out.println("1: Inserisci.");
		System.out.println("2: Svuota.");
		System.out.println("3: Stampa.");
		System.out.println("4: Count.");
		System.out.println("5: Esci.");
	}

	private static void inserisci(Classifica c) {
		System.out.print("Inserisci nome: ");
		String line = scanner.nextLine();
		String nome = line;
		System.out.print("Inserisci punteggio: ");
		line = scanner.nextLine();
		int punteggio = Integer.parseInt(line);

		System.out.println("La squadra " + nome + " ora ha "
		        + c.aggiungi(nome, punteggio) + " punti.");
	}

	private static void svuota(Classifica c) {
		c.svuota();
		System.out.println("Classifica svuotata.");
	}

	private static void stampa(Classifica c) {
		System.out.println(c.toString());
	}

	private static void count(Classifica c) {
		System.out.println("Il numero di squadre in "
		        + "classifica è " + c.count());
	}
}