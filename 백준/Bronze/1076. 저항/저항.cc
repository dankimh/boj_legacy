#include<iostream>
using namespace std;
int main(){
    string a;
    long long res=0;
        cin>>a;
        if(a=="black")res+=0;
        if(a=="brown")res+=10;
        if(a=="red")res+=20;
        if(a=="orange")res+=30;
        if(a=="yellow")res+=40;
        if(a=="green")res+=50;
        if(a=="blue")res+=60;
        if(a=="violet")res+=70;
        if(a=="grey")res+=80;
        if(a=="white")res+=90;
        cin>>a;
        if(a=="black")res+=0;
        if(a=="brown")res+=1;
        if(a=="red")res+=2;
        if(a=="orange")res+=3;
        if(a=="yellow")res+=4;
        if(a=="green")res+=5;
        if(a=="blue")res+=6;
        if(a=="violet")res+=7;
        if(a=="grey")res+=8;
        if(a=="white")res+=9;
    cin>>a;
    if(a=="black")res*=1;
        if(a=="brown")res*=10;
        if(a=="red")res*=100;
        if(a=="orange")res*=1000;
        if(a=="yellow")res*=10000;
        if(a=="green")res*=100000;
        if(a=="blue")res*=1000000;
        if(a=="violet")res*=10000000;
        if(a=="grey")res*=100000000;
        if(a=="white")res*=1000000000;

        printf("%lld",res);
}