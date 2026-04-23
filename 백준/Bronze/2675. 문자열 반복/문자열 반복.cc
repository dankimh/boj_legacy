#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        char a[20];
        scanf("%s",a);
        for(int j=0;j<strlen(a);j++){
            for(int k=0;k<n;k++){
                printf("%c",a[j]);
            }
        }
        printf("\n");
    }
}