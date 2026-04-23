#include<bits/stdc++.h>
int main(){
    char a,b;
    int i=0,c=1;
    while(scanf("%c",&a)!=EOF){
        if(i==0&&a==' ')c--;
        if(a=='\n'){
            if(b==' ')c--;
            break;
        }
        if(a==' ')c++;
        i++;
        b=a;
    }
    printf("%d",c);
}