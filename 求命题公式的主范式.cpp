#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int chtype(char c); //op:0 number:1 end:-2
int compare(char a, char b);
bool operate();

char oplist[] = {'!', '&', '|', '-', '+', '(', ')', '#', 10};
int complist[8][8] = { //	>:1		<:0		=:-1	error:-2
	{1, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 0, 0, 0, 0, 1, 1},
	{1, 1, 1, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 0, 0, 1, 1},
	{1, 1, 1, 1, 1, 0, 1, 1},
	{0, 0, 0, 0, 0, 0, -1, -2},
	{1, 1, 1, 1, 1, -2, 1, 1},
	{0, 0, 0, 0, 0, 0, -2, -1}};

stack<char> op;
stack<bool> ans;
queue<int> mm;
queue<int> MM;

int main()
{
	char c;
	char ori[1000];
	bool bl[200] = {0};
	int chh[20];
	int tpc = 0;
	int chnum = 0;
	c = getchar();
	while (c != '\n')
	{
		if (chtype(c) == 1)
		{
			ori[tpc++] = c;
			if (bl[c] == 0)
			{
				bl[c] = true;
				chh[chnum] = c;
				chnum++;
			}

			c = getchar();
		}
		else
		{
			ori[tpc++] = c;
			c = getchar();
		}
	}
	sort(chh, &chh[chnum - 1]);
	ori[tpc] = '#';
	ori[tpc + 1] = '\0';

	int maxnum = pow(2, chnum);
	for (int i = 0; i < maxnum; i++)
	{
		int m = i;
		while (!op.empty())
		{
			op.pop();
		}
		while (!ans.empty())
		{
			ans.pop();
		}

		for (int j = 0; j < chnum; j++)
		{
			int temp = m;
			(temp >>= 1) <<= 1;
			temp = m - temp;
			if (temp == 0)
			{
				bl[chh[chnum - j - 1]] = false;
			}
			else
			{
				bl[chh[chnum - j - 1]] = true;
			}
			m >>= 1;
		}
		c = ori[0];
		int k = 0;
		op.push('#');

		while (c != '\0')
		{
			if (chtype(c) == 1)
			{
				ans.push(bl[c]);

				c = ori[++k];
			}
			else
			{
				switch (compare(op.top(), c))
				{
				case 0:
					/* < */
					op.push(c);
					c = ori[++k];
					break;
				case -1:
					// =
					op.pop();
					c = ori[++k];
					break;
				case 1:
					bool tempp = operate();
					ans.push(tempp);
					break;
				}
			}
		}
		if (ans.top() == true)
		{
			mm.push(i);
		}
		else
		{
			MM.push(i);
		}
		ans.pop();
	}
	int flag = 1;

	if (mm.empty())
	{
		printf("0");
	}

	while (!mm.empty())
	{
		if (flag)
		{
			printf("m%d", mm.front());
			mm.pop();
			flag = 0;
		}
		else
		{
			printf(" ? m%d", mm.front());
			mm.pop();
		}
	}

	printf(" ; ");

	if (MM.empty())
	{
		printf("1");
	}

	flag = 1;
	while (!MM.empty())
	{
		if (flag)
		{
			printf("M%d", MM.front());
			MM.pop();
			flag = 0;
		}
		else
		{
			printf(" ? M%d", MM.front());
			MM.pop();
		}
	}
	printf("\n");
	return 0;
}

bool operate()
{
	char theta;
	bool a, b, c;

	b = ans.top();
	ans.pop();
	theta = op.top();
	op.pop();
	if (theta != '!')
	{
		a = ans.top();
		ans.pop();
	}

	switch (theta)
	{
	case '!':
		c = !b;
		break;
	case '&':
		c = a && b;
		break;
	case '|':
		c = a || b;
		break;
	case '-':
		c = !a || b;
		break;
	case '+':
		c = (!a || b) && (!b || a);
		break;
	}

	return c;
}

int compare(char a, char b)
{
	int c[2] = {a, b};
	for (int i = 0; i < 2; i++)
		switch (c[i])
		{
		case '+':
			c[i] = 0;
			break;
		case '-':
			c[i] = 1;
			break;
		case '|':
			c[i] = 2;
			break;
		case '&':
			c[i] = 3;
			break;
		case '!':
			c[i] = 4;
			break;
		case '(':
			c[i] = 5;
			break;
		case ')':
			c[i] = 6;
			break;
		case '#':
			c[i] = 7;
			break;
		}

	return complist[c[0]][c[1]];
}

int chtype(char c) //op:0	num:1	error:-2
{
	if (c == '\n')
		return -3; //end
	for (int i = 0; oplist[i] != 10; i++)
		if (c == oplist[i])
			return 0; //op
	return 1;		  //num
}

