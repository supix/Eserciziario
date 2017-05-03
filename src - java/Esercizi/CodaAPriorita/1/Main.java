import java.util.Scanner;

public class Main {
	// l'oggetto scanner aiuta a leggere dati inseriti sullo
	// standard-input (tastiera)
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		PriorityQueue l = new PriorityQueue();
		int i;

		do {
			stampaMenu();
			i = scanner.nextInt();
			switch (i) {
			case 1:
				pushLow(l);
				break;
			case 2:
				pushHigh(l);
				break;
			case 3:
				pop(l);
				break;
			case 4:
				svuota(l);
				break;
			case 5:
				empty(l);
				break;
			case 6:
				break;
			default:
				System.out.println("Scelta non valida.");
			}
		} while (i != 6);
	}

	private static void stampaMenu() {
		System.out.println("1. PushLow");
		System.out.println("2. PushHigh");
		System.out.println("3. Pop");
		System.out.println("4. Svuota");
		System.out.println("5. E' vuota");
		System.out.println("6. Esci");
		System.out.print("Scegli: ");
	}

	static void pushLow(PriorityQueue c) {
		System.out.print("Inserisci intero: ");
		int el = scanner.nextInt();
		c.pushLow(el);
	}
	
	static void pushHigh(PriorityQueue c) {
		System.out.print("Inserisci intero: ");
		int el = scanner.nextInt();
		c.pushHigh(el);
	}

	static void pop(PriorityQueue c) {
		if (!c.empty())
			System.out.println(c.pop());
		else
			System.out.println("La coda è vuota.");
	}

	static void svuota(PriorityQueue c) {
		c.clear();
	}

	static void empty(PriorityQueue c) {
		System.out.println(c.empty());
	}
}