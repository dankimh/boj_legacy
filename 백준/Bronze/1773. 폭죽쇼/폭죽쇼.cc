#include<bits/stdc++.h>
int main(){
    int n,c,i,b[100],a=0;
    scanf("%d %d",&n,&c);
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(i=1;i<=c;i++){
        for(int j=0;j<n;j++){
            if(i%b[j]==0){a++;break;}
        }
    }
    printf("%d",a);
}
