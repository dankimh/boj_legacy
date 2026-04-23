#include<stdio.h>
#include<vector>
using namespace std;
vector<int> a=vector<int>(5);
int main(){
    int c=0;
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
        if(a[i]<40)a[i]=40;
        c+=a[i];
    }
    printf("%d",c/5);
}
