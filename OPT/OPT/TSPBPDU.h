#pragma once
#include "gurobi_c++.h"
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include "InstanceReader.h"
#include "Solution.h"
using namespace std;

class TSPBPDU {

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

	static int optimizeMiniModel(Instance inst) {

		int N = inst.n;
		int R = inst.c;
		int L = inst.p;

		int i, l, j, a;

		int s = 0;

		try {

			/********************************************* INICIALIZACAO *****************************************************************/

			GRBEnv *env = new GRBEnv();

			GRBModel model = GRBModel(*env);

			GRBVar *u = new GRBVar[N];
			GRBVar *q = new GRBVar[L];
			GRBVar *p = new GRBVar[N];

			GRBVar **taxaRateio = new GRBVar*[N];
			GRBVar **x = new GRBVar*[N];
			GRBVar **f = new GRBVar*[inst.p];

			GRBVar ***v = new GRBVar**[inst.p];

			for (i = 0; i < N; i++) {
				x[i] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					x[i][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "x" + indexToString(i + 1, j + 1));

				}
			}

			for (i = 0; i < N; i++) {

				u[i] = model.addVar(0.0, N - 1, 0.0, GRB_INTEGER, "u" + indexToString(i + 1));

			}

			for (i = 0; i < N; i++) {
				taxaRateio[i] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					taxaRateio[i][j] = model.addVar(0.0, 1.0, 0.0, GRB_CONTINUOUS, "taxaRateio" + indexToString(i + 1, j + 1));

				}
			}

