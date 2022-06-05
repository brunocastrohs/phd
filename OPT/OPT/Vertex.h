#pragma once
struct vertex {

	bool *isVertexNextNeighbor;
	int *vertexNextNeighbor;
	int vertexNextNeighborCount = 0;

	bool *isVertexPrevNeighbor;
	int *vertexPrevNeighbor;
	int vertexPrevNeighborCount = 0;

	bool *isVertexNeighbor;
	int *vertexNeighbor;
	int vertexNeighborCount = 0;

	//int passangersCount = 0;
	int *departingPassangers;
	int dPassangersCount;

	int *possiblePassangersPerNeighbor;

	vertex() {};

	vertex(int n, int p) {
		isVertexNextNeighbor = (bool*)calloc(n + 1, sizeof(bool));
		vertexNextNeighbor = (int*)calloc(n + 1, sizeof(int));

		isVertexPrevNeighbor = (bool*)calloc(n + 1, sizeof(bool));
		vertexPrevNeighbor = (int*)calloc(n + 1, sizeof(int));

		isVertexNeighbor = (bool*)calloc(n + 1, sizeof(bool));
		vertexNeighbor = (int*)calloc(n + 1, sizeof(int));

		departingPassangers = (int*)calloc(p + 1, sizeof(int));
		dPassangersCount = 0;

		possiblePassangersPerNeighbor = (int*)calloc(n + 1, sizeof(int));

	}

	void reset() {
	
		free(isVertexNextNeighbor);
		free(vertexNextNeighbor);
		free(isVertexPrevNeighbor);
		free(vertexPrevNeighbor);
		free(isVertexNeighbor);
		free(vertexNeighbor);
		free(departingPassangers);
		free(possiblePassangersPerNeighbor);
		

	}

};
