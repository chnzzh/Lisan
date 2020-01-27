#include <cstdio>
#include <cstring>
#define N 30
bool dic[N], min[N], max[N];
int main()
{
	memset(dic, false, sizeof(dic));
	memset(min, true, sizeof(min));
	memset(max, true, sizeof(max));
	char c;
	while ((c = getchar()) != '\n')
	{
		if (c >= 'a' && c <= 'z') dic[c - 'a'] = true;
	}
	c = getchar();
	while (c != '\n')
	{
		while (c < 'a' || c > 'z') c = getchar();
		max[c - 'a'] = false;
		c = getchar();
		while (c < 'a' || c > 'z') c = getchar();
		min[c - 'a'] = false;
		c = getchar();
		while (c != '\n' && (c < 'a' || c > 'z')) c = getchar();
	}
	int i = 0;
	while (!dic[i] || !min[i]) i++;
	printf("%c", i + 'a');
	for (i++; i < 26; i++)
		if (dic[i] && min[i]) printf(",%c", i + 'a');
	printf("\n");
	i = 0;
	while (!dic[i] || !max[i]) i++;
	printf("%c", i + 'a');
	for (i++; i < 26; i++)
		if (dic[i] && max[i]) printf(",%c", i + 'a');
	printf("\n");
	return 0;
}
