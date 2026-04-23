#include<stdio.h>
int map[128][128],wh,bl;
void f(int x1,int y1,int x2,int y2){
    if(x1==x2&&y1==y2){
        if(map[x1][y1]==0)wh++;
        if(map[x1][y1]==1)bl++;
        return;
    }
    int i,j,ch=map[x1][y1],succ=1;
    for(i=x1;i<=x2;i++){
        for(j=y1;j<=y2;j++){
            if(map[i][j]!=ch){
                succ=0;
                break;
            }
            if(succ==0)break;
        }
    }
    if(!succ){
        f(x1,y1,(x1+x2+1)/2-1,(y1+y2+1)/2-1);
        f(x1,(y1+y2+1)/2,(x1+x2+1)/2-1,y2);
        f((x1+x2+1)/2,y1,x2,(y1+y2+1)/2-1);
        f((x1+x2+1)/2,(y1+y2+1)/2,x2,y2);
    }
    else{
        if(map[x1][y1]==0)wh++;
        if(map[x1][y1]==1)bl++;
        return;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }
    f(0,0,n-1,n-1);
    printf("%d\n%d",wh,bl);
}