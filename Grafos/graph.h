#include <iostream>
#include <vector>
using namespace std;

// Data structure to store a graph edge
struct Edge {
	int src, dest;
};

// A class to represent a graph object
class Graph
{
private:
	// a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;
    bool directed = true;
    void recDFS(int v, vector<bool> &discovered);
 
public:
    
	// Graph Constructor
	Graph(vector<Edge> const &edges, int n, bool isDirected = true)
	{
        directed = isDirected;
		// resize the vector to hold `n` elements of type `vector<int>`
		adjList.resize(n);

		// add edges to the directed graph
		for (auto &edge: edges)
		{

            bool exists=false;
            for (int i=0; i<adjList[edge.src].size(); i++) {
                if (adjList[edge.src].at(i)== edge.dest) {
                    exists=true;
                    break;
                }
            }

            if (!exists) {
			    // insert at the end
			    adjList[edge.src].push_back(edge.dest);
            }   

			if (!directed) {
                bool exists=false;
                for (int i=0; i<adjList[edge.dest].size(); i++) {
                    if (adjList[edge.dest].at(i)== edge.src) {
                        exists=true;
                        break;
                    }
                }
                if (!exists)     
                    adjList[edge.dest].push_back(edge.src);
            }
		}
	}
    void printGraph();
    void DFS(int v);   
};

// Function to print adjacency list representation of a graph
void Graph::printGraph()
{
    int n=adjList.size();

	for (int i = 0; i < n; i++)
	{
		// print the current vertex number
		cout << i << " ---> ";

		// print all neighboring vertices of a vertex `i`
		for (int v: adjList[i]) {
			cout << v << " ";
		}
		cout << endl;
	}
}

void Graph::DFS(int v) {
    vector<bool> discovered;
    discovered.resize( adjList.size() );
    for (int i = 0; i < adjList.size(); i++)
        discovered[i]=false;
    recDFS(v, discovered);
}


// Función para realizar el recorrido DFS en el graph en un graph
void Graph::recDFS(int v, vector<bool> &discovered)
{
    // marca el nodo actual como descubierto
    discovered[v] = true;
 
    // imprime el nodo actual
    cout << v << " ";
 
    // hacer para cada borde (v, u)
    for (int u: adjList[v])
    {
        // si aún no se ha descubierto `u`
        if (!discovered[u]) {
            recDFS(u, discovered);
        }
    }
}
