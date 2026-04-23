#include<stdio.h>
int main(){
	int n,i,k;
	scanf("%d",&n);
	long long int p[n];
	p[0]=1,p[1]=1;
	for(i=2;i<n;i++){
		p[i]=p[i-1]+p[i-2];
	}
	for(i=n;i<=n;i++){
		printf("%lld",p[n-1]);
	}
}