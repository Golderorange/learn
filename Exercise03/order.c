#include<stdio.h>

/*print Fahrenheit-Celsius table in reverse order*/
main()
{
	int fahr;
	for (fahr = 300; fahr >= 0; fahr -= 20)
		printf("%3d %6.lf\n", fahr, (fahr-32)* (5.0 / 9.0));
}