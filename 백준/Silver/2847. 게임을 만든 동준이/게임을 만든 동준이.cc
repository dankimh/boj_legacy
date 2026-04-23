#include<bits/stdc++.h>
int main(){
    int n,a[100],i,c=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=n-2;i>=0;i--){
        if(a[i+1]<=a[i]){
            while(a[i+1]<=a[i]){
                c++;
                a[i]--;
            }
        }
    }
    printf("%d",c);
}
