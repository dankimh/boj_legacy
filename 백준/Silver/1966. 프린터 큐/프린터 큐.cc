#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
int main(){
    int t;
    scanf("%d\n",&t);
    int i;
    for(i=0;i<t;i++){
        int n,m;
        scanf("%d %d\n",&n,&m);
        queue<pair<int,int>> a;
        for(int j=0;j<n;j++){
            int w;
            scanf("%d",&w);
            a.push(make_pair(w,j));
        }
        int seq=1;
        vector<int> b(n);
        while(!a.empty()){

            vector<pair<int,int>> imsi;
            int size=a.size();
            for(int j=0;j<size;j++){
                imsi.push_back(a.front());
                a.pop();
            }
            int m=0;
            for(auto &j:imsi){
                //printf("p%d %d\n",j.first,j.second);
                if(m<j.first)m=j.first;
            }
            //printf("a%d\n",size);
            if(imsi[0].first==m){
                b[imsi[0].second]=seq;
                seq++;
                //printf("a%d\n",size);
                if(size==1)break;
                for(int j=0;j<size-1;j++){
                    a.push(imsi[j+1]);
                }
            }
            else{
                for(int j=0;j<size-1;j++){
                    a.push(imsi[j+1]);
                }
                a.push(imsi[0]);
            }
        }
        printf("%d\n",b[m]);
    }

}