#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
stack<int> a;
int main() {
	int n, i;
	char b[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", b);
		if (!strcmp(b, "push")) {
			int k;
			scanf("%d", &k);
			a.push(k);
		}
		else if (!strcmp(b,"pop")) {
			if (a.empty())printf("-1\n");
			else {
				printf("%d\n", a.top());
				a.pop();
			}
		}
		else if (!strcmp(b, "size")) {
			printf("%d\n", a.size());
		}
		else if (!strcmp(b, "empty")) {
			printf("%d\n", a.empty());
		}
		else if (!strcmp(b, "top")) {
			if (a.empty())printf("-1\n");
			else printf("%d\n", a.top());
		}
	}
}