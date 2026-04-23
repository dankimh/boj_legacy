#include<bits/stdc++.h>
int main(){
    int i,a[8];
    for(i=0;i<8;i++){
        scanf("%d",&a[i]);
    }
    if(a[0]==1){
        for(i=1;i<9;i++){
            if(a[i-1]!=i){printf("mixed");return 0;}
        }
        printf("ascending");
    }
    else if(a[0]==8){
        for(i=1;i<9;i++){
            if(a[i-1]!=9-i){printf("mixed");return 0;}
        }
        printf("descending");
    }
    else printf("mixed");
}