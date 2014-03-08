#include "Subscriber.h"

typedef struct Node
{
	Subscriber_t * sub;
	struct Node * next;
} Node_t;

typedef struct Observer
{
	Node_t * list;
	void (*add)(struct Observer * obs, struct Subscriber * sub);
	void (*remove)(struct Observer * obs, struct Subscriber * sub);
	void (*propagate)(struct Observer * obs, char * message);
	void (*delete)(struct Observer * obs);
} Observer_t;

Node_t * newNode(struct Subscriber * newSub);
Observer_t * newObserver();