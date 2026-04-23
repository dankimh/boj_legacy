#include<stdio.h>
#include<string.h>
int q[100000];
int last=20000,fr=20000;
int size(){
    return last-fr;
}
void push_front(int x){
    q[--fr]=x;
}
void push_back(int x){
    q[last++]=x;
}
int pop_front(){
    if(fr==last)return -1;
    return q[fr++];
}
int pop_back(){
    if(fr==last)return -1;
    return q[--last];
}
int empty(){
    if(!size())return 1;
    else return 0;
}
int front(){
    if(!size())return -1;
    return q[fr];
}
int back(){
    if(!size())return -1;
    return q[last-1];
}
int main(){
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        char a[11];
        scanf("%s",a);
        if(!strcmp(a,"push_front")){
            int x;
            scanf("%d",&x);
            push_front(x);
        }
        if(!strcmp(a,"push_back")){
            int x;
            scanf("%d",&x);
            push_back(x);
        }
        else if(!strcmp(a,"pop_front")){
                printf("%d\n",pop_front());
        }
        else if(!strcmp(a,"pop_back")){
                printf("%d\n",pop_back());
        }
        else if(!strcmp(a,"size")){
                printf("%d\n",size());
        }
        else if(!strcmp(a,"empty")){
                printf("%d\n",empty());
        }
        else if(!strcmp(a,"front")){
                printf("%d\n",front());
        }
        else if(!strcmp(a,"back")){
                printf("%d\n",back());
        }
    }
}