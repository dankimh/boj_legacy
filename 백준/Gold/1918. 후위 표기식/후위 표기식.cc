#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string a;
    stack<char> st;
    cin>>a;
    for(auto &i:a){
        if(i>='A'&&i<='Z')printf("%c",i);
        else{
            if(i=='+'||i=='-'){
                while(!st.empty()){
                    char imsi=st.top();
                    if(imsi=='(')break;
                    printf("%c",imsi);
                    st.pop();
                }
                st.push(i);
            }
            else if(i=='*'||i=='/'){
                while(!st.empty()){
                    char imsi=st.top();
                    if(imsi=='('||imsi=='+'||imsi=='-')break;
                    printf("%c",imsi);
                    st.pop();
                }
                st.push(i);
            }
            else if(i=='(')st.push(i);
            else if(i==')'){
                while(st.top()!='('){
                    printf("%c",st.top());
                    st.pop();
                }
                st.pop();
            }
        }
    }
    while(!st.empty()){
        printf("%c",st.top());
        st.pop();
    }
}