#pragma once
#include "InstanceReader.h"
#include "Solution.h"
#include "TSPB.h";
#include "TSPBPDU.h";
#include "GRASP.h";


class NAIVE5 {

public:

	static double optimize(Solution s, Instance *inst) {

		s = HCZ::optimize(s, inst);

		s = MLS::optimize(s, inst);

		double cost = s.cost;

		s.reset();

		return cost;

	}


};
