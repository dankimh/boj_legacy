#include<bits/stdc++.h>
int p[1000001],h[1000001];
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
    for(i=0;i<=n;i++){
        h[i]=1;
        p[i]=i;
    }
    for(i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        if(a==0)u(b,c);
        if(a==1){
            if(f(b)==f(c))printf("YES\n");
            else printf("NO\n");
        }
    }
}
