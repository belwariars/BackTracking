// Print all PERMUTATIONS of a string...
// TIME COMPLEXITY: O(N!*N) as printing the string will also take N...

#include <bits/stdc++.h>
using namespace std;

void swap(char *a, char *b)
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

void permuteRemoveDuplicate(char str[], int start, int end)
{
	int n = end+1;
	char strNew[n];
	
	sort(str, str+n);
	int i;
	int j =0;
	for(i=0; i<n;)
	{
		strNew[j] = str[i];
		j++;
		while(str[i] == str[i+1])
		{
			i++;
		}
		i++;
	}
	
	strNew[++j] = '\0';
	
	printf("%s \n\n", strNew);

	int len = strlen(strNew);
	permutation(strNew, start, len-1);
}

int main()
{
	char str[] = "AAABBBBCAABCC";
	int n = strlen(str);
	
	permuteRemoveDuplicate(str, 0, n-1);
	return 0;
}
