#include "Subscriber.h"

void sub_notify(char * message, struct Subscriber * sub)
{
	printf("%d ", sub->number);
	
	int i;
	for (i = 0; i < 9; i++)
	{
		printf("%c", *message++);
	}
	printf("\n");
}

void sub_delete(struct Subscriber * sub)
{
	printf("deleting1\n");
	free(sub);
	printf("deleting2\n");
	sub = NULL;
	printf("deleting3\n");
}

Subscriber_t * newSubscriber(int no)
{
	Subscriber_t * sub = (Subscriber_t*) malloc(sizeof(Subscriber_t));
	sub->number = no;
	sub->notify = sub_notify;
	return sub;
}