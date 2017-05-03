import java.util.Scanner;

public class Main {
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		String line;
		Votazioni votazioni = new Votazioni();

		do {
			stampaMenu();
			System.out.print("Scelta: ");
			line = scanner.nextLine();
			switch (line) {
			case "1":
				aggiungiVoto(votazioni);
				break;
			case "2":
				svuota(votazioni);
				break;
			case "3":
				getVotiPartito(votazioni);
				break;
			case "4":
				getNumeroVoti(votazioni);
				break;
			case "5":
				getSituazione(votazioni);
				break;
			case "6":
				break;
			default:
				System.out.println("Scelta non valida.");
				break;
			}
		} while (!line.equals("6"));
	}

	private static void stampaMenu() {
		System.out.println("1: AggiungiVoto.");
		System.out.println("2: Svuota.");
		System.out.println("3: VotiPartito.");
		System.out.println("4: NumeroVoti.");
		System.out.println("5: Situazione.");
		System.out.println("6: Esci.");
	}

	private static void aggiungiVoto(Votazioni v) {
		System.out.print("Indicare il codice partito: ");
		String codice = scanner.nextLine();

		int voti = v.aggiungiVoto(codice);
		System.out.println("Voto aggiunto. Ora il partito ha "
		        + voti + " vot" + (voti == 1 ? "o" : "i") + ".");
	}

	private static void svuota(Votazioni v) {
		v.svuota();
		System.out.println("Struttura svuotata.");
	}

	private static void getVotiPartito(Votazioni v) {
		System.out.print("Indicare il codice partito: ");
		String codice = scanner.nextLine();

		System.out.println("Il partito " + codice
		        + " ha ottenuto voti: "
		        + v.getVotiPartito(codice));
	}

	private static void getNumeroVoti(Votazioni v) {
		System.out.println("I voti complessivi sono: " +
				v.getNumeroVoti() + ".");
	}

	private static void getSituazione(Votazioni v) {
		System.out.println(v.toString());
	}
}