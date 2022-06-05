#pragma once
#include "InstanceReader.h";
#include "Solution.h";
#include "LS_PUSH.h";
#include "LS_INTER.h";
#include "LS_SWAP.h";
#include "LS_FLIP.h";
#include "LS_POP.h";

class MLS {

public:

	static Solution optimize(Solution S, Instance *inst) {

		S = LS_FLIP::optimize(S, inst);
		S = LS_POP::optimize(S, inst);
		S = LS_INTER::optimize(S, inst);
		S = LS_SWAP::optimize(S, inst);

		return S;

	}


};