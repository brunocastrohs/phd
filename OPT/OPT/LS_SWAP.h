#pragma once
#include "InstanceReader.h"
#include "Solution.h"
#include "HCZ.h";
class LS_SWAP {

public:

	static Solution optimize(Solution s, Instance * inst) {

		Solution v = Solution();

		int * tour = InstanceReader::cloneVector(s.tour, s.n);

		int w = 0, p1, p2, p3, p4;

		int i_p1, i_p2, i_p3, i_p4;

		int jump = inst->n / 20 + 1;

		int start = jump > 5 ? (rand() % jump) + 1 : 1;

		for (int k = 0; k < s.n - 1; k += jump) {
			for (int c = start; c < s.n - 2; c += jump) {

				w = c == 1 ? next_index(k, s.n) : next_index(w, s.n);

				i_p1 = k;

				i_p2 = next_index(k, s.n);

				i_p3 = next_index(w, s.n);

				i_p4 = next_index(next_index(w, s.n), s.n);

				p1 = tour[i_p1];

				p2 = tour[i_p2];

				p3 = tour[i_p3];

				p4 = tour[i_p4];

				if (inst->D[p1][p2] / passangersPerEdge(p1, p2, inst) > inst->D[p2][p1] / passangersPerEdge(p2, p1, inst) && p1 != 1 && p2 != 1) {

					swap(i_p1, i_p2, tour);
					p1 = tour[i_p1];
					p2 = tour[i_p2];
					p3 = tour[i_p3];
					p4 = tour[i_p4];

					v = HCZ::optimize(Solution(s.n, inst->p, InstanceReader::cloneVector(tour, s.n), 9999999999999, s.bonus, InstanceReader::cloneVector(s.selectedVertex)), inst);

					if (v.cost < s.cost) {
						s.reset();
						s = v;
					}
					else
						v.reset();


				}

				if (inst->D[p3][p4] / passangersPerEdge(p3, p4, inst) > inst->D[p4][p3] / passangersPerEdge(p4, p3, inst) && p3 != 1 && p4 != 1) {

					swap(i_p3, i_p4, tour);
					p1 = tour[i_p1];
					p2 = tour[i_p2];
					p3 = tour[i_p3];
					p4 = tour[i_p4];

					v = HCZ::optimize(Solution(s.n, inst->p, InstanceReader::cloneVector(tour, s.n), s.cost, s.bonus, InstanceReader::cloneVector(s.selectedVertex)), inst);

					if (v.cost < s.cost) {
						s.reset();
						s = v;
					}
					else
						v.reset();


				}


				if (inst->D[p1][p2] / passangersPerEdge(p1, p2, inst) + inst->D[p3][p4] / passangersPerEdge(p3, p4, inst)
					>
					inst->D[p1][p4] / passangersPerEdge(p1, p4, inst) + inst->D[p3][p2] / passangersPerEdge(p3, p2, inst)
					&&
					p2 != 1 && p4 != 1) {

					swap(i_p4, i_p2, tour);
					p1 = tour[i_p1];
					p2 = tour[i_p2];
					p3 = tour[i_p3];
					p4 = tour[i_p4];

					v = HCZ::optimize(Solution(s.n, inst->p, InstanceReader::cloneVector(tour, s.n), s.cost, s.bonus, InstanceReader::cloneVector(s.selectedVertex)), inst);

					if (v.cost < s.cost) {
						s.reset();
						s = v;
					}
					else
						v.reset();


				}

				if (inst->D[p1][p2] / passangersPerEdge(p1, p2, inst) + inst->D[p3][p4] / passangersPerEdge(p3, p4, inst)
					>
					inst->D[p1][p3] / passangersPerEdge(p1, p3, inst) + inst->D[p2][p4] / passangersPerEdge(p2, p4, inst)
					&&
					p2 != 1 && p3 != 1 && p4 != 1
					) {

					swap(i_p3, i_p2, tour);
					p1 = tour[i_p1];
					p2 = tour[i_p2];
					p3 = tour[i_p3];
					p4 = tour[i_p4];

					v = HCZ::optimize(Solution(s.n, inst->p, InstanceReader::cloneVector(tour, s.n), s.cost, s.bonus, InstanceReader::cloneVector(s.selectedVertex)), inst);

					if (v.cost < s.cost) {
						s.reset();
						s = v;
					}
					else
						v.reset();


				}

				if (inst->D[p1][p2] / passangersPerEdge(p1, p2, inst) + inst->D[p3][p4] / passangersPerEdge(p3, p4, inst)
					>
					inst->D[p3][p2] / passangersPerEdge(p3, p2, inst) + inst->D[p4][p1] / passangersPerEdge(p4, p1, inst)
					&&
					p1 != 1 && p2 != 1 && p3 != 1 && p4 != 1) {

					swap(i_p4, i_p2, tour);
					swap(i_p1, i_p2, tour);
					p1 = tour[i_p1];
					p2 = tour[i_p2];
					p3 = tour[i_p3];
					p4 = tour[i_p4];

					v = HCZ::optimize(Solution(s.n, inst->p, InstanceReader::cloneVector(tour, s.n), s.cost, s.bonus, InstanceReader::cloneVector(s.selectedVertex)), inst);

					if (v.cost < s.cost) {
						s.reset();
						s = v;
					}
					else
						v.reset();

				}

			}

		}

		return s;

	}

	static void swap(int i, int j, int * tour) {
		if (tour[i] != 1 && tour[j] != 1) {
			int aux = tour[i];
			tour[i] = tour[j];
			tour[j] = aux;
		}

	}

	static int next_index(int i, int n) {
		return i == n - 2 ? 0 : i + 1;
	}

	static int passangersPerEdge(int o, int d, Instance *inst) {

		return 1 + inst->vertex[o].possiblePassangersPerNeighbor[d];

	}

};