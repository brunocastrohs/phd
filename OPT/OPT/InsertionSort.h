#pragma once
#include "Instance.h";
#include "Edge.h";
#include "Passanger.h";
#include "vector";
using namespace std;

class InsertionSort {

public:
	static void run(int* vop, int length) {
		int j;
		int key;
		int i;
		for (j = 1; j < length; j++) {
			key = vop[j];
			for (i = j - 1; (i >= 0) && (vop[i] < key); i--) {
				vop[i + 1] = vop[i];
			}
			vop[i + 1] = key;
		}
	}

	static void run(int* vop, double* sorter, int length) {
		int j = 1;
		int key;
		int i = 0;
		for (j = 1; j < length; j++) {
			key = vop[j];
			for (i = j - 1; (i >= 0) && (sorter[vop[i]] < sorter[key]); i--) {
				vop[i + 1] = vop[i];
			}
			vop[i + 1] = key;
		}
	}

	static vector<int> run(vector<int> vop, int* sorter, int length) {
		int j = 1;
		int key;
		int i = 0;
		for (j = 1; j < length; j++) {
			key = vop[j];
			for (i = j - 1; (i >= 0) && (sorter[vop[i]] < sorter[key]); i--) {
				vop[i + 1] = vop[i];
			}
			vop[i + 1] = key;
		}
		return vop;
	}

	static vector<int> run(vector<int> vop, double* sorter, int length) {
		int j = 1;
		int key;
		int i = 0;
		for (j = 1; j < length; j++) {
			key = vop[j];
			for (i = j - 1; (i >= 0) && (sorter[vop[i]] < sorter[key]); i--) {
				vop[i + 1] = vop[i];
			}
			vop[i + 1] = key;
		}
		return vop;
	}

	static vector<int> run(vector<int> vop, double** sorter, int length) {
		int j = 1;
		int key;
		int i = 0;
		for (j = 1; j < length; j++) {
			key = vop[j];
			for (i = j - 1; (i >= 0) && (sorter[vop[i]][1] < sorter[key][1]); i--) {
				vop[i + 1] = vop[i];
			}
			vop[i + 1] = key;
		}
		return vop;
	}

	static vector<int> runMin(vector<int> vop, double* sorter, int length) {
		int j = 1;
		int key;
		int i = 0;
		for (j = 1; j < length; j++) {
			key = vop[j];
			for (i = j - 1; (i >= 0) && (sorter[vop[i]] > sorter[key]); i--) {
				vop[i + 1] = vop[i];
			}
			vop[i + 1] = key;
		}
		return vop;
	}

	static vector<int> runMin(vector<int> vop, double** sorter, int length) {
		int j = 1;
		int key;
		int i = 0;
		for (j = 1; j < length; j++) {
			key = vop[j];
			for (i = j - 1; (i >= 0) && (sorter[vop[i]][1] > sorter[key][1]); i--) {
				vop[i + 1] = vop[i];
			}
			vop[i + 1] = key;
		}
		return vop;
	}

	static vector<int> run(vector<int> passangers, Instance *inst, int length) {
		int j = 1;
		int key;
		int i = 0;
		for (j = 1; j < length; j++) {
			key = passangers[j];
			for (i = j - 1; (i >= 0) && (inst->P_D[passangers[i]][1] < inst->P_D[key][1]); i--) {
				passangers[i + 1] = passangers[i];
			}
			passangers[i + 1] = key;
		}
		return passangers;
	}

	static int* run(int* passangers, Instance *inst, int length) {
		int j = 1;
		int key;
		int i = 0;
		for (j = 1; j < length; j++) {
			key = passangers[j];
			for (i = j - 1; (i >= 0) && (inst->P_D[passangers[i]][1] < inst->P_D[key][1]); i--) {
				passangers[i + 1] = passangers[i];
			}
			passangers[i + 1] = key;
		}
		return passangers;
	}

	static void run(int *v, passanger *inst, int length) {
		int j = 1;
		int key;
		int i = 0;
		for (j = 1; j < length; j++) {
			key = v[j];
			for (i = j - 1; (i >= 0) && (inst[v[i]].range < inst[key].range); i--) {
				v[i + 1] = v[i];
			}
			v[i + 1] = key;
		}

	}

};