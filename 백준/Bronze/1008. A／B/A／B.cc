#include<bits/stdc++.h>
int main(){
    int i,a,b;
    scanf("%d %d",&a,&b);
     for(i=0;i<100;i++){
         if(a==0)break;
         if(i==0&&a>=b){
            if(a%b!=0)printf("%d.",a/b);
            else printf("%d",a/b);
         }
         else{
            if(i==0)printf("0.");
            else printf("%d",a/b);
         }
         a%=b;
         a*=10;
     }
}
