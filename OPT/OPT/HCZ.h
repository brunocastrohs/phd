#pragma once
#include "InstanceReader.h"
#include "InsertionSort.h"
#include "Solution.h"
using namespace std;

class HCZ {
public:

	static edge* edges;

	static passanger* passangers;

	static edge *edgeHold;

	static passanger *passangersHold;

	static passanger *passangersUberHold;

	static bool* alreadyCounted;

	static int* boarded;

	static bool* isLocalBoarded;

	static bool* isBoarded;

	static int* nextBoarded;

	static bool* isNextBoarded;

	static int* uberBoarded;

	static bool* uberIsBoarded;

	static bool* uberAlreadyCounted;

	static int* uberNextBoarded;

	static bool* uberIsNextBoarded;

	static double **edgeBoardFactor;

	static Solution optimize(Solution v, Instance *inst) {

		resetDataGaters(inst);

		Solution l(v.n, inst->p, InstanceReader::cloneVector(v.tour, v.n), v.cost, v.bonus, InstanceReader::cloneVector(v.selectedVertex), InstanceReader::cloneVector(v.notPickedVertex));

		initEdges(&l, inst);

		initPassangers(&l, inst);

		allocatePassangersInEdges(&l, inst);

		bool hasUber = false;

		if (inst->isCType) {
			InstanceReader::copyPassangers(passangers, passangersUberHold, inst->p + 1);
			hasUber = allocatePassangersInUber(&l, inst);
		}

		updateTourCost(&l, hasUber, inst);

		if (l.cost < v.cost) {
			v.reset();
			v = l;
		}
		else {
			l.reset();
		}

		return v;

	}

	static void initEdges(Solution *s, Instance *inst) {

		int k = 0;

		do {
			edges[k].set(s->tour[k], s->tour[k + 1], k, k + 1, inst->D[s->tour[k]][s->tour[k + 1]], inst->c);
			k++;
		} while (k < s->n - 1);

	}

