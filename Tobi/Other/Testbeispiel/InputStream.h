#ifndef INPUTSTREAM_H_
#define INPUTSTREAM_H_ 
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

typedef struct InputStream
{
	char * stream;
	int index;
	bool (*hasNext)(struct InputStream * input);
	byte (*next)(struct InputStream * input);
	void (*delete)(struct InputStream * input);
} InputStream_t;

InputStream_t * newInputStream();

#endif