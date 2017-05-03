import java.time.Duration;
import java.time.LocalDateTime;

public class Timer {
	private LocalDateTime startTime;
	private LocalDateTime stopTime;

	public void start() {
		startTime = LocalDateTime.now();
		stopTime = null;
	}

	public void stop() {
		stopTime = LocalDateTime.now();
	}

	public void reset() {
		startTime = null;
		stopTime = null;
	}

	public int getTime() {
		if (startTime == null) // il timer � in stato di reset?
			return 0;

		if (stopTime == null) // il timer � in moto?
			return (int) Duration.between(startTime,
			        LocalDateTime.now()).getSeconds(); // s�
		else
			return (int) Duration.between(startTime, stopTime)
			        .getSeconds(); // no
	}
}