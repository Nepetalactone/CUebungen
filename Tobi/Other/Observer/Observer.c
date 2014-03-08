#include "Observer.h"

void obs_add(struct Observer * obs, struct Subscriber * sub)
{
	if (obs->list != NULL)
	{
		Node_t * iter = obs->list;
	
		while (iter->next != NULL)
		{
			iter++;
		}
	
		Node_t * node = newNode(sub);
		iter->next = node;
	} else 
	{
		Node_t * node = newNode(sub);
		obs->list = node;
	}
	printf("added node %d\n", sub->number);
}

void obs_remove(struct Observer * obs, struct Subscriber * sub)
{
	Node_t * iter = obs->list;
	
	while (iter->next->sub != sub)
	{
		iter++;
	}
	
	if (iter->next->next == NULL)
	{
		iter->next = NULL;
	}
	else
	{
		Node_t * skip = iter->next->next;
		iter->next = skip;
	}
}

void obs_propagate(struct Observer * obs, char * message)
{
	Node_t * iter = obs->list;
	
	if (iter != NULL)
	{
		do
		{
			iter->sub->notify(message, iter->sub);
			iter++;
		} while (iter->next != NULL);
	}
}

void obs_delete(struct Observer * obs)
{
	free(obs);
	obs = NULL;
}

Node_t * newNode(struct Subscriber * newSub)
{
	Node_t * node = (Node_t*) malloc(sizeof(Node_t));
	node->sub = newSub;
	node->next = NULL;
	return node;
}

Observer_t * newObserver()
{
	Observer_t * obs = (Observer_t*) malloc(sizeof(Observer_t));
	obs->list = NULL;
	obs->add = obs_add;
	obs->remove = obs_remove;
	obs->propagate = obs_propagate;
	obs->delete = obs_delete;
	return obs;
}