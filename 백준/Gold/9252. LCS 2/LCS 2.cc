#include<iostream>
#include<string>
#define max(a,b) a>b?a:b
using namespace std;
int ch[1001][1001]={0,};
int loc[1001];
int main(){
    string a,b,c;
    cin>>a>>b;
    int i,j,m=0;
    for(i=1;i<=a.size();i++){
        for(j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]){
                ch[i][j]=ch[i-1][j-1]+1;
            }
            else ch[i][j]=max(ch[i-1][j],ch[i][j-1]);
        }
    }
    printf("%d\n",ch[a.size()][b.size()]);
    i=a.size();
    j=b.size();
    while(i>0&&j>0){
        if(ch[i-1][j]>ch[i][j-1]){
            i--;
        }
        else if(ch[i-1][j]<ch[i][j-1]){
            j--;
        }
        else{
            if(ch[i][j]==ch[i-1][j])i--;
            else{
                c+=a[i-1];
                i--;
                j--;
            }
        }
    }
    for(i=c.size()-1;i>=0;i--){
        printf("%c",c[i]);
    }
}