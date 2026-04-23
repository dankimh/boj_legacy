#include<iostream>
#include<string>
#define max(a,b) a>b?a:b
using namespace std;
int ch[101][101][101]={0,};
int loc[1001];
int main(){
    string a,b,c;
    cin>>a>>b>>c;
    int i,j,m=0,k;
    for(i=1;i<=a.size();i++){
        for(j=1;j<=b.size();j++){
            for(k=1;k<=c.size();k++){
                if(a[i-1]==b[j-1]&&b[j-1]==c[k-1]){
                    ch[i][j][k]=ch[i-1][j-1][k-1]+1;
                }
                else ch[i][j][k]=max(max(ch[i-1][j][k],ch[i][j-1][k]),ch[i][j][k-1]);
            }
        }
    }
    printf("%d",ch[a.size()][b.size()][c.size()]);
}