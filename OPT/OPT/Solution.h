#pragma once
#include <sstream>
#include <vector>
#include "InstanceReader.h"
using namespace std;

class Solution {

public:
	int n;
	int size;
	double cost;
	double bonus;
	int onBoardCount;
	int* onBoardPassangers;
	int* tour;
	bool *selectedVertex;
	bool *notPickedVertex;
	int *edgeObserver;

	Solution() {
		size = 0;
		cost = 9999999999;
		bonus = 0;
		this->tour = NULL;
		this->onBoardPassangers = NULL;
		this->selectedVertex = NULL;
		this->notPickedVertex = NULL;
		this->edgeObserver = NULL;
	}

	Solution(int nv, int np, int *t, double c) {
		this->n = nv;
		this->size = np + 1;
		this->tour = t;
		this->cost = c;
		this->onBoardPassangers = (int*)calloc(size, sizeof(int));
		this->edgeObserver = (int*)calloc(nv, sizeof(int));
		this->onBoardCount = 0;
		this->selectedVertex = NULL;
		this->notPickedVertex = InstanceReader::createPickedVector();
		this->bonus = 0;
	}

	Solution(int nv, int np, int *t, double c, bool *sv) {
		this->n = nv;
		this->size = np + 1;
		this->tour = t;
		this->cost = c;
		this->edgeObserver = (int*)calloc(nv, sizeof(int));
		this->onBoardPassangers = (int*)calloc(size, sizeof(int));
		this->onBoardCount = 0;
		this->selectedVertex = sv;
		this->notPickedVertex = InstanceReader::createPickedVector();
		this->bonus = 0;
	}

	Solution(int nv, int np, int *t, double c, double b, bool *sv) {
		this->n = nv;
		this->size = np + 1;
		this->tour = t;
		this->cost = c;
		this->edgeObserver = (int*)calloc(nv, sizeof(int));
		this->onBoardPassangers = (int*)calloc(size, sizeof(int));
		this->onBoardCount = 0;
		this->selectedVertex = sv;
		this->bonus = b;
		this->notPickedVertex = InstanceReader::createPickedVector();
	}

	Solution(int nv, int np, int *t, double c, double b, bool *sv, bool *npk) {
		this->n = nv;
		this->size = np + 1;
		this->tour = t;
		this->cost = c;
		this->edgeObserver = (int*)calloc(nv, sizeof(int));
		this->onBoardPassangers = (int*)calloc(size, sizeof(int));
		this->onBoardCount = 0;
		this->selectedVertex = sv;
		this->bonus = b;
		this->notPickedVertex = npk;
	}

	Solution(int nv, int np, int *t, double c, double b, bool *sv, bool *npk, int* edo, int obpN, int* obp) {
		this->n = nv;
		this->size = np + 1;
		this->tour = t;
		this->cost = c;
		this->edgeObserver = edo;
		this->onBoardPassangers = obp;
		this->onBoardCount = obpN;
		this->selectedVertex = sv;
		this->bonus = b;
		this->notPickedVertex = npk;
	}

	Solution(int nv, int np, int* tourer,
		int* obp, double costa, double b, int nc, bool * sv, bool *pk, int *edc) {
		this->n = nv;
		this->size = np + 1;
		this->tour = tourer;
		this->onBoardPassangers = obp;
		this->onBoardCount = nc;
		this->cost = costa;
		this->bonus = b;
		this->selectedVertex = sv;
		this->notPickedVertex = pk;
		this->edgeObserver = edc;
	}

	Solution clone() {

		int * new_tour = (int*)calloc(n, sizeof(int));
		int * new_edgeObs = (int*)calloc(n, sizeof(int));

		int * new_onBoardPs = (int*)calloc(onBoardCount + 1, sizeof(int));

		bool * new_selectedVs = (bool*)calloc(n, sizeof(bool));
		bool * new_notPickVs = (bool*)calloc(n, sizeof(bool));

		for (int j = 0; j < onBoardCount; j++) {
			new_onBoardPs[j] = onBoardPassangers[j];
		}

		for (int j = 0; j < InstanceReader::d; j++) {
			if (j < n) {
				new_tour[j] = tour[j];
				new_edgeObs[j] = edgeObserver[j];
			}
			new_selectedVs[j] = selectedVertex[j];
			new_notPickVs[j] = notPickedVertex[j];
		}

		Solution cln(
			n,
			size - 1,
			new_tour,
			new_onBoardPs,
			cost,
			bonus,
			onBoardCount,
			new_selectedVs,
			new_notPickVs,
			new_edgeObs
		);

		return cln;

	}

	string toString() {

		stringstream str, tr, ps, pckb, qp;

		for (int i = 0; i < n; i++)
			tr << tour[i] << " ";

		for (int i = 0; i < n; i++)
			pckb << (notPickedVertex[i] ? "N" : "S") << " ";

		for (int i = 0; i < n - 1; i++)
			qp << edgeObserver[i] << " ";

		for (int i = 0; i<onBoardCount; i++) {
			ps << " " << onBoardPassangers[i] << " ";
		}

		str << "COST: " << cost;
		str << "\nBONUS: " << bonus;
		str << "\n" << tr.str();
		str << "\n" << pckb.str();
		str << "\n" << qp.str();
		str << "\n" << (onBoardCount) << " | [" << ps.str() << "]";

		return str.str();

	}

	void reset() {
		free(this->tour);
		free(this->selectedVertex);
		free(this->notPickedVertex);
		free(this->edgeObserver);
		free(this->onBoardPassangers);

	}

	bool equals(Solution s) {

		if (s.cost != this->cost || s.bonus != this->bonus || s.onBoardCount != this->onBoardCount || s.n != this->n)
			return false;

		for (int i = 0; i < s.n; i++) {
			if (s.tour[i] != this->tour[i] || s.selectedVertex[s.tour[i]] != this->selectedVertex[this->tour[i]] || s.edgeObserver[i] != this->edgeObserver[i]) {
				return false;
			}
		}

		for (int i = 0; i < s.onBoardCount; i++) {
			if (s.onBoardPassangers[i] != this->onBoardPassangers[i]) {
				return false;
			}
		}

		return true;

	}

};

struct passangerTour {
	int org = 0;
	int dest = 0;
	int i_org = 0;
	int i_dest = 0;
	int range = 0;
	int onBoardCount = 1;
	vector<int> passangers;

	passangerTour(int o, int d, int ia, int ib) {
		i_org = ia;
		i_dest = ib;
		org = o;
		dest = d;
		range = ib - ia;
	};

	passangerTour() {};

	string toString() {

		stringstream str;

		str << org << "_" << dest << " | range:" << range << " | p's: [ ";

		for (int p : passangers) {
			str << p << " ";
		}

		str << "] ; \n";

		return str.str();
	};

};