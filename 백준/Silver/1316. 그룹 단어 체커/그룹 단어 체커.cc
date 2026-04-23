#include<bits/stdc++.h>
int main(){
    int n;
    scanf("%d",&n);
    int i,j;
    int cnt=0;
    for(i=0;i<n;i++){
        char a[100];
        int ch[26]={0,};
        scanf("%s",a);
        int len=strlen(a);
        for(j=0;j<len;j++){
            char b=a[j];
            if(ch[b-'a']==1){cnt--;break;}
            ch[b-'a']=1;
            while(b==a[j]){
                j++;
            }
            j--;
        }
        cnt++;
        //for(int k=0;k<26;k++)printf("%d",ch[k]);
        //printf("\n");
        //for(char k='a';k<='z';k++)printf("%c",k);
        //printf("\n");
    }
    printf("%d",cnt);
}