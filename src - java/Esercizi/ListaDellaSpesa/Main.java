import java.util.Scanner;

public class Main {
	// l'oggetto scanner aiuta a leggere dati inseriti sullo
	// standard-input (tastiera)
	private static Scanner scanner = new Scanner(System.in);

	private static void stampaMenu() {
		System.out.println("'1' Aggiungi");
		System.out.println("'2' Elimina");
		System.out.println("'3' GetQuantita");
		System.out.println("'4' Svuota");
		System.out.println("'5' Stampa");
		System.out.println("'6' TestVeloce");
		System.out.println("'7' Esci");
		System.out.println("Scelta: ");
	}

	public static void main(String[] args) {
		ListaDellaSpesa lds = new ListaDellaSpesa();
		String line;

		do {
			stampaMenu();
			line = scanner.nextLine();
			switch (line) {
			case "1":
				aggiungi(lds);
				break;
			case "2":
				elimina(lds);
				break;
			case "3":
				getQuantita(lds);
				break;
			case "4":
				svuota(lds);
				break;
			case "5":
				stampa(lds);
				break;
			case "6":
				testVeloce(lds);
				break;
			case "7":
				break;
			default:
				System.out.println("Scelta non valida.");
				break;
			}
		} while (!line.equals("7"));
	}

	private static void aggiungi(ListaDellaSpesa lds) {
		System.out.println("Nome articolo: ");
		String nome = scanner.nextLine();
		System.out.println("Quantità articolo: ");
		String quantita_s = scanner.nextLine();
		float quantita = Float.parseFloat(quantita_s);
		float nq = lds.aggiungi(nome, quantita);
		System.out.println("Ora la quantità è: " + nq);
	}

	private static void elimina(ListaDellaSpesa lds) {
		System.out.println("Nome articolo: ");
		String nome = scanner.nextLine();
		boolean eliminato = lds.elimina(nome);
		if (eliminato)
			System.out.println("Articolo eliminato.");
		else
			System.out.println("Articolo non eliminato.");
	}

	private static void getQuantita(ListaDellaSpesa lds) {
		System.out.println("Nome articolo: ");
		String nome = scanner.nextLine();
		System.out.println("La quantità è: "
		        + lds.getQuantita(nome));
	}

	private static void svuota(ListaDellaSpesa lds) {
		lds.svuota();
		System.out.println("Lista svuotata.");
	}

	private static void stampa(ListaDellaSpesa lds) {
		System.out.println(lds.toString());
	}

	private static void testVeloce(ListaDellaSpesa lds) {
		lds.svuota();
		lds.aggiungi("Pane", 1f);
		lds.aggiungi("Latte", 1.5f);
		lds.aggiungi("Zucchero", 1f);
		lds.aggiungi("Prosciutto", 0.3f);
		System.out.println(lds.toString());
		System.out.println("Latte: "
		        + lds.aggiungi("Latte", 0.5f));
		lds.elimina("Pane");
		lds.elimina("Zucchero");
		lds.elimina("Prosciutto");
		System.out.println("Latte: "
		        + lds.aggiungi("Latte", 0.5f));
		System.out.println(lds.toString());
		lds.svuota();
		System.out.println(lds.toString());
	}
}