package heuristica;

import util.TSPInstanceReader;

public class HID {

	static public int bestCost = -1;
	
	static public boolean global_inserted[];

	public static int[] optimize(int W[][], int s[], int p1, int p2) {

		int n = W.length, globalPath[] = {};
		int globalCost = -1;

		int shots = s.length + 1, i = s[0];
		boolean initElements[] = new boolean[W.length];

		do {
			int occupiedSpots = -1, current_tour[] = {};

			int vk = 0;

			boolean inserted[] = new boolean[W.length];

			for (int e : s) {
				current_tour = addElementToSet(current_tour, e);
				inserted[e] = true;
				initElements[e] = true;
				occupiedSpots++;
			}

			do {
				i = next(i, n);
			} while (inserted[i]);

			current_tour = addElementToSet(current_tour, 1);
			inserted[1] = true;
			occupiedSpots++;

			vk = i;
			current_tour = addElementToSet(current_tour, vk);
			inserted[vk] = true;
			occupiedSpots++;

			// fechar ciclo
			current_tour = addElementToSet(current_tour, 1);
			occupiedSpots++;

			while (current_tour.length < inserted.length) {
				vk = getFarthest(vk, inserted, current_tour, W);
				int bp = bestPositionToInsert(vk, occupiedSpots, current_tour, W, initElements);
				current_tour = addElementToSet(current_tour, vk, bp);
				inserted[vk] = true;
				occupiedSpots++;
			}

			current_tour = exchange(current_tour, s, p1, p2);

			int currentCost = (int) tourCost(current_tour, W);

			if (currentCost < globalCost || globalCost == -1) {
				bestCost = globalCost = currentCost;
				globalPath = current_tour;

			}
			shots++;
		} while (shots != n - 1);

		/*
		 * System.out.print("Solution: ["); for(int e:globalPath){
		 * 
		 * System.out.print(" "+(e)+" "); } System.out.println("] | Cost:"
		 * +globalCost);
		 */

		return globalPath;

	}

	public static int[] exchange(int current_tour[], int s[], int p1, int p2) {

		int[] new_path = new int[current_tour.length];
		int n = new_path.length;

		int k = 0;
		for (int i = p1; i <= p2; i++, k++) {
			new_path[i] = s[k];
		}

		k = s.length;

		for (int i = 0; i < new_path.length; i++) {
			if (i >= p1 && i <= p2)
				continue;
			new_path[i] = current_tour[k];
			k++;
		}

		// new_path[n - 1] = new_path[0];

		return new_path;
	}

	public static int[] optimize(int W[][], int s) {
		int vk = 0;
		int n = W.length, globalPath[] = {};
		int globalCost = -1;

		int shots = 2, i = s;

		do {
			int occupiedSpots = 0, current_tour[] = {};
			boolean inserted[] = new boolean[W.length];

			current_tour = addElementToSet(current_tour, 1);
			inserted[1] = true;

			current_tour = addElementToSet(current_tour, s);
			inserted[s] = true;
			occupiedSpots++;

			i = next(i, n);
			vk = i;
			current_tour = addElementToSet(current_tour, vk);
			inserted[vk] = true;
			occupiedSpots++;

			// fechar ciclo
			current_tour = addElementToSet(current_tour, 1);
			occupiedSpots++;

			while (current_tour.length < inserted.length) {
				vk = getFarthest(vk, inserted, current_tour, W);
				int bp = bestPositionToInsert(vk, occupiedSpots, current_tour, W);
				current_tour = addElementToSet(current_tour, vk, bp);
				inserted[vk] = true;
				occupiedSpots++;
			}

			int currentCost = (int) tourCost(current_tour, W);

			if (currentCost < globalCost || globalCost == -1) {

				bestCost = globalCost = currentCost;
				globalPath = current_tour;

			}
			shots++;
		} while (shots != n - 1);
		/*
		 * System.out.print("Solution: ["); for(int e:globalPath){
		 * 
		 * System.out.print(" "+(e)+" "); } System.out.println("] | Cost:"
		 * +globalCost);
		 */
		return globalPath;

	}

	public static int[] optimize(int W[][]) {

		int n = W.length, globalPath[] = {};
		int globalCost = -1;

		for (int s = 2; s < n; s++) {
			int nxt = 0;
			for (int i = 2; i < n - 1; i++) {
				int occupiedSpots = 0, current_tour[] = {};
				boolean inserted[] = new boolean[W.length];

				current_tour = addElementToSet(current_tour, 1);
				inserted[1] = true;

				current_tour = addElementToSet(current_tour, s);
				inserted[s] = true;

				nxt = i == 2 ? next(s, n) : next(nxt, n);
				current_tour = addElementToSet(current_tour, nxt);
				inserted[nxt] = true;
				occupiedSpots++;
				int vk = nxt;

				// fechar ciclo
				current_tour = addElementToSet(current_tour, 1);
				occupiedSpots++;

				while (current_tour.length < inserted.length) {
					vk = getFarthest(vk, inserted, current_tour, W);
					int bp = bestPositionToInsert(vk, occupiedSpots, current_tour, W);
					current_tour = addElementToSet(current_tour, vk, bp);
					inserted[vk] = true;
					occupiedSpots++;
				}

				int currentCost = (int) tourCost(current_tour, W);

				if (currentCost < globalCost || globalCost == -1) {
					globalCost = currentCost;
					globalPath = current_tour;
					/*
					 * System.out.print("Solution: "); for (int e :
					 * current_tour) {
					 * 
					 * System.out.print((e) + ","); } System.out.println(
					 * " | Cost:" + globalCost);
					 */
				}
			}
		}

		bestCost = globalCost;

		// System.out.println("Custo: " + globalCost);

		return globalPath;

	}

