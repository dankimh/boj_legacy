#include<iostream>
#include<string.h>
#define ull unsigned long long
#define max(a,b) a>b?a:b
struct hang{
    char a;
    char b;
    char c;
};
bool operator==(struct hang &a, struct hang &b){
    return (a.a==b.a&&a.b==b.b&&a.c==b.c);
}
using namespace std;
int ch[3001][3001]={0,};
int main(){
    int i,j;
    char a[3000],b[3000];
    struct hang ha[1000],hb[1000];
    scanf("%s\n%s",a,b);
    for(i=0;i<strlen(a);i+=3){
        ha[i/3].a=a[i];
        ha[i/3].b=a[i+1];
        ha[i/3].c=a[i+2];
    }
    for(i=0;i<strlen(b);i+=3){
        hb[i/3].a=b[i];
        hb[i/3].b=b[i+1];
        hb[i/3].c=b[i+2];
    }
    for(i=1;i<=strlen(a)/3;i++){
        for(j=1;j<=strlen(b)/3;j++){
            if(ha[i-1]==hb[j-1])ch[i][j]=ch[i-1][j-1]+1;
            else ch[i][j]=max(ch[i-1][j],ch[i][j-1]);
        }
    }//for(i=1;i<=a.size();i++,printf(" %c\n",a[i-2]))for(j=1;j<=b.size();j++)printf("%d ",ch[i][j]);
    printf("%d",ch[strlen(a)/3][strlen(b)/3]);
}