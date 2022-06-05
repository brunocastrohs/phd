package matheuristica.gls;

public class Population_List {
	int n;
	Individual A[] = new Individual[1];
	int indexOfBest;
	int sumFitness;
	int avgFitness;
	int bestFitness;
	int highIndividualsCount;
	int size;

	public Population_List(int s) {
		n = 0;
		A = new Individual[s];
		size = s;
		bestFitness = Integer.MAX_VALUE;
		highIndividualsCount = 0;
	}

	int insert(Individual t) {
		if (t != null && n < size) {
			n++;
			A[n] = t;

			sumFitness += t.fitness;

			if (t.fitness < bestFitness) {
				bestFitness = t.fitness;
				indexOfBest = n;
			}

		}
		return n;
	}

	Individual get(int i) {
		if (i <= n && i > 0) {

			return A[i];

		}
		return null;
	}

	int insert(Individual t, int i) {

		if (t != null && n < size && i < size) {

			A[i] = t;

			if (t.fitness < bestFitness) {
				bestFitness = t.fitness;
				indexOfBest = i;
			}

		}

		return i;
	}

	Individual best() {
		return A[indexOfBest];
	}

	Individual extract(int i) {
		if (i <= n && i > 0) {

			Individual aux = A[i];

			sumFitness -= A[i].fitness;

			if (i == indexOfBest)
				bestFitness = Integer.MAX_VALUE;

			swap(i, n);

			n--;

			return aux;

		}
		return null;
	}

	static int next(int i, int n) {
		return i == n - 1 ? 1 : i + 1;
	}

	boolean isFull() {
		return n >= size - 1;
	}

	boolean isEmpty() {
		return n < 2;
	}

	void segregatePopulation() {

		avgFitness = sumFitness / n;

		Individual doppelGanger[] = new Individual[size];
		
		int k = 1, w = n;
		
		for (int i = 1; i<=n;i++) {
			
			if (A[i].fitness <= avgFitness) {
				highIndividualsCount++;
				doppelGanger[k] = A[i];
				if(i == indexOfBest)
					indexOfBest = k;
				k++;
			} else{
				doppelGanger[w] = A[i];
				w--;
			}
		}

		A = doppelGanger;
		
	}

	void swap(int i, int j) {
		Individual aux = A[i];
		A[i] = A[j];
		A[j] = aux;
	}

	public String toString() {
		String str = "[N: " + n + "| S:" + size + " | BST: " + bestFitness + "]";
		return str;
	}
}
