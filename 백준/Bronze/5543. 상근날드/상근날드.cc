#include<stdio.h>
int main() {
	int a[3], b[2],i,j,max=0xffff;
	scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &b[0], &b[1]);
	for (i = 0;i < 3;i++) {
		for (j = 0;j < 2;j++)if (a[i] + b[j] < max)max = a[i] + b[j];
	}
	printf("%d", max-50);
}