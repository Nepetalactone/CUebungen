#include "UpperInputStream.h"

main()
{
	InputStream_t * inputStream = newInputStream();
	FilterInputStream_t * filterInputStream = newFilterInputStream(inputStream);
	UpperInputStream_t * upperInputStream = newUpperInputStream(filterInputStream);
	
	int i;
	
	for (i = 0; i < 20; i++)
	{
		printf("%c", upperInputStream->next(upperInputStream));
	}
}