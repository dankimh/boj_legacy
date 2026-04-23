#include<bits/stdc++.h>
int main(){
    char a[100];
    int b[26],i;
    scanf("%s",a);
    for(i=0;i<26;i++)b[i]=-1;
    for(i=0;i<strlen(a);i++)if(b[a[i]-'a']==-1)b[a[i]-'a']=i;
    for(i=0;i<26;i++)printf("%d ",b[i]);
}
