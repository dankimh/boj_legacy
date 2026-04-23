#include<bits/stdc++.h>
using namespace std;
#define r_float __float128
typedef long double ld;
typedef long long ll;
r_float pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679q;
vector<r_float> fc(100);
r_float power(r_float x,int e){
    if(e==0)return 1;
    else return x*power(x,e-1);
}
r_float fact(r_float x){
    if(x<1.1)return fc[(int)x]=1;
    else return fc[(int)x]=x*fact(x-1);
}
r_float sinx(r_float x){
    x-=(__int128)(x/pi/2)*pi*2;
    r_float ret=x;
    r_float i,j=-1;
    for(i=3;i<54;i+=2,j*=-1){
        ret+=((int)j==-1?-1:1)*(power(x,(int)i)/fc[(int)i]);
    }
    return ret;
}
r_float a,b,c;
r_float f(r_float x){
    return a*x+b*sinx(x)-c;
}
int main(){
    auto imsi=fact(55);
    ld aa,bb,cc;
    cin>>aa>>bb>>cc;
    a=(r_float)aa;b=(r_float)bb;c=(r_float)cc;
    r_float st=-200000.0q;
    r_float en=200001.0q;
    r_float mid;
    int t=100;
    while(t--){
        mid=(st+en)/2.0;
        if(f(mid)<0)st=mid;
        else en=mid;
    }
    __int128 ans=0;
    ans+=(int)mid;
    mid-=(int)mid;
    for(int i=0;i<6;i++){
        mid*=10;
        ans*=10;
        ans+=(int)mid;
        mid-=(int)mid;
    }
    mid*=10;
    int seventh=(int)mid;
    r_float ret=(r_float)ans+(r_float)seventh*0.1;
    ret=round((ld)ret);
    string fin=to_string((ll)ret);
    if(fin.size()>6){
    for(int i=0;i<fin.size();i++){
        if(i==fin.size()-6)cout<<".";
        cout<<fin[i];
    }}
    else{
        cout<<"0.";
        for(int i=0;i<6-fin.size();i++)cout<<"0";
        for(auto &x:fin)cout<<x;
    }
}