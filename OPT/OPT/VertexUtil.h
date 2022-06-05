#pragma once
#include "vector";
#include "Instance.h";
#include "InsertionSort.h";

class VertexUtil {
public:
	static void configureVertex(Instance *inst) {

		for (int i = 1; i <= inst->n; i++) {

			inst->vertex[i] = vertex(inst->n, inst->p);

		}

		//configurar next neighbors
		for (int p = 1; p <= inst->p; p++) {

			int org = inst->P_D[p][3];

			int dest = inst->P_D[p][4];

			inst->vertex[org].departingPassangers[inst->vertex[org].dPassangersCount++] = p;

			if (!inst->vertex[org].isVertexNextNeighbor[dest]) {

				inst->vertex[org].isVertexNextNeighbor[dest] = true;
				inst->vertex[org].vertexNextNeighbor[inst->vertex[org].vertexNextNeighborCount] = dest;
				inst->vertex[org].vertexNextNeighborCount++;

				inst->vertex[org].isVertexNeighbor[dest] = true;
				inst->vertex[org].vertexNeighbor[inst->vertex[org].vertexNeighborCount] = dest;
				inst->vertex[org].vertexNeighborCount++;

			}

		}

		//configurar isRoot
		bool *isRoot = (bool*)calloc(inst->n + 1, sizeof(bool));

		isRoot[1] = true;

		for (int i = 0; i <= inst->vertex[1].vertexNeighborCount; i++)
			isRoot[inst->vertex[1].vertexNeighbor[i]] = true;

		//configurar prev neighbors
		for (int prev_id = 1; prev_id <= inst->n; prev_id++) {

			vertex prev_v = inst->vertex[prev_id];

			for (int i = 0; i < prev_v.vertexNextNeighborCount; i++) {

				int dest = prev_v.vertexNextNeighbor[i];

				if (!inst->vertex[dest].isVertexPrevNeighbor[prev_id]) {
					inst->vertex[dest].isVertexPrevNeighbor[prev_id] = true;
					inst->vertex[dest].vertexPrevNeighbor[inst->vertex[dest].vertexPrevNeighborCount] = prev_id;
					inst->vertex[dest].vertexPrevNeighborCount++;
				}

			}
		}

		//configurar combinação de prev
		for (int v_id = 1; v_id <= inst->n; v_id++) {

			vertex current_v = inst->vertex[v_id];

			for (int i = 0; i < current_v.vertexPrevNeighborCount; i++) {

				int prev_id = current_v.vertexPrevNeighbor[i];

				if (v_id == 1 || !isRoot[prev_id])

					for (int j = 0; j < current_v.vertexPrevNeighborCount; j++) {

						if (i != j) {

							int current_id = current_v.vertexPrevNeighbor[j];

							if (current_id != 1 && (v_id == 1 || !isRoot[current_id]) && !inst->vertex[prev_id].isVertexNeighbor[current_id]) {

								inst->vertex[prev_id].isVertexNeighbor[current_id] = true;
								inst->vertex[prev_id].vertexNeighbor[inst->vertex[prev_id].vertexNeighborCount] = current_id;
								inst->vertex[prev_id].vertexNeighborCount++;

								inst->vertex[prev_id].isVertexNextNeighbor[current_id] = true;
								inst->vertex[prev_id].vertexNextNeighbor[inst->vertex[prev_id].vertexNextNeighborCount] = current_id;
								inst->vertex[prev_id].vertexNextNeighborCount++;

							}

						}
					}



			}

		}

		/*
		//update de prevs com base nos new next
		//configurar prev neighbors
		for (int prev_id = 1; prev_id <= inst->n; prev_id++) {

		vertex prev_v = inst->vertex[prev_id];

		for (int i = 0; i < prev_v.vertexNextNeighborCount; i++) {

		int dest = prev_v.vertexNextNeighbor[i];

		if (!inst->vertex[dest].isVertexPrevNeighbor[prev_id]) {
		inst->vertex[dest].isVertexPrevNeighbor[prev_id] = true;
		inst->vertex[dest].vertexPrevNeighbor[inst->vertex[dest].vertexPrevNeighborCount] = prev_id;
		inst->vertex[dest].vertexPrevNeighborCount++;
		}

		}
		}

		//update de prevs com base na cominação
		//configurar combinação de prev
		for (int v_id = 1; v_id <= inst->n; v_id++) {

		vertex current_v = inst->vertex[v_id];

		for (int i = 0; i < current_v.vertexPrevNeighborCount; i++) {

		int prev_id = current_v.vertexPrevNeighbor[i];

		if (v_id == 1 || !isRoot[prev_id]) {

		for (int j = 0; j < current_v.vertexPrevNeighborCount; j++) {

		if (i != j) {

		int current_id = current_v.vertexPrevNeighbor[j];

		if (current_id != 1 && !inst->vertex[prev_id].isVertexNeighbor[current_id]) {

		inst->vertex[prev_id].isVertexNeighbor[current_id] = true;
		inst->vertex[prev_id].vertexNeighbor[inst->vertex[prev_id].vertexNeighborCount] = current_id;
		inst->vertex[prev_id].vertexNeighborCount++;

		inst->vertex[prev_id].isVertexNextNeighbor[current_id] = true;
		inst->vertex[prev_id].vertexNextNeighbor[inst->vertex[prev_id].vertexNextNeighborCount] = current_id;
		inst->vertex[prev_id].vertexNextNeighborCount++;

		}

		}
		}

		}

		}

		}

		//configurar combinação next
		for (int v_id = 1; v_id <= inst->n; v_id++) {

		vertex current_v = inst->vertex[v_id];

		for (int i = 0; i < current_v.vertexNextNeighborCount; i++) {

		int next_id = current_v.vertexNextNeighbor[i];

		if((v_id == 1 || !isRoot[next_id]))

		for (int j = 0; j < current_v.vertexNextNeighborCount; j++) {

		if (i != j) {

		int current_id = current_v.vertexNextNeighbor[j];

		if (current_id != 1 && (v_id == 1 || !isRoot[current_id]) &&  !inst->vertex[next_id].isVertexNeighbor[current_id]) {

		inst->vertex[next_id].isVertexNeighbor[current_id] = true;
		inst->vertex[next_id].vertexNeighbor[inst->vertex[next_id].vertexNeighborCount] = current_id;
		inst->vertex[next_id].vertexNeighborCount++;

		}

		}

		}

		}

		}
		/**/
		//configurar passageiros pelo tempo e maxSit

		configurePassangers(inst);

	}

