// program to print all permutations of a given string
// NOTE: IF THE input string has duplicate values, it will give WRONG RESULTS... ONLY WORKS FOR DISTINCT ELEMENTS...
// TIME COMPLEXITY: O(N!*N) as printing the string will also take N...

#include <bits/stdc++.h>
using namespace std;

void swap(char* a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void permutation(char str[], int start, int end)
{
	int i;
	if(start == end)
	{
		printf("%s ", str);
	}
	else
	{
		for(i=start; i<=end; i++)
		{
			swap(&str[start], &str[i]);
			permutation(str, start+1, end);
			swap(&str[start], &str[i]);
		}
	}
}

int main()
{
	char str[] = "ABC";
	int n = strlen(str);
	
	permutation(str, 0, n-1);
	return 0;
}
