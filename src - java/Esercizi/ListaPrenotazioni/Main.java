import java.util.Scanner;

public class Main {
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		String line;
		System.out.print("Inserire il numero di posti "
		        + "disponibili: ");
		line = scanner.nextLine();
		int posti = Integer.parseInt(line);

		ListaPrenotazioni l = new ListaPrenotazioni(posti);

		do {
			stampaMenu();
			System.out.print("Scelta: ");
			line = scanner.nextLine();
			switch (line) {
			case "1":
				prenota(l);
				break;
			case "2":
				eliminaPrenotazione(l);
				break;
			case "3":
				postiDisponibili(l);
				break;
			case "4":
				esistePrenotazione(l);
				break;
			case "5":
				svuota(l);
				break;
			case "6":
				stampa(l);
				break;
			case "7":
				break;
			default:
				System.out.println("Scelta non valida.");
				break;
			}
		} while (!line.equals("7"));
	}

	private static void stampaMenu() {
		System.out.println("1: Prenota.");
		System.out.println("2: Elimina prenotazione.");
		System.out.println("3: Posti disponibili.");
		System.out.println("4: Esiste prenotazione.");
		System.out.println("5: Svuota.");
		System.out.println("6: Stampa.");
		System.out.println("7: Esci.");
	}

	private static void prenota(ListaPrenotazioni l) {
		System.out.print("Inserisci matricola: ");
		String line = scanner.nextLine();
		int matr = Integer.parseInt(line);
		System.out.print("Inserisci nome: ");
		String nome = scanner.nextLine();
		if (l.prenota(matr, nome))
			System.out.println("Prenotazione effettuata.");
		else
			System.out.println("Prenotazione non effettuata");
	}

	private static void eliminaPrenotazione(ListaPrenotazioni l) {
		System.out.print("Inserisci matricola: ");
		String line = scanner.nextLine();
		int matr = Integer.parseInt(line);
		if (l.eliminaPrenotazione(matr))
			System.out.println("Prenotazione eliminata.");
		else
			System.out.println("Prenotazione non eliminata");
	}

	private static void postiDisponibili(ListaPrenotazioni l) {
		System.out.println("I posti disponibili sono: "
		        + l.getPostiDisponibili());
	}

	private static void esistePrenotazione(ListaPrenotazioni l) {
		System.out.print("Inserisci matricola: ");
		String line = scanner.nextLine();
		int matr = Integer.parseInt(line);
		if (l.esistePrenotazione(matr))
			System.out.println("Prenotazione esistente.");
		else
			System.out.println("Prenotazione non esistente");
	}

	private static void svuota(ListaPrenotazioni l) {
		l.svuota();
		System.out.println("Lista svuotata.");
	}

	private static void stampa(ListaPrenotazioni l) {
		System.out.println(l.toString());
	}
}