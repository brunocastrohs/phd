#pragma once
#include "vector";
#include "Vertex.h";
using namespace std;

typedef struct {
	int n;
	int p;
	int c;
	double Q;
	double **T;
	double **D;
	double **W;
	double **P_D;
	double **BONUS;
	bool isSimetric;
	bool isCType = false;
	vector<vertex> vertex;
	vector<int> vertexByTax;
	vector<int> vertexByPs;
	vector<int> vertexByB;
	vector<int> vertexByEDGE;
	vector<int> vertexBySCORE;
	double *vertexSCORE;
	double *vertexBSCORE;
	double *vertexTAXSCORE;
	double *vertexPsSCORE;
	double *vertexEDGESCORE;
	double totalScore = 0;
	double totalBScore = 0;
	double totalTAXScore = 0;
	double totalPsScore = 0;
	double totalEDGEScore = 0;
	long int seed = 1;

	void reset() {

		for (int i = 0; i < vertex.size(); i++) {
		//	vertex[i].reset();
		}

		free(vertexSCORE);
		free(vertexBSCORE);
		free(vertexTAXSCORE);
		free(vertexPsSCORE);
		free(vertexEDGESCORE);

	}

} Instance;