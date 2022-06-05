#pragma once
#include "InstanceReader.h"
#include "Solution.h"
#include "HCZ.h";
#include "LS_PUSH.h"

class LS_POP {

public:

	static Solution optimize(Solution s, Instance *inst) {

		int n = s.n - 1;

		Solution l = Solution();

		bool *localSelected = InstanceReader::cloneVector(s.selectedVertex);

		int * tour = InstanceReader::cloneVector(s.tour, s.n);

		int * localTour = InstanceReader::cloneVector(s.tour, s.n);

		bool altered = false;

		int localLenght = s.n;

		double bonus = s.bonus;

		int w, k, i1, p1 = 0, prev_p1, next_p1, removed = 0;

		int jump = inst->n / 20 + 1;

		int start = jump > 5 ? (rand() % jump) + 1 : 1;

		for (i1 = start; i1 < n; i1 += jump) {

			p1 = tour[i1];
			prev_p1 = tour[prev_index(i1, n)];
			next_p1 = tour[next_index(i1, n)];

			if ((s.edgeObserver[i1 - 1] == 0 && s.edgeObserver[i1] == 0) || (inst->D[prev_p1][p1] / passangersPerEdge(prev_p1, p1, inst) > inst->D[prev_p1][next_p1] / passangersPerEdge(prev_p1, next_p1, inst) && inst->D[p1][next_p1] / passangersPerEdge(p1, next_p1, inst) > inst->D[prev_p1][next_p1] / passangersPerEdge(prev_p1, next_p1, inst))) {
				localTour = removeElementToSet(localTour, localLenght--, p1);
				localSelected[p1] = false;
				altered = true;
				bonus -= inst->BONUS[p1][1];
			}

		}

		if (altered) {
			l = Solution(localLenght, inst->p, InstanceReader::cloneVector(localTour, localLenght), 9999999999, bonus, InstanceReader::cloneVector(localSelected));

			if (l.bonus < inst->Q) {
				l = LS_PUSH::optimize(l, inst);
			}
			else
				l = HCZ::optimize(Solution(localLenght, inst->p, InstanceReader::cloneVector(localTour, localLenght), 999999999999, bonus, InstanceReader::cloneVector(localSelected)), inst);

			if (l.cost < s.cost) {
				s.reset();
				s = l;
			}
			else
				l.reset();

		}

		free(tour);
		free(localSelected);

		return s;

	}

	static int * removeElementToSet(int* set, int setLength, int e) {

		int size = setLength - 1, i = 0;

		int * newQ = (int*)calloc(size, sizeof(int));

		for (int j = 0; j < setLength; j++) {
			int node = set[j];
			if (node != e) {
				newQ[i] = node;
				i++;
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