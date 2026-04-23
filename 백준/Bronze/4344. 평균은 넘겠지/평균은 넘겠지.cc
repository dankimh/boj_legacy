#include<stdio.h>
int main() {
	int a[1000];
	int c, i;
	scanf("%d", &c);
	for (i = 0;i < c;i++) {
		int n, j;
		
		int sum = 0,ch=0;
		scanf("%d", &n);
		for (j = 0;j < n;j++) {
			scanf("%d", &a[j]);
			sum += a[j];
		}
		for (j = 0;j < n;j++) {
			if ((double)a[j] > (double)(sum)/n) {
				ch++;
			}
		}
		printf("%.3lf%%\n", (double)(ch*100) / n);
	}
}