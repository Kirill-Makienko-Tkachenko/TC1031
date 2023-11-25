#include <iostream>
#include "graph.h"

using namespace std;

// Graph Implementation using STL
int main()
{
	// vector of graph edges as per the above diagram.
	// Please note that the initialization vector in the below format will
	// work fine in C++11, C++14, C++17 but will fail in C++98.
	vector<Edge> edges =
	{
		{0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
	};

	// total number of nodes in the graph (labelled from 0 to 5)
	int n = 6;

	// construct graph
	Graph graph(edges, n, false);

	// print adjacency list representation of a graph
	//graph.printGraph();

    graph.DFS(0);
	return 0;
}