#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> getpi(string p){
    ll psiz=(ll)p.size();
    ll i,j=0;
    vector<ll> pi(psiz,0);
    for(i=1;i<psiz;i++){
        while(j>0&&p[i]!=p[j])j=pi[j-1];
        if(p[i]==p[j]){
            pi[i]=j+1;
            j++;
        }
    }
    return pi;
}
ll kmp(string a,string b){
    ll asiz=(ll)a.size();
    ll bsiz=(ll)b.size();
    vector<ll> pi=getpi(b);
    ll ans=0,i,j=0;
    for(i=0;i<asiz;i++){
        while(j>0&&a[i]!=b[j])j=pi[j-1];
        if(a[i]==b[j]){
            if(j==bsiz-1){
                //printf("jj%d\n",j);
                ans++;
                j=pi[j];
            }
            else j++;
        }
    }
    return ans;
}
int main(){
    ll n;
    string fib[30];
    //ifstream readfile;
    //readfile.open("in.txt");
    fib[0]="0";
    fib[1]="1";
    for(ll i=2;i<30;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    string p;
    ll i=1;
    //if(readfile.is_open()){
    while(!cin.eof()){
        vector<ll> dp(101,0);
        if(cin.eof()==true)break;
        cin>>n;
        if(cin.eof()==true)break;
        cin>>p;
        ll psiz=(ll)p.size();
        //printf("x%lld\n",psiz);
        ll index;
        for(index=0;index<27;index++){
            if((ll)fib[index].size()>=psiz)break;
        }
        //printf("ind%lld\n",index);
        string head=fib[index].substr(0,psiz-1);
        string tail0,tail1;
        if(index%2==0){
            tail0=fib[index].substr(fib[index].size()-psiz+1,psiz-1);
            tail1=fib[index+1].substr(fib[index+1].size()-psiz+1,psiz-1);
        }
        else if(index%2==1){
            tail1=fib[index].substr(fib[index].size()-psiz+1,psiz-1);
            tail0=fib[index+1].substr(fib[index+1].size()-psiz+1,psiz-1);
        }
        dp[index]=kmp(fib[index],p);
        index++;
        dp[index]=kmp(fib[index],p);
        index++;
        //string tail=fib[index].substr(fib[index].size()-psiz,psiz);
        //cout<<head<<endl;
        for(;index<=n;index++){
            dp[index]+=dp[index-1]+dp[index-2];
            string tail=(index%2==0?tail1:tail0);
            string imsi=tail+head;
            //cout<<index<<' '<<tail<<' '<<head<<endl;
            ll sum=kmp(imsi,p);
            //cout<<sum<<endl;
            dp[index]+=sum;
        }
        //for(int j=0;j<=n;j++)printf("%lld ",dp[j]);
        //printf("\n");
        //for(int j=0;j<=20;j++)printf("%lld ",kmp(fib[j],p));
        //printf("\n");
        printf("Case %lld: %lld\n",i,dp[n]);
        i++;
    }
    //}
}