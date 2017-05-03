import java.util.Scanner;

public class Main {
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		String line;
		AgenziaMatrimoniale am = new AgenziaMatrimoniale();

		do {
			stampaMenu();
			System.out.print("Scelta: ");
			line = scanner.nextLine();
			switch (line) {
			case "1":
				aggiungiPersona(am);
				break;
			case "2":
				sposa(am);
				break;
			case "3":
				coniugato(am);
				break;
			case "4":
				numeroSposi(am);
				break;
			case "5":
				numeroCoppie(am);
				break;
			case "6":
				svuota(am);
				break;
			case "7":
				stampa(am);
				break;
			case "8":
				break;
			default:
				System.out.println("Scelta non valida.");
				break;
			}
		} while (!line.equals("8"));
	}

	private static void stampaMenu() {
		System.out.println("1: AggiungiPersona.");
		System.out.println("2: Sposa.");
		System.out.println("3: Coniugato.");
		System.out.println("4: NumeroSposi.");
		System.out.println("5: NumeroCoppie.");
		System.out.println("6: Svuota.");
		System.out.println("7: Stampa.");
		System.out.println("8: Esci.");
	}

	private static void aggiungiPersona(AgenziaMatrimoniale am) {
		System.out.print("Inserisci nome: ");
		String nome = scanner.nextLine();

		String sesso;
		boolean ok;
		do {
			System.out.print("Specificare il sesso (M, F): ");
			sesso = scanner.nextLine();
			ok = sesso.equals("M") || sesso.equals("m")
			        || sesso.equals("F") || sesso.equals("f");
		} while (!ok);

		boolean maschio = sesso.equals("M") || sesso.equals("m");

		if (am.aggiungiPersona(nome, maschio))
			System.out.println("Persona aggiunta.");
		else
			System.out.println("Persona non aggiunta");
	}

	private static void sposa(AgenziaMatrimoniale am) {
		System.out.print("Inserisci il primo nome: ");
		String nome1 = scanner.nextLine();
		System.out.print("Inserisci il secondo nome: ");
		String nome2 = scanner.nextLine();

		if (am.sposa(nome1, nome2))
			System.out.println("Matrimonio registrato.");
		else
			System.out.println("Matrimonio non registrato.");
	}

	public static void coniugato(AgenziaMatrimoniale am) {
		System.out.print("Inserisci il nome: ");
		String nome = scanner.nextLine();
		AgenziaMatrimoniale.RicercaConiugato rc = am.coniugato(nome);
		if (!rc.trovato)
			System.out.println("Persona non esistente.");
		else if (rc.coniugato)
			System.out.println("E' coniugato.");
		else
			System.out.println("Non è coniugato.");
	}

	private static void numeroSposi(AgenziaMatrimoniale am) {
		System.out.print("Il numero sposi è pari a ");
		System.out.print(am.numeroSposi());
		System.out.println(".");
	}

	private static void numeroCoppie(AgenziaMatrimoniale am) {
		System.out.print("Il numero coppie è pari a ");
		System.out.print(am.numeroCoppie());
		System.out.println(".");
	}

	private static void svuota(AgenziaMatrimoniale am) {
		am.svuota();
		System.out.println("Agenzia svuotata.");
	}

	private static void stampa(AgenziaMatrimoniale am) {
		System.out.println(am.toString());
	}
}