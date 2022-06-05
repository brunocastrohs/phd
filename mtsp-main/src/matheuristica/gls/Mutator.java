package matheuristica.gls;

import exato.BranchBound_TSP;
import util.TSPInstanceReader;

public class Mutator {

	static Individual maxMutate(Individual id, int W[][]) {
		int n = id.chromossomes.length - 1;
		int i, j;
		for (i = 2; i <= (n % 2 + n / 2); i++) {
			for (j = 1; j < n; j++) {

				Individual mutatedId = new Individual(id.fitness, id.chromossomes.clone());

				exchange(j, (j + i) % n == 0? next(j,n):(j + i) % n, mutatedId.chromossomes);

				mutatedId = mutate(mutatedId, W);

				if (mutatedId.fitness < id.fitness) {
					id = mutatedId;
				}

			}
		}

		return id;
	}
	
	static Individual medMutate(Individual id, int W[][]) {
		
		BranchBound_TSP bb = new BranchBound_TSP();
		
		id.chromossomes = bb.optimize( W , id.chromossomes.clone());

		id.fitness = evaluateFitness(id.chromossomes, W);
		
		return id;
		
	}

	public static Individual mutate(Individual id, int[][] W) {

		int n = id.chromossomes.length - 1;

		int i, i1, i2, allele1, allele2, p_allele1, n_allele2;

		boolean madeImprovment = true;

		do {
			// se uma melhoria foi feita, roda mais uma vez
			madeImprovment = false;
			// efetua as perturbações 2-opt
			for (i = 2; i <= (n % 2 + n / 2); i++)
				for (i1 = 1; i1 < n; i1++) {
					i2 = (i1 + i) % n == 0 ? 1: (i1 + i) % n;
					allele1 = id.chromossomes[i1];
					allele2 = id.chromossomes[i2];
					p_allele1 = id.chromossomes[prev(i1, n)];
					n_allele2 = id.chromossomes[next(i2, n)];
					if ((W[p_allele1][allele2] + W[allele1][n_allele2]) < (W[p_allele1][allele1]
							+ W[allele2][n_allele2])) {
						exchange(i1, i2, id.chromossomes);
						madeImprovment = true;
					}
				}

		} while (madeImprovment);

		id.fitness = evaluateFitness(id.chromossomes, W);

		return id;

	}

	public static Individual minMutate(Individual id, int[][] W) {

		int n = id.chromossomes.length - 1;

		int i, i1, i2, allele1, allele2, p_allele1, n_allele2;

		for (i = 2; i <= (n % 2 + n / 2); i++)
			for (i1 = 1; i1 < n; i1++) {
				i2 = (i1 + i) % n == 0 ? 1: (i1 + i) % n;
				allele1 = id.chromossomes[i1];
				allele2 = id.chromossomes[i2];
				p_allele1 = id.chromossomes[prev(i1, n)];
				n_allele2 = id.chromossomes[next(i2, n)];
				if ((W[p_allele1][allele2] + W[allele1][n_allele2]) < (W[p_allele1][allele1] + W[allele2][n_allele2])) {
					exchange(i1, i2, id.chromossomes);
				}
			}

		id.fitness = evaluateFitness(id.chromossomes, W);

		return id;

	}

	static void exchange(int p, int r, int[] sequence) {

		int n = sequence.length - 1;

		int n_elements, i, i1, i2, aux;

		if (p > r)
			n_elements = n - p + r + 1;
		else
			n_elements = r - p + 1;
		i1 = p;
		i2 = r;
		for (i = 0; i < n_elements / 2; i++) {
			aux = sequence[i1];
			sequence[i1] = sequence[i2];
			sequence[i2] = aux;
			i1 = next(i1, n);
			i2 = prev(i2, n);
		}
		//sequence[n] = sequence[0];
	}

	static int prev(int i, int n) {
		return i == 1 ? n - 1 : i - 1;
	}

	static int next(int i, int n) {
		return i == (n - 1) ? 1 : i + 1;
	}

	static int evaluateFitness(int tour[], int[][] W) {

		int sum = 0;
		int i = 0;

		do {
			sum += W[tour[i]][tour[i + 1]];
			i++;
		} while (i < tour.length - 1);

		return sum;

	}

	public static void main(String[] args) throws Exception {

		String path = "C:\\Users\\Bruno\\Documents\\data\\tsp\\kroa200.txt";

		int[][] W = TSPInstanceReader.run(path, TSPInstanceReader.MATRIX_CARTESIAN);

		int seed_tour[] = new int[W.length];

		for (int i = 0; i < W.length - 1; i++) {
			seed_tour[i] = i + 1;
		}

		seed_tour[W.length - 1] = seed_tour[0];

		int sum = evaluateFitness(seed_tour, W);

		System.out.println(sum);

		Individual id = Mutator.maxMutate(new Individual(sum, seed_tour), W);
		for (int e : id.chromossomes)
			System.out.print(e + " ");
		System.out.println("\n" + id.fitness);
		TSPInstanceReader.validateTour(id.chromossomes);

	}
}