	static void initPassangers(Solution *s, Instance *inst) {

		bool noDelay = false;

		int org;

		int i_org;

		int dest;

		int i_dest;

		bool passTroughORG, passTroughDEST;

		double currentTime;

		double currentDelay;

		double currentTax;

		int maxPersonsPerVertex = inst->c + 1;

		for (int p_id = 1; p_id <= inst->p; p_id++) {

			org = (int)inst->P_D[p_id][3];

			i_org = 0;

			dest = (int)inst->P_D[p_id][4];

			i_dest = 0;

			passTroughORG = false, passTroughDEST = false;

			currentTax = 0.0;

			currentTime = 0.0;

			currentDelay = 0;

			passanger p = passanger();

			for (int i = 0; i < s->n - 1; i++) {

				if (s->tour[i] == dest && dest != 1 && passTroughORG == false) {
					break;
				}
				else if (s->tour[i] == org && !passTroughDEST) {
					i_org = i;
					passTroughORG = true;
					p = passanger(p_id, org, dest, i_org);
					p.viable = true;
				}
				else if (s->tour[i] == dest && passTroughORG) {
					passTroughDEST = true;
					break;
				}

				if (passTroughORG) {

					//deve contar o tempo de cada aresta vij e o delay i da aresta de vij
					currentTax += inst->D[s->tour[i]][s->tour[i + 1]] / maxPersonsPerVertex;

					currentTime += inst->T[s->tour[i]][s->tour[i + 1]];

					currentDelay += noDelay || s->notPickedVertex[s->tour[i]] ? 0 : inst->BONUS[s->tour[i]][2];

					p.taxDiscarded = currentTax > inst->P_D[p_id][1];

					p.timeDiscarded = currentTime > inst->P_D[p_id][2];

					p.delayDiscarded = currentTime + currentDelay > inst->P_D[p_id][2];

					p.currentTime = currentTime;

					p.currentDelay = currentDelay;

					p.i_dest = i_dest = i + 1;

					p.range = i_dest - i_org;

					if (p.range <= 1 && (p.taxDiscarded || p.timeDiscarded)) {
						p.viable = false;
					}
					else if (p.delayDiscarded || p.taxDiscarded) {
						p.noDestDiscarded = true;
						currentTax -= inst->D[s->tour[i]][s->tour[i + 1]] / maxPersonsPerVertex;
						currentTime -= inst->T[s->tour[i]][s->tour[i + 1]];
						currentDelay -= s->notPickedVertex[s->tour[i]] ? 0 : inst->BONUS[s->tour[i]][2];
						p.taxDiscarded = currentTax > inst->P_D[p_id][1];
						p.timeDiscarded = currentTime > inst->P_D[p_id][2];
						p.delayDiscarded = currentTime + currentDelay > inst->P_D[p_id][2];
						p.currentTime = currentTime;
						p.range--;
						p.i_dest--;
						break;
					}

					if (!p.delayDiscarded && !passTroughDEST && !p.taxDiscarded) {
						edges[i].passangers[edges[i].passangersCount++] = (p.id);
					}

				}

			}

			if (!p.noDestDiscarded && dest == 1 && passTroughORG) {

				if (p.range <= 1 && (p.taxDiscarded || p.timeDiscarded)) {
					p.viable = false;
				}
				else if (p.delayDiscarded || p.taxDiscarded) {
					p.noDestDiscarded = true;
					int i = s->n - 2;
					currentTax -= inst->D[s->tour[i]][s->tour[i + 1]] / maxPersonsPerVertex;
					currentTime -= inst->T[s->tour[i]][s->tour[i + 1]];
					currentDelay -= s->notPickedVertex[s->tour[i]] ? 0 : inst->BONUS[s->tour[i]][2];
					p.taxDiscarded = currentTax > inst->P_D[p_id][1];
					p.timeDiscarded = currentTime > inst->P_D[p_id][2];
					p.delayDiscarded = currentTime + currentDelay > inst->P_D[p_id][2];
					p.currentTime = currentTime;
					p.range--;
					p.i_dest--;
				}


			}
			else if (!p.noDestDiscarded && passTroughORG && !passTroughDEST) {

				if (p.range <= 1 && (p.taxDiscarded || p.timeDiscarded)) {
					p.viable = false;
				}
				else if (p.delayDiscarded || p.taxDiscarded) {
					int i = s->n - 2;
					p.noDestDiscarded = true;
					currentTax -= inst->D[s->tour[i]][s->tour[i + 1]] / maxPersonsPerVertex;
					currentTime -= inst->T[s->tour[i]][s->tour[i + 1]];
					currentDelay -= s->notPickedVertex[s->tour[i]] ? 0 : inst->BONUS[s->tour[i]][2];
					p.taxDiscarded = currentTax > inst->P_D[p_id][1];
					p.timeDiscarded = currentTime > inst->P_D[p_id][2];
					p.delayDiscarded = currentTime + currentDelay > inst->P_D[p_id][2];
					p.currentTime = currentTime;
					p.range--;
					p.i_dest--;
				}
				p.noDestDiscarded = true;
			}


			p.currentTax = 0;
			passangers[p_id] = p;

		}

		for (int i = 0; i < s->n - 1; i++) {
			InsertionSort::run(edges[i].passangers, passangers, edges[i].passangersCount);
		}

	}

