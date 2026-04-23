#include<bits/stdc++.h>
int main(){
    int n,a[1000],i,ch[1000],j;
    scanf("%d",&n);
    for(i=0;i<n;i++){scanf("%d",&a[i]);ch[i]=0;}
    ch[0]=a[0];
    for(i=1;i<n;i++){
            int max=0;
            for(j=0;j<i;j++){
                if(a[j]<a[i]){
                    if(max<ch[j])max=ch[j];
                }

            }
            ch[i]=max+a[i];
    }
    int m=0;
    for(i=0;i<n;i++){
        if(m<ch[i])m=ch[i];

    }
    printf("%d",m);
}