#include<stdio.h>
int main(){
    int n,m,i,a[100],min=300001;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(min>(m-(a[i]+a[j]+a[k]))&&(m-(a[i]+a[j]+a[k]))>=0)min=(m-(a[i]+a[j]+a[k]));
            }
        }
    }
    printf("%d",m-min);
}