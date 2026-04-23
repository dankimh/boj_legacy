/*빨간색: 620nm 이상 780nm 이하
주황색: 590nm 이상 620nm 미만
노란색: 570nm 이상 590nm 미만
초록색: 495nm 이상 570nm 미만
파란색: 450nm 이상 495nm 미만
남색: 425nm 이상 450nm 미만
보라색: 380nm 이상 425nm 미만
*/
    #include<bits/stdc++.h>
using namespace std;
int main(){
    string a[7]={"Red", "Orange", "Yellow", "Green",  "Blue", "Indigo", "Violet"};
    int x[8]={781,620,590,570,495,450,425,0};
    int n;
    cin>>n;
    for(int i=0;i<7;i++){
        if(x[i]>n&&n>=x[i+1])cout<<a[i];
    }
}