#include<stdio.h>
int main(){
    int x1,y1,x2,y2,x3,y3,a,b,c;
    scanf("%d %d\n%d %d\n%d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    a=y1-y2;
    b=-x1+x2;
    c=y1*(x1-x2)-x1*(y1-y2);
    if(a<0){
        a=-a;
        b=-b;
        c=-c;
    }
    if(y1<y2){
        if(a*x3+b*y3+c>0)printf("-1");
        else if(a*x3+b*y3+c==0)printf("0");
        else printf("1");
    }
    else if(y1==y2){
        if(x1<x2){
            if(a*x3+b*y3+c>0)printf("-1");
            else if(a*x3+b*y3+c==0)printf("0");
            else printf("1");
        }
        else if(x1>x2){
            if(a*x3+b*y3+c>0)printf("1");
            else if(a*x3+b*y3+c==0)printf("0");
            else printf("-1");
        }
    }
    else{
        if(a*x3+b*y3+c>0)printf("1");
        else if(a*x3+b*y3+c==0)printf("0");
        else printf("-1");
    }

}