#include<stdio.h>
char a[64][64];
void f(int x1,int y1,int x2,int y2){
    if(x1==x2&&y1==y2){
        if(a[x1][y1]=='0')printf("0");
        if(a[x1][y1]=='1')printf("1");
        return;
    }
    int i,j,succ=1;
    char ch=a[x1][y1];
    for(i=x1;i<=x2;i++){
        for(j=y1;j<=y2;j++){
            if(a[i][j]!=ch){
                succ=0;
                break;
            }
            if(succ==0)break;
        }
    }
    if(!succ){
        printf("(");
        f(x1,y1,(x1+x2+1)/2-1,(y1+y2+1)/2-1);
        f(x1,(y1+y2+1)/2,(x1+x2+1)/2-1,y2);
        f((x1+x2+1)/2,y1,x2,(y1+y2+1)/2-1);
        f((x1+x2+1)/2,(y1+y2+1)/2,x2,y2);
        printf(")");
    }
    else{
        if(a[x1][y1]=='0')printf("0");
        if(a[x1][y1]=='1')printf("1");
        return;
    }
    return;
}
int main(){
    int n;
    scanf("%d\n",&n);
    int i,j;
    for(i=0;i<n;i++)scanf("%s",a[i]);
    f(0,0,n-1,n-1);
}