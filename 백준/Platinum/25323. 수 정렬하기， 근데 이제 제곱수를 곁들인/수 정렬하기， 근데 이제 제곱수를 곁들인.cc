#include<stdio.h>
#include<algorithm>
using namespace std;

long long int arr0[500000], arr1[500000];


long long int get_gcd(long long int a, long long int b){
    if(b==0)
        return a;
    else
        return get_gcd(b, a%b);
}

bool check_square(long long int a){
    long long int l=1, r=1000000000;
    while(l<=r){
        long long int m = (l+r)/2;
        //printf("%lld\n", m);
        if(m*m==a)
            return true;
        else if(m*m>a)
            r=m-1;
        else
            l=m+1;
    }
    return false;
}


int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%lld", &arr0[i]);
        arr1[i]=arr0[i];
    }
    sort(arr1, arr1+n);

    for(int i=0 ;i<n; i++){
        long long int gcd = get_gcd(arr0[i], arr1[i]);
        if(check_square(arr0[i]/gcd)==false || check_square(arr1[i]/gcd)==false){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}
