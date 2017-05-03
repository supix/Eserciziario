	public int eliminaTutti(int el) {
		int j = 0;
		int count = 0;
		for (int i = 0; i < numEl; i++) {
			if (v[i] == el) {
				count++;
			} else {
				if (i != j)
					v[j] = v[i];
				j++;
			}
		}

		numEl -= count;
		return count;
	}