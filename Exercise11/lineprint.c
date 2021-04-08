#include<stdio.h>
#define MAXLINE 1000			/*最长输入行大小*/

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/*输出最长输入行（主）*/
main()
{
	int len;					/*准确行长度*/
	int max;					/*至今为止最长行*/
	char line[MAXLINE];			/*准确输入行*/
	char longest[MAXLINE];		/*保存最长行*/

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0) {
		printf("%d, %s", len, line);
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)			/*为一行内容*/
		printf("%s", longest);
	return 0;
}
/*读入一行，并返回行长度*/
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
/*将from中的内容复制到to中*/
void copy(char to[], char from[]) 
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}