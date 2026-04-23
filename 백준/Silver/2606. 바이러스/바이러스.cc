#include<bits/stdc++.h>
int p[101],h[101];
int f(int a){
    if(p[a]==a)return a;
    else return p[a]=f(p[a]);
}
void u(int a,int b){
    a=f(a);
    b=f(b);
    if(h[a]>h[b]){
        int t=a;
        a=b;
        b=t;
    }
    if(h[a]==h[b])h[a]++;
    p[a]=b;
}
int main(){
    int n,m,i;
    int a,b,c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        h[i]=1;
        p[i]=i;
    }
    for(i=0;i<m;i++){
        scanf("%d %d",&b,&c);
        u(b,c);
    }
    int ch=0;
    for(i=2;i<=n;i++){
        if(f(1)==f(i))ch++;
    }
    printf("%d",ch);
}