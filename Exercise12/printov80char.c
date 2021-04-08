#include<stdio.h>
#define MAXLINE 1000			/*最长输入行大小*/
#define LONGLINE 80

int getline(char line[],int maxline);

/*打印长度大于80个字符的所有输入行*/
main()
{
	int len;				/*准确行长度*/
	char line[MAXLINE];		/*准确输入行*/

	while ((len = getline(line, MAXLINE)) > 0)
		if (len > LONGLINE)
			printf("%s", line);
	return 0;
}

int getline(char s[], int lim)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < lim - 2) {
			s[j] = c;			/*仍在边界范围内*/
			++j;
		}
	if (c == '\n') {
		s[j] = c;
		++j;
		++i;
	}
	s[j] = '\0';
	return i;
}