#pragma once
#include "InstanceReader.h"
#include "Solution.h"
#include "TSPB.h";
#include "TSPBPDU.h";
#include "HCZ.h";


class NAIVE2 {

public:

	static double optimize(int ** rout, Instance *inst) {

		Solution s = routToSolution(rout, inst);

		s = HCZ::optimize(s, inst);

		double cost = s.cost;

		s.reset();

		return cost;

	}

	static Solution routToSolution(int ** rout, Instance * inst) {

		int *tour = (int*)calloc(inst->n+1, sizeof(int));
		bool *selected = (bool*)calloc(inst->n+1, sizeof(bool));
		int k = 0;
		tour[k++] = 1;
		selected[tour[k - 1]] = true;
		double cost = 0;
		double bonus = 0;
		int i = 0;

		do {

			bool founded = false;

			for (int j = 0; !founded; j++) {
			
				if (rout[i][j] > 0){					
					i = j;
					founded = true;
				}

			}

			tour[k++] = i+1;
			cost += inst->D[tour[k-2]][tour[k-1]];
			bonus += inst->BONUS[tour[k-1]][1];
			selected[tour[k-1]] = true;
			
		} while (i+1 != 1);

		return Solution(k, inst->p, tour, cost, bonus, selected);
	}

};
