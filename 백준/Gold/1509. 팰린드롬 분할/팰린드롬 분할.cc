#include<bits/stdc++.h>
using namespace std;
string s;
int ch[2501][2501];
int f(int a,int b){
    if(ch[a][b])return ch[a][b];
    if(a==b){
        return ch[a][b]=1;
    }
    else if(b-a==1){
        if(s[a]==s[b]){
            return ch[a][b]=ch[b][a]=1;
        }
        else return ch[a][b]=ch[b][a]=2;
    }
    else{
        if(f(a+1,b-1)==1&&(s[a]==s[b])){
            return ch[a][b]=ch[b][a]=1;
        }
        else return ch[a][b]=ch[b][a]=2;
    }
}
int main(){
    cin>>s;
    int len=s.size(),i,j;
    for(i=0;i<len;i++){
        for(j=i;j<len;j++){
            f(i,j);
        }
    }
    vector<int> v(len+2,3000);
    v[0]=0;
    v[1]=1;
    for(i=2;i<=len;i++){
        for(j=0;j<i;j++){
            if(ch[i-1][j]==1){
                v[i]=min(v[i],v[j]+1);
            }
        }
    }
    //for(i=0;i<=len;i++)cout<<v[i]<<" ";
    printf("%d",v[len]);
}