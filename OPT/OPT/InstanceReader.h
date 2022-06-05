#pragma once
#include <ctime>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <iostream>
#include "Random.h";
#include "VertexUtil.h";
#include "Edge.h";
#include "Passanger.h";
#include "InsertionSort.h";
using namespace std;

class InstanceReader {

public:

	static int d;

	static Random *rd;

	int* getSeedTour(Instance *inst) {

		int* tour = new int[inst->n + 1];

		tour[0] = 1;

		int i = 1;

		double currentBonus = 0;

		for (int k : inst->vertexBySCORE) {
			tour[i] = k;
			i++;
			currentBonus += inst->BONUS[k][1];
			if (currentBonus >= inst->Q)
				break;
		}

		tour[i] = 1;

		return tour;

	}

	static void printVector(int* v, int n) {
		cout << "\n";
		for (int j = 0; j < n; j++) {
			if (v[j] == 0)
				break;
			printf("%d ", v[j]);
		}
		cout << "\n";
	}

	static void printMatrix(int** M, int n) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", M[i][j]);
			}
			printf("\n");
		}

	}

	static void printMatrix(double** M, int n) {

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				printf("%.10f ", M[i][j]);
			}
			printf("\n");
		}

	}

	static int* cloneVector(int* v, int n) {

		int * new_v = (int*)calloc(n, sizeof(n));

		for (int j = 0; j < n; j++) {
			new_v[j] = v[j];
		}

		return new_v;
	}

	static int* cloneVector(int* v, int n, int limit) {

		int * new_v = (int*)calloc(n, sizeof(n));

		for (int j = 0; j < limit; j++) {
			new_v[j] = v[j];
		}

		return new_v;
	}

	static void copyVector(int* v, int * new_v, int n) {

		for (int j = 0; j < n; j++) {
			new_v[j] = v[j];
		}

	}

	static void copyVector(bool* v, bool * new_v, int n) {

		for (int j = 0; j < n; j++) {
			new_v[j] = v[j];
		}

	}

	static int* cloneVector(int k, int* v, int n) {

		int * new_v = (int*)calloc(n, sizeof(n));

		for (int j = 0; j < n - 1; j++) {
			new_v[j] = v[j];
		}

		new_v[n - 2] = k;
		new_v[n - 1] = 1;

		return new_v;
	}

	static int** cloneVector(int** v, int n) {

		int ** new_v = new int*[n];

		for (int i = 1; i < n; i++) {
			new_v[i] = (int*)calloc(n, sizeof(int));
			for (int j = 1; j < n; j++)
				new_v[i][j] = v[i][j];
		}

		return new_v;
	}

	static int** clonePOVector(int** v, int n) {

		int ** new_v = new int*[n];

		for (int i = 1; i <= n - 1; i++) {
			new_v[i] = (int*)calloc(3, sizeof(int));
			for (int j = 1; j < 3; j++)
				new_v[i][j] = v[i][j];
		}

		return new_v;
	}

	static bool* createPickedVector() {

		return (bool*)calloc(d, sizeof(bool));
	}

	static double* cloneVector(double* v, int n) {

		double * new_v = (double*)calloc(n, sizeof(double));

		for (int j = 0; j < n; j++) {
			new_v[j] = v[j];
		}

		return new_v;
	}

	static bool* cloneVector(bool* v, int n) {

		bool * new_v = (bool*)calloc(n, sizeof(bool));

		for (int j = 0; j < n; j++) {
			new_v[j] = v[j];
		}

		return new_v;
	}

	static bool* cloneVector(bool* v) {

		bool * new_v = (bool*)calloc(d, sizeof(bool));

		for (int j = 1; j < d; j++) {
			new_v[j] = v[j];
		}

		return new_v;
	}

	static bool* initSelectedVertex() {

		bool * new_v = (bool*)calloc(d, sizeof(bool));

		return new_v;
	}

	static int* cloneVectorFromSolver(int* v, int n) {

		int * new_v = (int*)calloc(n, sizeof(n));

		for (int j = 0; j < n; j++) {
			new_v[j] = v[j] + 1;
		}
		new_v[n] = new_v[0];
		return new_v;
	}

	static edge* cloneEdges(edge* v, int n) {

		edge * new_v = (edge*)calloc(n, sizeof(edge));

		for (int j = 0; j < n; j++) {
			new_v[j] = v[j];
		}

		return new_v;

	}

	static void copyEdges(edge* v, edge * new_v, int n) {

		for (int j = 0; j < n; j++) {
			new_v[j] = v[j];
		}

	}

	static passanger* clonePassangers(passanger* v, int n) {

		passanger * new_v = (passanger*)calloc(n, sizeof(passanger));

		for (int j = 0; j < n; j++) {
			new_v[j] = v[j];
		}

		return new_v;

	}

	static void copyPassangers(passanger* v, passanger * new_v, int n) {

		for (int j = 0; j < n; j++) {
			new_v[j] = v[j];
		}

	}

	static int dimension() {
		return d;
	}

	static void printTime(clock_t start, clock_t end) {
		float seconds = (float)(end - start) / CLOCKS_PER_SEC;
		printf("\n\nTEMPO: %f (s)", seconds);
	}

	static vector<string> split(string delimiter, string s) {
		//	std::string s = "scott>=tiger>=mushroom";
		//	std::string delimiter = ">=";
		vector<string> splitted;
		size_t pos = 0;
		string token;
		while ((pos = s.find(delimiter)) != std::string::npos) {
			token = s.substr(0, pos);
			splitted.push_back(token);
			s.erase(0, pos + delimiter.length());
		}
		return splitted;
	}

	static Instance readInstance(const char * fileName, const char * number, const char * type) {
		const char * path = "C:\\Users\\Bruno\\Google Drive\\DTR\\5 INSTANCIAS\\BANCO\\";
		//C:\Users\Elaine\Google Drive\DTR\5 INSTANCIAS\tspPQDU
		char filePath[1000] = "";

		strcat(filePath, path);
		strcat(filePath, number);
		strcat(filePath, "\\");
		strcat(filePath, type);
		strcat(filePath, "\\");
		strcat(filePath, fileName);

		//	printf("\n%s\n\n", filePath);

		FILE *file;
		file = fopen(filePath, "r");

		char line[10000];

		fgets(line, sizeof line, file);

		int n = 0;

		int p = 0;

		int c = 0;

		double Q = 0.0;

		double **D;

		double **W;

		double **T;

		double **P_D;

		double *V_PT;

		double *V_EDGE;

		int *V_PN;

		double **BONUS;

		char seps[] = " ";
		char *token;
		int header[4];
		int i = 1;

		token = strtok(line, seps);
		while (token != NULL) {
			sscanf(token, "%i", &header[i]);
			//printf("%i ", header[i]);
			token = strtok(NULL, seps);
			i++;
		}

		n = header[1];
		p = header[2];
		c = header[3];

		fgets(line, sizeof line, file);

		//printf("\n\n");

		D = (double**)malloc(sizeof(double*) * (n + 1));

		V_EDGE = (double*)calloc((n + 1), sizeof(double));

		i = 1;

		for (int r = 1; r <= n; r++) {

			fgets(line, sizeof line, file);
			D[r] = (double*)malloc(sizeof(double) * (n + 1));
			token = strtok(line, seps);
			double d = 0;
			while (token != NULL && i <= n) {
				sscanf(token, "%lf", &D[r][i]);
				//	printf("%i ", D[r][i]);
				d = D[r][i];
				V_EDGE[r] += d;
				token = strtok(NULL, seps);
				i++;
			}
			//	printf("\n");
			V_EDGE[r] /= (n - 1);
			i = 1;
		}

		fgets(line, sizeof line, file);

		//	printf("\n");

		T = (double**)malloc(sizeof(double*) * (n + 1));

		i = 1;

		for (int r = 1; r <= n; r++) {

			fgets(line, sizeof line, file);
			token = strtok(line, seps);
			T[r] = (double*)malloc(sizeof(double) * (n + 1));

			while (token != NULL && i <= n) {
				sscanf(token, "%lf", &T[r][i]);
				//	printf("%i ", T[r][i]);
				token = strtok(NULL, seps);
				i++;
			}
			//	printf("\n");
			i = 1;
		}

		fgets(line, sizeof line, file);

		//	printf("\n");

		P_D = (double**)malloc(sizeof(double*) * (p + 1));

		V_PT = (double*)calloc((n + 1), sizeof(double));

		V_PN = (int*)calloc((n + 1), sizeof(int));

		i = 1;
		int k = i;
		int v = 1;
		double currentTax = 0;
		int currentN = 0;
		for (int r = 1; r <= p; r++) {

			fgets(line, sizeof line, file);
			token = strtok(line, seps);
			P_D[r] = (double*)malloc(sizeof(double) * 5);
			while (token != NULL && i <= 4) {
				sscanf(token, "%lf", &P_D[r][i]);
				//	printf("%.1lf ", P_D[r][i]);
				token = strtok(NULL, seps);

				if (i == 3) {
					if (v != P_D[r][i]) {
						currentTax = 0;
						currentN = 0;
					}

					currentN++;
					currentTax += P_D[r][1];

					v = P_D[r][i];

					V_PN[v] = currentN;

					V_PT[v] = currentTax;

				}

				i++;

			}
			//	printf("\n");
			i = 1;
		}

		fgets(line, sizeof line, file);

		//	printf("\n");

		W = (double**)malloc(sizeof(double*) * (p + 1));

		i = 1;

		for (int r = 1; r <= p; r++) {

			fgets(line, sizeof line, file);
			token = strtok(line, seps);
			W[r] = (double*)malloc(sizeof(double) * (n + 1));

			while (token != NULL && i <= n) {
				sscanf(token, "%lf", &W[r][i]);
				//printf("%i ", W[r][i]);
				token = strtok(NULL, seps);
				i++;
			}
			//	printf("\n");
			i = 1;
		}

		//	printf("\n");

		fgets(line, sizeof line, file);
		fgets(line, sizeof line, file);

		token = strtok(line, seps);

		sscanf(line, "%lf", &Q);
		//	printf("%.1lf \n", Q);

		BONUS = (double**)malloc(sizeof(double*) * (n + 1));
		BONUS[0] = (double*)calloc(3, sizeof(double));
		for (int r = 1; r <= n; r++) {

			fgets(line, sizeof line, file);
			token = strtok(line, seps);
			BONUS[r] = (double*)malloc(sizeof(double) * 3);
			i = 0;

			while (token != NULL && i <= 2) {
				if (i != 0) {
					sscanf(token, "%lf", &BONUS[r][i]);
					//	printf("%.1lf ", BONUS[r][i]);
				}
				token = strtok(NULL, seps);
				i++;
			}
			//	printf("\n");
		}

		Instance inst;

		for (int i = 2; i <= n; i++) {
			inst.vertexByPs.push_back(i);
			inst.vertexByTax.push_back(i);
			inst.vertexByB.push_back(i);
			inst.vertexByEDGE.push_back(i);
			inst.vertexBySCORE.push_back(i);
		}

		inst.vertexByPs = InsertionSort::run(inst.vertexByPs, V_PN, n - 1);
		free(V_PN);
		inst.vertexByTax = InsertionSort::run(inst.vertexByTax, V_PT, n - 1);
		free(V_PT);
		inst.vertexByEDGE = InsertionSort::runMin(inst.vertexByEDGE, V_EDGE, n - 1);
		free(V_EDGE);
		inst.vertexByB = InsertionSort::run(inst.vertexByB, BONUS, n - 1);

		inst.n = n;
		d = n + 1;
		inst.p = p;
		inst.vertex = vector<vertex>(d);
		inst.c = c;
		inst.D = D;
		inst.W = W;
		inst.T = T;
		inst.Q = Q;
		inst.P_D = P_D;
		inst.BONUS = BONUS;
		long int seed = (unsigned)time(0);
		inst.seed = seed;
		srand(seed);
		const char * aux = "simetrico";
		inst.isSimetric = strcmp(type, aux) == 0;
		inst.isCType = strstr(fileName, "C") != NULL;
		calculateScore(&inst);
		VertexUtil::configureVertex(&inst);

		return inst;


	}

	static Instance readInstance(const char * filePath) {
		//C:\Users\Elaine\Google Drive\DTR\5 INSTANCIAS\tspPQDU

		//	printf("\n%s\n\n", filePath);

		FILE *file;

		file = fopen(filePath, "r");

		char line[10000];

		fgets(line, sizeof line, file);

		int n = 0;

		int p = 0;

		int c = 0;

		double Q = 0.0;

		double **D;

		double **W;

		double **T;

		double **P_D;

		double *V_PT;

		double *V_EDGE;

		int *V_PN;

		double **BONUS;

		char seps[] = " ";
		char *token;
		int header[4];
		int i = 1;

		token = strtok(line, seps);
		while (token != NULL) {
			sscanf(token, "%i", &header[i]);
			//printf("%i ", header[i]);
			token = strtok(NULL, seps);
			i++;
		}

		n = header[1];
		p = header[2];
		c = header[3];

		fgets(line, sizeof line, file);

		//printf("\n\n");

		D = (double**)malloc(sizeof(double*) * (n + 1));

		V_EDGE = (double*)calloc((n + 1), sizeof(double));

		i = 1;

		for (int r = 1; r <= n; r++) {

			fgets(line, sizeof line, file);
			D[r] = (double*)malloc(sizeof(double) * (n + 1));
			token = strtok(line, seps);
			double d = 0;
			while (token != NULL && i <= n) {
				sscanf(token, "%lf", &D[r][i]);
				//	printf("%i ", D[r][i]);
				d = D[r][i];
				V_EDGE[r] += d;
				token = strtok(NULL, seps);
				i++;
			}
			//	printf("\n");
			V_EDGE[r] /= (n - 1);
			i = 1;
		}

		fgets(line, sizeof line, file);

		//	printf("\n");

		T = (double**)malloc(sizeof(double*) * (n + 1));

		i = 1;

		for (int r = 1; r <= n; r++) {

			fgets(line, sizeof line, file);
			token = strtok(line, seps);
			T[r] = (double*)malloc(sizeof(double) * (n + 1));

			while (token != NULL && i <= n) {
				sscanf(token, "%lf", &T[r][i]);
				//	printf("%i ", T[r][i]);
				token = strtok(NULL, seps);
				i++;
			}
			//	printf("\n");
			i = 1;
		}

		fgets(line, sizeof line, file);

		//	printf("\n");

		P_D = (double**)malloc(sizeof(double*) * (p + 1));

		V_PT = (double*)calloc((n + 1), sizeof(double));

		V_PN = (int*)calloc((n + 1), sizeof(int));

		i = 1;
		int k = i;
		int v = 1;
		double currentTax = 0;
		int currentN = 0;
		for (int r = 1; r <= p; r++) {

			fgets(line, sizeof line, file);
			token = strtok(line, seps);
			P_D[r] = (double*)malloc(sizeof(double) * 5);
			while (token != NULL && i <= 4) {
				sscanf(token, "%lf", &P_D[r][i]);
				//	printf("%.1lf ", P_D[r][i]);
				token = strtok(NULL, seps);

				if (i == 3) {
					if (v != P_D[r][i]) {
						currentTax = 0;
						currentN = 0;
					}

					currentN++;
					currentTax += P_D[r][1];

					v = P_D[r][i];

					V_PN[v] = currentN;

					V_PT[v] = currentTax;

				}

				i++;

			}
			//	printf("\n");
			i = 1;
		}

		fgets(line, sizeof line, file);

		//	printf("\n");

		W = (double**)malloc(sizeof(double*) * (p + 1));

		i = 1;

		for (int r = 1; r <= p; r++) {

			fgets(line, sizeof line, file);
			token = strtok(line, seps);
			W[r] = (double*)malloc(sizeof(double) * (n + 1));

			while (token != NULL && i <= n) {
				sscanf(token, "%lf", &W[r][i]);
				//printf("%i ", W[r][i]);
				token = strtok(NULL, seps);
				i++;
			}
			//	printf("\n");
			i = 1;
		}

		//	printf("\n");

		fgets(line, sizeof line, file);
		fgets(line, sizeof line, file);

		token = strtok(line, seps);

		sscanf(line, "%lf", &Q);
		//	printf("%.1lf \n", Q);

		BONUS = (double**)malloc(sizeof(double*) * (n + 1));
		BONUS[0] = (double*)calloc(3, sizeof(double));
		for (int r = 1; r <= n; r++) {

			fgets(line, sizeof line, file);
			token = strtok(line, seps);
			BONUS[r] = (double*)malloc(sizeof(double) * 3);
			i = 0;

			while (token != NULL && i <= 2) {
				if (i != 0) {
					sscanf(token, "%lf", &BONUS[r][i]);
					//	printf("%.1lf ", BONUS[r][i]);
				}
				token = strtok(NULL, seps);
				i++;
			}
			//	printf("\n");
		}

		Instance inst;

		for (int i = 2; i <= n; i++) {
			inst.vertexByPs.push_back(i);
			inst.vertexByTax.push_back(i);
			inst.vertexByB.push_back(i);
			inst.vertexByEDGE.push_back(i);
			inst.vertexBySCORE.push_back(i);
		}

		inst.vertexByPs = InsertionSort::run(inst.vertexByPs, V_PN, n - 1);
		free(V_PN);
		inst.vertexByTax = InsertionSort::run(inst.vertexByTax, V_PT, n - 1);
		free(V_PT);
		inst.vertexByEDGE = InsertionSort::runMin(inst.vertexByEDGE, V_EDGE, n - 1);
		free(V_EDGE);
		inst.vertexByB = InsertionSort::run(inst.vertexByB, BONUS, n - 1);

		inst.n = n;
		d = n + 1;
		inst.p = p;
		inst.vertex = vector<vertex>(d);
		inst.c = c;
		inst.D = D;
		inst.W = W;
		inst.T = T;
		inst.Q = Q;
		inst.P_D = P_D;
		inst.BONUS = BONUS;
		long int seed = (unsigned)time(0);
		inst.seed = seed;
		srand(seed);
		inst.isSimetric = true;
		inst.isCType = strstr(filePath, "-C-") != NULL;
		calculateScore(&inst);
		VertexUtil::configureVertex(&inst);

		return inst;


	}

	static void calculateScore(Instance *inst) {

		inst->vertexSCORE = (double*)calloc(inst->n + 1, sizeof(double));
		inst->vertexBSCORE = (double*)calloc(inst->n + 1, sizeof(double));
		inst->vertexEDGESCORE = (double*)calloc(inst->n + 1, sizeof(double));
		inst->vertexTAXSCORE = (double*)calloc(inst->n + 1, sizeof(double));
		inst->vertexPsSCORE = (double*)calloc(inst->n + 1, sizeof(double));

		int k = inst->n + 1;
		int c = 20;

		for (int v : inst->vertexByB) {

			inst->vertexSCORE[v] += (k * c);
			inst->vertexBSCORE[v] += (k * c);
			inst->totalBScore += inst->vertexBSCORE[v];

			k--;

		}

		k = inst->n + 1;

		for (int v : inst->vertexByEDGE) {

			inst->vertexSCORE[v] += (k * c);
			inst->vertexEDGESCORE[v] += (k * c);
			inst->totalEDGEScore += inst->vertexEDGESCORE[v];
			k--;

		}

		k = inst->n + 1;

		for (int v : inst->vertexByTax) {

			inst->vertexSCORE[v] += (k * c);
			inst->vertexTAXSCORE[v] += (k * c);
			inst->totalTAXScore += inst->vertexTAXSCORE[v];

			k--;

		}

		k = inst->n + 1;

		for (int v : inst->vertexByPs) {

			inst->vertexSCORE[v] += (k * c);
			inst->vertexPsSCORE[v] += (k * c);

			inst->totalPsScore += inst->vertexPsSCORE[v];
			inst->totalScore += inst->vertexSCORE[v];

			k--;

		}

		inst->vertexBySCORE = InsertionSort::run(inst->vertexBySCORE, inst->vertexSCORE, inst->n - 1);

	}


};