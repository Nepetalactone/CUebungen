#ifndef FILTERINPUTSTREAM_H_
#define FILTERINPUTSTREAM_H_
#include "InputStream.h"

typedef struct FilterInputStream
{
	InputStream_t * is;
	bool (*hasNext)(struct FilterInputStream * fis);
	byte (*next)(struct FilterInputStream * fis);
	void (*delete)(struct FilterInputStream * fis);
} FilterInputStream_t;

FilterInputStream_t * newFilterInputStream(InputStream_t * input);

#endif