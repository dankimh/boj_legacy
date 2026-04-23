#include<stdio.h>
#include<algorithm>
int n,c[25][25],d[5]={1,0,-1,0,1},p=0;
char m[25][25];
void f(int x,int y,int cnt){//printf("x: %d, y: %d, c: %d, p: %d\n",x+1,y+1,cnt,p);
    p++;
    c[x][y]=1;
    int i;
    for(i=0;i<4;i++){
        if(x+d[i]>=0&&x+d[i]<n&&y+d[i+1]>=0&&y+d[i+1]<n&&c[x+d[i]][y+d[i+1]]==0&&m[x+d[i]][y+d[i+1]]==1)f(x+d[i],y+d[i+1],cnt+1);
    }
    return;
}
int main(){
    int i,j,cnt=0,a[700];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",&m[i]);
        for(j=0;j<n;j++){
            m[i][j]-='0';
            //printf("%d ",m[i][j]);
        }
    }
    //for(i=0;i<n;i++,printf("\n"))for(j=0;j<n;j++)printf("%d ",m[i][j]);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(m[i][j]==1&&c[i][j]==0){
                //printf("a%d %d\n",i,j);
                f(i,j,1);
                a[cnt]=p;
                p=0;
                //printf("cnt : %d\n",a[cnt]);
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    std::sort(a,a+cnt);
    for(i=0;i<cnt;i++)printf("%d\n",a[i]);
}
