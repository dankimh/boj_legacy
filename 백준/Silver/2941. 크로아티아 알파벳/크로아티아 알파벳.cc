#include<bits/stdc++.h>
int main(){
    char a[100];
    scanf("%s",a);
    int ch=0,ans=0;
    int len=strlen(a);
    for(int i=0;i<len;i++){
        ans++;
        if(a[i]=='j'){
            if(i>0&&(a[i-1]=='l'||a[i-1]=='n'))ans--;
        }
        if(a[i]=='-')ans--;
        if(a[i]=='='){
            ans--;
            if(i>1&&(a[i-1]=='z'&&a[i-2]=='d'))ans--;
        }
    }
    printf("%d",ans);
}
