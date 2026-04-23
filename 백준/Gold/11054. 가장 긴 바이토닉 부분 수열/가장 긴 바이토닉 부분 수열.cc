#include<stdio.h>
int a[1000],n;
int f(int index,int dir){
    int ch[1000]={0,},i,j;
    if(dir==0){
    ch[0]=1;
    for(i=1;i<index+1;i++){
            int max=0;
            for(j=0;j<i;j++){
                if(a[j]<a[i]){
                    if(max<ch[j])max=ch[j];
                }

            }
            ch[i]=max+1;
    }
    int m=0;
    for(i=0;i<index+1;i++){
       //printf("in%da%d ",index,ch[i]);
        if(m<ch[i])m=ch[i];
    }
    //printf("\n");
    return ch[index];
    }
    else{
    ch[n-1]=1;
    for(i=n-2;i>=index;i--){
            int max=0;
            for(j=i+1;j<n;j++){
                if(a[j]<a[i]){
                    if(max<ch[j])max=ch[j];
                }

            }
            ch[i]=max+1;
    }
    int m=0;
    for(i=index;i<n;i++){
        //printf("in%db%d ",index,ch[i]);
        if(m<ch[i])m=ch[i];
    }
    //printf("\n");
    return ch[index];
    }
}
int main(){
    int i,ch[1000]={0,};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        int j;
        ch[i]+=f(i,0);
        ch[i]+=f(i,1);

    }
    int max=0;
    for(i=0;i<n;i++){
        if(max<ch[i])max=ch[i];
    }
    printf("%d",max-1);
}