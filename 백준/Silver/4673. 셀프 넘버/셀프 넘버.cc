#include<stdio.h>
int d(int n) {
	int sum=n;
	while (n>0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int main() {
	bool a[10001] = { 0, };
	int i;
	for (i = 1;i < 10001;i++) {
		if(d(i)<10001)a[d(i)] = true;
	}
	for (i = 1;i < 10001;i++) {
		if (!a[i])printf("%d\n", i);
	}
}