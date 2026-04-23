/*#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int n, a[1000],i,j;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)scanf_s("%d", &a[i]);
	sort(a,a+  n - 1);
	for (j = 0; j < n; j++)printf("%d\n", a[i]);
}*/
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
queue<int> a;
int main() {
	int n, i;
	char b[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", b);
		if (!strcmp(b, "push")) {
			//printf("1\n");
			int k;
			scanf("%d", &k);
			a.push(k);
		}
		else if (!strcmp(b,"pop")) {
			if (a.empty())printf("-1\n");
			else {
				printf("%d\n", a.front());
				a.pop();
			}
		}
		else if (!strcmp(b, "size")) {
			printf("%d\n", a.size());
		}
		else if (!strcmp(b, "empty")) {
			printf("%d\n", a.empty());
		}
		else if (!strcmp(b, "front")) {
			if (a.empty())printf("-1\n");
			else printf("%d\n", a.front());
		}
		else if (!strcmp(b, "back")) {
			if (a.empty())printf("-1\n");
			else printf("%d\n", a.back());
		}
	}
}