	static void allocatePassangersInEdges(Solution * s, Instance *inst) {

		InstanceReader::copyEdges(edges, edgeHold, s->n - 1);

		InstanceReader::copyPassangers(passangers, passangersHold, inst->p + 1);

		int boardedCount = 0;

		int nextBoardedCount = 0;

		bool doReset = false;

		int currentBoardCount = 0;

		for (int i = 0; i < s->n - 1; i++) {

			currentBoardCount = 0;

			//CONTABILIZAR QNTD DE PASS NA ARESTA
			for (int count = 0; count < edges[i].passangersCount; count++) {
				int p_id = edges[i].passangers[count];
				if (passangers[p_id].viable &&
					!passangers[p_id].delayDiscarded &&
					!passangers[p_id].taxDiscarded &&
					!passangers[p_id].noDestDiscarded &&
					(isLocalBoarded[p_id] || passangers[p_id].i_org == i)) {
					edges[i].boarded++;
				}
				if (edges[i].boarded >= inst->c)
					break;
			}


			//CONTABILIZAR QUEM JÁ VEM DE OUTRA ARESTA
			for (int j = 0; j < nextBoardedCount; j++) {

				int p_id = nextBoarded[j];

				if (currentBoardCount < inst->c &&
					passangers[p_id].viable &&
					!passangers[p_id].delayDiscarded) {

					passangers[p_id].currentTax += edges[i].cost / (edges[i].boarded + 1);

					alreadyCounted[p_id] = true;

					if (passangers[p_id].currentTax > inst->P_D[p_id][1]) {
						passangers[p_id].taxDiscarded = true;
						doReset = true;
						break;
					}

					if (passangers[p_id].i_dest == i + 1) {
						isNextBoarded[p_id] = false;
						isLocalBoarded[p_id] = false;
					}

					currentBoardCount++;

				}
				else if (currentBoardCount >= inst->c) {
					break;
				}

			}

			if (!doReset) {

				//ASSEGURAR DE CONTINUAR EMBARCADO QUEM AINDA NÃO CHEGOU EM SEU DESTINO
				for (int j = 0; j < nextBoardedCount; j++) {

					int p_id = nextBoarded[j];

					if (p_id != 0 && !isNextBoarded[p_id]) {
						swap(j, nextBoardedCount - 1, nextBoarded);
						nextBoarded[nextBoardedCount - 1] = 0;
						nextBoardedCount--;
						j--;
					}

				}

				//CONTABILIZAR NOVOS PASSAGEIROS NA ARESTA CORRENTE
				for (int count = 0; count < edges[i].passangersCount; count++) {
					int p_id = edges[i].passangers[count];

					if (currentBoardCount < inst->c &&
						!isNextBoarded[p_id] &&
						!alreadyCounted[p_id] &&
						passangers[p_id].viable &&
						!passangers[p_id].delayDiscarded &&
						!passangers[p_id].taxDiscarded &&
						!passangers[p_id].noDestDiscarded &&
						passangers[p_id].i_org == i) {

						passangers[p_id].currentTax += edges[i].cost / (edges[i].boarded + 1);

						if (passangers[p_id].i_dest != i + 1) {
							nextBoarded[nextBoardedCount++] = p_id;
							isNextBoarded[p_id] = true;
						}

						if (passangers[p_id].currentTax > inst->P_D[p_id][1]) {
							passangers[p_id].taxDiscarded = true;
							isLocalBoarded[p_id] = false;
							doReset = true;
							break;
						}

						isBoarded[p_id] = isLocalBoarded[p_id] = true;
						boarded[boardedCount++] = p_id;
						currentBoardCount++;

					}
					else if (currentBoardCount >= inst->c) {
						alreadyCounted[p_id] = false;
						break;
					}

					alreadyCounted[p_id] = false;

				}
			}

			if (doReset) {

				doReset = false;

				for (int j = 0; j < s->n - 1; j++) {
					edges[j] = edgeHold[j];
				}

				for (int j = 1; j <= inst->p; j++) {
					//reseta que não é taxDiscarded e viavel
					if (!passangers[j].taxDiscarded && passangers[j].viable) {
						if (passangersHold[j].noDestDiscarded) {
							passangersHold[j].range = passangers[j].range;
							passangersHold[j].i_dest = passangers[j].i_dest;
						}
						passangers[j] = passangersHold[j];
					}
					isBoarded[j] = false;
				}

				for (int j = 0; j < nextBoardedCount; j++) {
					isNextBoarded[nextBoarded[j]] = false;
					nextBoarded[j] = 0;
				}

				nextBoardedCount = 0;

				for (int j = 0; j < boardedCount; j++) {
					isLocalBoarded[boarded[j]] = false;
					boarded[j] = 0;
				}

				boardedCount = 0;

				i = -1;

			}

		}

		free(s->onBoardPassangers);
		s->onBoardPassangers = InstanceReader::cloneVector(boarded, inst->p + 1, boardedCount);
		s->onBoardCount = boardedCount;

	}

