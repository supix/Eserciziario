import java.util.Scanner; //importazione del package per l'uso
						  //dell'oggetto scanner

public class Main {
	//l'oggetto scanner aiuta a leggere dati inseriti sullo
	//standard-input (tastiera)
	private static Scanner scanner = new Scanner(System.in);
	
	public static void main(String[] args) {		
		DoubleLinkedList l = new DoubleLinkedList();
		int i;
		
		do {
			stampaMenu();
			i = scanner.nextInt();
			switch (i) {
			case 1:
				inserisci(l);
				break;
			case 2:
				svuota(l);
				break;
			case 3:
				stampaDiretta(l);
				break;
			case 4:
				stampaInversa(l);
				break;
			case 5:
				stampaAlternata(l);
				break;
			case 6:
				numeroElementi(l);
				break;
			case 7:
				break;
			default:
				System.out.println("Scelta non valida.");
			}
		} while (i != 7);
	}
	
	private static void stampaMenu() {
		System.out.println("1. Inserisci");
		System.out.println("2. Svuota");
		System.out.println("3. Stampa Diretta");
		System.out.println("4. Stampa Inversa");
		System.out.println("5. Stampa Alternata");
		System.out.println("6. Numero Elementi");
		System.out.println("7. Esci");
		System.out.print("Scegli: ");
	}
	
	private static void inserisci(DoubleLinkedList l) {
		System.out.print("Inserisci intero: ");
		int el = scanner.nextInt();
		l.inserisci(el);
	}
	
	private static void svuota(DoubleLinkedList l) {
		System.out.println("Svuotamento lista");
		l.svuota();
	}
	
	private static void stampaDiretta(DoubleLinkedList l) {
		System.out.print("Stampa diretta: ");
		System.out.println(l.stampaDiretta());
	}
	
	private static void stampaInversa(DoubleLinkedList l) {
		System.out.print("Stampa inversa: ");
		System.out.println(l.stampaInversa());
		System.out.println();
	}
	
	private static void stampaAlternata(DoubleLinkedList l) {
		System.out.print("Stampa: alternata: ");
		System.out.println(l.stampaAlternata());
	}

	private static void numeroElementi(DoubleLinkedList l) {
		System.out.println("Numero elementi: " +
				l.numeroElementi());
	}
}