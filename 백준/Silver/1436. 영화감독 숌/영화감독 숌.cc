#include<stdio.h>
#include<string.h>

int main(){
    int n,ch=0,i=666,j;
    scanf("%d",&n);
    while(ch<n){
        int k=0,x=i;
        char a[20];
        while(x>0){
            a[k]=(x%10)+'0';
            x/=10;
            k++;
        }
        a[k]='\0';
        //if(i==666)printf("%s %d\n",a,k);
        for(j=0;j<k-2;j++){
            if(a[j]=='6'&&a[j+1]=='6'&&a[j+2]=='6'){
                ch++;
                //printf("a%s\n",a);
                break;
            }
        }
        i++;
    }
    printf("%d",i-1);
}