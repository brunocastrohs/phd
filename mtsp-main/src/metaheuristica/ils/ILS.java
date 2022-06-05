package metaheuristica.ils;

import heuristica.HID;
import heuristica.LS;
import util.TSPInstanceReader;

public class ILS {

	public int bestCost = 0;

	public void m_optimize(int tours[][], int[][] W) {

		for(int i = 0; i<tours.length;i++)
			for(int j = 0; j<tours.length;j++)
				if(i!=j)
					LS.m_optimize(tours[i], tours[j], W);
		
		bestCost = 0;
		
		for(int[] tour: tours){
			if(tour!=null)
				bestCost += LS.tour_cost(tour, W);
		}
		

	}
	
	
	public int[] optimize(int S[], int pertubation_length, int[][] W) {

		S = LS.optimize(S, W);

		bestCost = LS.bestCost;

		int n = S.length - 1;

		int shots = 1;

		do {
			int[] R = perturbator(S.clone(), shots, pertubation_length);

			R = LS.optimize(R, W);

			S = accepatanceCriterion(S, R);

			shots++;

		} while (shots < n - 1);

		return S;

	}
	

	public int[] optimize(int S[], int[][] W) {

		S = LS.optimize(S, W);

		bestCost = LS.bestCost;

		int n = S.length - 1;

		int terminationCriterion = (n / 2) + (n % 2);

		int shots = 1;

		int pertubation_length = 2;

		do {

			shots = 1;

			do {
				int[] R = perturbator(S.clone(), shots, pertubation_length);

				R = LS.optimize(R, W);

				S = accepatanceCriterion(S, R);

				shots++;

			} while (shots < n - 1);

			pertubation_length++;

		} while (pertubation_length <= terminationCriterion);

		return S;

	}
	

	public int[] optimize(int[][] W) {

		int [] s0 = HID.optimize(W);
		
		int[] S = LS.optimize(s0, W);

		bestCost = LS.bestCost;

		int n = S.length - 1;

		int terminationCriterion = (n / 2) + (n % 2);

		int shots = 1;

		int pertubation_length = 2;

		do {

			shots = 1;

			do {
				int[] R = perturbator(S.clone(), shots, pertubation_length);

				R = LS.optimize(R, W);

				S = accepatanceCriterion(S, R);

				shots++;

			} while (shots < n - 1);

			pertubation_length++;

		} while (pertubation_length <= terminationCriterion);

		return S;

	}

	int[] perturbator(int[] R, int shot, int pertubation_length) {

		int n = R.length - 1;

		int p1 = shot;

		int p2 = (shot + pertubation_length) % n == 0 ? 1 : (shot + pertubation_length) % n;

		LS.exchange(p1, p2, R);

		return R;

	}

	int[] accepatanceCriterion(int S[], int R[]) {
		if (bestCost > LS.bestCost) {
			bestCost = LS.bestCost;
			return R.clone();
		} else {
			return S;
		}
	}

	public static void main(String[] args) throws Exception {

		String path = "C:\\Users\\Bruno\\Documents\\data\\tsp\\pr226.txt";

		int[][] W = TSPInstanceReader.run(path, TSPInstanceReader.MATRIX_CARTESIAN);

		int seed_tour[] = new int[W.length];

		for (int i = 0; i < W.length - 1; i++) {
			seed_tour[i] = i + 1;
		}

		int n = W.length;
		
		seed_tour[W.length - 1] = seed_tour[0];
		
		ILS ls = new ILS();

		int[] tour = ls.optimize(seed_tour, (int) (n*0.4) ,W);

		for (int e : tour)
			System.out.print(e + " ");

		System.out.println("\n" + ls.bestCost);

		TSPInstanceReader.validateTour(tour);
		
	}

}
