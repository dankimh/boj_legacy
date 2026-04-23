#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int aa[101]={0,},bb[101]={0,};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        aa[a]++;
        bb[b]++;
        int aaa=1,bbb=100;
        int aaaa[101],bbbb[101];
        memcpy(aaaa,aa,sizeof(aa));
        memcpy(bbbb,bb,sizeof(bb));
        while(!aaaa[aaa])aaa++;
        while(!bbbb[bbb])bbb--;
        int mi=-1;
        while(aaa<101&&bbb>0){
            //cout<<"x"<<aaa<<" "<<bbb<<"\n";
            if(aaa+bbb>mi)mi=aaa+bbb;
            if(aaaa[aaa]<bbbb[bbb]){
                bbbb[bbb]-=aaaa[aaa];
                aaa++;
            }
            else{
                aaaa[aaa]-=bbbb[bbb];
                bbb--;
            }
            while(!aaaa[aaa])aaa++;
            while(!bbbb[bbb])bbb--;
        }
        printf("%d\n",mi);
    }
}