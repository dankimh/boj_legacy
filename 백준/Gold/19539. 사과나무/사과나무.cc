#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[100000],i,sum=0,bsum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        bsum+=(a[i]/2);
    }
    if(sum%3!=0){
        printf("NO");
        return 0;
    }
    sum/=3;
    bsum>=sum?printf("YES"):printf("NO");
}