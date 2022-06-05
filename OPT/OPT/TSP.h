#pragma once
#include "gurobi_c++.h"
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include "InstanceReader.h"
using namespace std;

class TSP{

public:

	double bestCost=0;
	int * bestTour;
	
	string indexToString(int i) {
		stringstream s;
		s << i;
		return s.str();
	}

	string indexToString(int i, int j) {
		stringstream s;
		s << i<<"_"<<j;
		return s.str();
	}

	int run(Instance inst) {

		int N = inst.n;

		int i, j;

		GRBVar **x = NULL;
		GRBEnv *env = NULL;
		GRBVar *u = NULL;

		try {

			/********************************************* INICIALIZAÇÃO *****************************************************************/

			env = new GRBEnv();

			x = new GRBVar*[N];

			u = new GRBVar[N];

			GRBModel model = GRBModel(*env);

			for (i = 0; i < N; i++) {
				x[i] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					x[i][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "x" + indexToString(i + 1, j + 1));

				}
			}


			for (i = 0; i < N; i++) {

				u[i] = model.addVar(0.0, GRB_INFINITY, 0.0, GRB_CONTINUOUS, "u" + indexToString(i + 1));

			}

			/********************************************* CONFIGURACAO DA F. OBJ E CRIAÇÃO DAS VAR. DE DECISÃO *****************************************************************/


			GRBQuadExpr obj = 0;
			GRBQuadExpr xe = 0;

			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {

					xe = (inst.D[i + 1][j + 1] * x[i][j]);

					obj += xe;

				}
			}

			model.setObjective(obj, GRB_MINIMIZE);

			/********************************************* RESTRICOES ************************************************************************************/

			for (i = 0; i < N; i++) {
				x[i][i].set(GRB_DoubleAttr_UB, 0);
			}

			//RESTRICAO 2
			for (j = 0; j < N; j++) {
				//if (j != s) {
				GRBLinExpr c = 0;
				for (i = 0; i < N; i++) {
					if (i != j) {
						c += x[i][j];
					}
				}
				model.addConstr(c == 1, "cicloIda" + indexToString(j + 1));
				//}
			}

			//RESTRICAO 3
			for (j = 0; j < N; j++) {
				//if (j != s) {
				GRBLinExpr c = 0;
				for (i = 0; i < N; i++) {
					if (i != j) {
						c += x[j][i];
					}
				}
				model.addConstr(c == 1, "cicloVolta" + indexToString(j + 1));
				//}
			}

			//RESTRICAO 4
			GRBLinExpr c = 0;
			GRBLinExpr c1 = 0;
			for (i = 1; i < N; i++) {
				for (j = 1; j < N; j++) {

					if (j != i) {
						c = 0;
						c += u[i] - u[j] + 1;
						model.addConstr(c <= N * (1 - x[i][j]), "evitarSubCiclo" + indexToString(i + 1, j + 1));
					}
				}
			}

			if (true) {

				model.optimize();
				if (model.get(GRB_IntAttr_SolCount) > 0)
					bestCost = model.get(GRB_DoubleAttr_ObjVal);
				model.update();
				model.write("model_tsp.lp");
				model.write("solution_tsp.sol");
				//cout << "Obj: " << model.get(GRB_DoubleAttr_ObjVal) << endl;
				//printTour(model, inst, cb, x);
			}

		}
		catch (GRBException e) {
			cout << "Error number: " << e.getErrorCode() << endl;
			cout << e.getMessage() << endl;
		}
		catch (...) {
			cout << "Error during optimization" << endl;
		}

		delete[] x;
		delete env;
		delete u;

		return 0;
	}

	

};