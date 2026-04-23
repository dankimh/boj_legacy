#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,d,k,i=1;
    cin>>a>>d>>k;
    double dd,kk,ddd=1.0,tot=0;
    dd=(double)d/100;
    kk=(double)k/100;
    while(1){
        if(dd>=1.0){
            tot+=(double)i*(double)a*ddd;
            break;
        }
        tot+=(double)i*(double)a*ddd*dd;
        ddd*=(1-dd);
        dd*=(1+kk);
        i++;

    }
    printf("%.7lf",tot);
}