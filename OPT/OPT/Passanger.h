#pragma once

struct passanger {
	int id = 0;
	int org = 0;
	int dest = 0;
	int i_org = 0;
	int i_dest = 0;
	int range = 0;
	double saving = 0;
	double currentDelay = 0;
	double currentTax = 0;
	double currentTime = 0;
	bool viable = false;
	bool timeDiscarded = false;
	bool delayDiscarded = false;
	bool noDestDiscarded = false;
	bool sitDiscarded = false;
	bool taxDiscarded = false;
	bool uberDiscarded = false;

	passanger(int i, int o, int d, int i_o) {
		id = i;
		i_org = i_o;
		org = o;
		dest = d;
	};

	passanger() {};

	void reset() {
		id = 0;
		org = 0;
		dest = 0;
		i_org = 0;
		i_dest = 0;
		range = 0;
		saving = 0;
		currentDelay = 0;
		currentTax = 0;
		currentTime = 0;
		viable = false;
		timeDiscarded = false;
		delayDiscarded = false;
		noDestDiscarded = false;
		sitDiscarded = false;
		taxDiscarded = false;
		uberDiscarded = false;
	};

};
