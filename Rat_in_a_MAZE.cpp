// RAT IN A MAZE...

#include <bits/stdc++.h>
using namespace std;


#define N 4

void printsol(int sol[N][N])
{
	int i,j;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%2d", sol[i][j]);
		}
		printf("\n");
	}
}

int isSafe(int x, int y, int maze[N][N])
{
	if(x>=0 && x<N && y>=0 && y<N && maze[x][y] ==1)
		return 1;
	else
		return 0;	
}

int solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
	if(x == N-1 && y == N-1)
	{
		sol[x][y] = 1;
		return 1;
	}
	
	
	if(isSafe(x, y, maze))
	{
		sol[x][y] = 1;
		
		if(solveMazeUtil(maze, x+1, y, sol))
			return 1;
		
		if(solveMazeUtil(maze, x, y+1, sol))
			return 1;
			
		sol[x][y] = 0;
			return 0;
	}
	
	return 0;
}

void solveMaze(int maze[N][N])
{
	int sol[N][N] = {{0, 0, 0, 0},
					 {0, 0, 0, 0},
					 {0, 0, 0, 0},
					 {0, 0, 0, 0}
					};
	
	if(solveMazeUtil(maze, 0, 0, sol)==1)
	{
		printf("Solution Exists\n\n");
		printsol(sol);
	}
	else
	{
		printf("Solution doesn't Exists");
	}
}

int main()
{
	int maze[N][N]  =  { {1, 0, 0, 0},
        				 {1, 1, 0, 1},
       					 {0, 1, 0, 0},
      					 {1, 1, 1, 1}
   					    };
   					    
   	solveMaze(maze);
   	
	return 0;
}
