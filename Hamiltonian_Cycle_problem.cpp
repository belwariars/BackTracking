// HAMILTONIAN CYCLE Problem...

#include <bits/stdc++.h>
using namespace std;

#define V 5

int isSafe(int graph[V][V], int path[], int i, int pos)
{
	if(graph[path[pos-1]][i] == 0)
		return 0;
		
	int j;
	for(j=0; j<pos; j++)
	{
		if(path[j] == i)
			return 0;
	}
	
	return 1;
}

int hamiltonCycleUtil(int graph[V][V], int path[], int pos)
{
	if(pos == V)
	{
		if(graph[path[pos-1]][path[0]] == 1)
		{
			return 1;
		}
		else
			return 0;
	}
	
	int i;
	for(i=1; i<V; i++)
	{
		if(isSafe(graph, path, i, pos))
		{
			path[pos] = i;
			
			if(hamiltonCycleUtil(graph, path, pos+1) == 1)
				return 1;
			
			path[pos] = -1;
		}
	}
}

void printPath(int path[])
{
	int i;
	for(i=0; i<V; i++)
	{
		printf("%d ", path[i]);
	}
}

void hamiltonCycle(int graph[V][V])
{
	int path[V];
	int i;
	
	for(i=0; i<V; i++)
	{
		path[i] = -1;
	}
	
	path[0] = 0;
	if(hamiltonCycleUtil(graph, path, 1) == 1)
	{
		printf("Hamilton Cycle Exists\n\n");
		printPath(path);
		printf("%d", path[0]);
	}
	else
	{
		printf("Cycle doesn't exists");
		printPath(path);
	}
}

int main()
{
	int graph[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
                     
    hamiltonCycle(graph);
	return 0;
}
