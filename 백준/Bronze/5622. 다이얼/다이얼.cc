#include<bits/stdc++.h>
int main(){
    int a[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    char b[16];
    scanf("%s",b);
    int len=strlen(b);
    int time=0;
    for(int i=0;i<len;i++){
        time+=(a[b[i]-'A']+1);
    }
    printf("%d",time);
}