#include <iostream>
#include <ios>
#include <fstream>
#include <thread>
#include <chrono>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TSP.h";
#include "TSPB.h";
#include "TSPBPDU.h";
#include "NAIVE1.h";
#include "NAIVE2.h";
#include "NAIVE3.h";
#include "NAIVE4.h";
#include "NAIVE5.h";

using namespace std;

string runNaives(char* number, const char* fileName, char* type, int naive1Limit, int naive3Limit) {

	stringstream str;

	double costNAIVE1 = 0, costNAIVE2 = 0, costNAIVE3 = 0, costNAIVE4 = 0, costNAIVE5 = 0;

	double timeNAIVE1 = 0, timeNAIVE2 = 0, timeNAIVE3 = 0, timeNAIVE4 = 0, timeNAIVE5 = 0;

	clock_t begin, end;



	Instance inst = InstanceReader::readInstance(fileName, number, type);

	HCZ::initDataGaters(&inst);

	//GRASP PARAMS

	int iterMax = 392;
	double alpha = 0.47;

	//NAIVES EXECS

	begin = clock();
	int** rout = TSPB::optimize(inst);
	end = clock();
	double tspbTIME = double(end - begin) / CLOCKS_PER_SEC;

	if (true) {
	
		begin = clock();
		costNAIVE1 = NAIVE1::optimize(rout, &inst);
		end = clock();
		timeNAIVE1 = tspbTIME + (double(end - begin) / CLOCKS_PER_SEC);
	
	}

	if (false) {
		begin = clock();
		costNAIVE2 = NAIVE2::optimize(rout, &inst);
		end = clock();
		timeNAIVE2 = tspbTIME + (double(end - begin) / CLOCKS_PER_SEC);
	}

	begin = clock();
	Solution s = GRASP::optimize(iterMax, alpha, &inst);
	end = clock();
	double graspTIME = double(end - begin) / CLOCKS_PER_SEC;

	Solution s1 = Cloner::clone(s, &inst);
	Solution s2 = Cloner::clone(s, &inst);
	Solution s3 = Cloner::clone(s, &inst);

	if (true) {
		begin = clock();
		costNAIVE3 = NAIVE3::optimize(s1, &inst);
		end = clock();
		timeNAIVE3 = graspTIME + (double(end - begin) / CLOCKS_PER_SEC);
	}

	if (false) {
		begin = clock();
		costNAIVE4 = NAIVE4::optimize(s2, &inst);
		end = clock();
		timeNAIVE4 = graspTIME + (double(end - begin) / CLOCKS_PER_SEC);
	}

	if (false) {
		begin = clock();
		costNAIVE5 = NAIVE5::optimize(s3, &inst);
		end = clock();
		timeNAIVE5 = graspTIME + (double(end - begin) / CLOCKS_PER_SEC);
	}

	cout << fileName << " | " << type << endl;

	str << costNAIVE1 <<";"<< timeNAIVE1 << ";";
	
	str << costNAIVE2 << ";" << timeNAIVE2 << ";";

	str << costNAIVE3 << ";" << timeNAIVE3 << ";";

	str << costNAIVE4 << ";" << timeNAIVE4 << ";";

	str << costNAIVE5 << ";" << timeNAIVE5 << ";";

	str << "\n";

	//s.reset();
	//s1.reset();
	//s2.reset();
	//s3.reset();
	
	//for (int i = 0; i < inst.n;i++) {
//		free(rout[i]);
//	}

//	free(rout);

	inst.reset();

	HCZ::resetDataGaters(&inst);

	return str.str();

}

void insertFile(int numberBegin, int numberLimit, int groupBegin, int groupLimit, int capacityBegin, int capacityLimit) {

	ofstream log("RESULTING.csv", std::ios_base::app | std::ios_base::out);

	char** number = new char*[8];
	int numberCount = 0;
	char** type   = new char*[3];
	int typeCount = 0;
	char** capacity  = new char*[3];
	int capacityCount = 0;
	char** group = new char*[3];
	int groupCount = 0;

	for (int i = 0; i < 8; i++) {
		number[i] = new char[5];
		if (i < 3) {
			type[i] = new char[5];
			capacity[i] = new char[5];
			group[i] = new char[5];
		}
	}

	int k = 0;

	number[k++] = "10";
	number[k++] = "20";
	number[k++] = "30";
	number[k++] = "40";
	number[k++] = "50";
	number[k++] = "100";
	number[k++] = "200";
	number[k++] = "500";

	k = 0;

	group[k++] = "A";
	group[k++] = "B";
	group[k++] = "C";

	k = 0;

	capacity[k++] = "3";
	capacity[k++] = "4";
	capacity[k++] = "5";

	k = 0;

	type[k++] = "simetrico";
	type[k++] = "assimetrico";
	
	log << "\n";
	
	for (typeCount = 0; typeCount < 2; typeCount++) {
		for (groupCount = groupBegin; groupCount < groupLimit; groupCount++) {
			for (numberCount = numberBegin; numberCount < numberLimit; numberCount++) {
				for (capacityCount = capacityBegin; capacityCount < capacityLimit; capacityCount++) {
					stringstream str1, str2;
					str1 << "INST-" << group[groupCount] << "-" << number[numberCount] << "-" << capacity[capacityCount]<<".txt";
					str2 << runNaives(number[numberCount], str1.str().c_str(), type[typeCount], 50, 50);
					log << type[typeCount] << ";" << "INST-" << group[groupCount] << "-" << number[numberCount] << "-" << capacity[capacityCount] << ";" << str2.str();
				}
			}
		}
		log << "\n\n";
	}

	log << "\n";

	log.close();

}

int main(void) {
	
	char* number = "5";
	char* fileName = "INST-C-5-3.txt";
	char* type = "assimetrico";


	Instance inst = InstanceReader::readInstance(fileName, number, type);

	TSPBPDU::optimize(inst);

	cout << "HI threrU";

	system("pause");


	/*
	ofstream log("RESULTING.csv", std::ios_base::app | std::ios_base::out);
	stringstream str1, str2;

	char* n = "200";
	char* fileName = "INST-A-200-3.txt";
	char* type = "simetrico";

	str1 << fileName;
	str2 << runNaives(n, str1.str().c_str(), type, 0, 0);
	log << type << ";" << str1.str() << ";" << str2.str();
	*/
	
	//rodar 40 e 50 para A e B

	//0 - 8: number
	//0 - 3: letter
	//0 - 3: capacity

	//insertFile(3, 4, 0, 1, 0, 3);

	return 0;

}