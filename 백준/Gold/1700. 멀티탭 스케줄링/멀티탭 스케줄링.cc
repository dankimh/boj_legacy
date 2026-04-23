#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int i,j,l,cnt=0;
    vector<int> a(k);
    vector<int> plug(n,0);
    for(i=0;i<k;i++)cin>>a[i];
    for(i=0;i<k;i++){
        /*for(j=0;j<n;j++)cout<<plug[j]<<" ";
        cout<<"s\n";*/
        int chk=0;
        for(j=0;j<n;j++){
            if(plug[j]==0){plug[j]=a[i];chk=1;break;}
            if(plug[j]==a[i]){chk=1;break;}
        }
        if(chk)continue;
        int loc=0,mx=-1;
        vector<int> ch(n,-1);
        for(j=0;j<n;j++){
            for(l=i+1;l<k;l++){
                if(a[l]==plug[j]){
                    ch[j]=l;
                    break;
                }
            }
        }
        for(j=0;j<n;j++){
            if(mx<ch[j]){
                mx=ch[j];
                loc=j;
            }
            if(ch[j]==-1){
                loc=j;
                break;
            }
        }
        plug[loc]=a[i];
        cnt++;

    }
    cout<<cnt;
}