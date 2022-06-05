#pragma once
#include "InstanceReader.h";
#include "Solution.h";

class Cloner {
public:
	static Solution clone(Solution s, Instance *inst) {
		int * new_tour = (int*)calloc(inst->n + 1, sizeof(int));
		int * new_edgeObs = (int*)calloc(inst->n + 1, sizeof(int));

		int * new_onBoardPs = (int*)calloc(inst->p + 1, sizeof(int));

		bool * new_selectedVs = (bool*)calloc(inst->n + 1, sizeof(bool));
		bool * new_notPickVs = (bool*)calloc(inst->n + 1, sizeof(bool));

		for (int j = 0; j < s.onBoardCount; j++) {
			new_onBoardPs[j] = s.onBoardPassangers[j];
		}

		for (int j = 0; j < InstanceReader::d; j++) {
			if (j < s.n) {
				new_tour[j] = s.tour[j];
				new_edgeObs[j] = s.edgeObserver[j];
			}
			new_selectedVs[j] = s.selectedVertex[j];
			new_notPickVs[j] = s.notPickedVertex[j];
		}

		return Solution(
			s.n,
			s.size - 1,
			new_tour,
			new_onBoardPs,
			s.cost,
			s.bonus,
			s.onBoardCount,
			new_selectedVs,
			new_notPickVs,
			new_edgeObs
		);
	}
};