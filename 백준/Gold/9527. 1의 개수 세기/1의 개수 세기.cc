#include<stdio.h>
#include<iostream>
#include<string>
#define ll long long
using namespace std;
string f(ll n){
    string a;
    while(n>0){
        if(n%2)a.insert(0,"1");
        else a.insert(0,"0");
        n/=2;
    }
    return a;
}
ll g(string a){
    ll n=0,bit=1;
    for(int i=a.size()-1;i>=0;i--){
        n+=(a[i]-'0')*bit;
        bit*=2;
    }
    return n;
}
int main(){
    ll a,b,i;
    scanf("%lld %lld",&a,&b);
    ll cnt[60]={1<<0,};
    for(i=1;i<=56;i++){
        cnt[i]=cnt[i-1]+((ll)1<<i)+((ll)1<<(i-1))*i;
    }
    /*for(i=0;i<=56;i++){
        printf("%lld\n",cnt[i]);
    }*/
    string ac=f(a-1);
    string bc=f(b);
    //cout<<ac<<"\n"<<bc<<"\n";
    ll ca=0,cb=0;
    while(!ac.empty()){
        if(ac[0]=='0'){
            ac.erase(ac.begin());
            continue;
        }
        if(ac.size()==1){
            if(ac[0]=='1')ca++;
            break;
        }
        //printf("a%lld %lld\n",ac.size(),cnt[ac.size()-2]);
        ca+=cnt[ac.size()-2];
        ac.erase(ac.begin());
        ca+=(g(ac)+1);
    }
    while(!bc.empty()){
        if(bc[0]=='0'){
            bc.erase(bc.begin());
            continue;
        }
        if(bc.size()==1){
            if(bc[0]=='1')cb++;
            break;
        }
        //printf("b%lld %lld\n",bc.size(),cnt[bc.size()-2]);
        cb+=cnt[bc.size()-2];
        bc.erase(bc.begin());
        cb+=(g(bc)+1);
        //printf("bb%lld\n",cb);
    }
    printf("%lld",cb-ca);
}