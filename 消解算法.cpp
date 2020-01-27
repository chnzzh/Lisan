#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef struct node {
	int type;				//-1 0 1
	char data;
	struct node * next;
} Node, *NPtr;

typedef struct nodes {
	NPtr first;
	NPtr last;
	NPtr next;
	int size;
} Nodes , *NSPtr;
typedef struct {
	NSPtr first;
	NSPtr last;
	int size;
} SS;

char oplist[] = {'!', '&', '|', '-', '+', '(', ')', 10};

void INITSS(SS* s);
int chtype(char c); //op:0 number:1 end:-2
int main()
{
	SS s0, s1, s2, s;
	INITSS(&s0); INITSS(&s1); INITSS(&s2);
	
	char c = getchar();
	int newflag = 1, fflag = 0;
	
	while(c != '\n')
	{
		if (newflag)
		{
			NSPtr temp = (NSPtr)malloc(sizeof(Nodes));
			INITNS(temp);
			s->last->next = temp;
			s->last = temp;
			
			newflag = 0;
			if(c == '(')
				c = getchar();
		}
		
		if(chtype(c) == 1)		//ch
		{
			NPtr n;
			n = (NPtr)malloc(sizeof(Node));
			
			n->type = fflag;
			n->data = c;
			n->next = NULL;
			
			
		}
		
	}
	
	return 0;
}

void INITSS(SS* s)
{
	s->first = s->last = (SS*)malloc(sizeof(SS));
	s->size = 0;
}
void INITNS(NSPtr ns)
{
	ns->first = ns->last = (NSPtr)malloc(sizeof(Nodes));
	ns->next = NULL;
	ns->size = 0;
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
