#include<stdio.h>

#define MAXHIST 15			/*直方图最大长度*/
#define MAXWORD 11			/*单词最大长度*/
#define IN 1				/*输入一个词*/
#define OUT 0				/*输出一个词*/

/*打印水平直方图*/
main() {
	int c, i, nc, state;
	int len;				/*相对长度*/
	int maxvalue;			/*数组wl中的最大值*/
	int ovflow;				/*长度过载单词数*/
	int wl[MAXWORD];		/*单词长度计数*/

	state = OUT;
	nc = 0;					/*一个单词中的字符数目*/
	ovflow = 0;				/*长度过载单词数*/

	for (i = 0; i < MAXWORD; ++i)
		wl[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (nc > 0)
				if (nc < MAXWORD)
					++wl[nc];
				else
					++ovflow;
			nc = 0;
		}
		else if (state == OUT) {
			state = IN;
			nc = 1;
		}else
			++nc;
	}
	maxvalue = 0;
	for (i = 1; i < MAXWORD; ++i)
		if (wl[i] > maxvalue)
			maxvalue = wl[i];
	for (i = 1; i < MAXWORD; ++i) {
		printf("%5d - %5d：", i, wl[i]);
		if (wl[i] > 0) {
			if ((len = wl[i] * MAXHIST / maxvalue) <= 0)	/*按比例缩放，根据*出现的比例观察出现次数的多少*/
				len = 1;
		}else
			len = 0;
		while (len > 0) {
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	if (ovflow > 0)
		printf("There are %d words >= %d\n", ovflow, MAXWORD);
}