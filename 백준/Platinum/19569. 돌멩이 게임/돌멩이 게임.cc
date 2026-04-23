#include<bits/stdc++.h>
#define FF fflush(stdout)
#define E if(total>=n)exit(0);
using namespace std;
int main(){
    int n,total=0;
    cin>>n;
    if(n%5!=1&&n%5!=4){
        cout<<"NO";
        exit(0);
    }
    cout<<"YES\n";
    cout<<"1\n";
    FF;
    total++;
    E;
    if(n%5==4){
        int a;
        cin>>a;
        if(a==1){
            cout<<"2\n";
            FF;
        }
        else if(a==2){
            cout<<"1\n";
            FF;
        }
        total+=3;
    }

    E;
    while(total<n){
        int next;
        cin>>next;
        total+=next;
        if(next==1){
            cout<<"1\n";
            FF;
            E;
            total++;
            cin>>next;
            if(next==1){
                cout<<"2\n";
                FF;
                E;
            }
            else if(next==2){
                cout<<"1\n";
                FF;
                E;
            }
            total+=3;
        }
        else if(next==2){
            cout<<"3\n";
            FF;
            E;
            total+=3;
        }
        else if(next==3){
            cout<<"2\n";
            FF;
            E;
            total+=2;
        }
        else{
            cout<<"1\n";
            FF;
            E;
            total+=1;
        }
        E;
    }
}