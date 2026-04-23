#include <stdio.h>
#include <math.h>
#define u double
u arr[1001];
u hsum[1001];
u jsum[1001];
u vunsan(int start, int end)
{
    return (jsum[end]-jsum[start-1])*(end-start+1) - (hsum[end]-hsum[start-1])*(hsum[end]-hsum[start-1]);
}
int main(void)
{
   int n;
   scanf("%d", &n);
   for(int i = 1; i <= n; i++)
    {
        scanf("%lf", &arr[i]);
        hsum[i] = hsum[i-1] + arr[i];
        jsum[i] = jsum[i-1] + (arr[i]*arr[i]);
    }
    for(int i=1;i<=n;i++){
        //printf("%lld %lld\n",hsum[i],jsum[i]);
    }
    printf("1\n");
   for(int i = 2; i <= n; i++)
    {
        int k=93849;
        u temp=-1;
        for(int j = 1; j <= n-i+1; j++)
        {
            //printf("%d %d %lf %lf\n",i,j,vunsan(j,j+i-1),temp);
            if(vunsan(j, j+i-1) > temp)
            {
                //printf("i'm here\n");
                temp = vunsan(j, j+i-1);
                k = j;
            }
        }
        printf("%d\n", k);
    }
    return 0;
}