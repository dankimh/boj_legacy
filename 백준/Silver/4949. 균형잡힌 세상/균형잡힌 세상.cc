#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    while(1){
        getline(cin,a);
        if(a.size()==1&&a==".")break;
        stack<int> s;
        int ch=1;
        for(int i=0;i<a.size();i++){
            if(a[i]=='(')s.push(a[i]);
            if(a[i]=='[')s.push(a[i]);
            if(a[i]==')'){
                if(s.size()==0){
                    printf("no\n");
                    ch=0;
                    break;
                }
                else{
                    if(s.top()=='(')s.pop();
                    else{
                        printf("no\n");
                        ch=0;
                        break;
                    }
                }
            }
            if(a[i]==']'){
                if(s.size()==0){
                    printf("no\n");
                    ch=0;
                    break;
                }
                else {
                    if(s.top()=='[')s.pop();
                    else{
                        printf("no\n");
                        ch=0;
                        break;
                    }
                }
            }

        }
        if(ch==1){
            if(s.size()==0)printf("yes\n");
            else printf("no\n");
        }
    }
}