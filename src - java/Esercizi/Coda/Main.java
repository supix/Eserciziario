import java.util.Scanner;

public class Main {
	// l'oggetto scanner aiuta a leggere dati inseriti sullo
	// standard-input (tastiera)
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		Coda l = new Coda();
		int i;

		do {
			stampaMenu();
			i = scanner.nextInt();
			switch (i) {
			case 1:
				push(l);
				break;
			case 2:
				top(l);
				break;
			case 3:
				pop(l);
				break;
			case 4:
				somma(l);
				break;
			case 5:
				svuota(l);
				break;
			case 6:
				numeroElementi(l);
				break;
			case 7:
				empty(l);
				break;
			case 8:
				break;
			default:
				System.out.println("Scelta non valida.");
			}
		} while (i != 8);
	}

	private static void stampaMenu() {
		System.out.println("1. Push");
		System.out.println("2. Top");
		System.out.println("3. Pop");
		System.out.println("4. Somma");
		System.out.println("5. Svuota");
		System.out.println("6. NumeroElementi");
		System.out.println("7. E' vuota");
		System.out.println("8. Esci");
		System.out.print("Scegli: ");
	}

	static void push(Coda c) {
		System.out.print("Inserisci intero: ");
		int el = scanner.nextInt();
		c.push(el);
	}

	static void top(Coda c) {
		if (!c.empty())
			System.out.println(c.top());
		else
			System.out.println("La coda è vuota.");
	}

	static void pop(Coda c) {
		if (!c.empty())
			System.out.println(c.pop());
		else
			System.out.println("La coda è vuota.");
	}

	static void somma(Coda c) {
		System.out.println(c.somma());
	}

	static void svuota(Coda c) {
		c.svuota();
	}

	static void numeroElementi(Coda c) {
		System.out.println(c.count());
	}

	static void empty(Coda c) {
		System.out.println(c.empty());
	}
}