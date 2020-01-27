#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define SIZE 100


int main()
{
	int m = 0;
	int W[SIZE][SIZE];
	// ‰»Î
	do
	{
		scanf("%d", &W[1][++m]);
	} while (getchar() != '\n');
	for (int i = 2; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &W[i][j]);
		}
	}
	//Warshell

	for (int k = 1; k <= m; k++)
	{
		for (int i = 1; i <= m; i++)
		{
			//if (W[i][j])
			//{
				for (int j = 1; j <= m; j++)
				{
					W[i][j] = W[i][j] || (W[i][k] && W[k][j]);
				}
			//}
		}
	}

	for (int i = 1; i <= m; i++)
	{
		printf("%d", W[i][1]);
		for (int j = 2; j <= m; j++)
		{
			printf(" %d", W[i][j]);
		}
		printf("\n");
	}

	return 0;
}
