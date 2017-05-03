import java.time.Duration;
import java.time.LocalDateTime;

public class Timer {
	private int storedTime;
	private LocalDateTime startTime;

	private boolean isRunning() {
		return startTime != null;
	}

	public void start() {
		if (!isRunning())
			startTime = LocalDateTime.now();
	}

	public void stop() {
		if (isRunning()) {
			// accumula il tempo del cont. in corso
			storedTime += Duration.between(startTime,
			        LocalDateTime.now()).getSeconds();
			startTime = null; // ferma il conteggio
		}
	}

	public void reset() {
		storedTime = 0;
		startTime = null;
	}

	public int getTime() {
		int t = storedTime;

		if (isRunning())
			t += Duration
			        .between(startTime, LocalDateTime.now())
			        .getSeconds();

		return t;
	}
}