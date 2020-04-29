#include <iostream>
#include <climits>
#include <iomanip>
#include <string> 

using namespace std;

// Number of vertices in the adjMatrix
#define N 4

// Recursive Function to print path of given 
// vertex u from source vertex v

void printPath(int path[][N], int v, int u)
{
	if (path[v][u] == v)
		return;

	printPath(path, v, path[v][u]);
	cout << path[v][u] << " ";
}

 string namecity(int index) {
	switch (index) {


	case 0:  return "St Petersburg";
		break;
	case 1: return "Moscow";
		break;
	case 2: return "Xavarovsk";
		break;
	case 3: return "Vladivostok";
		break;
	default:
		throw invalid_argument("Invalid city name" );
	}

}
// Function to print the shortest cost with path 
// information between all pairs of cities
void printSolution(int cost[N][N], int path[N][N])
{
	for (int v = 0; v < N; v++)
	{
		for (int u = 0; u < N; u++)
		{
			if (cost[v][u] == INT_MAX)
				cout << setw(5) << "inf";
			else
				cout << setw(5) << cost[v][u];
		}
		cout << endl;
	}

	cout << endl;
	for (int v = 0; v < N; v++)
	{
		for (int u = 0; u < N; u++)
		{
			if (u != v )
			{
				
				cout << "Least cost from  " << namecity(v) <<
					" to " << namecity(u) << " is (" << cost[v][u] <<")"<< endl;
			}
		}
	}
}



// Function to run Floyd-Warshell algorithm
void FloydWarshell(int adjMatrix[][N])
{
	// cost[] and parent[] stores shortest-cost
	// (shortest-cost) information
	int cost[N][N], path[N][N];

	// initialize cost[] and parent[]
	for (int v = 0; v < N; v++)
	{
		for (int u = 0; u < N; u++)
		{
			// initally cost would be same as weight 
			// of the edge
			cost[v][u] = adjMatrix[v][u];

			if (v == u)
				path[v][u] = 0;
			else if (cost[v][u] != INT_MAX)
				path[v][u] = v;
		}
	}

	// run Floyd-Warshell
	for (int k = 0; k < N; k++)
	{
		for (int v = 0; v < N; v++)
		{
			for (int u = 0; u < N; u++)
			{
				// If vertex k is the least cost from v to u,
				// then update the value of cost[v][u], path[v][u]

				if (cost[v][k] != INT_MAX && cost[k][u] != INT_MAX
					&& cost[v][k] + cost[k][u] < cost[v][u])
				{
					cost[v][u] = cost[v][k] + cost[k][u];
					path[v][u] = path[k][u];
				}
			}

		}
	}

	// Print the least cost between all pairs of cities
	printSolution(cost, path);
}


int main()
{
	// given adjacency representation of matrix
	int adjMatrix[N][N] =
	{
		{	   0, 10,	  14, 20 },
		{	   20,	   0,	   40, INT_MAX },
		{ INT_MAX, 35,	   0,	   8},
		{ INT_MAX,	  INT_MAX, 13,	   0 }
	};

	FloydWarshell(adjMatrix);

	return 0;
}