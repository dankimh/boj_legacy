#include<stdio.h>
#include<stdlib.h>
int n,mp[9][9];
void f(int t){
    int i,j;

    //_sleep(100);
    /*for(i=0;i<9;i++){
        for(j=0;j<9;j++)printf("%d ",mp[i][j]);
        printf("\n");
    }*/
    int x=t/9;
    int y=t%9;

    if(t==81){
        for(i=0;i<9;i++){
        for(j=0;j<9;j++)printf("%d ",mp[i][j]);
        printf("\n");
    }
    exit(0);
    }
    int cc=0;
    int ch[10]={0,};
    if(mp[x][y]==0){
        cc=1;
        for(int k=0;k<9;k++){
            ch[mp[k][y]]++;
            ch[mp[x][k]]++;
        }
        for(int k=(x/3)*3;k<(x/3)*3+3;k++){
            for(int l=(y/3)*3;l<(y/3)*3+3;l++){
                //printf("kl%d %d\n",k,l);
                ch[mp[k][l]]++;
            }
        }
        //for(int k=1;k<=9;k++)printf("%d\n",ch[k]);
        for(int k=1;k<=9;k++){
            if(ch[k]==0){
                cc=2;
                mp[x][y]=k;
                f(t+1);
                mp[x][y]=0;
            }
        }
    }
    else f(t+1);
    /*if(cc==1){printf("x%d %d %d\n",x,y,t);
        mp[x][y]=0;
        return;
    }*/
}
int main(){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){scanf("%d",&mp[i][j]);}
    }
    f(0);
}