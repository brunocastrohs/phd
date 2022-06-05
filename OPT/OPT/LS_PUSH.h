#pragma once
#include "InstanceReader.h"
#include "Solution.h"
#include "HCZ.h";
class LS_PUSH {

public:

	static Solution optimize(Solution s, Instance *inst) {

		int n = s.n - 1;

		Solution l = Solution();

		bool *localSelected = NULL;

		int * tour = NULL;

		double bonus = 0;

		int localLenght = s.n;

		int *localTour = NULL;

		double localBestCost = 9999999999;

		int w, k, i1, p1 = 0, prev_p1, next_p1;

		int jump = s.n / 10 + 1;

		int start = 0;

		bool isFirstEntry = true;

		while (s.bonus < inst->Q) {

			localLenght = s.n;
			bonus = s.bonus;
			localSelected = InstanceReader::cloneVector(s.selectedVertex);
			tour = InstanceReader::cloneVector(s.tour, s.n);
			localTour = InstanceReader::cloneVector(tour, localLenght);
			localBestCost = 9999999999;
			start = jump > 5 ? (rand() % jump) : 0;

			do {
				w = (rand() % (inst->n - 1)) + 2;
			} while (localSelected[w]);

			for (i1 = start; i1 < n; i1 += jump) {

				p1 = localTour[i1];

				next_p1 = localTour[next_index(i1, n)];

				if (
					inst->D[p1][w] / passangersPerEdge(p1, w, inst) < inst->D[p1][next_p1] / passangersPerEdge(p1, next_p1, inst)
					|| inst->D[w][next_p1] / passangersPerEdge(w, next_p1, inst) < inst->D[p1][next_p1] / passangersPerEdge(p1, next_p1, inst)
					|| (inst->vertex[p1].isVertexNextNeighbor[w] || inst->vertex[w].isVertexNextNeighbor[next_p1])
					) {

					localTour = addElementToSet(localTour, localLenght, w, i1 + 1);
					bonus += inst->BONUS[w][1];
					localSelected[w] = true;

					l = HCZ::optimize(Solution(localLenght + 1, inst->p, InstanceReader::cloneVector(localTour, localLenght + 1), 999999999999, bonus, InstanceReader::cloneVector(localSelected)), inst);

					if (localBestCost > l.cost) {
						localBestCost = l.cost;
						if (s.cost > l.cost || s.bonus < inst->Q) {
							s.reset();
							s = l;
						}
					}
					else {
						l.reset();
					}

					bonus -= inst->BONUS[w][1];
					localSelected[w] = false;
					free(localTour);
					localTour = InstanceReader::cloneVector(tour, localLenght);

				}
			}

			free(localTour);
			localTour = NULL;
			free(tour);
			tour = NULL;
			free(localSelected);
			localSelected = NULL;

		}

		if (localTour != NULL)
			free(localTour);

		if (tour != NULL)
			free(tour);

		if (localSelected != NULL)
			free(localSelected);

		return s;

	}

	static int * addElementToSet(int* set, int setLength, int e, int position) {

		int size = setLength + 1, i = 0;

		int * newQ = (int*)calloc(size, sizeof(int));

		for (int j = 0; j < setLength; j++) {
			int node = set[j];
			if (i == position) {
				newQ[i] = e;
				i++;
				newQ[i] = node;
				i++;
			}
			else {
				newQ[i] = node;
				i++;
				if (i == position) {
					newQ[i] = e;
				}

			}
		}

		free(set);

		return newQ;

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