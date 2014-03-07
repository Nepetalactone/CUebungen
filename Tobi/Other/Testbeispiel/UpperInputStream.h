#include "FilterInputStream.h"

typedef struct UpperInputStream
{
	FilterInputStream_t * fis;
	bool (*hasNext)(struct UpperInputStream * uis);
	byte (*next)(struct UpperInputStream * uis);
	void (*delete)(struct UpperInputStream * uis);
} UpperInputStream_t;

UpperInputStream_t * newUpperInputStream(FilterInputStream_t * input);