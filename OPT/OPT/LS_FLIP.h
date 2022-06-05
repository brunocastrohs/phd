#pragma once
#include "InstanceReader.h"
#include "Solution.h"
#include "HCZ.h";
class LS_FLIP {

public:

	static Solution optimize(Solution s, Instance *inst) {

		int n = s.n - 1;

		Solution l = Solution();

		int * tour = InstanceReader::cloneVector(s.tour, s.n);

		int distance_p1Top2, i1, i2, p1, p2, prev_p1, next_p2;

		bool madeImprovment = true;

		int maxIter = 100;

		for (distance_p1Top2 = 1; distance_p1Top2 <= (n % 2 + n / 2); distance_p1Top2++)
			for (i1 = 1; i1 < n; i1++) {

				i2 = (i1 + distance_p1Top2) % n == 0 ? 1 : (i1 + distance_p1Top2) % n;
				i1 = i1 == i2 ? i1 + 1 : i1;
				p1 = tour[i1];
				p2 = tour[i2];
				prev_p1 = tour[prev_index(i1, n)];
				next_p2 = tour[next_index(i2, n)];
				if ((inst->D[prev_p1][p2] + inst->D[p1][next_p2]) < (inst->D[prev_p1][p1] + inst->D[p2][next_p2])) {

					exchange(i1, i2, tour, s.n);

					l = HCZ::optimize(Solution(s.n, inst->p, InstanceReader::cloneVector(tour, s.n), 9999999999999, s.bonus, InstanceReader::cloneVector(s.selectedVertex)), inst);

					if (l.cost < s.cost) {
						s.reset();
						s = l;
					}
					else
						l.reset();

				}
			}

		free(tour);

		return s;

	}

	static Solution optimizeRout(Solution s, Instance *inst) {

		int n = s.n - 1;

		int * tour = InstanceReader::cloneVector(s.tour, s.n);

		int distance_p1Top2, i1, i2, p1, p2, prev_p1, next_p2;

		bool madeImprovment = true;

		int maxIter = 100;

		double cost = 0;

		for (distance_p1Top2 = 1; distance_p1Top2 <= (n % 2 + n / 2); distance_p1Top2++)
			for (i1 = 1; i1 < n; i1++) {

				i2 = (i1 + distance_p1Top2) % n == 0 ? 1 : (i1 + distance_p1Top2) % n;
				i1 = i1 == i2 ? i1 + 1 : i1;
				p1 = tour[i1];
				p2 = tour[i2];
				prev_p1 = tour[prev_index(i1, n)];
				next_p2 = tour[next_index(i2, n)];
				if ((inst->D[prev_p1][p2] + inst->D[p1][next_p2]) < (inst->D[prev_p1][p1] + inst->D[p2][next_p2])) {

					exchange(i1, i2, tour, s.n);

					cost = tourCost(tour, s.n, inst);

					if (cost < s.cost) {
						Solution l = Solution(s.n, inst->p, InstanceReader::cloneVector(tour, s.n), cost, s.bonus, InstanceReader::cloneVector(s.selectedVertex));
						s.reset();
						s = l;
					}

				}
			}

		free(tour);

		return s;

	}

	static double tourCost(int * tour, int n, Instance *inst) {
	
		int k = 0;

		double cost = 0;

		do {
			cost += inst->D[tour[k]][tour[k + 1]];
			k++;
		}while(k < n-1);
		
		return cost;

	}

	static void exchange(int p, int r, int* sequence, int sequenceLength) {

		int n = sequenceLength - 1;

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

		sequence[n] = sequence[0];

	}

	static int prev_index(int i, int n) {
		return i == 1 ? n : i - 1;
	}

	static int next_index(int i, int n) {
		return i == n ? 1 : i + 1;
	}

	static int prev(int i, int n) {
		return i == 1 ? n - 1 : i - 1;
	}

	static int next(int i, int n) {
		return i == (n - 1) ? 1 : i + 1;
	}

};