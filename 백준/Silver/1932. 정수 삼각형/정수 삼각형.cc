#include<stdio.h>
#include<algorithm>
int a[500][500],b[500][500];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++)scanf("%d",&a[i][j]);
    }
    //b[0][0]=a[0][0];
    for(i=0;i<n-1;i++){
        for(j=0;j<=i;j++){
            if(b[i+1][j]<a[i][j]+b[i][j])b[i+1][j]=a[i][j]+b[i][j];
            if(b[i+1][j+1]<a[i][j]+b[i][j])b[i+1][j+1]=a[i][j]+b[i][j];
        }
    }
    for(i=0;i<n;i++)b[n-1][i]+=a[n-1][i];
    int m=*std::max_element(b[n-1],b[n-1]+n);
    printf("%d",m);
}