#include<stdio.h>
#define ll long long
int main(){
    ll n,i,aa[50];
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&aa[i]);
    }
    ll max=-1;
    for(i=0;i<n;i++){
        ll cnt=0;
        for(ll j=0;j<n;j++){
            ll x1=i,y1=aa[i],x2=j,y2=aa[j];
            if(j==i)continue;
            ll a=y1-y2;
            ll b=-x1+x2;
            ll c=y1*(x1-x2)-x1*(y1-y2);
            if(b<0){
                a=-a;
                b=-b;
                c=-c;
            }
            ll ch=1;
            //printf("a%d %d %d\n",a,b,c);
            for(ll k=j+1;k<i;k++){
                //printf("1-%d\n",j);
                if(a*k+b*aa[k]+c>=0){ch=0;break;}
            }
            for(ll k=i+1;k<j;k++){
                //printf("2-%d\n",j);
                if(a*k+b*aa[k]+c>=0){ch=0;break;}
            }
            cnt+=ch;
        }
        //printf("cnt-%d\n",cnt);
        if(max<cnt)max=cnt;
    }
    printf("%lld",max);
}