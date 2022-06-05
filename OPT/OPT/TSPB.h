#pragma once
#include "gurobi_c++.h"
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include "InstanceReader.h"
using namespace std;

class TSPB {

public:

	static string indexToString(int i) {
		stringstream s;
		s << i;
		return s.str();
	}

	static string indexToString(int i, int j) {
		stringstream s;
		s << i << "_" << j;
		return s.str();
	}

	static string indexToString(int l, int i, int j) {
		stringstream s;
		s << l << "_" << i << "_" << j;
		return s.str();
	}

	static int** optimize(Instance inst) {

		int N = inst.n;
		int R = inst.c;
		int L = inst.p;

		int i, l, j, a;

		int s = 0;

		int ** tour = (int**) calloc(inst.n+1, sizeof(int*));

		for (i = 0; i < N+1; i++) {

			tour[i] = (int*) calloc(inst.n+1, sizeof(int));

		}

		GRBVar **x = new GRBVar*[N];

		try {

			/********************************************* INICIALIZAÇÃO *****************************************************************/

			GRBEnv *env = new GRBEnv();

			GRBModel model = GRBModel(*env);

			GRBVar *u = new GRBVar[N];
			GRBVar *p = new GRBVar[N];

			for (i = 0; i < N; i++) {

				u[i] = model.addVar(0.0, N - 1, 0.0, GRB_INTEGER, "u" + indexToString(i + 1));
				p[i] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "p" + indexToString(i + 1));
			
			}

			for (i = 0; i < N; i++) {
				x[i] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					x[i][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "x" + indexToString(i + 1, j + 1));

				}
			}

			/********************************************* CONFIGURACAO DA F. OBJ *****************************************************************/

			GRBQuadExpr obj = 0;
			GRBQuadExpr xe = 0;
			GRBQuadExpr ve = 0;

			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {

					xe = (inst.D[i + 1][j + 1] * x[i][j]);

					obj += xe;

				}
			}

			model.setObjective(obj, GRB_MINIMIZE);

			/********************************************* RESTRICOES ************************************************************************************/
			GRBLinExpr c = 0;
			GRBLinExpr c1 = 0;
			GRBQuadExpr qc = 0;
			GRBQuadExpr qc1 = 0;

			for (i = 0; i < N; i++) {
				x[i][i].set(GRB_DoubleAttr_UB, 0);
			}

			u[s].set(GRB_DoubleAttr_UB, 0);
			p[s].set(GRB_DoubleAttr_UB, 0);

			//RESTRICAO 2
			for (j = 0; j < N; j++) {
				if (j != s) {
					GRBLinExpr c = 0;
					for (i = 0; i < N; i++) {
						if (i != j) {
							c += x[i][j];
						}
					}
					model.addConstr(c <= 1, "rest2_cicloIda" + indexToString(j + 1));
				}
			}

			//RESTRICAO 3
			for (j = 0; j < N; j++) {
				if (j != s) {
					GRBLinExpr c = 0;
					for (i = 0; i < N; i++) {
						if (i != j) {
							c += x[j][i];
						}
					}
					model.addConstr(c <= 1, "rest3_cicloVolta" + indexToString(j + 1));
				}
			}

			//RESTRICAO 4
			GRBLinExpr o1 = 0;
			for (i = 0; i < N; i++)
				if (i != s)
					o1 += x[s][i];
			model.addConstr(o1 == 1, "rest4_origemEm1");

			//RESTRICAO 5
			GRBLinExpr d1 = 0;
			for (i = 0; i < N; i++)
				if (i != s)
					d1 += x[i][s];
			model.addConstr(d1 == 1, "rest5_destinoEm1");

			//RESTRICAO 6
			for (j = 0; j < N; j++) {
				if (j != s) {
					c = 0;
					c1 = 0;

					for (i = 0; i < N; i++)
						if (i != j)
							c += x[i][j];

					for (i = 0; i < N; i++)
						if (i != j)
							c1 += x[j][i];

					model.addConstr(c - c1 == 0, "rest6_idaVolta" + indexToString(j + 1));

				}
			}

			//RESTRICAO 7

			for (i = 1; i < N; i++) {
				for (j = 1; j < N; j++) {

					if (j != i) {
						c = u[i] - u[j] + x[i][j] * (N - 1);
						model.addConstr(c <= N - 2, "rest7_evitarSubCiclo" + indexToString(i + 1, j + 1));
					}

				}
			}

			//RESTRICAO 8
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					qc += inst.BONUS[i + 1][1] * p[i] * x[i][j];
				}
			}

			model.addQConstr(qc >= inst.Q, "rest8_bonusMinimo");

			//***************************** RESOLUCAO *****************************************//
			model.optimize();
			system("cls");
			if (model.get(GRB_IntAttr_SolCount) > 0) {

				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++)
						if (i != j && x[i][j].get(GRB_DoubleAttr_X) > 0.8) {
							
							tour[i][j] = 1;
							cout << "x_" << indexToString(i + 1, j + 1) << " : "<< x[i][j].get(GRB_DoubleAttr_X) <<"\n";
						}
				}

				//cout << "\n";
			}
			delete(p);
			delete(u);
			for (int i = 0; i < inst.n; i++)
				delete(x[i]);
			delete(x);
			//delete(env);
		}
		catch (GRBException e) {
			cout << "Error number: " << e.getErrorCode() << endl;
			cout << e.getMessage() << endl;
		}
		catch (...) {
			cout << "Error during optimization" << endl;
		}

		return tour;
	}

};
