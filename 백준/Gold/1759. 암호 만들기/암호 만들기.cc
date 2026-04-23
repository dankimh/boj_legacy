#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
bool m (char i,char j) { return (i<j); }
char a[15];
int l,c;
char vowel[5]={'a','e','i','o','u'};
void f(int loc,int cnt,int vow,int nvow,char ans[]){

    ans[cnt]=a[loc];

    //printf("l%d %d\n",loc,cnt);
    //_sleep(100);
    if(cnt==l-1){
        if(vow<1||nvow<2)return;
        else {
            //printf("ans - ");
            for(int j=0;j<=cnt;j++)printf("%c",ans[j]);
            printf("\n");
            return;
        }
    }
    //for(int j=0;j<=cnt;j++)printf("%c",ans[j]);
    //printf("x\n");
    int i;
    for(i=loc+1;i<c;i++){
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){f(i,cnt+1,vow+1,nvow,ans);}
        else {f(i,cnt+1,vow,nvow+1,ans);}
    }
}
int main(){

    scanf("%d %d",&l,&c);
    int i;
    for(i=0;i<c;i++){getchar();a[i]=getchar();}
    std::sort(a,a+c,m);
    //for(i=0;i<c;i++)printf("%c",a[i]);
    //printf("\n");
    char ans[15];
    for(i=0;i<c-l+1;i++){
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){f(i,0,1,0,ans);}
        else {f(i,0,0,1,ans);}
    }
}