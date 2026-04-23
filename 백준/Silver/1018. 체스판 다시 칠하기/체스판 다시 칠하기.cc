#include<stdio.h>
#include<string.h>
#include<algorithm>
int main(){
    int n,m;
    char aa;
    char a[50][50];
    int b[10000],c=0;
    int i,j;
    for(i=0;i<10000;i++)b[i]=0xffff;

    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]=='W')a[i][j]=0;
            if(a[i][j]=='B')a[i][j]=1;
        }
    }
    for(i=0;i<n-7;i++){
        for(j=0;j<m-7;j++){
            int k,l,ch=0,cnt=0;
            for(k=i;k<i+8;k++){
                for(l=j;l<j+8;l++){
                    if(a[k][l]!=ch)cnt++;
                    ch++;
                    ch%=2;
                }
                ch++;
                ch%=2;
            }
            ch=1;
            b[c]=cnt;
            c++;
            cnt=0;
            for(k=i;k<i+8;k++){
                for(l=j;l<j+8;l++){
                    if(a[k][l]!=ch)cnt++;
                    ch++;
                    ch%=2;
                }
                ch++;
                ch%=2;
            }
            b[c]=cnt;
            c++;
        }
    }
    std::sort(b,b+10000);
    printf("%d",b[0]);
}
