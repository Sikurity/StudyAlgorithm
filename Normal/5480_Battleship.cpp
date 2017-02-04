/**
*	@link	https://www.acmicpc.net/problem/5480
*	@date	2017. 02. 04 18:01
*	@author	Sikurity
*	@method Simple Linked List
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

typedef struct _LIST
{
	int data;
	struct _LIST *next;
} LIST;
typedef struct _BATTLESHIP
{
	int sx, sy, ex, ey, w;
} BATTLESHIP;

LIST *head, *tail;

void push(int val)
{
	tail->data = val;
	tail->next = (LIST *)malloc(sizeof(LIST));
	tail = tail->next;
	tail->data = 0;
	tail->next = NULL;
}

void pop()
{
	LIST *p = head;
	head = head->next;
	free(p);
}

void init()
{
	head = (LIST *)malloc(sizeof(LIST));
	head->data = 0;
	head->next = 0;
	tail = head;
}

void destroy()
{
	while(head)
		pop();
}

BATTLESHIP ship[100001];
LIST *p, *ph;

int main()
{
	int t, n, k, l;
	int point, wh;
	int i, j, temp;

	scanf("%d", &t);
	while(t--)
	{
		init();

		scanf("%d %d %d", &n, &k, &l);

		push(0);
		for(i = 0; i < k; i++)
		{
			scanf("%d %d %d %d %d", &ship[i].sx, &ship[i].sy, &ship[i].ex, &ship[i].ey, &ship[i].w);

			if(ship[i].sx > ship[i].ex){ temp = ship[i].sx; ship[i].sx = ship[i].ex; ship[i].ex = temp; }
			if(ship[i].sy > ship[i].ey){ temp = ship[i].sy; ship[i].sy = ship[i].ey; ship[i].ey = temp; }

			push(i);
		}

		for(i = 0; i < l; i++)
		{
			scanf("%d %d", &point, &wh);
			int max = 0;
			ph = head;
			if(wh)
			{
				for(p = head->next; p; ph = p, p = p->next)
				{
					j = p->data;
					if(ship[j].sx <= point&&point <= ship[j].ex)
					{
						max = max < ship[j].w ? ship[j].w : max;
						ph->next = p->next;
						free(p);
						p = ph;
					}
				}
			}
			else
			{
				for(p = head->next; p; ph = p, p = p->next)
				{
					j = p->data;
					if(ship[j].sy <= point&&point <= ship[j].ey)
					{
						max = max < ship[j].w ? ship[j].w : max;
						ph->next = p->next;
						free(p);
						p = ph;
					}
				}
			}
			
			printf("%d\n", max);
		}

		destroy();
	}

	return 0;
}