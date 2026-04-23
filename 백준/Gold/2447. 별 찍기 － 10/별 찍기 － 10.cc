#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> f(int n){
    if(n==1){
        vector<string> p;
        p.push_back("*");
        return p;
    }
    int i,j,k,l;
    vector<string> a=f(n/3),b(n);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i==1&&j==1){
                string imsi;
                for(k=0;k<n/3;k++)imsi+=" ";
                for(k=n/3*i,l=0;k<n/3*(i+1);k++,l++){
                    b[k]+=imsi;
                }
            }
            else{
                for(k=n/3*i,l=0;k<n/3*(i+1);k++,l++){
                    b[k]+=a[l];
                }
            }
        }
    }
    return b;
}
int main(){
    int n;
    scanf("%d",&n);
    vector<string> a=f(n);
    for(int i=0;i<a.size();i++)cout<<a[i]<<"\n";
}