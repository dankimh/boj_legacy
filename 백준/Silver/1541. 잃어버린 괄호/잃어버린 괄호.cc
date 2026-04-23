#include<iostream>
#include<string>
using namespace std;
int f(string a){
    int i,p=1,sum=0;
    for(i=a.size()-1;i>=0;i--){
        sum+=p*(a[i]-'0');
        p*=10;
    }
    return sum;
}
int main(){
    string a;
    cin>>a;
    int op=0,sum=0,num=0;
    string b;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9')b.push_back(a[i]);
        else{
            if(op==0){
                sum+=f(b);
                b.clear();
            }
            else if(op==1){
                sum-=f(b);
                b.clear();
            }

            if(a[i]=='+')continue;
            else if(a[i]=='-'){
                op=1;
            }
        }
    }
    if(!op)sum+=f(b);
    else sum-=f(b);
    printf("%d",sum);
}