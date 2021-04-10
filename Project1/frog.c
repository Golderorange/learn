#include<stdio.h>
int plan(int two,int three,int jump);

main()
{
	int n;
	int two, three, jump;
	int count;
	scanf_s("%d",&n);
	jump = (n + 1) / 2;
	two = jump-1;
	three = 1;
	count = plan(two,three,jump);
	printf("%d \n", count+1);
}

int plan(int two,int three, int jump) {
	int static count = 0;
	int counter=0;
	int i, j, k;
	int up = 1;
	int downle = 1;
	int downri = 1;
	for (i = 1; i <= two; i++)
		downle *= i;
	for (j = 1; j <= three; j++)
		downri *= j;
	for (k = 1; k <= jump; k++)
		up *= k;
	counter = up / (downle * downri);
	three++;
	two--;
	if (three % 2 == 0) {
		two--;
		jump--;
	}
	if (two != 0 && two != -1) {
		plan(two, three, jump);
	}
	count += counter;
	return count;
}