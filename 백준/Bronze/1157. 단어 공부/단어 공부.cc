#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    char a[1000000];
    int b[26]={0,};
    scanf("%s",a);
    int len=strlen(a);
    for(int i=0;i<len;i++){
        b[tolower(a[i])-'a']++;
    }
    int max=-1,ind=0;
    char c='?';
    for(int i=0;i<26;i++){
        if(max==b[i]&&b[i]!=0){
            c='?';
        }
        if(max<b[i]){max=b[i];c=i+'a';}
    }
    printf("%c",toupper(c));
}
