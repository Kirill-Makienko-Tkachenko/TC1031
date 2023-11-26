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
		{1, 2}, {2, 1}, {1, 3}, {3, 1}, {2, 3}, {3, 2}, {2, 4}, {4, 2},
		{2, 5}, {5, 2}, {4, 5}, {5, 4}, {6, 5}, {5, 6}, {3, 5}, {5, 3}, {3, 7}, {7, 3}, {3, 8}, {8, 3},
		{7, 8}, {8, 7}
	};

	// total number of nodes in the graph (labelled from 0 to 5)
	int n = 22;

	// construct graph
	Graph graph(edges, n, false);

	// print adjacency list representation of a graph
	//graph.printGraph();

    cout << "DFS a partir del nodo 0: " << endl;
	graph.DFS(1);
	cout << endl;
	cout << "BFS a partir del nodo 0: " << endl;
	graph.BFS(1);
	return 0;
}