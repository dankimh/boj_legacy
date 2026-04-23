#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
p f(int a,string s){
    int i=a,ch=a,sz=s.size();
    while(1){//printf("x%d-%d %d\n",a,i,sz);
        if(i==sz)return {stoi(s.substr(0,a)),stoi(s.substr(sz-ch,ch))};
        string imsi1=s.substr(i-ch,ch);
        //printf("dd%d %d\n",i+ch,sz);
        if(i+ch>sz)return {1000,1000};
        string imsi2=s.substr(i,ch);
        int a1=stoi(imsi1);
        int a2=stoi(imsi2);
        //printf("aa%d %d %d %d\n",a1,a2,i,ch);
        if(a1+1==a2){i+=ch;continue;}
        else{
            if(a1==9){

                a2=stoi(s.substr(i,ch+1));

                if(a2==10){
                    ch++;
                    i+=ch;
                    continue;
                }
                else{
                    return {1000,1000};
                }
            }
            else if(a1==99){
                a2=stoi(s.substr(i,ch+1));
                if(a2==100){
                    ch++;
                    i+=ch;
                    continue;
                }
                else return {1000,1000};
            }
            else return {1000,1000};
        }
    }
}
void pr(p a){
    cout<<a.first<<" "<<a.second<<"\n";;
}
p m(p a,p b){
    if(a.first<b.first)return a;
    else{
        return b;
    }
}
int main(){
    string s;
    cin>>s;
    p a,b,c;
    a=f(1,s);
    b=f(2,s);
    c=f(3,s);
    auto x=m(a,m(b,c));
    pr(x);
}
