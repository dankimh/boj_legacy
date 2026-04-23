#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<char>> f(int n){
    if(n==3){
        vector<vector<char>> first={{' ',' ','*',' ',' '},{' ','*',' ','*',' '},{'*','*','*','*','*'}};
        return first;
    }
    int i,j;
    vector<vector<char>> sample=f(n/2);

    vector<vector<char>> ans(n,vector<char>(2*n-1,' '));
    for(i=0;i<n/2;i++){
        for(j=n/2;j<3*n/2-1;j++){
            ans[i][j]=sample[i][j-n/2];
        }
    }

    for(i=n/2;i<n;i++){
        for(j=0;j<n-1;j++){
            ans[i][j]=sample[i-n/2][j];
        }
    }
    for(i=n/2;i<n;i++){
        for(j=n;j<2*n-1;j++){
            ans[i][j]=sample[i-n/2][j-n];
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    auto ans=f(n);
    for(auto &i:ans){
        for(auto &j:i)printf("%c",j);
        printf("\n");
    }
}