			for (i = 0; i < N; i++) {

				p[i] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "p" + indexToString(i + 1));

			}

			for (l = 0; l < L; l++) {

				q[l] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "q" + indexToString(l + 1));

			}

			for (l = 0; l < L; l++) {
				f[l] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					f[l][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "f" + indexToString(l + 1, j + 1));

				}
			}


			for (l = 0; l < L; l++) {
				v[l] = new GRBVar*[inst.n];
				for (i = 0; i < N; i++) {
					v[l][i] = new GRBVar[N];
					for (j = 0; j < N; j++) {

						v[l][i][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "v" + indexToString(l + 1, i + 1, j + 1));

					}
				}
			}


			/********************************************* CONFIGURACAO DA F. OBJ *****************************************************************/

			GRBQuadExpr obj = 0;
			GRBQuadExpr xe = 0;

			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {

					xe = inst.D[i + 1][j + 1] * x[i][j] * taxaRateio[i][j];

					obj += xe;

				}
			}

			for (l = 0; l < inst.p; l++) {
				for (j = 0; j < N; j++) {

					xe = (inst.W[l + 1][j + 1] * f[l][j]);

					obj += xe;

				}
			}

			model.setObjective(obj, GRB_MINIMIZE);

			/********************************************* RESTRICOES ************************************************************************************/
			GRBLinExpr constraint = 0;
			GRBLinExpr constraintAUX = 0;
			GRBQuadExpr quadConstraint = 0;
			GRBQuadExpr quadConstraintAUX = 0;

			for (i = 0; i < N; i++) {
				x[i][i].set(GRB_DoubleAttr_UB, 0);
				taxaRateio[i][i].set(GRB_DoubleAttr_UB, 0);
			}

			u[s].set(GRB_DoubleAttr_UB, 0);
			p[s].set(GRB_DoubleAttr_UB, 0);

			/****************************************************************** CAIXEIRO ****************************************************************************/

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
					constraint = 0;
					constraintAUX = 0;

					for (i = 0; i < N; i++)
						if (i != j)
							constraint += x[i][j];

					for (i = 0; i < N; i++)
						if (i != j)
							constraintAUX += x[j][i];

					model.addConstr(constraint - constraintAUX == 0, "rest6_idaVolta" + indexToString(j + 1));

				}
			}

			//RESTRICAO 7
			for (i = 1; i < N; i++) {
				for (j = 1; j < N; j++) {

					if (j != i) {
						constraint = 0;
						constraint += u[i] - u[j] + x[i][j] * (N - 1);
						model.addConstr(constraint <= N - 2, "rest7_evitarSubCiclo" + indexToString(i + 1, j + 1));
					}

				}
			}

			/****************************************************************** BONUS ****************************************************************************/

			//RESTRICAO 8
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					quadConstraint += inst.BONUS[i + 1][1] * p[i] * x[i][j];
				}
			}
			model.addQConstr(quadConstraint >= inst.Q, "rest8_bonusMinimo");

			/****************************************************************** PASSAGEIRO ****************************************************************************/

			//RESTRICAO 9
			for (l = 0; l < L; l++) {

				quadConstraint = 0;

				for (i = 0; i < N; i++) {

					for (j = 0; j < N; j++) {

						quadConstraint += v[l][i][j] * inst.T[i + 1][j + 1] + p[i] * inst.BONUS[i + 1][2] * v[l][i][j];

					}


				}

				model.addQConstr(quadConstraint <= inst.P_D[l + 1][2], "rest9_tempoLimitePassageiro" + indexToString(l + 1));

			}

			//RESTRICAO 10
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (i != j) {
						constraint = 0;
						for (l = 0; l < L; l++) {
							constraint += v[l][i][j];
						}
						model.addConstr(constraint <= inst.c*x[i][j], "rest10_carroCapPassandoPelaAresta" + indexToString(i + 1, j + 1));
					}
				}
			}

			//RESTRICAO 11
			for (l = 0; l < L; l++) {
				quadConstraint = 0;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++) {
						quadConstraint += v[l][i][j] * inst.D[i + 1][j + 1] * taxaRateio[i][j];
					}
				}

				model.addQConstr(quadConstraint <= inst.P_D[l + 1][1], "rest11_tarifaMaxPassageiro" + indexToString(l + 1));

			}


			//RESTRICAO 16
			for (int l = 0; l < L; l++) {
				constraint = 0;
				for (int j = 0; j < N; j++) {
					constraint += f[l][j];
				}
				model.addConstr(constraint <= 1, "rest16_passageiroDesembarcaSoUmaVez" + indexToString(l + 1));
			}

			//RESTRICAO 18
			constraint = 0;

			for (l = 0; l < L; l++) {

				constraint += f[l][s];

			}

			constraintAUX = 0;

			for (int l = 0; l < L; l++) {
				for (int j = 0; j < N; j++) {
					if (j != s)
						constraintAUX += v[l][j][s];
				}

			}

			model.addConstr(constraint == constraintAUX, "rest18_obrigaQuemEstiverChegandoEm1Desembarcar");


			//******************************************************** NOVAS **********************************************************

			//RESTRICAO A - CALCULO DA TAXA DE RATEIO
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {

					if (i != j) {
						constraint = 1;
						for (l = 0; l < L; l++) {
							constraint += v[l][i][j];
						}
						model.addQConstr((constraint)* taxaRateio[i][j] == 1.0, "restA_quantidadeDePassageirosNaAresta" + indexToString(i + 1, j + 1));
					}

				}
			}

			//RESTRICAO B
			for (l = 0; l < L; l++) {
				//inst.P_D[l + 1][3]-1 e igual a origem do passageiro l o qual vc vai colocar no teu formato
				//l+1 ? pq a na minha instancia, os elemtnos s?o indexados de 1 a N, e aqui de 0 a N-1
				//Mesmo pensamento para justificar [3]-1
				constraint = f[l][(int)inst.P_D[l + 1][3] - 1];
				model.addConstr(constraint == 0, "restB_passageiroNaoDesembarcaNaSuaOrigem" + indexToString(l + 1));

			}

			//RESTRICAO C
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (i != j) {
						for (l = 0; l < L; l++) {
							model.addConstr(v[l][i][j] <= x[i][j], "restC_soPassaPassageiroPorOndePassaVeiculo" + indexToString(l + 1, i + 1, j + 1));
						}
					}
				}
			}

			//RESTRICAO D 
			for (l = 0; l < L; l++) {
				for (j = 0; j < N; j++) {
					constraint = 0;
					for (i = 0; i < N; i++) {
						if (i != j) {
							constraint += v[l][i][j];
						}
					}
					model.addConstr(constraint == f[l][j], "restD_PassageiroDesembarcaConformeValorDeF" + indexToString(l + 1, j + 1));
				}
			}

			//RESTRICAO E
			for (l = 0; l < L; l++) {

				constraint = 0;

				for (j = 0; j < N; j++) {
					constraint += f[l][j];
				}

				model.addConstr(constraint - q[l] == 0, "restE_SePassageiroEmbarcaEntaoForcaDesembarque" + indexToString(l + 1));

			}

			//RESTRICAO F
			for (l = 0; l < L; l++) {

				int i = inst.P_D[l + 1][3] - 1;

				constraint = 0;

				for (j = 0; j < N; j++) {
					if (i != j) {
						constraint += v[l][i][j];
					}
				}

				constraint -= q[l];

				model.addConstr(constraint == 0, "restF_PassageiroEhEmbarcadoApenasNaOrigem" + indexToString(l + 1));

			}

			model.optimize();

			if (model.get(GRB_IntAttr_SolCount) > 0) {
				//bestCost = model.get(GRB_DoubleAttr_ObjVal);
				//system("cls");
				model.write("solution_tspbpdu.sol");
				cout << "INSTNACIA: " << inst.n << " " << inst.p << " " << inst.c << endl;
				cout << "\n******************** x *****************************" << endl;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++)
						if (i != j && x[i][j].get(GRB_DoubleAttr_X) > 0)
							cout << "x_" << (i + 1) << "_" << (j + 1) << " = " << x[i][j].get(GRB_DoubleAttr_X) << endl;
				}
				cout << "******************** Passageiros Por Aresta *****************************" << endl;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++)
						if (i != j && taxaRateio[i][j].get(GRB_DoubleAttr_X) < 0.9) {
							double qtd = (1 / taxaRateio[i][j].get(GRB_DoubleAttr_X));
							cout << "pessoasDentroDoCarro_" << (i + 1) << "_" << (j + 1) << " = " << qtd << "(" << taxaRateio[i][j].get(GRB_DoubleAttr_X) << ")\n";
						}
				}
				cout << "******************** p *****************************" << endl;
				for (i = 0; i < N; i++) {
					if (p[i].get(GRB_DoubleAttr_X) > 0)
						cout << "p" << (i + 1) << " = " << p[i].get(GRB_DoubleAttr_X) << endl;
				}
				cout << "******************** q *****************************" << endl;
				for (l = 0; l < L; l++) {
					if (q[l].get(GRB_DoubleAttr_X) > 0)
						cout << "q" << (l + 1) << " = " << q[l].get(GRB_DoubleAttr_X) << endl;
				}
				cout << "******************** f *****************************" << endl;
				for (l = 0; l < L; l++)
					for (j = 0; j < N; j++) {
						if (f[l][j].get(GRB_DoubleAttr_X) > 0)
							cout << "f_" << (l + 1) << "_" << (j + 1) << " = " << f[l][j].get(GRB_DoubleAttr_X) << endl;
					}
				cout << "******************** v *****************************" << endl;
				for (l = 0; l < L; l++) {
					for (i = 0; i < N; i++) {
						for (j = 0; j < N; j++) {
							if (v[l][i][j].get(GRB_DoubleAttr_X) > 0) {
								cout << "Passageiro" << (l + 1) << " | O: " << inst.P_D[l + 1][3] << " | D: " << inst.P_D[l + 1][4] << "\n";
								cout << "v_" << (l + 1) << "_" << (i + 1) << "_" << (j + 1) << " = " << v[l][i][j].get(GRB_DoubleAttr_X) << endl;
							}
						}
					}
				}
				cout << "******************** SOLUCAO *****************************\n" << endl;
				//cout << "Z: " << bestCost << "\n\n";
			}

		}
		catch (GRBException e) {
			cout << "Error number: " << e.getErrorCode() << endl;
			cout << e.getMessage() << endl;
		}
		catch (...) {
			cout << "Error during optimization" << endl;
		}

		return 0;
	}

	static int optimize(Instance inst) {

		int N = inst.n;
		int R = inst.c;
		int L = inst.p;

		int i, l, j, a;

		int s = 0;

		try {

			/********************************************* INICIALIZACAO *****************************************************************/

			GRBEnv *env = new GRBEnv();

			GRBModel model = GRBModel(*env);

			model.getEnv().set(GRB_DoubleParam_TimeLimit, 5000);

			GRBVar *u = new GRBVar[N];
			GRBVar *q = new GRBVar[L];
			GRBVar *p = new GRBVar[N];

			GRBVar **taxaRateio = new GRBVar*[N];
			GRBVar **x = new GRBVar*[N];
			GRBVar **f = new GRBVar*[inst.p];

			GRBVar ***v = new GRBVar**[inst.p];

			for (i = 0; i < N; i++) {
				x[i] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					x[i][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "x" + indexToString(i + 1, j + 1));

				}
			}

			for (i = 0; i < N; i++) {

				u[i] = model.addVar(0.0, N - 1, 0.0, GRB_INTEGER, "u" + indexToString(i + 1));

			}

			for (i = 0; i < N; i++) {
				taxaRateio[i] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					taxaRateio[i][j] = model.addVar(0.0, 1.0, 0.0, GRB_CONTINUOUS, "taxaRateio" + indexToString(i + 1, j + 1));

				}
			}

			for (i = 0; i < N; i++) {

				p[i] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "p" + indexToString(i + 1));

			}

			for (l = 0; l < L; l++) {

				q[l] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "q" + indexToString(l + 1));

			}

			for (l = 0; l < L; l++) {
				f[l] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					f[l][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "f" + indexToString(l + 1, j + 1));

				}
			}


			for (l = 0; l < L; l++) {
				v[l] = new GRBVar*[inst.n];
				for (i = 0; i < N; i++) {
					v[l][i] = new GRBVar[N];
					for (j = 0; j < N; j++) {

						v[l][i][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "v" + indexToString(l + 1, i + 1, j + 1));

					}
				}
			}


			/********************************************* CONFIGURACAO DA F. OBJ *****************************************************************/

			GRBQuadExpr obj = 0;
			GRBQuadExpr xe = 0;

			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {

					xe = inst.D[i + 1][j + 1] * x[i][j] * taxaRateio[i][j];

					obj += xe;

				}
			}

			for (l = 0; l < inst.p; l++) {
				for (j = 0; j < N; j++) {

					xe = (inst.W[l + 1][j + 1] * f[l][j]);

					obj += xe;

				}
			}

			model.setObjective(obj, GRB_MINIMIZE);

			/********************************************* RESTRICOES ************************************************************************************/
			GRBLinExpr constraint = 0;
			GRBLinExpr constraintAUX = 0;
			GRBQuadExpr quadConstraint = 0;
			GRBQuadExpr quadConstraintAUX = 0;

			for (i = 0; i < N; i++) {
				x[i][i].set(GRB_DoubleAttr_UB, 0);
				taxaRateio[i][i].set(GRB_DoubleAttr_UB, 0);
			}

			u[s].set(GRB_DoubleAttr_UB, 0);
			p[s].set(GRB_DoubleAttr_UB, 0);

			/****************************************************************** CAIXEIRO ****************************************************************************/

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
					constraint = 0;
					constraintAUX = 0;

					for (i = 0; i < N; i++)
						if (i != j)
							constraint += x[i][j];

					for (i = 0; i < N; i++)
						if (i != j)
							constraintAUX += x[j][i];

					model.addConstr(constraint - constraintAUX == 0, "rest6_idaVolta" + indexToString(j + 1));

				}
			}

			//RESTRICAO 7
			for (i = 1; i < N; i++) {
				for (j = 1; j < N; j++) {

					if (j != i) {
						constraint = 0;
						constraint += u[i] - u[j] + x[i][j] * (N - 1);
						model.addConstr(constraint <= N - 2, "rest7_evitarSubCiclo" + indexToString(i + 1, j + 1));
					}

				}
			}

			/****************************************************************** BONUS ****************************************************************************/

			//RESTRICAO 8
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					quadConstraint += inst.BONUS[i + 1][1] * p[i] * x[i][j];
				}
			}
			model.addQConstr(quadConstraint >= inst.Q, "rest8_bonusMinimo");

			/****************************************************************** PASSAGEIRO ****************************************************************************/

			//RESTRICAO 9
			for (l = 0; l < L; l++) {

				quadConstraint = 0;

				for (i = 0; i < N; i++) {

					for (j = 0; j < N; j++) {

						quadConstraint += v[l][i][j] * inst.T[i + 1][j + 1] + p[i] * inst.BONUS[i + 1][2] * v[l][i][j];

					}


				}

				model.addQConstr(quadConstraint <= inst.P_D[l + 1][2], "rest9_tempoLimitePassageiro" + indexToString(l + 1));

			}

			//RESTRICAO 10
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (i != j) {
						constraint = 0;
						for (l = 0; l < L; l++) {
							constraint += v[l][i][j];
						}
						model.addConstr(constraint <= inst.c*x[i][j], "rest10_carroCapPassandoPelaAresta" + indexToString(i + 1, j + 1));
					}
				}
			}

			//RESTRICAO 11
			for (int l = 0; l < L; l++) {
				constraint = 0;
				for (int j = 0; j < N; j++) {
					constraint += f[l][j];
				}
				model.addConstr(constraint <= 1, "rest11_passageiroDesembarcaSoUmaVez" + indexToString(l + 1));
			}

			//RESTRICAO 12
			for (l = 0; l < L; l++) {
				quadConstraint = 0;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++) {
						quadConstraint += v[l][i][j] * inst.D[i + 1][j + 1] * taxaRateio[i][j];
					}
				}

				model.addQConstr(quadConstraint <= inst.P_D[l + 1][1], "rest12_tarifaMaxPassageiro" + indexToString(l + 1));

			}

			//REST 13
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {

					if (i != j) {
						constraint = 1;
						for (l = 0; l < L; l++) {
							constraint += v[l][i][j];
						}
						model.addQConstr((constraint)* taxaRateio[i][j] == 1.0, "rest13_quantidadeDePassageirosNaAresta" + indexToString(i + 1, j + 1));
					}

				}
			}

			//REST 14
			for (l = 0; l < L; l++) {
				constraint = f[l][(int)inst.P_D[l + 1][3] - 1];
				model.addConstr(constraint == 0, "rest14_passageiroNaoDesembarcaNaSuaOrigem" + indexToString(l + 1));

			}

			//REST 15
			for (l = 0; l < L; l++) {
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++) {
						model.addConstr(v[l][i][j] <= q[l], "rest15_soPassaPassageiroPorOndePassaVeiculo" + indexToString(l + 1, i + 1, j + 1));
					}
				}
			}

			//REST 16
			for (int l = 0; l < L; l++) {

				for (int j = 0; j < N; j++) {
					if (j != inst.P_D[l + 1][3] - 1) {

						quadConstraint = 0;

						for (int i = 0; i < N; i++) {
							if (i != j) {
								quadConstraint += v[l][i][j];
							}
						}

						for (int i = 0; i < N; i++) {
							if (i != j) {
								quadConstraint -= v[l][j][i];
							}

						}

						model.addQConstr(quadConstraint == f[l][j], "rest16_passageiroEmbarcadoProssegueEmbarcado" + indexToString(l + 1, j + 1));

					}
				}
			}

			//RESTRICAO 17
			for (l = 0; l < L; l++) {

				constraint = 0;

				for (j = 0; j < N; j++) {
					constraint += f[l][j];
				}

				model.addConstr(constraint - q[l] == 0, "rest17_SePassageiroEmbarcaEntaoForcaDesembarque" + indexToString(l + 1));

			}

			//RESTRICAO 18
			for (l = 0; l < L; l++) {

				int i = inst.P_D[l + 1][3] - 1;

				constraint = 0;

				for (j = 0; j < N; j++) {
					if (i != j) {
						constraint += v[l][i][j];
					}
				}

				model.addConstr(constraint == q[l], "rest18_PassageiroEhEmbarcadoApenasNaOrigem" + indexToString(l + 1));

			}

			//REST 19
			for (int l = 0; l < L; l++) {
				for (int i = 0; i < N; i++) {
					constraint = f[l][i];

					for (int j = 0; j < N; j++) {
						constraint += v[l][i][j];
					}

					model.addConstr(constraint <= 1, "rest19_passageiroEmbarcadoNaoDesembarcaDeNovo" + indexToString(l + 1, i + 1));

				}
			}

			//RESTRICAO 20
			for (l = 0; l < L; l++) {

				int j = inst.P_D[l + 1][3] - 1;

				constraint = 0;

				for (i = 0; i < N; i++) {
					constraint += v[l][i][j];
				}

				model.addConstr(constraint == 0, "rest20_PassageiroEhEmbarcadoApenasNaOrigem" + indexToString(l + 1));

			}

			//RESTRICAO 21
			constraint = 0;

			for (l = 0; l < L; l++) {

				constraint = 0;

				for (int j = 0; j < N; j++) {
					if (j != s)
						constraint += v[l][j][s];
				}

				model.addConstr(constraint == f[l][s], "rest21_obrigaQuemEstiverChegandoEm1Desembarcar");

			}


			//REST 22

			constraint = 0;

			for (l = 0; l < L; l++) {
				if (s == (int)inst.P_D[l + 1][3] - 1) {
					constraint += q[l];
				}
			}

			constraintAUX = 0;

			for (l = 0; l < L; l++) {
				for (int j = 0; j < N; j++) {
					constraintAUX += v[l][s][j];
				}
			}

			//model.addConstr(constraint <= constraintAUX, "rest22_garantiaQueSoEmbarcaEmSPassageirosDoVerticeS" + indexToString(i + 1));

			model.optimize();

			model.write("MODEL.lp");

			if (model.get(GRB_IntAttr_SolCount) > 0) {
				float bestCost = model.get(GRB_DoubleAttr_ObjVal);
				system("cls");
				cout << "INSTNACIA: " << inst.n << " " << inst.p << " " << inst.c << endl;
				cout << "\n******************** x *****************************" << endl;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++)
						if (i != j && x[i][j].get(GRB_DoubleAttr_X) > 0)
							cout << "x_" << (i + 1) << "_" << (j + 1) << " = " << x[i][j].get(GRB_DoubleAttr_X) << endl;
				}
				cout << "******************** Passageiros Por Aresta *****************************" << endl;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++)
						if (i != j && taxaRateio[i][j].get(GRB_DoubleAttr_X) < 0.7) {
							double qtd = (1 / taxaRateio[i][j].get(GRB_DoubleAttr_X));
							cout << "pessoasDentroDoCarro_" << (i + 1) << "_" << (j + 1) << " = " << qtd << "(" << taxaRateio[i][j].get(GRB_DoubleAttr_X) << ")\n";
						}
				}
				cout << "******************** p *****************************" << endl;
				for (i = 0; i < N; i++) {
					if (p[i].get(GRB_DoubleAttr_X) > 0)
						cout << "p" << (i + 1) << " = " << p[i].get(GRB_DoubleAttr_X) << endl;
				}
				cout << "******************** q *****************************" << endl;
				for (l = 0; l < L; l++) {
					if (q[l].get(GRB_DoubleAttr_X) > 0)
						cout << "q" << (l + 1) << " = " << q[l].get(GRB_DoubleAttr_X) << endl;
				}
				cout << "******************** f *****************************" << endl;
				for (l = 0; l < L; l++)
					for (j = 0; j < N; j++) {
						if (f[l][j].get(GRB_DoubleAttr_X) > 0)
							cout << "f_" << (l + 1) << "_" << (j + 1) << " = " << f[l][j].get(GRB_DoubleAttr_X) << endl;
					}
				cout << "******************** v *****************************" << endl;
				for (l = 0; l < L; l++) {
					for (i = 0; i < N; i++) {
						for (j = 0; j < N; j++) {
							if (v[l][i][j].get(GRB_DoubleAttr_X) > 0) {
								cout << "Passageiro" << (l + 1) << " | O: " << inst.P_D[l + 1][3] << " | D: " << inst.P_D[l + 1][4] << "\n";
								cout << "v_" << (l + 1) << "_" << (i + 1) << "_" << (j + 1) << " = " << v[l][i][j].get(GRB_DoubleAttr_X) << endl;
							}
						}
					}
				}
				cout << "******************** SOLUCAO *****************************\n" << endl;
				cout << "Z: " << bestCost << "\n\n";
			}

		}
		catch (GRBException e) {
			cout << "Error number: " << e.getErrorCode() << endl;
			cout << e.getMessage() << endl;
		}
		catch (...) {
			cout << "Error during optimization" << endl;
		}

		return 0;
	}

	static double optimize(int** tour, Instance inst) {

		int N = inst.n;
		int R = inst.c;
		int L = inst.p;

		int i, l, j, a;

		int s = 0;

		try {

			/********************************************* INICIALIZACAO *****************************************************************/

			GRBEnv *env = new GRBEnv();

			GRBModel model = GRBModel(*env);

			model.getEnv().set(GRB_DoubleParam_TimeLimit, 88000);

			GRBVar *u = new GRBVar[N];
			GRBVar *q = new GRBVar[L];
			GRBVar *p = new GRBVar[N];

			GRBVar **taxaRateio = new GRBVar*[N];
			GRBVar **x = new GRBVar*[N];
			GRBVar **f = new GRBVar*[inst.p];

			GRBVar ***v = new GRBVar**[inst.p];

			for (i = 0; i < N; i++) {
				x[i] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					x[i][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "x" + indexToString(i + 1, j + 1));

				}
			}

			for (i = 0; i < N; i++) {

				u[i] = model.addVar(0.0, N - 1, 0.0, GRB_INTEGER, "u" + indexToString(i + 1));

			}

			for (i = 0; i < N; i++) {
				taxaRateio[i] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					taxaRateio[i][j] = model.addVar(0.0, 1.0, 0.0, GRB_CONTINUOUS, "taxaRateio" + indexToString(i + 1, j + 1));

				}
			}

			for (i = 0; i < N; i++) {

				p[i] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "p" + indexToString(i + 1));

			}

			for (l = 0; l < L; l++) {

				q[l] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "q" + indexToString(l + 1));

			}

			for (l = 0; l < L; l++) {
				f[l] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					f[l][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "f" + indexToString(l + 1, j + 1));

				}
			}


			for (l = 0; l < L; l++) {
				v[l] = new GRBVar*[inst.n];
				for (i = 0; i < N; i++) {
					v[l][i] = new GRBVar[N];
					for (j = 0; j < N; j++) {

						v[l][i][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "v" + indexToString(l + 1, i + 1, j + 1));

					}
				}
			}


			/********************************************* CONFIGURACAO DA F. OBJ *****************************************************************/

			GRBQuadExpr obj = 0;
			GRBQuadExpr xe = 0;

			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {

					xe = inst.D[i + 1][j + 1] * x[i][j] * taxaRateio[i][j];

					obj += xe;

				}
			}

			for (l = 0; l < inst.p; l++) {
				for (j = 0; j < N; j++) {

					xe = (inst.W[l + 1][j + 1] * f[l][j]);

					obj += xe;

				}
			}

			model.setObjective(obj, GRB_MINIMIZE);

			/********************************************* RESTRICOES ************************************************************************************/
			GRBLinExpr constraint = 0;
			GRBLinExpr constraintAUX = 0;
			GRBQuadExpr quadConstraint = 0;
			GRBQuadExpr quadConstraintAUX = 0;

			for (i = 0; i < N; i++) {
				x[i][i].set(GRB_DoubleAttr_UB, 0);
				taxaRateio[i][i].set(GRB_DoubleAttr_UB, 0);
			}

			u[s].set(GRB_DoubleAttr_UB, 0);
			p[s].set(GRB_DoubleAttr_UB, 0);

			/****************************************************************** CAIXEIRO ****************************************************************************/

			//RESTRICAO NAIVE
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {

					if (j != i && tour[i][j] == 1) {
						model.addConstr(x[i][j] == 1, "restNaive" + indexToString(i + 1, j + 1));
					}
					else
						model.addConstr(x[i][j] == 0, "restNaive" + indexToString(i + 1, j + 1));
				}
			}
			cout << "\n\n ";

			/****************************************************************** BONUS ****************************************************************************/

			//RESTRICAO 8
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					quadConstraint += inst.BONUS[i + 1][1] * p[i] * x[i][j];
				}
			}
			model.addQConstr(quadConstraint >= inst.Q, "rest8_bonusMinimo");

			/****************************************************************** PASSAGEIRO ****************************************************************************/

			//RESTRICAO 9
			for (l = 0; l < L; l++) {

				quadConstraint = 0;

				for (i = 0; i < N; i++) {

					for (j = 0; j < N; j++) {

						quadConstraint += v[l][i][j] * inst.T[i + 1][j + 1] + p[i] * inst.BONUS[i + 1][2] * v[l][i][j];

					}


				}

				model.addQConstr(quadConstraint <= inst.P_D[l + 1][2], "rest9_tempoLimitePassageiro" + indexToString(l + 1));

			}

			//RESTRICAO 10
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (i != j) {
						constraint = 0;
						for (l = 0; l < L; l++) {
							constraint += v[l][i][j];
						}
						model.addConstr(constraint <= inst.c*x[i][j], "rest10_carroCapPassandoPelaAresta" + indexToString(i + 1, j + 1));
					}
				}
			}

			//RESTRICAO 11
			for (int l = 0; l < L; l++) {
				constraint = 0;
				for (int j = 0; j < N; j++) {
					constraint += f[l][j];
				}
				model.addConstr(constraint <= 1, "rest11_passageiroDesembarcaSoUmaVez" + indexToString(l + 1));
			}

			//RESTRICAO 12
			for (l = 0; l < L; l++) {
				quadConstraint = 0;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++) {
						quadConstraint += v[l][i][j] * inst.D[i + 1][j + 1] * taxaRateio[i][j];
					}
				}

				model.addQConstr(quadConstraint <= inst.P_D[l + 1][1], "rest12_tarifaMaxPassageiro" + indexToString(l + 1));

			}

			//REST 13
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {

					if (i != j) {
						constraint = 1;
						for (l = 0; l < L; l++) {
							constraint += v[l][i][j];
						}
						model.addQConstr((constraint)* taxaRateio[i][j] == 1.0, "rest13_quantidadeDePassageirosNaAresta" + indexToString(i + 1, j + 1));
					}

				}
			}

			//REST 14
			for (l = 0; l < L; l++) {
				constraint = f[l][(int)inst.P_D[l + 1][3] - 1];
				model.addConstr(constraint == 0, "rest14_passageiroNaoDesembarcaNaSuaOrigem" + indexToString(l + 1));

			}

			//REST 15
			for (l = 0; l < L; l++) {
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++) {
						model.addConstr(v[l][i][j] <= q[l], "rest15_soPassaPassageiroPorOndePassaVeiculo" + indexToString(l + 1, i + 1, j + 1));
					}
				}
			}

			//REST 16
			for (int l = 0; l < L; l++) {

				for (int j = 0; j < N; j++) {
					if (j != inst.P_D[l + 1][3] - 1) {

						quadConstraint = 0;

						for (int i = 0; i < N; i++) {
							if (i != j) {
								quadConstraint += v[l][i][j];
							}
						}

						for (int i = 0; i < N; i++) {
							if (i != j) {
								quadConstraint -= v[l][j][i];
							}

						}

						model.addQConstr(quadConstraint == f[l][j], "rest16_passageiroEmbarcadoProssegueEmbarcado" + indexToString(l + 1, j + 1));

					}
				}
			}

			//RESTRICAO 17
			for (l = 0; l < L; l++) {

				constraint = 0;

				for (j = 0; j < N; j++) {
					constraint += f[l][j];
				}

				model.addConstr(constraint - q[l] == 0, "rest17_SePassageiroEmbarcaEntaoForcaDesembarque" + indexToString(l + 1));

			}

			//RESTRICAO 18
			for (l = 0; l < L; l++) {

				int i = inst.P_D[l + 1][3] - 1;

				constraint = 0;

				for (j = 0; j < N; j++) {
					if (i != j) {
						constraint += v[l][i][j];
					}
				}

				model.addConstr(constraint == q[l], "rest18_PassageiroEhEmbarcadoApenasNaOrigem" + indexToString(l + 1));

			}

			//REST 19
			for (int l = 0; l < L; l++) {
				for (int i = 0; i < N; i++) {
					constraint = f[l][i];

					for (int j = 0; j < N; j++) {
						constraint += v[l][i][j];
					}

					model.addConstr(constraint <= 1, "rest19_passageiroEmbarcadoNaoDesembarcaDeNovo" + indexToString(l + 1, i + 1));

				}
			}

			//RESTRICAO 20
			for (l = 0; l < L; l++) {

				int j = inst.P_D[l + 1][3] - 1;

				constraint = 0;

				for (i = 0; i < N; i++) {
					constraint += v[l][i][j];
				}

				model.addConstr(constraint == 0, "rest20_PassageiroEhEmbarcadoApenasNaOrigem" + indexToString(l + 1));

			}

			//RESTRICAO 21
			constraint = 0;

			for (l = 0; l < L; l++) {

				constraint = 0;

				for (int j = 0; j < N; j++) {
					if (j != s)
						constraint += v[l][j][s];
				}

				model.addConstr(constraint == f[l][s], "rest21_obrigaQuemEstiverChegandoEm1Desembarcar");

			}


			//REST 22

			constraint = 0;

			for (l = 0; l < L; l++) {
				if (s == (int)inst.P_D[l + 1][3] - 1) {
					constraint += q[l];
				}
			}

			constraintAUX = 0;

			for (l = 0; l < L; l++) {
				for (int j = 0; j < N; j++) {
					constraintAUX += v[l][s][j];
				}
			}

			model.addConstr(constraint <= constraintAUX, "rest22_garantiaQueSoEmbarcaPassageirosDoVertice" + indexToString(i + 1));

			model.optimize();

			if (model.get(GRB_IntAttr_SolCount) > 0) {
				system("cls");
				return model.get(GRB_DoubleAttr_ObjVal);
				//bestCost = model.get(GRB_DoubleAttr_ObjVal);
				//	system("cls");
				model.write("solution_tspbpdu.sol");
				cout << "INSTNACIA: " << inst.n << " " << inst.p << " " << inst.c << endl;
				cout << "\n******************** x *****************************" << endl;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++)
						if (i != j && x[i][j].get(GRB_DoubleAttr_X) == 1)
							cout << "x_" << (i + 1) << "_" << (j + 1) << " = " << x[i][j].get(GRB_DoubleAttr_X) << endl;
				}
				cout << "******************** Passageiros Por Aresta *****************************" << endl;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++)
						if (i != j && taxaRateio[i][j].get(GRB_DoubleAttr_X) < 0.9) {
							double qtd = (1 / taxaRateio[i][j].get(GRB_DoubleAttr_X));
							cout << "pessoasDentroDoCarro_" << (i + 1) << "_" << (j + 1) << " = " << qtd << "(" << taxaRateio[i][j].get(GRB_DoubleAttr_X) << ")\n";
						}
				}
				cout << "******************** p *****************************" << endl;
				for (i = 0; i < N; i++) {
					if (p[i].get(GRB_DoubleAttr_X) == 1)
						cout << "p" << (i + 1) << " = " << p[i].get(GRB_DoubleAttr_X) << endl;
				}
				cout << "******************** q *****************************" << endl;
				for (l = 0; l < L; l++) {
					if (q[l].get(GRB_DoubleAttr_X) == 1)
						cout << "q" << (l + 1) << " = " << q[l].get(GRB_DoubleAttr_X) << endl;
				}
				cout << "******************** f *****************************" << endl;
				for (l = 0; l < L; l++)
					for (j = 0; j < N; j++) {
						if (f[l][j].get(GRB_DoubleAttr_X) == 1)
							cout << "f_" << (l + 1) << "_" << (j + 1) << " = " << f[l][j].get(GRB_DoubleAttr_X) << endl;
					}
				cout << "******************** v *****************************" << endl;
				for (l = 0; l < L; l++) {
					for (i = 0; i < N; i++) {
						for (j = 0; j < N; j++) {
							if (v[l][i][j].get(GRB_DoubleAttr_X) == 1) {
								cout << "Passageiro" << (l + 1) << " | O: " << inst.P_D[l + 1][3] << " | D: " << inst.P_D[l + 1][4] << "\n";
								cout << "v_" << (l + 1) << "_" << (i + 1) << "_" << (j + 1) << " = " << v[l][i][j].get(GRB_DoubleAttr_X) << endl;
							}
						}
					}
				}
				cout << "******************** SOLUCAO *****************************\n" << endl;
			}

		}
		catch (GRBException e) {
			cout << "Error number: " << e.getErrorCode() << endl;
			cout << e.getMessage() << endl;
		}
		catch (...) {
			cout << "Error during optimization" << endl;
		}

		return 0;
	}

	static double optimize(Solution S, Instance inst) {

		int N = inst.n;
		int R = inst.c;
		int L = inst.p;

		int i, l, j, a;

		int s = 0;

		int **tour = (int**)calloc(inst.n+1, sizeof(int*));

		for (i = 0; i < N + 1; i++) {

			tour[i] = (int*)calloc(inst.n + 1, sizeof(int));

		}


		for (int k = 0; k < S.n-1; k++) {
			int i = S.tour[k]-1;
			int j = S.tour[k+1]-1;
			tour[i][j] = 1;
		}

		try {

			/********************************************* INICIALIZACAO *****************************************************************/

			GRBEnv *env = new GRBEnv();

			GRBModel model = GRBModel(*env);

			model.getEnv().set(GRB_DoubleParam_TimeLimit, 88000);

			GRBVar *u = new GRBVar[N];
			GRBVar *q = new GRBVar[L];
			GRBVar *p = new GRBVar[N];

			GRBVar **taxaRateio = new GRBVar*[N];
			GRBVar **x = new GRBVar*[N];
			GRBVar **f = new GRBVar*[inst.p];

			GRBVar ***v = new GRBVar**[inst.p];

			for (i = 0; i < N; i++) {
				x[i] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					x[i][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "x" + indexToString(i + 1, j + 1));

				}
			}

			for (i = 0; i < N; i++) {

				u[i] = model.addVar(0.0, N - 1, 0.0, GRB_INTEGER, "u" + indexToString(i + 1));

			}

			for (i = 0; i < N; i++) {
				taxaRateio[i] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					taxaRateio[i][j] = model.addVar(0.0, 1.0, 0.0, GRB_CONTINUOUS, "taxaRateio" + indexToString(i + 1, j + 1));

				}
			}

			for (i = 0; i < N; i++) {

				p[i] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "p" + indexToString(i + 1));

			}

			for (l = 0; l < L; l++) {

				q[l] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "q" + indexToString(l + 1));

			}

			for (l = 0; l < L; l++) {
				f[l] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					f[l][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "f" + indexToString(l + 1, j + 1));

				}
			}

			for (l = 0; l < L; l++) {
				v[l] = new GRBVar*[inst.n];
				for (i = 0; i < N; i++) {
					v[l][i] = new GRBVar[N];
					for (j = 0; j < N; j++) {

						v[l][i][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "v" + indexToString(l + 1, i + 1, j + 1));

					}
				}
			}


			/********************************************* CONFIGURACAO DA F. OBJ *****************************************************************/

			GRBQuadExpr obj = 0;
			GRBQuadExpr xe = 0;

			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {

					xe = inst.D[i + 1][j + 1] * x[i][j] * taxaRateio[i][j];

					obj += xe;

				}
			}

			for (l = 0; l < inst.p; l++) {
				for (j = 0; j < N; j++) {

					xe = (inst.W[l + 1][j + 1] * f[l][j]);

					obj += xe;

				}
			}

			model.setObjective(obj, GRB_MINIMIZE);

			/********************************************* RESTRICOES ************************************************************************************/
			GRBLinExpr constraint = 0;
			GRBLinExpr constraintAUX = 0;
			GRBQuadExpr quadConstraint = 0;
			GRBQuadExpr quadConstraintAUX = 0;

			for (i = 0; i < N; i++) {
				x[i][i].set(GRB_DoubleAttr_UB, 0);
				taxaRateio[i][i].set(GRB_DoubleAttr_UB, 0);
			}

			u[s].set(GRB_DoubleAttr_UB, 0);
			p[s].set(GRB_DoubleAttr_UB, 0);

			/****************************************************************** CAIXEIRO ****************************************************************************/

			//RESTRICAO NAIVE
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {

					if (j != i && tour[i][j] == 1) {
						model.addConstr(x[i][j] == 1, "restNaive" + indexToString(i + 1, j + 1));
					}
					else
						model.addConstr(x[i][j] == 0, "restNaive" + indexToString(i + 1, j + 1));
				}
			}
			cout << "\n\n ";

			/****************************************************************** BONUS ****************************************************************************/

			//RESTRICAO 8
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					quadConstraint += inst.BONUS[i + 1][1] * p[i] * x[i][j];
				}
			}
			model.addQConstr(quadConstraint >= inst.Q, "rest8_bonusMinimo");

			/****************************************************************** PASSAGEIRO ****************************************************************************/

			//RESTRICAO 9
			for (l = 0; l < L; l++) {

				quadConstraint = 0;

				for (i = 0; i < N; i++) {

					for (j = 0; j < N; j++) {

						quadConstraint += v[l][i][j] * inst.T[i + 1][j + 1] + p[i] * inst.BONUS[i + 1][2] * v[l][i][j];

					}


				}

				model.addQConstr(quadConstraint <= inst.P_D[l + 1][2], "rest9_tempoLimitePassageiro" + indexToString(l + 1));

			}

			//RESTRICAO 10
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (i != j) {
						constraint = 0;
						for (l = 0; l < L; l++) {
							constraint += v[l][i][j];
						}
						model.addConstr(constraint <= inst.c*x[i][j], "rest10_carroCapPassandoPelaAresta" + indexToString(i + 1, j + 1));
					}
				}
			}

			//RESTRICAO 11
			for (int l = 0; l < L; l++) {
				constraint = 0;
				for (int j = 0; j < N; j++) {
					constraint += f[l][j];
				}
				model.addConstr(constraint <= 1, "rest11_passageiroDesembarcaSoUmaVez" + indexToString(l + 1));
			}

			//RESTRICAO 12
			for (l = 0; l < L; l++) {
				quadConstraint = 0;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++) {
						quadConstraint += v[l][i][j] * inst.D[i + 1][j + 1] * taxaRateio[i][j];
					}
				}

				model.addQConstr(quadConstraint <= inst.P_D[l + 1][1], "rest12_tarifaMaxPassageiro" + indexToString(l + 1));

			}

			//REST 13
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {

					if (i != j) {
						constraint = 1;
						for (l = 0; l < L; l++) {
							constraint += v[l][i][j];
						}
						model.addQConstr((constraint)* taxaRateio[i][j] == 1.0, "rest13_quantidadeDePassageirosNaAresta" + indexToString(i + 1, j + 1));
					}

				}
			}

			//REST 14
			for (l = 0; l < L; l++) {
				constraint = f[l][(int)inst.P_D[l + 1][3] - 1];
				model.addConstr(constraint == 0, "rest14_passageiroNaoDesembarcaNaSuaOrigem" + indexToString(l + 1));

			}

			//REST 15
			for (l = 0; l < L; l++) {
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++) {
						model.addConstr(v[l][i][j] <= q[l], "rest15_soPassaPassageiroPorOndePassaVeiculo" + indexToString(l + 1, i + 1, j + 1));
					}
				}
			}

			//REST 16
			for (int l = 0; l < L; l++) {

				for (int j = 0; j < N; j++) {
					if (j != inst.P_D[l + 1][3] - 1) {

						quadConstraint = 0;

						for (int i = 0; i < N; i++) {
							if (i != j) {
								quadConstraint += v[l][i][j];
							}
						}

						for (int i = 0; i < N; i++) {
							if (i != j) {
								quadConstraint -= v[l][j][i];
							}

						}

						model.addQConstr(quadConstraint == f[l][j], "rest16_passageiroEmbarcadoProssegueEmbarcado" + indexToString(l + 1, j + 1));

					}
				}
			}

			//RESTRICAO 17
			for (l = 0; l < L; l++) {

				constraint = 0;

				for (j = 0; j < N; j++) {
					constraint += f[l][j];
				}

				model.addConstr(constraint - q[l] == 0, "rest17_SePassageiroEmbarcaEntaoForcaDesembarque" + indexToString(l + 1));

			}

			//RESTRICAO 18
			for (l = 0; l < L; l++) {

				int i = inst.P_D[l + 1][3] - 1;

				constraint = 0;

				for (j = 0; j < N; j++) {
					if (i != j) {
						constraint += v[l][i][j];
					}
				}

				model.addConstr(constraint == q[l], "rest18_PassageiroEhEmbarcadoApenasNaOrigem" + indexToString(l + 1));

			}

			//REST 19
			for (int l = 0; l < L; l++) {
				for (int i = 0; i < N; i++) {
					constraint = f[l][i];

					for (int j = 0; j < N; j++) {
						constraint += v[l][i][j];
					}

					model.addConstr(constraint <= 1, "rest19_passageiroEmbarcadoNaoDesembarcaDeNovo" + indexToString(l + 1, i + 1));

				}
			}

			//RESTRICAO 20
			for (l = 0; l < L; l++) {

				int j = inst.P_D[l + 1][3] - 1;

				constraint = 0;

				for (i = 0; i < N; i++) {
					constraint += v[l][i][j];
				}

				model.addConstr(constraint == 0, "rest20_PassageiroEhEmbarcadoApenasNaOrigem" + indexToString(l + 1));

			}

			//RESTRICAO 21
			constraint = 0;

			for (l = 0; l < L; l++) {

				constraint = 0;

				for (int j = 0; j < N; j++) {
					if (j != s)
						constraint += v[l][j][s];
				}

				model.addConstr(constraint == f[l][s], "rest21_obrigaQuemEstiverChegandoEm1Desembarcar");

			}


			//REST 22

			constraint = 0;

			for (l = 0; l < L; l++) {
				if (s == (int)inst.P_D[l + 1][3] - 1) {
					constraint += q[l];
				}
			}

			constraintAUX = 0;

			for (l = 0; l < L; l++) {
				for (int j = 0; j < N; j++) {
					constraintAUX += v[l][s][j];
				}
			}

			model.addConstr(constraint <= constraintAUX, "rest22_garantiaQueSoEmbarcaPassageirosDoVertice" + indexToString(i + 1));

			model.optimize();

			if (model.get(GRB_IntAttr_SolCount) > 0) {
				system("cls");
				return model.get(GRB_DoubleAttr_ObjVal);
				//bestCost = model.get(GRB_DoubleAttr_ObjVal);
				//	system("cls");
				model.write("solution_tspbpdu.sol");
				cout << "INSTNACIA: " << inst.n << " " << inst.p << " " << inst.c << endl;
				cout << "\n******************** x *****************************" << endl;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++)
						if (i != j && x[i][j].get(GRB_DoubleAttr_X) == 1)
							cout << "x_" << (i + 1) << "_" << (j + 1) << " = " << x[i][j].get(GRB_DoubleAttr_X) << endl;
				}
				cout << "******************** Passageiros Por Aresta *****************************" << endl;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++)
						if (i != j && taxaRateio[i][j].get(GRB_DoubleAttr_X) < 0.9) {
							double qtd = (1 / taxaRateio[i][j].get(GRB_DoubleAttr_X));
							cout << "pessoasDentroDoCarro_" << (i + 1) << "_" << (j + 1) << " = " << qtd << "(" << taxaRateio[i][j].get(GRB_DoubleAttr_X) << ")\n";
						}
				}
				cout << "******************** p *****************************" << endl;
				for (i = 0; i < N; i++) {
					if (p[i].get(GRB_DoubleAttr_X) == 1)
						cout << "p" << (i + 1) << " = " << p[i].get(GRB_DoubleAttr_X) << endl;
				}
				cout << "******************** q *****************************" << endl;
				for (l = 0; l < L; l++) {
					if (q[l].get(GRB_DoubleAttr_X) == 1)
						cout << "q" << (l + 1) << " = " << q[l].get(GRB_DoubleAttr_X) << endl;
				}
				cout << "******************** f *****************************" << endl;
				for (l = 0; l < L; l++)
					for (j = 0; j < N; j++) {
						if (f[l][j].get(GRB_DoubleAttr_X) == 1)
							cout << "f_" << (l + 1) << "_" << (j + 1) << " = " << f[l][j].get(GRB_DoubleAttr_X) << endl;
					}
				cout << "******************** v *****************************" << endl;
				for (l = 0; l < L; l++) {
					for (i = 0; i < N; i++) {
						for (j = 0; j < N; j++) {
							if (v[l][i][j].get(GRB_DoubleAttr_X) == 1) {
								cout << "Passageiro" << (l + 1) << " | O: " << inst.P_D[l + 1][3] << " | D: " << inst.P_D[l + 1][4] << "\n";
								cout << "v_" << (l + 1) << "_" << (i + 1) << "_" << (j + 1) << " = " << v[l][i][j].get(GRB_DoubleAttr_X) << endl;
							}
						}
					}
				}
				cout << "******************** SOLUCAO *****************************\n" << endl;
			}

		}
		catch (GRBException e) {
			cout << "Error number: " << e.getErrorCode() << endl;
			cout << e.getMessage() << endl;
		}
		catch (...) {
			cout << "Error during optimization" << endl;
		}

		return 0;
	}


	static int optimizeUFCModel(Instance inst) {

		int N = inst.n;
		int R = inst.c;
		int L = inst.p;

		int i, l, j, a;

		int s = 0;

		try {

			/********************************************* INICIALIZACAO *****************************************************************/

			GRBEnv *env = new GRBEnv();

			GRBModel model = GRBModel(*env);

			model.getEnv().set(GRB_DoubleParam_TimeLimit, 80000);

			GRBVar *u = new GRBVar[N];
			GRBVar *p = new GRBVar[N];

			GRBVar **taxaRateio = new GRBVar*[N];
			GRBVar **x = new GRBVar*[N];
			GRBVar **f = new GRBVar*[inst.p];

			GRBVar ***v = new GRBVar**[inst.p];

			for (i = 0; i < N; i++) {
				x[i] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					x[i][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "x" + indexToString(i + 1, j + 1));

				}
			}

			for (i = 0; i < N; i++) {

				u[i] = model.addVar(0.0, N - 1, 0.0, GRB_INTEGER, "u" + indexToString(i + 1));

			}

			for (i = 0; i < N; i++) {
				taxaRateio[i] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					taxaRateio[i][j] = model.addVar(0.0, 1.0, 0.0, GRB_CONTINUOUS, "taxaRateio" + indexToString(i + 1, j + 1));

				}
			}

			for (i = 0; i < N; i++) {

				p[i] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "p" + indexToString(i + 1));

			}

			for (l = 0; l < L; l++) {
				f[l] = new GRBVar[N];
				for (j = 0; j < N; j++) {

					f[l][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "f" + indexToString(l + 1, j + 1));

				}
			}


			for (l = 0; l < L; l++) {
				v[l] = new GRBVar*[inst.n];
				for (i = 0; i < N; i++) {
					v[l][i] = new GRBVar[N];
					for (j = 0; j < N; j++) {

						v[l][i][j] = model.addVar(0.0, 1.0, 0.0, GRB_BINARY, "v" + indexToString(l + 1, i + 1, j + 1));

					}
				}
			}


			/********************************************* CONFIGURACAO DA F. OBJ *****************************************************************/

			GRBQuadExpr obj = 0;
			GRBQuadExpr xe = 0;

			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {

					xe = inst.D[i + 1][j + 1] * x[i][j] * taxaRateio[i][j];

					obj += xe;

				}
			}

			for (l = 0; l < inst.p; l++) {
				for (j = 0; j < N; j++) {

					xe = (inst.W[l + 1][j + 1] * f[l][j]);

					obj += xe;

				}
			}

			model.setObjective(obj, GRB_MINIMIZE);

			/********************************************* RESTRICOES ************************************************************************************/
			GRBLinExpr constraint = 0;
			GRBLinExpr constraintAUX = 0;
			GRBQuadExpr quadConstraint = 0;
			GRBQuadExpr quadConstraintAUX = 0;

			for (i = 0; i < N; i++) {
				x[i][i].set(GRB_DoubleAttr_UB, 0);
				taxaRateio[i][i].set(GRB_DoubleAttr_UB, 0);
			}

			u[s].set(GRB_DoubleAttr_UB, 0);
			p[s].set(GRB_DoubleAttr_UB, 0);

			/****************************************************************** CAIXEIRO ****************************************************************************/

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
					constraint = 0;
					constraintAUX = 0;

					for (i = 0; i < N; i++)
						if (i != j)
							constraint += x[i][j];

					for (i = 0; i < N; i++)
						if (i != j)
							constraintAUX += x[j][i];

					model.addConstr(constraint - constraintAUX == 0, "rest6_idaVolta" + indexToString(j + 1));

				}
			}

			//RESTRICAO 7
			for (i = 1; i < N; i++) {
				for (j = 1; j < N; j++) {

					if (j != i) {
						constraint = 0;
						constraint += u[i] - u[j] + x[i][j] * (N - 1);
						model.addConstr(constraint <= N - 2, "rest7_evitarSubCiclo" + indexToString(i + 1, j + 1));
					}

				}
			}

			/****************************************************************** BONUS ****************************************************************************/

			//RESTRICAO 8
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					quadConstraint += inst.BONUS[i + 1][1] * p[i] * x[i][j];
				}
			}
			model.addQConstr(quadConstraint >= inst.Q, "rest8_bonusMinimo");

			/****************************************************************** PASSAGEIRO ****************************************************************************/

			//RESTRICAO 9
			for (l = 0; l < L; l++) {

				quadConstraint = 0;

				for (i = 0; i < N; i++) {

					for (j = 0; j < N; j++) {

						quadConstraint += v[l][i][j] * inst.T[i + 1][j + 1] + p[i] * inst.BONUS[i + 1][2] * v[l][i][j];

					}


				}

				model.addQConstr(quadConstraint <= inst.P_D[l + 1][2], "rest9_tempoLimitePassageiro" + indexToString(l + 1));

			}

			//RESTRICAO 10
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (i != j) {
						constraint = 0;
						for (l = 0; l < L; l++) {
							constraint += v[l][i][j];
						}
						model.addConstr(constraint <= inst.c*x[i][j], "rest10_carroCapPassandoPelaAresta" + indexToString(i + 1, j + 1));
					}
				}
			}

			//RESTRICAO 11
			for (l = 0; l < L; l++) {
				quadConstraint = 0;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++) {
						quadConstraint += v[l][i][j] * inst.D[i + 1][j + 1] * taxaRateio[i][j];
					}
				}

				model.addQConstr(quadConstraint <= inst.P_D[l + 1][1], "rest11_tarifaMaxPassageiro" + indexToString(l + 1));

			}

			//REST 12
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {

					if (i != j) {
						constraint = 1;
						for (l = 0; l < L; l++) {
							constraint += v[l][i][j];
						}
						model.addQConstr((constraint)* taxaRateio[i][j] == 1.0, "rest13_quantidadeDePassageirosNaAresta" + indexToString(i + 1, j + 1));
					}

				}
			}

			//RESTRICAO 13
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (i != j) {
						for (l = 0; l < L; l++) {
							model.addConstr(v[l][i][j] <= x[i][j], "rest13_soPassaPassageiroPorOndePassaVeiculo" + indexToString(l + 1, i + 1, j + 1));
						}
					}
				}
			}

			//REST 14
			for (int l = 0; l < L; l++) {

				for (int j = 0; j < N; j++) {
					if (j != inst.P_D[l + 1][3] - 1) {

						constraint = 0;

						for (int i = 0; i < N; i++) {
							if (i != j) {
								constraint += v[l][i][j];
							}
						}

						for (int i = 0; i < N; i++) {
							if (i != j) {
								constraint -= v[l][j][i];
							}

						}

						model.addConstr(constraint == f[l][j], "rest14_passageiroEmbarcadoProssegueEmbarcado" + indexToString(l + 1, j + 1));

					}
				}
			}

			//REST 15
			for (l = 0; l < L; l++) {

				constraint = 0;

				i = inst.P_D[l + 1][3] - 1;

				for (j = 0; j < N; j++) {
					if (j != i) {
						constraint += v[l][i][j] - f[l][j];
					}

				}

				model.addConstr(constraint == 0, "rest15_UFC" + indexToString(l + 1, i + 1, j + 1));

			}

			//////////////////////////////////////////////////////////////

			model.optimize();

			if (model.get(GRB_IntAttr_SolCount) > 0) {
			//	bestCost = model.get(GRB_DoubleAttr_ObjVal);
				//	system("cls");
				model.write("solution_tspbpdu.sol");
				cout << "INSTNACIA: " << inst.n << " " << inst.p << " " << inst.c << endl;
				cout << "\n******************** x *****************************" << endl;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++)
						if (i != j && x[i][j].get(GRB_DoubleAttr_X) == 1)
							cout << "x_" << (i + 1) << "_" << (j + 1) << " = " << x[i][j].get(GRB_DoubleAttr_X) << endl;
				}
				cout << "******************** Passageiros Por Aresta *****************************" << endl;
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++)
						if (i != j && taxaRateio[i][j].get(GRB_DoubleAttr_X) < 0.9) {
							double qtd = (1 / taxaRateio[i][j].get(GRB_DoubleAttr_X));
							cout << "pessoasDentroDoCarro_" << (i + 1) << "_" << (j + 1) << " = " << qtd << "(" << taxaRateio[i][j].get(GRB_DoubleAttr_X) << ")\n";
						}
				}
				cout << "******************** p *****************************" << endl;
				for (i = 0; i < N; i++) {
					if (p[i].get(GRB_DoubleAttr_X) == 1)
						cout << "p" << (i + 1) << " = " << p[i].get(GRB_DoubleAttr_X) << endl;
				}
				cout << "******************** f *****************************" << endl;
				for (l = 0; l < L; l++)
					for (j = 0; j < N; j++) {
						if (f[l][j].get(GRB_DoubleAttr_X) == 1)
							cout << "f_" << (l + 1) << "_" << (j + 1) << " = " << f[l][j].get(GRB_DoubleAttr_X) << endl;
					}
				cout << "******************** v *****************************" << endl;
				for (l = 0; l < L; l++) {
					for (i = 0; i < N; i++) {
						for (j = 0; j < N; j++) {
							if (v[l][i][j].get(GRB_DoubleAttr_X) == 1) {
								cout << "Passageiro" << (l + 1) << " | O: " << inst.P_D[l + 1][3] << " | D: " << inst.P_D[l + 1][4] << "\n";
								cout << "v_" << (l + 1) << "_" << (i + 1) << "_" << (j + 1) << " = " << v[l][i][j].get(GRB_DoubleAttr_X) << endl;
							}
						}
					}
				}
				cout << "******************** SOLUCAO *****************************\n" << endl;
				//cout << "Z: " << bestCost << "\n\n";
			}

		}
		catch (GRBException e) {
			cout << "Error number: " << e.getErrorCode() << endl;
			cout << e.getMessage() << endl;
		}
		catch (...) {
			cout << "Error during optimization" << endl;
		}

		return 0;
	}

};
