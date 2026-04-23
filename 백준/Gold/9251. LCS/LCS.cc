#include<iostream>
#include<string>
#define max(a,b) a>b?a:b
using namespace std;
int ch[1001][1001]={0,};
int main(){
    string a,b;
    int m;
    scanf("%d",&m);
    cin>>a>>b;

    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1])ch[i][j]=ch[i-1][j-1]+1;
            else ch[i][j]=max(ch[i-1][j],ch[i][j-1]);
        }
    }
    printf("%d",ch[a.size()][b.size()]);
}