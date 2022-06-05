#pragma once
#include "InstanceReader.h"
#include "Solution.h"
#include "TSPB.h";
#include "TSPBPDU.h";


class NAIVE1 {

public:

	static double optimize(int **rout, Instance *inst) {

		return TSPBPDU::optimize(rout, *inst);

	}

};
