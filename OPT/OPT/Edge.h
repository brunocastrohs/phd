#pragma once
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

struct edge {
	int org = 0;
	int dest = 0;
	int i_org = 0;
	int i_dest = 0;
	int boarded = 0;
	int maxBoarded = 0;
	double cost = 0;
	int* passangers;
	int passangersCount = 0;

	edge(int o, int d, int ia, int ib, double c, int m, int np) {
		i_org = ia;
		i_dest = ib;
		org = o;
		dest = d;
		cost = c;
		maxBoarded = m;
		passangers = (int*)calloc(np, sizeof(int));
	};

	edge(int np) {
		passangers = (int*)calloc(np, sizeof(int));
	};

	void set(int o, int d, int ia, int ib, double c, int m) {
		reset();
		i_org = ia;
		i_dest = ib;
		org = o;
		dest = d;
		cost = c;
		maxBoarded = m;
	};

	void reset() {
		i_org = 0;
		i_dest = 0;
		org = 0;
		dest = 0;
		cost = 0;
		maxBoarded = 0;
		boarded = 0;
		for (int i = 0; i < passangersCount; i++) {
			passangers[i] = 0;
			passangersCount--;
		}

	};

};
