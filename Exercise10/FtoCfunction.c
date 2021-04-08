#include<stdio.h>

#define UPPER 300

float celsius(float fahr);


main()
{
	float fahr;
	int lower, step;

	step = 20;

	printf("fahr  celsius\n");
	for (lower = 0; lower < UPPER; lower += step) {
		fahr = lower;
		float celsius(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius(fahr));
	}
}

float celsius(float fahr) {
	return (5.0 / 9.0) * (fahr - 32.0);
}