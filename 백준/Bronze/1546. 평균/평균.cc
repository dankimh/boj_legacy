#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int n,i;
	double a[1000];
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		scanf("%lf", &a[i]);
	}
	sort(a, a + n);
	for (i = 0;i < n;i++) {
		a[i] = a[i] * 100 / a[n - 1];
	}
	double sum = 0;
	for (i = 0;i < n;i++) {
		sum += a[i];
	}
	printf("%g", sum / n);
}