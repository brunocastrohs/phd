#pragma once
#include <cfloat> // DBL_MAX
#include <cmath> // std::nextafter
#include <random>
using namespace std;

class Random {

public:
	random_device rd;
	mt19937 gen;
	uniform_real_distribution<> dis;

	Random() {}

	double generateNumber() {

		mt19937 gen(rd());
		uniform_real_distribution<> dis(0.0, std::nextafter(1.0, DBL_MAX));

		return dis(gen);

	}

	double generateNumber(double start, double end) {

		mt19937 gen(rd());
		uniform_real_distribution<> dis(start, std::nextafter(end, DBL_MAX));

		return dis(gen);

	}

};

