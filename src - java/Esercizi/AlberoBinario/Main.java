import java.util.Scanner; //importazione del package per l'uso
//dell'oggetto scanner

public class MainAlberoBinario {
	// l'oggetto scanner aiuta a leggere dati inseriti sullo
	// standard-input (tastiera)
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		AlberoBinario albero = new AlberoBinario();
		int i;

		do {
			stampaMenu();
			i = scanner.nextInt();

			switch (i) {
			case 1:
				inserisci(albero);
				break;
			case 2:
				ricerca(albero);
				break;
			case 3:
				elimina(albero);
				break;
			case 4:
				svuota(albero);
				break;
			case 5:
				preOrdine(albero);
				break;
			case 6:
				inOrdine(albero);
				break;
			case 7:
				postOrdine(albero);
				break;
			case 8:
				copia(albero);
				break;
			case 9:
				break;
			default:
				System.out.println("Scelta non valida.");
				break;
			}
		} while (i != 9);
	}

	private static void stampaMenu() {
		System.out.println();
		System.out.println("1. Inserisci");
		System.out.println("2. Ricerca");
		System.out.println("3. Elimina");
		System.out.println("4. Svuota");
		System.out.println("5. Pre-ordine");
		System.out.println("6. InOrdine");
		System.out.println("7. Post-Ordine");
		System.out.println("8. Copia albero");
		System.out.println("9. Esci");
		System.out.println();
		System.out.print("Scelta: ");
	}

	private static void inserisci(AlberoBinario a) {
		System.out.print("Inserisci intero: ");
		int el = scanner.nextInt();
		a.aggiungiElem(el);
	}

	private static void ricerca(AlberoBinario a) {
		System.out.print("Inserisci intero: ");
		int el = scanner.nextInt();
		if (a.inAlb(el))
			System.out.println("Trovato.\n");
		else
			System.out.println("Non trovato.\n");
	}

	private static void elimina(AlberoBinario a) {
		System.out.print("Inserisci intero: ");
		int el = scanner.nextInt();
		a.elimina(el);
	}

	private static void svuota(AlberoBinario a) {
		System.out.print("Svuotamento albero.");
		a.svuota();
	}

	private static void preOrdine(AlberoBinario a) {
		System.out.print("Stampa in pre-ordine: ");
		System.out.print(a.preOrdine());
	}

	private static void inOrdine(AlberoBinario a) {
		System.out.print("Stampa in ordine: ");
		System.out.print(a.inOrdine());
	}

	private static void postOrdine(AlberoBinario a) {
		System.out.print("Stampa in post-ordine: ");
		System.out.print(a.postOrdine());
	}

	private static void copia(AlberoBinario a) {
		AlberoBinario b = new AlberoBinario(a);
		System.out
		        .print("La visita in ordine dell'albero copiato e': ");
		b.inOrdine();

		// al termine di questa funzione, l'istanza di AlberoBinario
		// b diventa non più riferita da alcun riferimento. Verrà
		// rimossa dal garbage collector.
	}
}