	static bool allocatePassangersInUber(Solution * s, Instance *inst) {

		InstanceReader::copyEdges(edges, edgeHold, s->n - 1);

		InstanceReader::copyVector(s->onBoardPassangers, uberBoarded, inst->p + 1);

		InstanceReader::copyVector(isBoarded, uberIsBoarded, inst->p + 1);

		int boardedCount = s->onBoardCount;

		int nextBoardedCount = 0;

		bool doReset = false;

		int currentBoardCount = 0;

		for (int i = 0; i < s->n - 1; i++) {

			currentBoardCount = edges[i].boarded;

			//CONTABILIZAR QNTD DE PASS NA ARESTA
			for (int count = 0; count < edges[i].passangersCount; count++) {
				int p_id = edges[i].passangers[count];
				if (passangers[p_id].viable &&
					!passangers[p_id].delayDiscarded &&
					!passangers[p_id].taxDiscarded &&
					!isBoarded[p_id] &&
					edges[i].boarded < inst->c &&
					(uberIsBoarded[p_id] || passangers[p_id].i_org == i)) {
					edges[i].boarded++;
				}
				if (edges[i].boarded >= inst->c)
					break;
			}


			//CONTABILIZAR QUEM JÁ VEM DE OUTRA ARESTA
			for (int j = 0; j < nextBoardedCount; j++) {

				int p_id = uberNextBoarded[j];

				if (currentBoardCount < inst->c &&
					passangers[p_id].viable &&
					!passangers[p_id].delayDiscarded) {

					passangers[p_id].currentTax += edges[i].cost / (edges[i].boarded + 1);

					uberAlreadyCounted[p_id] = true;

					if (passangers[p_id].currentTax > inst->P_D[p_id][1]) {
						passangers[p_id].taxDiscarded = true;
						doReset = true;
						break;
					}

					//compara a economia
					if (passangers[p_id].noDestDiscarded && passangers[p_id].i_dest == i + 1 && passangers[p_id].currentTax < inst->W[p_id][s->tour[passangers[p_id].i_dest]]) {
						passangers[p_id].range--;
						passangers[p_id].i_dest--;
						uberIsBoarded[p_id] = false;
						if (passangers[p_id].range == 0) {
							passangers[p_id].viable = false;
						}
						doReset = true;
						break;
					}

					if (passangers[p_id].i_dest == i + 1) {
						uberIsNextBoarded[p_id] = false;
						uberIsBoarded[p_id] = false;
					}

					currentBoardCount++;

				}
				else if (currentBoardCount >= inst->c) {
					break;
				}

			}

			if (!doReset) {

				//ASSEGURAR DE CONTINUAR EMBARCADO QUEM AINDA NÃO CHEGOU EM SEU DESTINO
				for (int j = 0; j < nextBoardedCount; j++) {

					int p_id = uberNextBoarded[j];

					if (p_id != 0 && !uberIsNextBoarded[p_id]) {
						swap(j, nextBoardedCount - 1, uberNextBoarded);
						uberNextBoarded[nextBoardedCount - 1] = 0;
						nextBoardedCount--;
						j--;
					}

				}

				//CONTABILIZAR NOVOS PASSAGEIROS NA ARESTA CORRENTE
				for (int count = 0; count < edges[i].passangersCount; count++) {
					int p_id = edges[i].passangers[count];

					if (currentBoardCount < inst->c &&
						!uberIsNextBoarded[p_id] &&
						!uberAlreadyCounted[p_id] &&
						passangers[p_id].viable &&
						!passangers[p_id].delayDiscarded &&
						!passangers[p_id].taxDiscarded &&
						!isBoarded[p_id] &&
						passangers[p_id].i_org == i) {

						passangers[p_id].currentTax += edges[i].cost / (edges[i].boarded + 1);

						if (passangers[p_id].i_dest != i + 1) {
							uberNextBoarded[nextBoardedCount++] = p_id;
							uberIsNextBoarded[p_id] = true;
						}

						//compara penalidade com economia
						if (passangers[p_id].noDestDiscarded && passangers[p_id].i_dest == i + 1 && passangers[p_id].currentTax < inst->W[p_id][s->tour[passangers[p_id].i_dest]]) {
							passangers[p_id].range--;
							passangers[p_id].i_dest--;
							uberIsBoarded[p_id] = false;
							if (passangers[p_id].range == 0) {
								passangers[p_id].viable = false;
							}
							doReset = true;
							break;
						}

						if (passangers[p_id].currentTax > inst->P_D[p_id][1]) {
							passangers[p_id].taxDiscarded = true;
							uberIsBoarded[p_id] = false;
							doReset = true;
							break;
						}

						uberIsBoarded[p_id] = true;
						uberBoarded[boardedCount++] = p_id;
						currentBoardCount++;

					}
					else if (currentBoardCount >= inst->c) {
						uberAlreadyCounted[p_id] = false;
						break;
					}

					uberAlreadyCounted[p_id] = false;

				}
			}

			if (doReset) {

				doReset = false;

				for (int j = 0; j < s->n - 1; j++) {
					edges[j] = edgeHold[j];
				}

				for (int j = 1; j <= inst->p; j++) {
					//reseta quem não foi taxdiscarded ou se toronu inviavel
					if (!passangers[j].taxDiscarded && passangers[j].viable) {
						if (passangersUberHold[j].noDestDiscarded) {
							passangersUberHold[j].range = passangers[j].range;
							passangersUberHold[j].i_dest = passangers[j].i_dest;
						}
						passangers[j] = passangersUberHold[j];
					}
				}

				for (int j = 0; j < nextBoardedCount; j++) {
					uberIsNextBoarded[uberNextBoarded[j]] = false;
					uberNextBoarded[j] = 0;
				}

				nextBoardedCount = 0;

				for (int j = s->onBoardCount; j < boardedCount; j++) {
					uberIsBoarded[uberBoarded[j]] = false;
					uberBoarded[j] = 0;
				}

				boardedCount = s->onBoardCount;

				i = -1;

			}

		}

		free(s->onBoardPassangers);
		s->onBoardPassangers = InstanceReader::cloneVector(uberBoarded, inst->p + 1, boardedCount);
		bool hasUber = boardedCount > s->onBoardCount;
		s->onBoardCount = boardedCount;

		return hasUber;

	}

