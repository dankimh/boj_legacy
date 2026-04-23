#include<stdio.h>
int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = 0;i < 2 * n;i++) {
		for (j = 0;j < n;j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0)printf("*");
				else printf(" ");
			}
			else {
				if (j % 2 == 0)printf(" ");
				else printf("*");
			}
		}
		printf("\n");
	}
}