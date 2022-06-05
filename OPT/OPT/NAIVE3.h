#pragma once
#include "InstanceReader.h"
#include "Solution.h"
#include "TSPB.h";
#include "TSPBPDU.h";
#include "GRASP.h";


class NAIVE3 {

public:

	static double optimize(Solution s, Instance *inst) {

		return TSPBPDU::optimize(s, *inst);

	}


};
