#include<stdio.h>

struct linkedlist
{
	int value;
	struct linkedlist* prev;
	struct linkedlist* next;
};

int main(int argc, char** args)
{
	struct linkedlist ll;
	ll.value = 20;
	
	struct linkedlist ll2;
	ll2.value = 30;
	
	ll.next = &ll2;
	ll2.prev = &ll;
	
	struct linkedlist* l = &ll;
	
	for (int i = 0; i < 2; i++)
	{
		printf("%d", l->value);
		l = l->next;
	}
	#printf("%d", ll.next->value);
}