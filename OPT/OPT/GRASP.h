#pragma once
#include "InstanceReader.h";
#include "Solution.h";
#include "MLS.h";
#include "Cloner.h"

//clever algorithms 76

class GRASP {

public:

	static Solution optimize(int maxIter, double alpha, Instance *inst) {

		Solution S;

		do {

			int v = (rand() % (inst->n - 1)) + 2;

			Solution R = greedyRandomizedConstruction(v, alpha, inst);

			if (S.size == 0 || S.cost > R.cost) {
				S.reset();
				S = Solution(R.n, inst->p, InstanceReader::cloneVector(R.tour, R.n), R.cost, R.bonus, InstanceReader::cloneVector(R.selectedVertex));
			}

			Solution V = LS_FLIP::optimizeRout(Cloner::clone(R, inst), inst);

			if (S.cost > V.cost) {
				S.reset();
				S = Solution(V.n, inst->p, InstanceReader::cloneVector(V.tour, V.n), V.cost, V.bonus, InstanceReader::cloneVector(V.selectedVertex));
			}
			else
				V.reset();

			R.reset();

			maxIter--;

		} while (maxIter > 0);

		return S;

	}

	static Solution greedyRandomizedConstruction(int s, double alpha, Instance *inst) {

		int n = inst->n + 1;

		int* tour = new int[n];

		bool *inserted = (bool*)calloc(n, sizeof(bool));

		double currentCost = 0;

		int currentTourLength = 0;

		double currentBonus = 0;

		tour[0] = 1;
		inserted[1] = true;
		currentTourLength++;

		tour[currentTourLength] = s;
		inserted[s] = true;
		currentCost += inst->D[tour[currentTourLength - 1]][tour[currentTourLength]];
		currentBonus += inst->BONUS[s][1];
		currentTourLength++;

		while (currentTourLength < n - 1) {

			double* featureCosts = (double*)calloc(n, sizeof(double));

			double minCost = 99999999;

			double maxCost = -99999999;

			for (int i : inst->vertexBySCORE) {

				if (!inserted[i]) {

					featureCosts[i] = inst->D[tour[currentTourLength - 1]][i];

					minCost = featureCosts[i] < minCost ? featureCosts[i] : minCost;

					maxCost = featureCosts[i] > maxCost ? featureCosts[i] : maxCost;

				}


			}

			int *RCL = (int*)calloc(n - currentTourLength, sizeof(int));

			int w = 0;

			double epsilon = minCost + alpha * (maxCost - minCost);

			for (int i = 1; i < n; i++) {
				if (!inserted[i] && featureCosts[i] <= epsilon) {
					RCL[w] = i;
					w++;
				}

			}

			s = RCL[(rand() % w)];
			tour[currentTourLength] = s;
			inserted[s] = true;
			currentCost += inst->D[tour[currentTourLength - 1]][tour[currentTourLength]];
			currentBonus += inst->BONUS[s][1];
			currentTourLength++;

			if (currentBonus >= inst->Q) {
				break;
				free(RCL);
				free(featureCosts);
			}
		}

		s = 1;
		tour[currentTourLength] = s;
		inserted[s] = true;
		currentCost += inst->D[tour[currentTourLength - 1]][tour[currentTourLength]];
		currentTourLength++;

		return Solution(currentTourLength, inst->p, tour, currentCost, currentBonus, inserted);

	}

};