#include<stdio.h>
int main() {
	int n,a,i=0;
	scanf("%d", &n);
	a = n;
	while (1) {
		a = ((a % 10) * 10) + (((a / 10)) + (a % 10)) % 10;
		i++;
		if (a == n) { printf("%d", i); break; }
	}
}