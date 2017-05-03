import java.util.Scanner;

public class Main {
	private static Scanner scanner = new Scanner(System.in);

	public static void main(String[] args) {
		String line;
		Timer timer = new Timer();

		do {
			stampaMenu();
			System.out.print("Scelta: ");
			line = scanner.nextLine();
			switch (line) {
			case "s":
				start(timer);
				break;
			case "x":
				stop(timer);
				break;
			case "r":
				reset(timer);
				break;
			case "p":
				showTimer(timer);
				break;
			case "e":
				break;
			default:
				System.out.println("Scelta non valida.");
				break;
			}
		} while (!line.equals("e"));
	}

	private static void stampaMenu() {
		System.out.println("Timer semplice.");
		System.out.println("s: start.");
		System.out.println("x: stop.");
		System.out.println("r: reset.");
		System.out.println("p: show timer.");
		System.out.println("e: exit.");
	}

	private static void start(Timer t) {
		t.start();
		System.out.println("Timer started.");
	}

	private static void stop(Timer t) {
		t.stop();
		System.out.println("Timer stopped.");
	}

	private static void reset(Timer t) {
		t.reset();
		System.out.println("Timer reset.");
	}

	private static void showTimer(Timer t) {
		int seconds = t.getTime();
		System.out.println("Timer shows: " + seconds + ".");
	}
}