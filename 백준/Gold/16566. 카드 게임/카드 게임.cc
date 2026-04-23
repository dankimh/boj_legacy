#include<bits/stdc++.h>
using namespace std;
class disjoint_set{
public:
    disjoint_set(int n){
        this->sz=n;
        for(int i=0;i<n;i++)this->parent.push_back(i);

    }
    int d_find(int x){
        if(x==this->parent[x]){
            return x;
        }
        return this->parent[x]=d_find(this->parent[x]);
    }
    void d_union(int a,int b){
        a=d_find(a);
        b=d_find(b);
        if(a!=b)this->parent[b]=a;
    }
private:
    int sz=0;
    vector<int> parent;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(m);
    int i;
    for(i=0;i<m;i++)cin>>a[i];
    sort(a.begin(),a.end());
    disjoint_set s(n+1);
    for(i=0;i<k;i++){
        int c;
        cin>>c;
        int st=0,en=m-1;
        while(st<en){
            int mid=(st+en)/2;
            int x=s.d_find(a[mid]);
            if(x<=c){
                st=mid+1;
            }
            else{
                en=mid;
            }
        }
        cout<<s.d_find(a[en])<<"\n";
        if(en!=0)s.d_union(a[en-1],a[en]);
        else s.d_union(0,a[en]);
    }



}