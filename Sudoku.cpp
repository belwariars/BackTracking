// SUDOKU Problem...

#include <bits/stdc++.h>
using namespace std;

#define N 9
#define UNASSIGNED 0

int UsedInRow(int grid[N][N], int row, int num)
{
	int i;
	for(i=0; i<N; i++)
	{
		if(grid[row][i] == num)
			return 1;
	}
	return 0;
}

int UsedInCol(int grid[N][N], int col, int num)
{
	int i;
	for(i=0; i<N; i++)
	{
		if(grid[i][col] == num)
			return 1;
	}
	return 0;
}

int UsedInBox(int grid[N][N], int row, int col, int num)
{
	int i,j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(grid[i+row][j+col] == num)
				return 1;
		}
	}
	
	return 0;
}

int isSafe(int grid[N][N], int row, int col, int num)
{
	return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row%3 , col - col%3, num);
}

int unAssignedLocation(int grid[N][N], int &row, int &col)
{
	for(row =0; row<N; row++)
	{
		for(col=0; col<N; col++)
		{
			if(grid[row][col] == UNASSIGNED)
			{
				return 1;
			}
		}
	}
	return 0;
}

int solveSudoku(int grid[N][N])
{
	int row, col;
	
	if(!unAssignedLocation(grid, row, col))
	{
		return 1;
	}
	int num;
	
	for(num=1; num<=9; num++)
	{
		if(isSafe(grid, row, col, num) == 1)
		{
			grid[row][col] = num;
			
			if(solveSudoku(grid) == 1)
				return 1;
			
			grid[row][col] = UNASSIGNED;
		}
	}
	return 0;
}

void printGrid(int grid[N][N])
{
	int i,j;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%2d", grid[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    
    if(solveSudoku(grid))
    {
    	printf("Succeess\n\n");
    	printGrid(grid);
	}
	else
	{
		printf("No success");
	}
	return 0;
}
