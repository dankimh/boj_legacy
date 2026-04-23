#include<stdio.h>
int m[101][101][101];
int w(int a,int b,int c){
    if(m[a+50][b+50][c+50])return m[a+50][b+50][c+50];
    if(a<=0||b<=0||c<=0)return 1;
    if(a>20||b>20||c>20)return m[a+50][b+50][c+50]=w(20,20,20);
    if(a<b&&b<c)return m[a+50][b+50][c+50]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else return m[a+50][b+50][c+50]=w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}
int main(){
    while(1){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a==-1&&b==-1&&c==-1)break;
        printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }
}