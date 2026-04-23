#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
constexpr __int128 mo=1e9+7;
struct mat22{
    __int128 a,b,c,d;
};
mat22 matmul(mat22 a,mat22 b,__int128 mod){
    return {((a.a*b.a)%mod+(a.b*b.c)%mod)%mod,((a.a*b.b)%mod+(a.b*b.d)%mod)%mod,((a.c*b.a)%mod+(a.d*b.c)%mod)%mod,((a.c*b.b)%mod+(a.d*b.d)%mod)%mod};
}
mat22 matpow(__int128 b,__int128 mod){
    mat22 a={1,1,1,0},ans={1,0,0,1};
    while(b>0){
        if(b%2){
            ans=matmul(ans,a,mod);
        }
        b/=2;
        a=matmul(a,a,mod);
    }
    return ans;
}
__int128 fib(__int128 n,__int128 mod){
    return (matpow(n,mod).c+mod)%mod;
}
__int128 mypow(__int128 a,__int128 b,__int128 mod){
    __int128 ans=1;
    while(b>0){
        if(b%2){
            ans=ans*a%mod;
        }
        b/=2;
        a=a*a%mod;
    }
    return ans;
}
int main(){
    ll nn,kk;
    cin>>nn>>kk;
    assert(nn!=0&&kk!=0);
    __int128 n=nn,k=kk,A,B;
    __int128 fnk=fib(n*k,mo*mo),fn_1k=fib((n-1)*k,mo*mo),fk=fib(k,mo*mo);
    if(fk%mo!=0){
        A=(fnk)*mypow(fk,mo-2,mo)%mo+mo;
        B=(fn_1k)*mypow(fk,mo-2,mo)%mo;
    }
    else{
        fnk/=mo;fn_1k/=mo;fk/=mo;
        A=fnk*mypow(fk,mo-2,mo)%mo+mo;
        B=(fn_1k)*mypow(fk,mo-2,mo)%mo;
    }
    if(k%2==0){B=-B;B+=mo;}
    cout<<(ll)(A%mo)<<" "<<(ll)(B%mo);
}

