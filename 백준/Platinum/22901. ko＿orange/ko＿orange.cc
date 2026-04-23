#include<bits/stdc++.h>
using namespace std;
/*int dp[2400][2400];
int f(int st,int en,int lie,int cnt){
    if(dp[st][en])return -1;
    //cout<<st<<" "<<en<<"\n";
    if(cnt==13){
        if(st!=en)return -1;
        else return st;
    }
    if(st==en)return st;
    int mid=(st+en)/2+1;
    cout<<"? "<<mid<<"\n";
    fflush(stdout);
    int res;
    cin>>res;
    if(res==0){
            dp[st][en]=1;
        //if(lie==1){
            en=mid-1;
            return f(st,en,lie,cnt+1);
        //}
        //else{

        //}
    }
    else{
        if(lie==0){
            dp[st][en]=1;
            st=mid;
            return f(st,en,lie,cnt+1);
        }
        else{
            int a=f(st,en,lie-1,cnt+1);
        }
    }
}*/
void solve(){
    int st=2100,en=2399,lie=1,ans=0,bef=0;
    //memset(dp,0,sizeof(dp));
    //int ans=f(st,en,lie,0);
    for(int i=0;i<18;i++){
        //cout<<st<<" "<<en<<"\n";
        if(st==en)break;
        int mid=(st+en>>1)+1;
        cout<<"? "<<mid<<"\n";
        fflush(stdout);
        int res;
        cin>>res;
        if(res==0){
            if(bef==1){
                lie=-1;
            }
            en=mid-1;
        }
        else{
            if(lie==0){
                st=mid;
                lie++;
                bef=0;
            }
            else if(lie==1){
                lie--;
                bef=res;
            }
            else{
                st=mid;
            }
        }
    }
    cout<<"! "<<st<<"\n";
}
int main(){
    int tt;
    cin>>tt;
    while(tt--)solve();
}