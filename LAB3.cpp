#include <iostream>
#include <climits>
#include <iomanip>
#include <string> 

using namespace std;

// Number of vertices in the adjacency Matrix
#define N 4
// Recursive Function to print path of given 
// vertex i from source vertex j

void printPath(int path[][N], int i, int j)
{
	if (path[i][j] == i)
		return;

	printPath(path, i, path[i][j]);
	cout << path[i][j] << " ";
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
// Function to print the least cost 
 // between all pairs of cities
void printSolution(int cost[N][N], int path[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (cost[i][j] == INT_MAX)
				cout << setw(5) << "inf";
			else
				cout << setw(5) << cost[i][j];
		}
		cout << endl;
	}

	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j != i )
			{
				
				cout << "Least cost from  " << namecity(i) <<
					" to " << namecity(j) << " is (" << cost[i][j] <<")"<< endl;
			}
		}
	}
}



// Function to run Floyd-Warshell algorithm
void FloydWarshell(int adjacencyMatrix[][N])
{
	// cost[] stores shortest cost and path[] stores the shortest route information
	
	int cost[N][N], path[N][N];

	// initialize cost[] and path[]
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// initially cost would be same as weight 
			// of the edge of the graph
			cost[i][j] = adjacencyMatrix[i][j];

			if (i == j)
				path[i][j] = 0;
			else if (cost[i][j] != INT_MAX)
				path[i][j] = i;
		}
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// If vertex k is the least cost from v to u,
				// then update the value of cost[v][u], path[v][u]

				if (cost[i][k] != INT_MAX && cost[k][j] != INT_MAX
					&& cost[i][k] + cost[k][j] < cost[i][j])
				{
					cost[i][j] = cost[i][k] + cost[k][j];
					path[i][j] = path[k][j];
				}
			}

		}
	}

	// Print the least cost between all pairs of cities
	printSolution(cost, path);
}


int main()
{
	// given adjacency matrix representation of a graph
	int graph[N][N] =
	{
		{	   0, 10,	  14, 20 },
		{	   20,	   0,	   40, INT_MAX },
		{ INT_MAX, 35,	   0,	   8},
		{ INT_MAX,	  INT_MAX, 13,	   0 }
	};

	FloydWarshell(graph);

	return 0;
}