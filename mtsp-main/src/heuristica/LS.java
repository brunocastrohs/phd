package heuristica;

import java.util.Random;

import util.TSPInstanceReader;

public class LS {

	public static int bestCost = -1;
	
	public static void m_optimize(int[]tour1 , int[]tour2,  int[][] W) {

		int n1 = tour1.length - 1;
		
		int n2 = tour2.length - 1;

		int distance_p1Top2, prev_p1, next_p2;

		boolean madeImprovment = false;
		
		do {

			for(int i=1; i < n1;i++)
				for(int j=1;j<n2;j++){
			
				madeImprovment = false;
				
				int i1 = i;
			
				int p1 = tour1[i1];
				
				int prev1 = tour1[i1-1];
				
				int next1 = tour1[i1+1];
				
				int i2 = j;
				
				int p2 = tour2[i2];
				
				int prev2 = tour2[i2-1];
				
				int next2 = tour2[i2+1];
	
				int save = W[prev1][p2] + W[p2][next1] + W[prev2][p1] + W[p1][next2];
				
				int current = W[prev1][p1] + W[p1][next1] + W[prev2][p2] + W[p2][next2];
				
				if(save < current){
					tour1[i1] = p2;
					tour2[i2] = p1;
					madeImprovment = true;
				}
				
			}
		} while (madeImprovment);

		//bestCost = tour_cost(tour, W);


	}
	
	public static int[] optimize(int[] tour, int[][] W) {

		int n = tour.length - 1;

		int distance_p1Top2, i1, i2, p1, p2, prev_p1, next_p2;

		boolean madeImprovment = true;

		do {
			// se uma melhoria foi feita, roda mais uma vez
			madeImprovment = false;
			// efetua as perturbações 2-opt
			for (distance_p1Top2 = 1; distance_p1Top2 <= (n % 2 + n / 2); distance_p1Top2++)
				for (i1 = 1; i1 < n; i1++) {
					
					i2 = (i1 + distance_p1Top2)%n;
					i2 = i2==0?1:i2;
					p1 = tour[i1];
					p2 = tour[i2];
					prev_p1 = tour[prev(i1, n)];
					next_p2 = tour[next(i2, n)];
					if ((W[prev_p1][p2] + W[p1][next_p2]) < (W[prev_p1][p1]	+ W[p2][next_p2])) {
						exchange(i1, i2, tour);
						madeImprovment = true;
					}
				}

		} while (madeImprovment);

		bestCost = tour_cost(tour, W);

		return tour;

	}

	public static void exchange(int p, int r, int[] sequence) {

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

	public static int tour_cost(int tour[], int[][] W) {

		int sum = 0;
		int i = 0;

		do {
			sum += W[tour[i]][tour[i + 1]];
			i++;
		} while (i < tour.length - 1);

		return sum;

	}

	public static void main(String[] args) throws Exception {

		String path = "C:\\Users\\Bruno\\Documents\\data\\tsp\\pr226.txt";

		int[][] W = TSPInstanceReader.run(path, TSPInstanceReader.MATRIX_CARTESIAN);

		int seed_tour[] = new int[W.length];

		for (int i = 0; i < W.length - 1; i++) {
			seed_tour[i] = i + 1;
		}

		seed_tour[W.length - 1] = seed_tour[0];

		int sum = tour_cost(seed_tour, W);

		System.out.println(sum);

		int[] tour = LS.optimize(seed_tour, W);
		
		for (int e : tour)
			System.out.print(e + " ");
		System.out.println("\n" + LS.bestCost);
		// c = TWO_OPT.best_tour;
		// c=null;

	}
	
}
