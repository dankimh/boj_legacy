#include<stdio.h>
bool check(int n) {
	if (n == 1000)return false;
	if (n < 100)return true;
	if ((n / 10) % 10 - n % 10 != (n / 100) % 10 - (n / 10) % 10)return false;
	return true;
}
int main() {
	int n;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		if (check(i))sum++;
	}
	printf("%d", sum);
}
