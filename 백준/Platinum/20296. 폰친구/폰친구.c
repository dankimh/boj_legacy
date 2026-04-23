#include<sys/stat.h>
#include<sys/mman.h>
#include<unistd.h>
#define r(n) for(char c=*p++;c&16;n=10*n+(c&15),c=*p++);
#define l long long
#define z 1000000007
l a[1001000],s;l f(l n,l r){if(!r)return 1;l B=(a[r]*a[n-r])%z,i,e=z-2,x=1;while(e){if(e%2){x*=B;x%=z;}B*=B;B%=z;e/=2;}return (x*a[n])%z;}l h(l n,l r){return f(n+r-1,r);}__libc_start_main(){char w[10],*p=(char*)mmap(0,80,1,MAP_SHARED,0,0);l n,m,M,k,i,b=1,A,B;r(n);r(m);r(M);r(k);for(i=1;i<=1001000;i++){b*=i;b%=z;a[i]=b;}A=M-m+1;B=k-n*m;for(i=0;B-i*A>=0;i++){if(i%2)s-=f(n,i)*h(n,B-i*A);else s+=f(n,i)*h(n,B-i*A);s=(s%z+z)%z;}for(i=0;s;s/=10)w[9-i++]=s%10|48;syscall(1,1,w+10-i,i);_exit(0);}main;