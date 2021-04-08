#include<stdio.h>
#include<ctype.h>

#define MAXHIST 15			/*直方图最大长度*/
#define MAXCHAR 128			/*不同字符总数*/

/*打印输入中各字符出现频度的直方图*/
main() 
{
	int c, i;
	int len;				/*打印的相对长度*/
	int maxvalue;			/*cc【】最大长度值*/
	int cc[MAXCHAR];		/*记录字符出现频数*/

	for (i = 0; i < MAXCHAR; ++i)
		cc[i] = 0;
	while ((c = getchar()) != EOF)
		if (c < MAXCHAR)
			++cc[c];

	maxvalue = 0;
	for (i = 1; i < MAXCHAR; ++i)
		if (maxvalue < cc[i])
			maxvalue = cc[i];

	for (i = 1; i < MAXCHAR; ++i) {
		if (isprint(i))
			printf("%5d - %c - %5d", i, i, cc[i]);
		else
			printf("%5d -    - %5d", i, cc[i]);
		if (cc[i] > 0) {
			if ((len = cc[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		}
		else
			len = 0;
		while (len > 0) {
			putchar('*');
			--len;
		}
		putchar('\n');
	}
}