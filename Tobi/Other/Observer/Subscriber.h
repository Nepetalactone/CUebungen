#include <stdio.h>
#include <stdlib.h>

typedef struct Subscriber
{
	int number;
	void (*notify)(char * message, struct Subscriber * sub);
	void (*delete)(struct Subscriber * sub);
} Subscriber_t;

Subscriber_t * newSubscriber();