	static void configurePassangers(Instance *inst) {

		bool *isInviable = (bool*)calloc(inst->p + 1, sizeof(bool));

		bool *currentBoarded = (bool*)calloc(inst->p + 1, sizeof(bool));

		for (int i = 1; i <= inst->n; i++) {

			InsertionSort::run(inst->vertex[i].departingPassangers, inst, inst->vertex[i].dPassangersCount);

			vertex v = inst->vertex[i];

			int org = i;

			for (int j = 0; j < v.vertexNextNeighborCount; j++) {

				int dest = v.vertexNextNeighbor[j];

				for (int p_id = 0; p_id < v.dPassangersCount; p_id++) {

					int p = v.departingPassangers[p_id];

					if (!isInviable[p] && inst->P_D[p][4] == dest) {

						bool timeViable = inst->T[org][dest] <= inst->P_D[p][2];

						if (timeViable && inst->vertex[org].possiblePassangersPerNeighbor[dest] < inst->c) {

							inst->vertex[org].possiblePassangersPerNeighbor[dest]++;
							currentBoarded[p] = true;

						}
						else
							isInviable[p] = true;

					}

				}

				for (int p_id = v.dPassangersCount - 1; p_id >= 0; p_id--) {

					int p = v.departingPassangers[p_id];

					if (currentBoarded[p] && inst->P_D[p][4] == dest) {

						bool notTaxViable = inst->D[org][dest] / (inst->vertex[org].possiblePassangersPerNeighbor[dest] + 1) > inst->P_D[p][1];

						if (notTaxViable) {
							inst->vertex[org].possiblePassangersPerNeighbor[dest] = 0;
							isInviable[p] = true;
							currentBoarded[p] = false;
							j--;
							break;
						}

					}

				}


			}

		}

	}



};
