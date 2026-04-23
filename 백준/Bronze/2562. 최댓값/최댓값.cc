#include<stdio.h>
int main() {
	int i, a[9];
	int max = 0,witch=0;
	for (i = 0;i < 9;i++) {
		scanf("%d", &a[i]);
		if (a[i] > max) { max = a[i];witch = i; }
	}
	printf("%d\n%d", max, witch+1);
}