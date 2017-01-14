// m - COLORING Problem...

#include <bits/stdc++.h>
using namespace std;

#define V 4

int isSafe(int graph[V][V], int color[], int c, int v)
{
	int i;
	for(i=0; i<V; i++)
	{
		if(graph[v][i] && c == color[i])
		{
			return false;
		}
	}
	return true;
}

int mColoringUtil(int graph[V][V], int color[], int m, int v)
{
	if(v == V)
		return 1;
		
	int c;
	for(c=1; c<=m; c++)
	{
		if(isSafe(graph, color, c, v))
		{
			color[v] = c;
			
			if(mColoringUtil(graph, color, m, v+1) == 1)
				return 1;
				
			color[v] = 0;
		}
	}
	
	return 0;
}

void printColor(int color[], int m)
{
	int i;
	for(i=0; i<V; i++)
	{
		printf("%2d", color[i]);
	}
	
}

void mColoring(int graph[V][V], int m)
{
	int color[V];
	int i;
	for(i=0; i<V; i++)
	{
		color[i] = 0;
	}
	
	if(mColoringUtil(graph, color, m, 0) == 1)
	{
		printf("Success\n\n");
		printColor(color, m);
	}
	else
	{
		printf("No Success\n\n");
	}
}

int main()
{
	 int graph[V][V] = {{0, 1, 1, 1},
       					{1, 0, 1, 0},
       					{1, 1, 0, 1},
      					{1, 0, 1, 0},
   						};
   						
   	int m = 3;
   	
   	mColoring(graph, m);
	return 0;
}
