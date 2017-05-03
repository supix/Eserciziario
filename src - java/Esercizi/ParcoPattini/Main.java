import java.util.Scanner;

public class Main {
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		String line;
		ParcoPattini parco = new ParcoPattini();

		do {
			stampaMenu();
			System.out.print("Scelta: ");
			line = scanner.nextLine();
			switch (line) {
			case "1":
				aggiungiPattini(parco);
				break;
			case "2":
				svuota(parco);
				break;
			case "3":
				numeroTotPattini(parco);
				break;
			case "4":
				fitta(parco);
				break;
			case "5":
				disponibilita(parco);
				break;
			case "6":
				numeroPattini(parco);
				break;
			case "7":
				restituzione(parco);
				break;
			case "8":
				stampa(parco);
				break;
			case "9":
				break;
			default:
				System.out.println("Scelta non valida.");
				break;
			}
		} while (!line.equals("9"));
	}

	private static void stampaMenu() {
		System.out.println("1: AggiungiPattini.");
		System.out.println("2: Svuota.");
		System.out.println("3: NumeroTotPattini.");
		System.out.println("4: Fitta.");
		System.out.println("5: Disponibilità.");
		System.out.println("6: NumeroPattini.");
		System.out.println("7: Restituzione.");
		System.out.println("8: Stampa.");
		System.out.println("9: Esci.");
	}

	private static void aggiungiPattini(ParcoPattini p) {
		System.out.print("Inserire la taglia: ");
		String line = scanner.nextLine();
		int taglia = Integer.parseInt(line);
		p.aggiungiPattini(taglia);
		System.out.println("Pattini aggiunti al parco.");
	}

	private static void svuota(ParcoPattini p) {
		p.svuota();
		System.out.println("Parco svuotato.");
	}

	private static void numeroTotPattini(ParcoPattini p) {
		System.out.print("Il parco pattini contiene ");
		System.out.print(p.numeroTotPattini());
		System.out.println(" paia di pattini in totale.");
	}

	private static void fitta(ParcoPattini p) {
		System.out.print("Inserire la taglia: ");
		String line = scanner.nextLine();
		int taglia = Integer.parseInt(line);
		if (p.fitta(taglia))
			System.out.println("Pattini fittati.");
		else
			System.out.println("Pattini non disponibili.");
	}

	private static void disponibilita(ParcoPattini p) {
		System.out.print("Inserire la taglia: ");
		String line = scanner.nextLine();
		int taglia = Integer.parseInt(line);
		System.out.println("Disponibilita' taglia " + taglia
		        + ": " + p.disponibilita(taglia) + ".");
	}

	private static void numeroPattini(ParcoPattini p) {
		System.out.print("Inserire la taglia: ");
		String line = scanner.nextLine();
		int taglia = Integer.parseInt(line);
		System.out.println("Il parco contiene "
		        + p.numeroPattini(taglia)
		        + " paia di pattini di taglia " + taglia + ".");
	}

	private static void restituzione(ParcoPattini p) {
		System.out.print("Inserire la taglia: ");
		String line = scanner.nextLine();
		int taglia = Integer.parseInt(line);
		if (p.restituzione(taglia))
			System.out.println("Pattini restituiti.");
		else
			System.out.println("Errore. Pattini non fittati.");
	}

	private static void stampa(ParcoPattini p) {
		System.out.println(p.toString());
	}
}