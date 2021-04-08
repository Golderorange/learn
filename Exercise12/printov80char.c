#include<stdio.h>
#define MAXLINE 1000			/*������д�С*/
#define LONGLINE 80

int getline(char line[],int maxline);

/*��ӡ���ȴ���80���ַ�������������*/
main()
{
	int len;				/*׼ȷ�г���*/
	char line[MAXLINE];		/*׼ȷ������*/

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
			s[j] = c;			/*���ڱ߽緶Χ��*/
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