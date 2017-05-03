import java.util.Scanner;

public class Main {
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.print("Inserisci peso MAX contenitore: ");
		String line = scanner.nextLine();
		Contenitore c = new Contenitore(Integer.parseInt(line));

		do {
			stampa_menu();
			line = scanner.nextLine();
			switch (line) {
			case "1":
				inserisci(c);
				break;
			case "2":
				svuota(c);
				break;
			case "3":
				pesoComplessivo(c);
				break;
			case "4":
				pesoResiduo(c);
				break;
			case "5":
				numeroElementi(c);
				break;
			case "6":
				stampa(c);
				break;
			case "7":
				break;
			default:
				System.out.println("Scelta non valida.");
				break;
			}
		} while (!line.equals("7"));
	}

	private static void stampa_menu() {
		System.out.println("1: Inserisci.");
		System.out.println("2: Svuota.");
		System.out.println("3: Peso Complessivo.");
		System.out.println("4: Peso Residuo.");
		System.out.println("5: Numero Elementi.");
		System.out.println("6: Stampa.");
		System.out.println("7: Esci.");
	}

	private static void inserisci(Contenitore c) {
		System.out.print("Inserisci nome elemento: ");
		String nome = scanner.nextLine();
		System.out.print("Inserisci peso elemento: ");
		String peso_s = scanner.nextLine();
		int peso = Integer.parseInt(peso_s);
		if (c.inserisci(nome, peso))
			System.out.println("Elemento inserito.");
		else
			System.out.println("Elemento NON inserito.");
	}

	private static void svuota(Contenitore c) {
		c.svuota();
		System.out.println("Contenitore svuotato.");
	}

	private static void pesoComplessivo(Contenitore c) {
		System.out.println("Il peso complessivo è: "
		        + c.pesoComplessivo());
	}

	private static void pesoResiduo(Contenitore c) {
		System.out.println("Il peso residuo è: "
		        + c.pesoResiduo());
	}

	private static void numeroElementi(Contenitore c) {
		System.out.println("N. Elem: " + c.numElem());
	}

	private static void stampa(Contenitore c) {
		System.out.println("Il contenuto del contenitore e':");
		System.out.println(c.toString());
	}
}