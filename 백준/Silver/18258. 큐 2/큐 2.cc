#include<stdio.h>
#include<string.h>
int q[2000000];
int last=0,fr=0;
int size(){
    return last-fr;
}
void push(int x){
    q[last]=x;
    last++;
}
int pop(){
    if(fr==last)return -1;
    int a=q[fr];
    fr++;
    return a;
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
        if(!strcmp(a,"push")){
            int x;
            scanf("%d",&x);
            push(x);
        }
        else if(!strcmp(a,"pop")){
                printf("%d\n",pop());
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