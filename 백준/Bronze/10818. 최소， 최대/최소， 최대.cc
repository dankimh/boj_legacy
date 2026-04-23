#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int n, i, a[1000000];
	scanf("%d", &n);
	for (i = 0;i < n;i++)scanf("%d", &a[i]);
	sort(a, a + n);
	printf("%d %d", a[0], a[n-1]);
}