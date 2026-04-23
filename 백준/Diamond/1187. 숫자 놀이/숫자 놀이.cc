#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
vi b;
vi c;
vi f(vi a){
    //for(auto &i:a)printf("a%d ",i);
    //printf("\n");
    int i;
    int siz=(int)a.size();
    int mod=(siz+1)/2;
    int n=siz/2;
    //printf("n%d\n",n);
    if(siz==1){
        b[a[0]]=-1;
        return a;
    }

    vi input1,input2,input3;
    for(i=0;i<n;i++){
        input1.push_back(a[i]);
    }
    vi ans1=f(input1);
    for(i=0;i<(int)ans1.size();i++){
        b[ans1[i]]=-1;
    }
    for(i=0;i<siz;i++){
        if((int)input2.size()==n)break;
        if(b[a[i]]!=-1)input2.push_back(a[i]);
    }
    vi ans2=f(input2);
    for(i=0;i<(int)ans1.size();i++){
        b[ans2[i]]=-1;
    }
    for(i=0;i<siz;i++){
        if((int)input3.size()==n)break;
        if(b[a[i]]!=-1)input3.push_back(a[i]);
    }
    vi ans3=f(input3);
    int a1=0,a2=0,a3=0;
    for(i=0;i<(int)ans1.size();i++){
        a1+=c[ans1[i]];
        a2+=c[ans2[i]];
        a3+=c[ans3[i]];
    }//printf("x%d %d %d %d\n",a1,a2,a3,mod);

    if(a1%mod==a2%mod){
        vi ans;
        for(i=0;i<(int)ans1.size();i++){
            ans.push_back(ans1[i]);
        }
        for(i=0;i<(int)ans2.size();i++){
            ans.push_back(ans2[i]);
        }
        for(i=0;i<(int)ans3.size();i++){
            b[ans3[i]]=c[ans3[i]];
        }
        return ans;
    }
    if(a1%mod==a3%mod){
        vi ans;
        for(i=0;i<(int)ans1.size();i++){
            ans.push_back(ans1[i]);
        }
        for(i=0;i<(int)ans3.size();i++){
            ans.push_back(ans3[i]);
        }
        for(i=0;i<(int)ans2.size();i++){
            b[ans2[i]]=c[ans2[i]];
        }
        return ans;
    }
    if(a2%mod==a3%mod){
        vi ans;
        for(i=0;i<(int)ans2.size();i++){
            ans.push_back(ans2[i]);
        }
        for(i=0;i<(int)ans3.size();i++){
            ans.push_back(ans3[i]);
        }
        for(i=0;i<(int)ans1.size();i++){
            b[ans1[i]]=c[ans1[i]];
        }
        return ans;
    }
}
int main(){

    int n;
    scanf("%d",&n);
    int i;
    b.resize(2*n-1);
    c.resize(2*n-1);

    vi a(2*n-1);
    for(i=0;i<2*n-1;i++){scanf("%d",&b[i]);a[i]=i;c[i]=b[i];}

    auto ans=f(a);

    for(auto &i:ans)printf("%d ",c[i]);
}