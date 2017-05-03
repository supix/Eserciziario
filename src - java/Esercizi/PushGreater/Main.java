import java.util.Scanner;

public class Main {
	// l'oggetto scanner aiuta a leggere dati inseriti sullo
	// standard-input (tastiera)
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		Pila l = new Pila();
		int i;

		do {
			stampaMenu();
			i = scanner.nextInt();
			switch (i) {
			case 1:
				push(l);
				break;
			case 2:
				pushGreater(l);
				break;
			case 3:
				top(l);
				break;
			case 4:
				pop(l);
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
		System.out.println("2. PushGreater");
		System.out.println("3. Top");
		System.out.println("4. Pop");
		System.out.println("5. Svuota");
		System.out.println("6. NumeroElementi");
		System.out.println("7. E' vuota");
		System.out.println("8. Esci");
		System.out.print("Scegli: ");
	}

	static void push(Pila p) {
		System.out.print("Inserisci intero: ");
		int el = scanner.nextInt();
		p.push(el);
	}

	static void pushGreater(Pila p) {
		System.out.print("Inserisci intero: ");
		int el = scanner.nextInt();
		boolean inserito = p.pushGreater(el);
		if (inserito)
			System.out.println("Inserimento avvenuto.");
		else
			System.out.println("Inserimento non avvenuto.");
	}

	static void top(Pila p) {
		if (!p.empty())
			System.out.println(p.top());
		else
			System.out.println("La pila è vuota.");
	}

	static void pop(Pila p) {
		if (!p.empty())
			System.out.println(p.pop());
		else
			System.out.println("La pila è vuota.");
	}

	static void svuota(Pila p) {
		p.svuota();
	}

	static void numeroElementi(Pila p) {
		System.out.println(p.count());
	}

	static void empty(Pila p) {
		System.out.println(p.empty());
	}
}