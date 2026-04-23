#include<bits/stdc++.h>
int main(){
    int n,i,j,s=0,c=1;
    char a[80];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",a);
        s=0;
        c=1;
        for(j=0;j<strlen(a);j++){
            if(a[j]=='O'){
                s+=c;
                c++;
            }
            if(a[j]=='X')c=1;
        }
        printf("%d\n",s);
    }
}
