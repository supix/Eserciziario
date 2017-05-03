import java.util.Scanner; //importazione del package per l'uso
						  //dell'oggetto scanner

public class Main {
	//l'oggetto scanner aiuta a leggere dati inseriti sullo
	//standard-input (tastiera)
	private static Scanner scanner = new Scanner(System.in);
	
	public static void main(String[] args) {		
		Lista l = new Lista();
		int i;
		
		do {
			stampaMenu();
			i = scanner.nextInt();
			switch (i) {
			case 1:
				inserisci(l);
				break;
			case 2:
				ricerca(l);
				break;
			case 3:
				elimina(l);
				break;
			case 4:
				svuota(l);
				break;
			case 5:
				stampa(l);
				break;
			case 6:
				numeroElementi(l);
				break;
			case 7:
				copiaLista(l);
				break;
			case 8:
				break;
			default:
				System.out.println("Scelta non valida.");
			}
		} while (i != 8);
	}
	
	private static void stampaMenu() {
		System.out.println("1. Inserisci");
		System.out.println("2. Ricerca");
		System.out.println("3. Elimina");
		System.out.println("4. Svuota");
		System.out.println("5. Stampa");
		System.out.println("6. NumeroElementi");
		System.out.println("7. CopiaLista");
		System.out.println("8. Esci");
		System.out.print("Scegli: ");
	}
	
	private static void inserisci(Lista l) {
		System.out.print("Inserisci intero: ");
		int el = scanner.nextInt();
		l.inserisci(el);
	}
	
	private static void ricerca(Lista l) {
		System.out.print("Inserisci intero: ");
		int el = scanner.nextInt();
		if (l.ricerca(el))
			System.out.println("Trovato.");
		else
			System.out.println("Non trovato.");
	}
	
	private static void elimina(Lista l) {
		System.out.print("Inserisci intero: ");
		int el = scanner.nextInt();
		l.elimina(el);
	}
	
	private static void svuota(Lista l) {
		System.out.println("Svuotamento lista");
		l.svuota();
	}
	
	private static void stampa(Lista l) {
		System.out.print("Stampa: ");
		System.out.println(l.toString());
	}

	private static void numeroElementi(Lista l) {
		System.out.println("Numero elementi: " +
				l.numeroElementi());
	}
	
	private static void copiaLista(Lista l) {
		Lista lcopia = new Lista(l);
		System.out.println("Lista copiata. La nuova lista " +
				"contiene: ");
		lcopia.toString();
	}
}