#include<bits/stdc++.h>
int main(){
    int n,a[1000000],b[1000000],e[1000000],i,c=0,d=0,f=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++){
        if(b[i]==a[0]){
            if(b[(i-1+n)%n]==a[n-1]){c=i;d=0;}
            if(b[(i+1)%n]==a[n-1]){c=i;d=1;}
        }
    }
    i=0;
    //printf("%d %d\n",c,d);
    if(d==0){
        for(i=0;i<n;i++){
            if(a[(i-c+n)%n]!=b[i]){printf("bad puzzle");return 0;}
        }
        printf("good puzzle");
    }
    if(d==1){
        int j;
        for(j=0;j<n;j++){
            e[j]=b[n-j-1];
        }
        f=n-c-1;
        for(i=0;i<n;i++){
            if(a[(i-f+n)%n]!=e[i]){printf("bad puzzle");return 0;}
        }
        printf("good puzzle");
    }
}