	public static int[] m_optimize(int W[][], int n, boolean isFirst) {

		int globalPath[] = {};

		int globalCost = -1;

		int nxt = 1;
		
		boolean best_inserted[] = null;
		
		global_inserted = isFirst? new boolean[W.length]:global_inserted;
		
		for (int i = 1; i < n - 1; i++) {

			int occupiedSpots = 0, current_tour[] = {};

			boolean inserted[] = global_inserted.clone();

			current_tour = addElementToSet(current_tour, 1);
			inserted[1] = true;

			do {

				nxt = next(nxt, W.length-1);

			} while (inserted[nxt]);

			current_tour = addElementToSet(current_tour, nxt);
			inserted[nxt] = true;
			occupiedSpots++;
			int vk = nxt;

			// fechar ciclo
			current_tour = addElementToSet(current_tour, 1);
			occupiedSpots++;

			while (current_tour.length < n+2) {
				vk = getFarthest(vk, inserted, current_tour, W);
				int bp = bestPositionToInsert(vk, occupiedSpots, current_tour, W);
				current_tour = addElementToSet(current_tour, vk, bp);
				inserted[vk] = true;
				occupiedSpots++;
			}

			int currentCost = (int) tourCost(current_tour, W);

			if (currentCost < globalCost || globalCost == -1) {
				globalCost = currentCost;
				globalPath = current_tour;
				best_inserted = inserted.clone();
			}
		}

		bestCost = globalCost;

		global_inserted = best_inserted.clone();
		
		return globalPath;

	}
	
	

	static int getFarthest(int i, boolean inserted[], int current_tour[], int W[][]) {

		int farthest = 0;
		double max = -1;

		for (int j = 1; j < inserted.length; j++) {
			if (!inserted[j] && W[i][j] > max) {
				farthest = j;
				max = W[i][j];
			}
		}

		return farthest;

	}

	static int bestPositionToInsert(int k, int possibleSpots, int current_tour[], int W[][]) {

		int i, x, y, bestPosition = 0;
		double min = -1;

		for (i = 0; i < possibleSpots; i++) {

			x = i;
			y = i + 1;

			if ((k != current_tour[x]) && (k != current_tour[y])) {

				double insertionCost = W[current_tour[x]][k] + W[k][current_tour[y]]
						- W[current_tour[x]][current_tour[y]];

				if (insertionCost < min || min == -1) {

					min = insertionCost;
					bestPosition = y;

				}
			}
		}

		return bestPosition;

	}

	static int bestPositionToInsert(int k, int possibleSpots, int current_tour[], int W[][], boolean[] initElements) {

		int i, x, y, bestPosition = 0;
		double min = -1;

		for (i = 0; i < possibleSpots; i++) {

			x = i;
			y = i + 1;

			if (initElements[current_tour[x]])
				continue;

			if ((k != current_tour[x]) && (k != current_tour[y])) {

				double insertionCost = W[current_tour[x]][k] + W[k][current_tour[y]]
						- W[current_tour[x]][current_tour[y]];

				if (insertionCost < min || min == -1) {

					min = insertionCost;
					bestPosition = y;

				}
			}
		}

		return bestPosition;

	}

	static int tourCost(int tour[], int W[][]) {

		int sum = 0;
		int i = 0;

		do {
			sum += W[tour[i]][tour[i + 1]];
			i++;
		} while (i < tour.length - 1);

		return sum;

	}

	static int[] addElementToSet(int[] set, int e) {

		int size = set.length + 1, i = 0, lastIndex = set.length;

		int newQ[] = new int[size];

		for (int node : set) {
			newQ[i] = node;
			i++;

		}

		newQ[lastIndex] = e;

		return newQ;

	}

	static int[] addElementToSet(int set[], int e, int position) {

		int size = set.length + 1, i = 0;

		int newQ[] = new int[size];

		for (int node : set) {
			if (i == position) {
				newQ[i] = e;
				i++;
				newQ[i] = node;
				i++;
			} else {
				newQ[i] = node;
				i++;
				if (i == position) {
					newQ[i] = e;
				}

			}
		}

		return newQ;

	}

	static int next(int s, int n) {
		int nd = s == n - 1 ? 2 : s + 1;
		return nd;
	}

	public static void main(String[] args) throws Exception {

		String path = "C:\\Users\\Bruno\\Documents\\data\\tsp\\pr76.txt";
		
		int[][] W = TSPInstanceReader.run(path, TSPInstanceReader.MATRIX_CARTESIAN);
		
		int tours[][] = new int[5][];
		int cost = 0; 
		tours[0] = m_optimize(W, 20, true);
		cost += bestCost;
		System.out.println("COST: "+ bestCost);
		tours[1] = m_optimize(W, 20, false);
		cost += bestCost;
		System.out.println("COST: "+ bestCost);
		tours[2] = m_optimize(W, 20, false);
		cost += bestCost;
		System.out.println("COST: "+ bestCost);
		tours[3] = m_optimize(W, 15, false);
		cost += bestCost;
		System.out.println("COST: "+ bestCost);
		
		System.out.println("TOTAL COST: "+ cost);
		
		TSPInstanceReader.m_validateTour(tours, W);
		
	}

	
	
}
