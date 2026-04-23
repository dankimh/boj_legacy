#include<bits/stdc++.h>
double max(double a,double b,double c){
    if(a>b){
        if(c>a)return c;
        else return a;
    }
    else{
        if(c>b)return c;
        else return b;
    }
}
double min(double a,double b,double c){
    if(a<b){
        if(c<a)return c;
        else return a;
    }
    else{
        if(c<b)return c;
        else return b;
    }
}
int main(){
    double x1,y1,x2,y2,x3,y3;
    scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
    double A,B,C;
    A=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    B=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    C=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    double a,b,c;
    a=A+B;
    b=B+C;
    c=C+A;
    double ma=0,mi=0;
    ma=max(a,b,c);
    mi=min(a,b,c);
    if((x1-x2)*(y1-y3)==(y1-y2)*(x1-x3))printf("-1");
    else{
        printf("%.17lf",2*ma-2*mi);
    }
}