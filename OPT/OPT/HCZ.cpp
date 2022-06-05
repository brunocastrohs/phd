#include "HCZ.h";

edge* HCZ::edges = NULL;

passanger* HCZ::passangers = NULL;

edge* HCZ::edgeHold = NULL;

passanger* HCZ::passangersHold = NULL;

bool* HCZ::alreadyCounted = NULL;

int* HCZ::boarded = NULL;

bool* HCZ::isBoarded = NULL;

int* HCZ::nextBoarded = NULL;

bool* HCZ::isNextBoarded = NULL;

double **HCZ::edgeBoardFactor = NULL;

//uber

passanger* HCZ::passangersUberHold = NULL;

bool* HCZ::isLocalBoarded = NULL;

int * HCZ::uberBoarded = NULL;

bool* HCZ::uberIsBoarded = NULL;

bool* HCZ::uberAlreadyCounted = NULL;

int* HCZ::uberNextBoarded = NULL;

bool* HCZ::uberIsNextBoarded = NULL;