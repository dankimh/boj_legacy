#include<bits/stdc++.h>
int main(){
    int n,i,j,a[1000][1000],p,x=0,y=0,c=1,t,xx,yy;
    scanf("%d %d",&n,&t);
    p=n-1;
    if(p==0){
        printf("1");
        exit(0);
    }
    for(;;){
        for(i=0;i<p;i++){
            a[x][y]=c;
            c++;
            x++;
        }
        if(c==n*n+1)break;
        for(i=0;i<p;i++){
            a[x][y]=c;
            c++;
            y++;
        }
        if(c==n*n+1)break;
        for(i=0;i<p;i++){
            a[x][y]=c;
            c++;
            x--;
        }
        if(c==n*n+1)break;
        for(i=0;i<p;i++){
            a[x][y]=c;
            c++;
            y--;
        }
        if(c==n*n+1)break;
        if(p==2)p--;
        else p-=2;
        x++;
        y++;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(t==n*n+1-a[i][j]){xx=i;yy=j;}
            printf("%d ",n*n+1-a[i][j]);
        }
        printf("\n");
    }
    printf("%d %d",xx+1,yy+1);
}