#include<stdio.h>
#include<stdlib.h>
int n,i,a[50],aa,bb;
int main(){scanf("%d",&n);for(i=0;i<n;i++)scanf("%d",&a[i]);if(n==1)printf("A");else if(n==2){if(a[0]==a[1])printf("%d",a[0]);else printf("A");}else{if(a[0]==a[1]){for(i=2;i<n;i++){if(a[i-1]!=a[i]){printf("B");exit(0);}}printf("%d",a[0]);}else{aa=(a[2]-a[1])/(a[1]-a[0]);bb=a[1]-aa*a[0];for(i=2;i<n;i++){if(a[i]!=aa*a[i-1]+bb){printf("B");exit(0);}}printf("%d",a[n-1]*aa+bb);}}}
