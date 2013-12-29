#include <stdio.h>

main()
{
	float fahr, celsius;
	float lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	fahr = lower;
	
	printf("Fahrenheit\tCelsius\n");
	
	while (fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f \t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	
	printf("\n\nCelsius\tFahrenheit\n");
	
	celsius = 0;
	fahr = 0;
	
	while (celsius <= upper)
	{
		fahr = (9.0/5.0)*celsius + 32.0;
		printf("%3.0f \t%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
	
	fahr = 0;
	celsius = 0;
	
	printf("\n\nFahrenheit\tCelsius\n");
	
	for (fahr = 300; fahr >= 0; fahr = fahr - step)
	{
			printf("%3.0f \t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}
}