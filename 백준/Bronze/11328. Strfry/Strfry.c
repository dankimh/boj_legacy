#include<stdio.h>
#include<string.h>
int main() {
	char a[1001], b[1001];
	int n, i, j, c[1000], d[1000];
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < 1000; j++) { c[j] = 0; d[j] = 0; }
		int e = 1;
		scanf("%s %s", a, b);
		if(strlen(a)!=strlen(b)){printf("Impossible\n");continue;}
		for(j=0;j<(int)strlen(a);j++){
			c[a[j]-'a']++;
			d[b[j]-'a']++;
		}
		for(j=0;j<1000;j++){
			if(c[j]!=d[j])e=0;
		}
		if(e)printf("Possible\n");
		else printf("Impossible\n");
	}
	
}