	static double updateTourCost(Solution *s, bool hasUber, Instance *inst) {

		double cost = 0;

		for (int i = 0; i < s->n - 1; i++) {
			cost += edges[i].cost / (1 + edges[i].boarded);

			edgeBoardFactor[edges[i].org][edges[i].dest] = edges[i].boarded == 0 ? 0.8 : edges[i].boarded / 10.0 + 1.0;

			s->edgeObserver[i] = edges[i].boarded;

		}

		if (hasUber)
			for (int i = 0; i < s->onBoardCount; i++) {
				cost += inst->W[s->onBoardPassangers[i]][s->tour[passangers[s->onBoardPassangers[i]].i_dest]];
			}

		s->cost = cost;

		return cost;
	}

	static void swap(int i, int j, int* v) {
		int aux = v[i];
		v[i] = v[j];
		v[j] = aux;

	}

	static void initDataGaters(Instance *inst) {

		edgeBoardFactor = new double*[inst->n + 1];

		edges = (edge*)calloc(inst->n + 1, sizeof(edge));
		edgeHold = (edge*)calloc(inst->n + 1, sizeof(edge));

		for (int i = 0; i <= inst->n; i++) {
			edgeBoardFactor[i] = (double*)calloc(inst->n + 1, sizeof(double));
			edges[i].passangers = (int*)calloc(inst->p + 1, sizeof(int));
			edgeHold[i].passangers = (int*)calloc(inst->p + 1, sizeof(int));
		}

		passangers = (passanger*)calloc(inst->p + 1, sizeof(passanger));

		passangersHold = (passanger*)calloc(inst->p + 1, sizeof(passanger));

		alreadyCounted = (bool*)calloc(inst->p + 1, sizeof(bool));

		boarded = (int*)calloc(inst->p + 1, sizeof(int));

		isBoarded = (bool*)calloc(inst->p + 1, sizeof(bool));

		nextBoarded = (int*)calloc(inst->p + 1, sizeof(int));

		isNextBoarded = (bool*)calloc(inst->p + 1, sizeof(bool));



		//uber
		passangersUberHold = (passanger*)calloc(inst->p + 1, sizeof(passanger));

		isLocalBoarded = (bool*)calloc(inst->p + 1, sizeof(bool));

		uberBoarded = (int*)calloc(inst->p + 1, sizeof(int));

		uberIsBoarded = (bool*)calloc(inst->p + 1, sizeof(bool));

		uberAlreadyCounted = (bool*)calloc(inst->p + 1, sizeof(bool));

		uberNextBoarded = (int*)calloc(inst->p + 1, sizeof(int));

		uberIsNextBoarded = (bool*)calloc(inst->p + 1, sizeof(bool));

	}

	static void resetDataGaters(Instance *inst) {

		for (int i = 0; i <= inst->p; i++) {

			if (i <= inst->n) {
				edges[i].reset();
			}

			passangers[i].reset();
			passangersHold[i].reset();
			alreadyCounted[i] = false;
			boarded[i] = 0;
			nextBoarded[i] = 0;
			isBoarded[i] = false;
			isNextBoarded[i] = false;

			//uber
			passangersUberHold[i].reset();
			isLocalBoarded[i] = false;
			uberBoarded[i] = 0;
			uberIsBoarded[i] = false;
			uberAlreadyCounted[i] = false;
			uberNextBoarded[i] = 0;
			uberIsNextBoarded[i] = false;
		}

	}


};