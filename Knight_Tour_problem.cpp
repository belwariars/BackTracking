// Knight Tour Problem...

#include <bits/stdc++.h>
using namespace std;

# define N 8

void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

int isSafe(int x, int y, int sol[N][N])
{
	if(x>=0 && x<N && y>=0 && y<N && sol[x][y] == -1)
		return 1;
	else
		return 0;
}

int solveKTutil(int x, int y, int movei, int sol[N][N], int moveX[], int moveY[])
{
	if(movei == N*N)
	{
		return 1;
	}
	int k;
	int nxt_x;
	int nxt_y;
	for(k=0; k<8; k++)
	{
		nxt_x = x + moveX[k];
		nxt_y = y + moveY[k];
		if(isSafe(nxt_x, nxt_y, sol))
		{
			sol[nxt_x][nxt_y] = movei;
			if (solveKTutil(nxt_x, nxt_y, movei+1, sol,
                         moveX, moveY) == 1)
             return 1;
         else
             sol[nxt_x][nxt_y] = -1;
		}
	}
	
	return 0;
}

void solveKT()
{
	int sol[N][N];
	int i,j;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			sol[i][j] = -1;
		}
	}
	
	int moveX[8] = { 2, 1, -1, -12, -2, -1,  1,  2 };
	int moveY[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
	
	sol[0][0] = 0;
	
	if(solveKTutil(0, 0, 1, sol, moveX, moveY) == 1)
	{
		printf("Solution Exists\n\n");
		printSolution(sol);
		return;
	}
	
		printf("Solution doesn't exists'");
	
}

int main()
{
	solveKT();
	return 0;
}
