#include<bits/stdc++.h>
using namespace std;
int dig(int n){
    int i=0;
    while(n>0){
        n/=10;
        i++;
    }
    return i;
}
int f(int n,int x,int y){
    string a=to_string(n);
    //cout<<a<<"\n";
    if(x==0&&a[y]=='0')return -1;
    swap(a[x],a[y]);
    int ret=stoi(a);
    return ret;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> ans(20,-1);
    int sz=dig(n);
    queue<pair<int,int>> q;
    vector<int> a(1000001,0);
    q.push({n,0});
    while(!q.empty()){
        int num=q.front().first;
        int time=q.front().second;
        //cout<<num<<" "<<time<<"a\n";
        q.pop();
        if(num>ans[time])ans[time]=num;
        if(time>=k)continue;

        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                int x=f(num,i,j);
                //cout<<x<<"x\n";
                if(x==-1)continue;
                if(a[x]<=time){
                    q.push({x,time+1});
                    a[x]++;
                }
            }
        }
    }
    //for(auto &i:ans)cout<<i<<"\n";
    if(ans[k]==-1)cout<<"-1";
    else cout<<ans[k];
}