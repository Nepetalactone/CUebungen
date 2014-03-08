#include "Observer.h"

main()
{
	Observer_t * obs = newObserver();
	Subscriber_t * firstSub = newSubscriber(1);
	Subscriber_t * secondSub = newSubscriber(2);
	Subscriber_t * thirdSub = newSubscriber(3);
	
	obs->add(obs, firstSub);
	obs->add(obs, secondSub);
	obs->add(obs, thirdSub);
	
	obs->propagate(obs, "blablabla");
	
	obs->remove(obs, secondSub);
	
	obs->propagate(obs, "blablabla");
}