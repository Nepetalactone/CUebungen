#include <stdio.h>
#define TRUE 0
#define FALSE 1
typedef int bool;
typedef char byte;

typedef struct InputStream
{
	char * stream;
	int index;
	bool (*hasNext)(struct InputStream * input);
	byte (*next)(struct InputStream * input);
	void (*delete)(struct InputStream * input);
} InputStream_t;

bool is_hasNext(struct InputStream * input)
{
	char * c = input->stream;
	c += input->index;
	//printf("2%c\n", *c);
	c += 1;
	//printf("3%c\n", *c);
	if (c == '\0')
	{
		return FALSE;
	}
	return TRUE;
}

byte is_next(struct InputStream * input)
{
	char * c = input->stream;
	c += input->index;
	if (is_hasNext(input) == TRUE)
	{
		input->index++;
	}
	return * c;
}

void is_delete(struct InputStream * input)
{
}

InputStream_t is_instance = { "blablabla\0", 0, &is_hasNext, &is_next, &is_delete };

typedef struct FilterInputStream
{
	InputStream_t * is;
	bool (*hasNext)(struct FilterInputStream * fis);
	byte (*next)(struct FilterInputStream * fis);
	void (*delete) (struct FilterInputStream * fis);
} FilterInputStream_t;

bool fis_hasNext(struct FilterInputStream * fis)
{
	return fis->is->hasNext(fis->is);
}

byte fis_next(struct FilterInputStream * fis)
{
	return fis->is->next(fis->is);
}

void fis_delete(struct FilterInputStream * fis)
{
}

FilterInputStream_t fis_instance = { &is_instance, &fis_hasNext, &fis_next, &fis_delete };

typedef struct UpperCaseStream
{
	FilterInputStream_t * fis;
	bool (*hasNext)(struct UpperCaseStream * ucs);
	byte (*next)(struct UpperCaseStream * ucs);
	void (*delete)(struct UpperCaseStream * ucs);
} UpperCaseStream_t;

bool ucs_hasNext(struct UpperCaseStream * ucs)
{
	return ucs->fis->hasNext(ucs->fis);
}

byte ucs_next(struct UpperCaseStream * ucs)
{
	char c = ucs->fis->next(ucs->fis);
	
	if ((c >= 'a') || (c <= 'z'))
	{
		c += 'A' - 'a';
	}
	return c;
}

void ucs_delete(struct UpperCaseStream * ucs)
{
	
}

UpperCaseStream_t ucs_instance = { &fis_instance, &ucs_hasNext, &ucs_next, &ucs_delete }; 

void main()
{
	int i = 0;
	while ((i < 100) && (ucs_instance.hasNext(&ucs_instance) == TRUE))
	{
		//ucs_instance.next(&ucs_instance);
		printf("%c", ucs_instance.next(&ucs_instance));
		//printf("%d\n\n", i);
		i++;
	}
}