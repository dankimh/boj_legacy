#include<stdio.h>
int main() {
	int a, b, c;
	int i;
	int ch[10] = { 0, };
	scanf("%d %d %d", &a, &b, &c);
	int n;
	n = a * b * c;
	while (n > 0) {
		ch[n % 10]++;
		n /= 10;
	}
	for (i = 0;i < 10;i++) {
		printf("%d\n", ch[i]);
	}
}