#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
constexpr ld interval=0.00005;
constexpr int cnt=20000;
constexpr ld pi=3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
ld f(ld a,ld b,ld x){
    return pi*(a*exp(-(x*x))+b*sqrt(x))*(a*exp(-(x*x))+b*sqrt(x));
}
ld simpson(ld a,ld b,ld st,ld en){
    return (en-st)*(f(a,b,st)+4*f(a,b,(st+en)/2)+f(a,b,en))/6;
}
int main(){
    int n,idx;
    ld v,mn=10000000000;
    cin>>v>>n;
    cout.precision(15);
    for(int i=0;i<n;i++){
        ld a,b,h,st,en,s=0;
        cin>>a>>b>>h;
        for(int j=0;j<cnt*h;j++){
            st=interval*j;
            en=interval*(j+1);
            s+=simpson(a,b,st,en);
        }
        //cout<<(long double)s<<" "<<abs(s-v)<<"x\n";
        if(mn>abs(s-v)){
            mn=abs(s-v);
            idx=i;
        }
    }
    cout<<idx;//<<" "<<mn;
}
