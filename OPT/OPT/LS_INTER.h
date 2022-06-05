#pragma once
#include "InstanceReader.h"
#include "Solution.h"
#include "HCZ.h";
#include "LS_PUSH.h"

class LS_INTER {

public:

	static Solution optimize(Solution s, Instance *inst) {

		int n = s.n - 1;

		Solution l = Solution();

		bool *localSelected = InstanceReader::cloneVector(s.selectedVertex);

		int * tour = InstanceReader::cloneVector(s.tour, s.n);

		bool inserted = false;

		int *localBestTour = tour;

		double localBestCost = 99999999999999.0, localBonus = s.bonus;

		double bonus = s.bonus;

		int w, k, i1, p1 = 0, prev_p1, next_p1, removed = 0;

		int jump = inst->n / 20;

		int start = jump > 5 ? (rand() % jump) + 1 : 1;

		for (w = 2; w <= inst->n; w++) {
			if (!localSelected[w]) {
				for (i1 = start; i1 < n; i1 += 1 + jump) {

					p1 = tour[i1];
					prev_p1 = tour[prev_index(i1, n)];
					next_p1 = tour[next_index(i1, n)];

					if ((inst->D[prev_p1][w] / passangersPerEdge(prev_p1, w, inst) + inst->D[w][next_p1]) / passangersPerEdge(w, next_p1, inst) < (inst->D[prev_p1][p1] / passangersPerEdge(prev_p1, p1, inst) + inst->D[p1][next_p1]) / passangersPerEdge(p1, next_p1, inst)) {

						bonus -= inst->BONUS[p1][1];
						tour[i1] = w;
						bonus += inst->BONUS[w][1];
						localSelected[p1] = false;
						localSelected[w] = true;

						l = HCZ::optimize(Solution(s.n, inst->p, InstanceReader::cloneVector(tour, s.n), 9999999999999, bonus, InstanceReader::cloneVector(localSelected)), inst);

						if (localBestCost >= l.cost) {
							if (localBestTour != tour)
								free(localBestTour);
							localBestTour = InstanceReader::cloneVector(l.tour, l.n);
							localBestCost = l.cost;
							localBonus = bonus;
							inserted = true;
							removed = p1;
						}

						if (l.cost <= s.cost) {
							s.reset();
							s = l;
							removed = p1;
						}
						else
							l.reset();

						bonus -= inst->BONUS[w][1];
						bonus += inst->BONUS[p1][1];
						tour[i1] = p1;
						localSelected[p1] = true;
						localSelected[w] = false;

					}
				}

				if (inserted)
					free(tour);
				tour = localBestTour;
				localSelected[w] = inserted;
				localSelected[removed] = false;
				localBestCost = 99999999999999.0;
				bonus = localBonus;
				inserted = false;
				removed = 0;

			}

		}

		if (localBestTour == tour)
			free(localBestTour);
		else {
			free(tour);
			free(localBestTour);
		}
		free(localSelected);

		if (s.bonus < inst->Q)
			s = LS_PUSH::optimize(s, inst);

		return s;

	}

	static int prev_index(int i, int n) {
		return i == 1 ? n : i - 1;
	}

	static int next_index(int i, int n) {
		return i == n ? 1 : i + 1;
	}

	static int passangersPerEdge(int o, int d, Instance *inst) {

		return 1 + inst->vertex[o].possiblePassangersPerNeighbor[d];

	}


};