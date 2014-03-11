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
	free(sub);
	sub = NULL;
}

Subscriber_t * newSubscriber(int no)
{
	Subscriber_t * sub = (Subscriber_t*) malloc(sizeof(Subscriber_t));
	sub->number = no;
	sub->notify = sub_notify;
	sub->delete = sub_delete;
	return sub;
}