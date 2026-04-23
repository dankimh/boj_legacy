#include<bits/stdc++.h>
using namespace std;
class Set{
private:
    bitset<20> a;
public:
    void add(int x){
        a[x-1]=1;
    }
    void remove(int x){
        a[x-1]=0;
    }
    void check(int x){
        cout<<a[x-1]<<"\n";
        return;
    }
    void toggle(int x){
        a[x-1]=!a[x-1];
    }
    void all(){
        a=bitset<20>((1<<21)-1);
    }
    void empt(){
        a=bitset<20>(0);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin>>m;
    Set x;
    while(m--){
        string a;
        cin>>a;
        if(a=="all"){
            x.all();
        }
        else if(a=="empty"){
            x.empt();
        }
        else{
            int b;
            cin>>b;
            if(a=="add")x.add(b);
            if(a=="check")x.check(b);
            if(a=="remove")x.remove(b);
            if(a=="toggle")x.toggle(b);
        }
    }
}