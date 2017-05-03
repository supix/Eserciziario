public class TempPredictor {
	int time1;
	int time2;
	float temp1;
	float temp2;

	public TempPredictor(int time, float temp) {
		// Inizializzare in questo modo le temp. ed i tempi
		// significa imporre che le ultime _due_ letture della
		// temperatura hanno fornito un risult. pari a temp e
		// su queste ultime due letture bisogna estrapolare
		// inizialmente la stima.
		time1 = time - 1;
		time2 = time;
		temp1 = temp;
		temp2 = temp;
	}

	public void setTemp(int time, float temp) {
		time1 = time2; // sposta l'ultima lettura nella penultima
		temp1 = temp2;
		time2 = time; // aggiorna l'ultima lettura con i dati
		              // indicati dall'utente
		temp2 = temp;
	}

	public float estimateTemp(int time) {
		return (temp2 - temp1) / (time2 - time1)
		        * (time - time1) + temp1;
	}
}