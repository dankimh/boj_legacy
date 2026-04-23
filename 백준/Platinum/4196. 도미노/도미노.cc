/*#include<stdio.h>
int main(){
    int t;
    int i,j,k;
    scanf("%d",&t);
    for(k=0;k<t;k++){
        int n,a[100][100];
        scanf("%d",&n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)scanf("%d",&a[i][j]);
        }
        int a1=0,a2=0,a3=0;
        int sum=n*(n+1)/2;
        for(i=0;i<n;i++)a1+=a[i][i];
        for(i=0;i<n;i++){
            int imsi=0;
            for(j=0;j<n;j++);
        }
    }
}
*/
/*#include<stdio.h>
int main(){
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        int k,n;
        int a[14],b[14];
        for(int j=0;j<14;j++){
            a[j]=j+1;
            b[j]=0;
        }
        scanf("%d %d",&k,&n);
        for(int j=0;j<k;j++){
            for(int l=0;l<n;l++){
                b[l]=0;
            }
            for(int l=0;l<n;l++){
                //b[l]=0;
                for(int r=0;r<=l;r++){
                    b[l]+=a[r];
                }

            }
            for(int l=0;l<n;l++){
                a[l]=b[l];
            }
        }
        printf("%d\n",b[n-1]);
    }
}
*/
/*#include<stdio.h>
int main(){
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        long long x,y,a=2,c=0;
        scanf("%d %d",&x,&y);
        long long sub=y-x;
        while(c<sub){
            c+=a/2;
            a++;
        }
        printf("%d\n",a-2);
    }
}
*/
/*#include<stdio.h>
int f(int n){
    if(n==1||n==0)return 1;
    return n*f(n-1);
}
int main(){
    int a;
    scanf("%d",&a);
    printf("%d",f(a));
}
*/
/*#include<stdio.h>
int main(){
    int n,m,i,a[100],min=300001;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(min>(m-(a[i]+a[j]+a[k]))&&(m-(a[i]+a[j]+a[k]))>=0)min=(m-(a[i]+a[j]+a[k]));
            }
        }
    }
    printf("%d",m-min);
}*/
/*#include<stdio.h>
#include<algorithm>
int main(){
    int n,a[10001]={0,};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=1;i<10001;i++){
        for(int j=0;j<a[i];j++){
            printf("%d\n",i);
        }
    }
}*/
/*#include<stdio.h>
int main(){
    int n,a[8001]={0,};
    int sum=0,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        sum+=x;
        a[x+4000]++;
    }

    printf("%d\n",sum/n);

    int b=0,o=0;
    for(i=0;i<8001;i++){
        for(j=0;j<a[i];j++){
            b++;
            if(b==n/2+1){o=1;break;}
        }
        if(o==1)break;
    }
    printf("%d\n",i-4000);

    int c=0,d=0,e=0;
    for(i=0;i<8001;i++){
        if(a[i]>c){c=a[i];e=1;d=i;}
        else if(a[i]==c){if(e==1)d=i;e++;}

    }
    printf("%d\n",d-4000);

    for(i=0;i<8001;i++){
        if(a[i]!=0)break;
    }
    for(j=8000;j>=0;j--){
        if(a[j]!=0)break;
    }
    printf("%d",j-i);
}
*/

/*#include<stdio.h>
#include<math.h>
void h(int n,int a,int b,int c){
    if(n==1)printf("%d %d\n",a,c);
    else{
        h(n-1,a,c,b);
        printf("%d %d\n",a,c);
        h(n-1,b,a,c);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",(int)pow(2,n)-1);
    h(n,1,2,3);
}*/

/*#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b){
    if(*(int *)a>*(int*)b)return 1;
    else if(*(int *)a<*(int*)b)return -1;
    else return 0;
}
int main(){
    int a[8001]={0,},t[500001]={0,};
    int n;
    int sum=0;
    int max=-4001, min=4001;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int b;
        scanf("%d",&b);
        if(max<b)max=b;
        if(min>b)min=b;
        sum+=b;
        a[b+4000]++;
        t[i]=b;
    }
    printf("%.0lf\n",((double)sum/n));
    qsort(t,n,sizeof(int),compare);
    int x=0;
    for(int i=0;i<8000;i++){
        x+=a[i];
        if((x+a[i+1])>=(n+1)/2){
            x=i+1-4000;
            break;
        }
    }
    printf("%d\n",x);
    printf("%d\n",t[(n+1)/2-1]);
    int m=-1,f=1,mm=0;
    for(int i=0;i<8001;i++){
        if(m<a[i]){m=a[i];mm=i-4000;f=1;}
        else if(m<=a[i]&&f<2){m=a[i];mm=i-4000;f++;}
    }
    printf("%d\n",mm);
    printf("%d",max-min);
}*/

/*#include<stdio.h>
#include<algorithm>
int main(){
    int n;
    scanf("%d",&n);
    int a[10],i=0;
    while(n>0){
        a[i]=n%10;
        i++;
        n/=10;
    }
    std::sort(a,a+i);
    for(int j=i-1;j>=0;j--)printf("%d",a[j]);
}*/

/*#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<string>
using namespace std;
vector<pair<int,string>> s;
int main(){
    int n;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        string x;
        cin >> x;
        s.push_back(make_pair(x.size(),x));
    }
    sort(s.begin(),s.end());
    cout<<s[0].second<<"\n";
    for(i=1;i<s.size();i++){
        if(!s[i-1].second.compare(s[i].second))continue;
        cout<<s[i].second<<"\n";
    }
}*/

/*#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    vector<pair<pair<int,int>,string>> a;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        int b;
        string s;
        cin>>b>>s;
        a.push_back(make_pair(make_pair(b,i),s));
    }
    sort(a.begin(),a.end());
    for(auto& x:a){
        cout<<x.first.first<<" "<<x.second<<"\n";
    }
}*/

/*#include<stdio.h>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
vector<pair<int,int>> a;
vector<pair<int,int>> c;
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        int b;
        scanf("%d",&b);
        a.push_back(make_pair(b,i));
    }
    sort(a.begin(),a.end());
    int j=0;
    c.push_back(make_pair(a[0].second,j));
    j++;
    for(i=1;i<n;i++){
        if(a[i].first==a[i-1].first){
            c.push_back(make_pair(a[i].second,c[i-1].second));
        }
        else{
            c.push_back(make_pair(a[i].second,j));
            j++;
        }
    }
    sort(c.begin(),c.end());
    for(auto& k:c){
        printf("%d ",k.second);
    }
}*/

/*#include<stdio.h>
int n,m;
int a[20]={0,},b[20]={0,};
void f(int t,int c){
    //printf("tc%d %d\n",t,c);
    b[t]=c;
    a[c]=1;
    if(t==m-1){
        for(int i=0;i<m;i++){
            printf("%d ",b[i]);
        }
        printf("\n");
        b[t]=0;
        a[c]=0;
        return;
    }

    for(int i=1;i<=n;i++){
        if(a[i]==0){f(t+1,i);}
    }
    b[t]=0;
    a[c]=0;
    return;
}
int main(){

    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        f(0,i);
    }
}
*/

/*#include<stdio.h>
int n,m;
int a[20]={0,},b[20]={0,};
void f(int t,int c){
    //printf("tc%d %d\n",t,c);
    b[t]=c;
    a[c]=1;
    if(t==m-1){
        for(int i=0;i<m;i++){
            printf("%d ",b[i]);
        }
        printf("\n");
        b[t]=0;
        a[c]=0;
        return;
    }

    for(int i=c;i<=n;i++){
        if(a[i]==0){f(t+1,i);}
    }
    b[t]=0;
    a[c]=0;
    return;
}
int main(){

    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        f(0,i);
    }
}
*/

/*#include<stdio.h>
int n,m;
int a[20]={0,},b[20]={0,};
void f(int t,int c){
    //printf("tc%d %d\n",t,c);
    b[t]=c;
    a[c]=1;
    if(t==m-1){
        for(int i=0;i<m;i++){
            printf("%d ",b[i]);
        }
        printf("\n");
        b[t]=0;
        a[c]=0;
        return;
    }

    for(int i=c;i<=n;i++){
        {f(t+1,i);}
    }
    b[t]=0;
    a[c]=0;
    return;
}
int main(){

    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        f(0,i);
    }
}
*/

/*#include<stdio.h>
int mp[16],cnt,n;
void f(int t){
    if(t==n){cnt++;return;}
    int i;
    for(i=0;i<n;i++){
        int c=0;
        for(int j=0;j<t;j++){
            if(mp[j]==i||j+mp[j]==t+i||j-mp[j]==t-i){c=1;break;}
        }
        if(!c){
            mp[t]=i;
            f(t+1);
        }
    }
    return;
}
int main(){
    scanf("%d",&n);
    f(0);
    printf("%d",cnt);
}*/

/*#include<stdio.h>
#include<stdlib.h>
int n,mp[9][9];
void f(int t){
    int i,j;


    //_sleep(100);
    for(i=0;i<9;i++){
        for(j=0;j<9;j++)printf("%d ",mp[i][j]);
        printf("\n");
    }
    int x=t/9;
    int y=t%9;

    if(t==81){
        for(i=0;i<9;i++){
        for(j=0;j<9;j++)printf("%d ",mp[i][j]);
        printf("\n");
    }
    exit(0);
    }
    int cc=0;
    int ch[10]={0,};
    if(mp[x][y]==0){
        cc=1;
        for(int k=0;k<9;k++){
            ch[mp[k][y]]++;
            ch[mp[x][k]]++;
        }
        for(int k=(x/3)*3;k<(x/3)*3+3;k++){
            for(int l=(y/3)*3;l<(y/3)*3+3;l++){
                //printf("kl%d %d\n",k,l);
                ch[mp[k][l]]++;
            }
        }
        //for(int k=1;k<=9;k++)printf("%d\n",ch[k]);
        for(int k=1;k<=9;k++){
            if(ch[k]==0){
                cc=2;
                mp[x][y]=k;
                f(t+1);
                mp[x][y]=0;
            }
        }
    }
    else f(t+1);
    if(cc==1){printf("x%d %d %d\n",x,y,t);
        mp[x][y]=0;
        return;
    }
}
int main(){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){scanf("%d",&mp[i][j]);}
    }
    f(0);
}
*/

/*#include<stdio.h>
int m[101][101][101];
int w(int a,int b,int c){
    if(m[a+50][b+50][c+50])return m[a+50][b+50][c+50];
    if(a<=0||b<=0||c<=0)return 1;
    if(a>20||b>20||c>20)return m[a+50][b+50][c+50]=w(20,20,20);
    if(a<b&&b<c)return m[a+50][b+50][c+50]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else return m[a+50][b+50][c+50]=w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}
int main(){
    while(1){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a==-1&&b==-1&&c==-1)break;
        printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }
}
*/

/*#include<stdio.h>
int a[1000000];
int m;
int f(int n){
    if(a[n])return a[n]%15746;
    if(n==1)return 1;
    if(n==2)return 2;
    return a[n]=(f(n-1)+f(n-2))%15746;
}
int main(){
    scanf("%d",&m);
    printf("%d",f(m));
}*/

/*#include<stdio.h>
#define ll unsigned long long
ll p[102]={0,1,1,1,2,2,3,4,5,7,9,12,16,};
ll f(int n){
    if(p[n])return p[n];
    if(n<10)return p[n];
    return p[n]=f(n-1)+f(n-5);
}
int main(){
    int t,n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&t);
        printf("%lld\n",f(t));
    }
}*/

/*#include<stdio.h>
int a[1000],n;
int f(int index,int dir){
    int ch[1000]={0,},i,j;
    if(dir==0){
    ch[0]=1;
    for(i=1;i<index+1;i++){
            int max=0;
            for(j=0;j<i;j++){
                if(a[j]<a[i]){
                    if(max<ch[j])max=ch[j];
                }

            }
            ch[i]=max+1;
    }
    int m=0;
    for(i=0;i<index+1;i++){
       //printf("in%da%d ",index,ch[i]);
        if(m<ch[i])m=ch[i];
    }
    //printf("\n");
    return ch[index];
    }
    else{
    ch[n-1]=1;
    for(i=n-2;i>=index;i--){
            int max=0;
            for(j=i+1;j<n;j++){
                if(a[j]<a[i]){
                    if(max<ch[j])max=ch[j];
                }

            }
            ch[i]=max+1;
    }
    int m=0;
    for(i=index;i<n;i++){
        //printf("in%db%d ",index,ch[i]);
        if(m<ch[i])m=ch[i];
    }
    //printf("\n");
    return ch[index];
    }
}
int main(){
    int i,ch[1000]={0,};
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        int j;
        ch[i]+=f(i,0);
        ch[i]+=f(i,1);

    }
    int max=0;
    for(i=0;i<n;i++){
        if(max<ch[i])max=ch[i];
    }
    printf("%d",max-1);
}
*/

/*#include<stdio.h>
#include<vector>
using namespace std;
vector<int> lcs, ind;
int main(){
    int n,a[1000],i,ch[1000],cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    ch[0]++;
    lcs.push_back(a[0]);
    ch[0]=0;
    for(i=1;i<n;i++){
        if(lcs[cnt]<a[i]){
            lcs.push_back(a[i]);
            cnt++;
            ch[i]=cnt;
        }
        else{
            auto p=lower_bound(lcs.begin(),lcs.end(),a[i])-lcs.begin();
            lcs[p]=a[i];
            ch[i]=p;
        }
    }
    printf("%d\n",cnt+1);
    for(i=n-1;i>=0&&cnt>=0;i--){
        if(ch[i]==cnt){
            ind.push_back(a[i]);
            cnt--;
        }
    }
    for(i=ind.size()-1;i>=0;i--){
        printf("%d ",ind[i]);
    }
}*/

/*#include<stdio.h>
int main(){
    int dp[101][1001];
    int n,k,a[1001][2];
    int i,j;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    for(i=0;i<=k;i++)dp[0][i]=0;
    for(i=0;i<=n;i++)dp[i][0]=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            if(j<a[i][0])dp[i][j]=dp[i-1][j];
            else{
                if(a[i][1]+dp[i-1][j-a[i][0]]>dp[i-1][j])dp[i][j]=a[i][1]+dp[i-1][j-a[i][0]];
                else dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=k;j++)printf("%d ",dp[i][j]);
        printf("\n");
    }
    printf("%d",dp[n][k]);
}*/

/*#include<stdio.h>
#include<vector>
#include<math.h>
#define ll long long
#define vll vector<ll>
using namespace std;
ll f(vll &arr,vll &t,int node,int st,int en){

    if(st==en){
        return t[node]=arr[st];
    }

    int mid=(st+en)/2;
    return t[node]=f(arr,t,node*2,st,mid)+f(arr,t,node*2+1,mid+1,en);
}
void f1(vll &arr,vll &t,int node,int st,int en,int goal,ll ch){
//printf("s%d %d %d\n",node,st,en);
     if(st==en){
        t[node]+=ch;
        arr[st]+=ch;
        return;
     }
     int mid=(st+en)/2;
     if(goal<=mid){
        t[node]+=ch;
        f1(arr,t,node*2,st,mid,goal,ch);
        return;
     }
     else{
        t[node]+=ch;
        f1(arr,t,node*2+1,mid+1,en,goal,ch);
        return;
     }
}
ll f2(vll &t, int node, int st, int en, int start, int end){
    int mid=(st+en)/2;
    if(en<start)return 0;
    if(end<st)return 0;
    if(start<=st&&en<=end){
        return t[node];
    }
    return f2(t,node*2,st,mid,start,end)+f2(t,node*2+1,mid+1,en,start,end);
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int i;
    vll arr(n),t(4*n);
    ll sum=0;
    for(i=0;i<n;i++){
        ll imsi;
        scanf("%lld",&arr[i]);

    }
    sum=f(arr,t,1,0,n-1);

    for(i=0;i<m+k;i++){
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a==1)f1(arr,t,1,0,n-1,b-1,c-arr[b-1]);
        if(a==2)printf("%lld\n",f2(t,1,0,n-1,b-1,c-1));

    }//for(auto &j:arr)printf("a%lld\n",j);
}
*/

/*#include<utility>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main(){
    int n,i,now=0,cnt=0;
    scanf("%d",&n);
    vector<pair<int, int>> a(n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i].second,&a[i].first);
    }
    sort(a.begin(),a.end());
    for(auto& i:a){
         if(i.second<now)continue;
         else{
            now=i.first;
            cnt++;
         }
    }
    printf("%d",cnt);
}*/

/*#include<stdio.h>
#include<stdlib.h>
#define ll long long
int mp[2001][2001];
int nCr(int a, int b, int mod){
    if(mp[a][b])return mp[a][b];
    if(a==b)return mp[a][b]=1%mod;
    if(b==1)return mp[a][b]=a%mod;
    if(b==0)return mp[a][b]=1%mod;

    return mp[a][b]=((nCr(a-1,b,mod))+(nCr(a-1,b-1,mod)))%mod;
}
int main(){
    ll n,k,ncr=1;
    int m;
    scanf("%lld %lld %d",&n,&k,&m);

    while(n>0){
        int a,b;
        a=n%m;
        b=k%m;
        if(a<b){
            ncr=0;
            break;
        }
        ncr*=nCr(a,b,m);
        ncr%=m;
        n/=m;
        k/=m;
    }
    printf("%lld",ncr);
}
*/

/*#include<stdio.h>
#define ll long long
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
     int t,i;
     scanf("%d",&t);
     for(i=0;i<t;i++){
        ll k,c;
        ll r0,r1;
        ll s0,s1;
        ll t0,t1;
        ll q;
        scanf("%lld %lld",&k,&c);
        if(gcd(k,c)!=1){
            printf("IMPOSSIBLE\n");
            continue;
        }
        else if(k==1){
            if(c==1){printf("2\n");continue;}
            printf("1\n");continue;
        }
        else if(c==1){
            if(k>=1000000000){
                printf("IMPOSSIBLE\n");
                continue;
            }
            printf("%lld\n",k+1);
            continue;
        }
        else{
            ll temp;
            r0=k;r1=c;
            s0=1;s1=0;
            t0=0;t1=1;
            while(r1>0){
                q=r0/r1;
                temp=r0;
                r0=r1;
                r1=temp-r0*q;

                temp=s0;
                s0=s1;
                s1=temp-s0*q;

                temp=t0;
                t0=t1;
                t1=temp-t0*q;
            }
            if(t0<0)t0+=k;
            printf("%lld\n",t0);
        }
     }
}
*/

/*#include<iostream>
#include<vector>
#include<string>
#include<utility>
using namespace std;
vector <pair<int,int>> levelState(100001);
int state(int start,int end, int height){
    if(height==1){
        levelstate[height]=make_pair( )
    }
}
int main(){

}*/

/*#include<stdio.h>
#include<vector>
#include<utility>
#include<stdlib.h>
using namespace std;
vector<int> map(100);
int g(vector<vector<pair<int,int>>> &gr, int node){
    //printf("a%d\n",node);
    //_sleep(500);
    int length=0,max=0,i;
    for(i=0;i<gr[node].size();i++){
        if(map[gr[node][i].first]==0){
            map[gr[node][i].first]=1;
            length=g(gr,gr[node][i].first)+gr[node][i].second;
        }
        if(max<length)max=length;
    }
    return max;
}
int main(){
    int v;
    scanf("%d",&v);
    vector<vector<pair<int,int>>> graph(100);
    vector<int> startlist;
    int i;
    for(i=0;i<v;i++){
        int e;
        scanf("%d",&e);
        int a=0,b;
        while(1){
            scanf("%d",&a);
            if(a==-1)break;
            scanf("%d",&b);
            graph[e].push_back(make_pair(a,b));
        }

        if(graph[e].size()==1){startlist.push_back(e);}
    }

    int max=0;
    for(auto& i:startlist){
        for(int j=0;j<v;j++)map[j]=0;
        map[i]=1;
        int length=g(graph,i);
        if(max<length)max=length;
    }
    printf("%d",max);
}
*/

/*#include<stdio.h>
#include<stdlib.h>
int post[100000];
int in[100000];
int pre[100000];
int cnt,n;
void f(int stloc,int enloc,int st,int en){
    if(st>en)return;
    //_sleep(100);
    int node=post[en];
    pre[cnt]=node;
    cnt++;
    //printf("d%d %d %d %d %d\n",stloc,enloc,st,en,node);
    if(st==en)return;
    int i;
    for(i=stloc;i<=enloc;i++){
        if(in[i]==node)break;
    }
    f(stloc,i-1,st,st+(i-stloc)-1);
    f(i+1,enloc,st+(i-stloc),en-1);
    return;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&in[i]);
    for(i=0;i<n;i++)scanf("%d",&post[i]);
    f(0,n-1,0,n-1);
    for(i=0;i<n;i++)printf("%d ",pre[i]);
}*/

/*#include<stdio.h>
#include<algorithm>
int main(){
    int n;
    scanf("%d",&n);
    int a[1000];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    std::sort(a,a+n);
    int m=0;
    for(int i=0;i<n;i++){
        m+=(n-i)*a[i];
    }
    printf("%d",m);
}
*/

/*#include<iostream>
#include<string>
using namespace std;
int f(string a){
    int i,p=1,sum=0;
    for(i=a.size()-1;i>=0;i--){
        sum+=p*(a[i]-'0');
        p*=10;
    }
    return sum;
}
int main(){
    string a;
    cin>>a;
    int op=0,sum=0,num=0;
    string b;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9')b.push_back(a[i]);
        else{
            if(op==0){
                sum+=f(b);
                b.clear();
            }
            else if(op==1){
                sum-=f(b);
                b.clear();
            }

            if(a[i]=='+')continue;
            else if(a[i]=='-'){
                op=1;
            }
        }
    }
    if(!op)sum+=f(b);
    else sum-=f(b);
    printf("%d",sum);
}
*/
/*#include<iostream>
using namespace std;
#define endl "\n"

#include<vector>
#include<utility>
#include<algorithm>

pair<vector<int>, vector<int>> SplitInorder(vector<int> v, int x) {
   vector<int> left;
   vector<int> right;
   bool state = 0;
   for (int i = 0; i < v.size(); i++) {
      if (v[i] == x) { state = 1; continue; }
      if (!state) {
         left.push_back(v[i]);
      }
      else { right.push_back(v[i]); }
   }
   return make_pair(left, right);
}

pair<vector<int>, vector<int>> SplitPostorder(vector<int> v,vector<int> inorder_left) {
   vector<int> left;
   vector<int> right;
   int tmp;
   for (int i = 0; i < v.size()-1; i++) {
      tmp = v[i];
      auto it = find(inorder_left.begin(), inorder_left.end(), tmp);
      if (it == inorder_left.end()) {
         right.push_back(tmp);
      }
      else { left.push_back(tmp); }
   }

   return make_pair(left, right);
}

void Preorder(vector<int> Inorder, vector<int> Postorder) {
   if (Postorder.size() == 0) {
      return;
   }
   if (Postorder.size() == 1) {
      cout << Postorder[0] << " ";
      return;
   }
   int x = Postorder[Postorder.size()-1];
   cout << x << " ";

   pair<vector<int>, vector<int>> si = SplitInorder(Inorder, x);
   pair<vector<int>, vector<int>> sp = SplitPostorder(Postorder, si.first);

   Preorder(si.first, sp.first); // left
   Preorder(si.second, sp.second); // right
   return;
}


int main() {
   vector<int> inorder;
   vector<int> postorder;
   int n;
   cin >> n;
   int tmp;
   for (int i = 0; i < n; i++) {
      cin >> tmp;
      inorder.push_back(tmp);
   }
   for (int i = 0; i < n; i++) {
      cin >> tmp;
      postorder.push_back(tmp);
   }
   Preorder(inorder, postorder);

   return 0;
}*/

/*#include<stdio.h>
#define ll long long
ll m[10][10];
ll f(int a,int b){
    if(a==b)return m[a][b]=1;
    if(b==1)return m[a][b]=a;
    if(b==0)return m[a][b]=1;
    return m[a][b]=f(a-1,b)+f(a-1,b-1);
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d",f(n,k));
}*/

/*#include<stdio.h>
#define ll long long
#define MOD 10007
ll m[10][10];
ll f(int a,int b){
    if(m[a][b])return m[a][b];
    if(a==b)return m[a][b]=1;
    if(b==1)return m[a][b]=a%MOD;
    if(b==0)return m[a][b]=1;
    return m[a][b]=(f(a-1,b)+f(a-1,b-1))%MOD;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d",f(n,k)%MOD);
}*/

/**#include<stdio.h>
#include<vector>
using namespace std;
#define ll long long
ll f(int n,int r,ll mod){
    ll A=1,B=1;
    int i;
    for(i=1;i<=n;i++){
        A*=i;
        A%=mod;
    }
    for(i=1;i<=r;i++){
        B*=i;
        B%=mod;
    }
    for(i=1;i<=n-r;i++){
        B*=i;
        B%=mod;
    }
    ll ex=mod-2;
    ll re=1;
    while(ex){
        if(ex%2){
            re*=B;
            re%=mod;
        }
        B*=B;
        B%=mod;
        ex/=2;
    }
    printf("%lld",(re*A)%mod);
    return (re*A)%mod;
}
int main(){
    int n,r;
    ll mod;
    scanf("%d %d %lld",&n,&r,&mod);
    int i;
    vector<ll> primes;
    vector<ll> mods;
    i=2;
    int d=1,imsi=mod;
    while (i<=imsi) {
		if (imsi%i == 0) {
			d*=i;
			imsi = imsi / i;
		}
		else{
            if(d!=1)primes.push_back(d);
            d=1;
            i++;
		}
	}
	primes.push_back(d);
    int result=1;
    for(auto &i:primes){
        printf("prime%d\n",i);
        mods.push_back(f(n,r,i));
    }
    for(auto &i:mods){
        printf("mod%lld\n",i);
    }
    printf("%d",result);
}
**/
/*#include<stdio.h>
#define ll long long
int main(){
    int m,i;
    ll mod=1000000007;
    scanf("%d",&m);
    ll a[4000];
    a[0]=1;
    for(i=1;i<=4000;i++){
        a[i]=(i*a[i-1])%mod;
    }
    for(int j=0;j<m;j++){
        int n,r;
        scanf("%d %d",&n,&r);
        ll A=a[n];
        ll B=(a[n-r]*a[r])%mod;
        ll ex=mod-2;
        ll re=1;
        while(ex){
            if(ex%2){
                re*=B;
                re%=mod;
            }
            B*=B;
            B%=mod;
            ex/=2;
        }
        printf("%lld\n",(re*A)%mod);
    }
}*/
/*
#include<stdio.h>
#define ll long long
int main(){
    int n,r;
    ll mod=1000000007;
    scanf("%d %d",&n,&r);
    int i;
    ll A=1,B=1;
    for(i=1;i<=n;i++){
        A*=i;
        A%=mod;
    }
    for(i=1;i<=r;i++){
        B*=i;
        B%=mod;
    }
    for(i=1;i<=n-r;i++){
        B*=i;
        B%=mod;
    }
    ll ex=mod-2;
    ll re=1;
    while(ex){
        if(ex%2){
            re*=B;
            re%=mod;
        }
        B*=B;
        B%=mod;
        ex/=2;
    }
    printf("%lld",(re*A)%mod);
}*/
/*#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;

matrix operator * (const matrix &a, const matrix &b) {
    ll size = a.size();
    matrix res(size, vector<ll>(size));
    for (ll i = 0; i < size; i++) {
        for (ll j = 0; j < size; j++) {
            for (ll k = 0; k < size; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] %= 1000;
        }
    }
    return res;
}

matrix power(matrix a, ll n) {
    ll size = a.size();
    matrix res(size, vector<ll>(size));
    for (ll i = 0; i < size; i++) { // ґЬА§ За·Д
        res[i][i] = 1;
    }
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * a;
        }
        n /= 2;
        a = a * a;
    }
    return res;

}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    for(int i=1; i<= test_case; i++){
        ll n;
        cin >> n;
        matrix a = { {6,-4}, {1, 0} };
        matrix res = power(a, n - 1);
        string ans = to_string((((28 * res[1][0] + 6 * res[1][1]) - 1) % 1000 + 1000) % 1000);
        ll size = ans.size();
        while (true) {
            if (size == 3) break;
            ans = "0" + ans;
            size++;

        }
        cout << "Case #" << i << ": " << ans << '\n';
     }


    return 0;
}*/
/*#include<stdio.h>
#include<math.h>
#define ll long long
int a[501000];
ll g(int b,int n){
    ll re=1,mod=100000;
    while(n){
        if(n%2){
            re*=b;
            re%=mod;
        }
        b*=b;
        b%=mod;
        n/=2;
    }
    return re%mod;
}
ll f(int n){
    //printf("n%d\n",n);
    if(n<500000){
        if(a[n])return a[n];
    }
    if(n==1)return a[n]=6;
    if(n%2){
        if(n<500000)return a[n]=((f(n/2))*(f((n/2)+1))-(6*g(4,n/2)))%100000;
        else return ((f(n/2))*(f((n/2)+1))-(6*g(4,n/2)))%100000;
    }

    else{
        if(n<500000)return a[n]=((f(n/2))*(f(n/2))-(2*g(4,n/2)))%100000;
        else return ((f(n/2))*(f(n/2))-(2*g(4,n/2)))%100000;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    int i;

    for(i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        printf("Case #%d: %03lld\n",n,((f(n)-1)+100000)%1000);

    }
}
*/
/*#include<stdio.h>
#include<math.h>
#define ll long long
int a[400000010];
int g(int b,int n){
    int re=1,mod=1000;
    while(n){
        if(n%2){
            re*=b;
            re%=mod;
        }
        b*=b;
        b%=mod;
        n/=2;
    }
    return re;
}
int f(int n){
    if(n<400000000&&a[n])return a[n];
    if(n==1)return a[n]=6;
    if(n%2){
        if(n<400000000)return a[n]=(f(n/2)*f((n/2)+1)-6*g(4,n/2))%100000;
        else return (f(n/2)*f((n/2)+1)-6*g(4,n/2))%100000;
    }
    else{
        if(n<400000000)return a[n]=(f(n/2)*f(n/2)-2*g(4,n/2))%100000;
        else return (f(n/2)*f(n/2)-2*g(4,n/2))%100000;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    int i;
    int arr[33]={1,6,28,};
    int ab=4;
    for(i=2;i<=32;i++){
        arr[i]=(arr[i-1]*arr[i-1])-2*ab;
        arr[i]%=1000;
        ab*=ab;
        ab%=1000;
    }
    for(i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        printf("Case #%d: %03d\n",n,f(n)-1);
    }
}*/

/*#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    int arr[100];
    int i;
    for(i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int ex=n-1;
        int a=1,b=0,c=0,d=1;
        int da=6,db=-4,dc=1,dd=0;
        while(ex){
            if(ex%2){
                int ta=a,tb=b,tc=c,td=d;
                a=(ta*da+tb*dc)%1000;
                b=(ta*db+tb*dd)%1000;
                c=(tc*da+td*dc)%1000;
                d=(tc*db+td*dd)%1000;
            }
            int aaa=da,bbb=db,ccc=dc,ddd=dd;
            da=(aaa*aaa+bbb*ccc)%1000;
            db=(aaa*bbb+bbb*ddd)%1000;
            dc=(ccc*aaa+ddd*ccc)%1000;
            dd=(ccc*bbb+ddd*ddd)%1000;
            ex/=2;
        }
        int ans=c*28+d*6;
        arr[i]=(ans+999)%1000;

    }
    for(i=0;i<t;i++){
        printf("Case #%d: %03d\n",i+1,arr[i]);
    }
}
*/

/**#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
void maketree(vector<vector<int>> &t,vector<int> &arr,int node,int st,int en){
    printf("ss%d %d %d\n",node,st,en);
    if(st==en){t[node].push_back(arr[st]);return;}
    int mid=(st+en)/2;
    maketree(t,arr,node*2,st,mid);
    maketree(t,arr,node*2+1,mid+1,en);
    t[node].resize(t[node*2].size()+t[node*2+1].size());
    merge(t[node*2].begin(),t[node*2].end(),t[node*2+1].begin(),t[node*2+1].end(),t[node].begin());
    return;
}
vector<int> Q(vector<vector<int>> &t,int p,int q,int node,int st,int en){
    //printf("ssq%d %d %d\n",node,st,en);
    vector<int> imsi;
    int mid=(st+en)/2;

    if(en<p)return imsi;
    if(q<st)return imsi;
    imsi=t[node];
    for(auto& i:imsi){
        printf("%d ",i);
    }
    printf("\n");
    if(p<=st&&en<=q){return imsi;}
    //printf("a\n");
    vector<int> a=Q(t,p,q,node*2,st,mid);
    vector<int> b=Q(t,p,q,node*2+1,mid+1,en);
    vector<int> res(a.size()+b.size());
    merge(a.begin(),a.end(),b.begin(),b.end(),res.begin());
    return res;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int i;
    vector<int> a(100000);
    vector<vector<int>> mergetree(18);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    maketree(mergetree,a,1,0,n-1);
    for(i=0;i<m;i++){
        int p,q,r;
        scanf("%d %d %d",&p,&q,&r);
        vector<int> arr;
        arr=Q(mergetree,p-1,q-1,1,0,n-1);
        printf("%d\n",arr[r-1]);
    }
    for(auto &i:mergetree){
        for(auto &j:i){
            printf("%d ",j);
        }
        printf("\n");
    }
}
**/

/*#include<stdio.h>
#include<string.h>
#define bzero(x,y) memset(x,0,y)
int v[501];
int mp[501][501];
int ch=1,n;
int f(int node,int prev){
    //printf("c%d %d %d\n",node,prev,ch);
    v[node]=1;
    int i;
    int r=1;
    for(i=1;i<=n;i++){
        if(i==node)continue;
        if(mp[node][i]==1){
            if(v[i]==0){
                if(!f(i,node))r=0;
            }
            else{
                if(i!=prev)r=0;
            }
        }
    }
    return r;
}
int main(){
    int j=1;
    while(1){
        int m,i,c=0;
        scanf("%d %d",&n,&m);
        if(n==0&&m==0)break;
        bzero(v,sizeof(int)*501);
        bzero(mp,sizeof(int)*251001);
        for(i=0;i<m;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            mp[a][b]=1;
            mp[b][a]=1;
        }
        for(i=1;i<=n;i++){
            ch=1;
            if(!v[i]){c+=f(i,0);}

        }
        if(c==0)printf("Case %d: No trees.\n",j);
        if(c==1)printf("Case %d: There is one tree.\n",j);
        if(c>1)printf("Case %d: A forest of %d trees.\n",j,c);
        j++;
    }
}*/

/*#include<stdio.h>
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
*/
/*#include<queue>
#include<stdio.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    queue<int> q;
    for(int i=0;i<n;i++){
        q.push(i+1);
    }
    while(q.size()>1){
        int a;
        q.pop();
        a=q.front();
        q.pop();
        q.push(a);
    }
    printf("%d",q.back());
}
*/

/*#include<stdio.h>
#include<queue>
using namespace std;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    queue<int> a;
    vector<int> ans;
    int i;
    for(i=0;i<n;i++)a.push(i+1);
    while(!a.empty()){
        if(a.size()>=k){
            int b[k];
            for(i=0;i<k;i++){
                b[i]=a.front();
                a.pop();
            }
            ans.push_back(b[k-1]);
            //printf("%d, ",b[k-1]);
            for(i=0;i<k-1;i++){
                a.push(b[i]);
            }
        }
        else if(a.size()>1){
            int b=k;
            while(b>a.size())b-=a.size();
            int c[b];
            for(i=0;i<b;i++){
                c[i]=a.front();
                a.pop();
            }
            ans.push_back(c[b-1]);
            //printf("%d, ",c[b-1]);
            for(i=0;i<b-1;i++){
                a.push(c[i]);
            }
        }
        else{
            ans.push_back(a.front());
            //printf("%d>",a.front());
            a.pop();
        }
    }
    printf("<");
    for(i=0;i<ans.size()-1;i++){
        printf("%d, ",ans[i]);
    }
    printf("%d>",ans[ans.size()-1]);
}*/
/*#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
int main(){
    int t;
    scanf("%d\n",&t);
    int i;
    for(i=0;i<t;i++){
        int n,m;
        scanf("%d %d\n",&n,&m);
        queue<pair<int,int>> a;
        for(int j=0;j<n;j++){
            int w;
            scanf("%d",&w);
            a.push(make_pair(w,j));
        }
        int seq=1;
        vector<int> b(n);
        while(!a.empty()){

            vector<pair<int,int>> imsi;
            int size=a.size();
            for(int j=0;j<size;j++){
                imsi.push_back(a.front());
                a.pop();
            }
            int m=0;
            for(auto &j:imsi){
                //printf("p%d %d\n",j.first,j.second);
                if(m<j.first)m=j.first;
            }
            //printf("a%d\n",size);
            if(imsi[0].first==m){
                b[imsi[0].second]=seq;
                seq++;
                //printf("a%d\n",size);
                if(size==1)break;
                for(int j=0;j<size-1;j++){
                    a.push(imsi[j+1]);
                }
            }
            else{
                for(int j=0;j<size-1;j++){
                    a.push(imsi[j+1]);
                }
                a.push(imsi[0]);
            }
        }
        printf("%d\n",b[m]);
    }

}
*/
/*#pragma warning(disable: 4996)
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
*/

/*#include<stdio.h>
int map[128][128],wh,bl;
void f(int x1,int y1,int x2,int y2){
    if(x1==x2&&y1==y2){
        if(map[x1][y1]==0)wh++;
        if(map[x1][y1]==1)bl++;
        return;
    }
    int i,j,ch=map[x1][y1],succ=1;
    for(i=x1;i<=x2;i++){
        for(j=y1;j<=y2;j++){
            if(map[i][j]!=ch){
                succ=0;
                break;
            }
            if(succ==0)break;
        }
    }
    if(!succ){
        f(x1,y1,(x1+x2+1)/2-1,(y1+y2+1)/2-1);
        f(x1,(y1+y2+1)/2,(x1+x2+1)/2-1,y2);
        f((x1+x2+1)/2,y1,x2,(y1+y2+1)/2-1);
        f((x1+x2+1)/2,(y1+y2+1)/2,x2,y2);
    }
    else{
        if(map[x1][y1]==0)wh++;
        if(map[x1][y1]==1)bl++;
        return;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }
    f(0,0,n-1,n-1);
    printf("%d\n%d",wh,bl);
}
*/

/*#include<stdio.h>
char a[64][64];
void f(int x1,int y1,int x2,int y2){
    if(x1==x2&&y1==y2){
        if(a[x1][y1]=='0')printf("0");
        if(a[x1][y1]=='1')printf("1");
        return;
    }
    int i,j,succ=1;
    char ch=a[x1][y1];
    for(i=x1;i<=x2;i++){
        for(j=y1;j<=y2;j++){
            if(a[i][j]!=ch){
                succ=0;
                break;
            }
            if(succ==0)break;
        }
    }
    if(!succ){
        printf("(");
        f(x1,y1,(x1+x2+1)/2-1,(y1+y2+1)/2-1);
        f(x1,(y1+y2+1)/2,(x1+x2+1)/2-1,y2);
        f((x1+x2+1)/2,y1,x2,(y1+y2+1)/2-1);
        f((x1+x2+1)/2,(y1+y2+1)/2,x2,y2);
        printf(")");
    }
    else{
        if(a[x1][y1]=='0')printf("0");
        if(a[x1][y1]=='1')printf("1");
        return;
    }
    return;
}
int main(){
    int n;
    scanf("%d\n",&n);
    int i,j;
    for(i=0;i<n;i++)scanf("%s",a[i]);
    f(0,0,n-1,n-1);
}*/

/*#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<utility>
#define ll long long
using namespace std;
void g(vector<int> &his,vector<int> &segtree,int node,int st,int en){

    if(st==en){segtree[node-1]=st;return;}
    g(his,segtree,node*2,st,(st+en)/2);
    g(his,segtree,node*2+1,(st+en)/2+1,en);
    if(his[segtree[node*2-1]]<=his[segtree[node*2+1-1]])segtree[node-1]=segtree[node*2-1];
    else segtree[node-1]=segtree[node*2+1-1];
    //if(a.first<b.first){
    //    return segtree[node-1]=a;
    //}
    //else if(a.first==b.first){
    //    if(a.second<b.second)return segtree[node-1]=a;
    //    else return segtree[node-1]=b;
    //}
}
int h(vector<int> &his,vector<int> &segtree,int node,int st,int en,int start,int end){
    //printf("h%d %d %d\n",node,st,en);
    if(en<start)return -1;
    if(end<st)return -1;
    if(start<=st&&en<=end)return segtree[node-1];
    int a,b;
    a=h(his,segtree,node*2,st,(st+en)/2,start,end);
    b=h(his,segtree,node*2+1,(st+en)/2+1,en,start,end);
    if(a==-1)return b;
    else if(b==-1)return a;
    else{
        if(his[a]<=his[b]){
            return a;
        }
        else return b;
    }
}
ll f(vector<int> &his,vector<int> &segtree,int st,int en,int n){

    if(st>en){
        return -1;
    }
    if(st==en){
        return his[st];
    }
    //ll min=1000000001,loc=0,i;
    int m;
    m=h(his,segtree,1,0,n-1,st,en);
    //printf("m%d %d\n",m,his[m]);
    ll a=0,b,c=0;
    if(st<=m-1)a=f(his,segtree,st,m-1,n);
    if(m+1<=en)c=f(his,segtree,m+1,en,n);
    //b=f(his,i,i);

    ll result=0;
    if(a<c)result=c;
    else result=a;
    if(result<((ll)his[m]*(ll)(en-st+1)))result=(ll)his[m]*(ll)(en-st+1);
    //result=max(a.first,c.first);
    //result=max(result,(ll)his[m]*(ll)(en-st+1));
    return result;
}
int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(n==0)break;
        int i;
        vector<int> his(n);
        vector<int> segtree(300000);
        for(i=0;i<n;i++)scanf("%d",&his[i]);
        g(his,segtree,1,0,n-1);
        //for(i=0;i<15;i++)printf("seg%d\n",segtree[i]);
        ll ans;
        //ans=g(his,0,n-1);
        ans=f(his,segtree,0,n-1,n);
        printf("%d\n",ans);
    }
}
*/

/*#include<stdio.h>
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
}*/

/*#include<stdio.h>
int main(){
    int prime[20000],cnt=0;
    int n,i;
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        int ch=0;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){ch=1;break;}
        }
        if(ch==0){
            prime[cnt]=i;
            cnt++;
        }
    }
    //for(i=0;i<cnt;i++)printf("%d ",prime[i]);
    int front=0,rear=0,sum=0,ans=0;
    while(rear<=cnt){
        //printf("a%d\n",sum);
        if(sum<n){
            sum+=prime[rear++];
        }
        else if(sum==n){
            ans++;
            sum+=prime[rear++];
        }
        else {
            sum-=prime[front++];
        }
    }
    printf("%d",ans);
}
*/

/*#include<stdio.h>
#define ll long long
int main(){
    ll n;
    scanf("%lld",&n);
    ll ex=n,a=2,b=0,c=1,d=1;
    while(ex){
        //printf("a%lld %lld %lld %lld\n",a,b,c,d);
        if(ex%2){
            ll ta=a,tb=b;
            a=(ta*c+5*tb*d)/2;
            b=(ta*d+tb*c)/2;
            a%=10000000;
            b%=10000000;
        }
        ll tc=c,td=d;
        c=((tc*tc+5*td*td)/2)%10000000;
        d=((2*tc*td)/2)%10000000;
        ex/=2;
    }
    ex=n;
    ll p=2,q=0,r=1,s=-1;
    while(ex){
        //printf("a%lld %lld %lld %lld\n",p,q,r,s);
        if(ex%2){
            ll tp=p,tq=q;
            p=(tp*r+5*tq*s)/2;
            q=(tp*s+tq*r)/2;
            p%=10000000;
            q%=10000000;
        }
        ll tr=r,ts=s;
        r=((tr*tr+5*ts*ts)/2)%10000000;
        s=((2*tr*ts)/2)%10000000;
        ex/=2;
    }

    printf("%lld",((b-q)/2)%1000000);
}

*/
/*#include<stdio.h>
int main(){
    int prime[100001],cnt=0;
    int n,i,s;
    scanf("%d %d",&n,&s);
    for(i=0;i<n;i++){
        scanf("%d",&prime[i]);
    }
    prime[n]=0;
    int front=0,rear=0,sum=0,ans=100001;
    while(rear<=n){
        //printf("a%d %d %d\n",front,rear,sum);
        if(sum<s){
            sum+=prime[rear++];
        }
        else if(sum==s){
            if(ans>rear-front)ans=rear-front;
            sum+=prime[rear++];
        }
        else {
            if(ans>rear-front)ans=rear-front;
            sum-=prime[front++];
        }
    }
    int min=100001;
    if(ans>100000)printf("0");
    else printf("%d",ans);
}
*/
/*#include<stdio.h>
#include<queue>
#include<stdlib.h>
#include<utility>
using namespace std;
int prime[20000],cnt=0;
int g(int a,int b){
    int time=0,i;
    //printf("g%d %d \n",a,b);
    for(i=0;i<4;i++){
        if(a%10!=b%10)time++;
        a/=10;
        b/=10;
    }
    //printf("%d\n",time);
    if(time==1)return 1;
    else return 0;
}
int main(){
    int i;
    for(i=1000;i<=10000;i++){
        int ch=0;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){ch=1;break;}
        }
        if(ch==0){
            prime[cnt]=i;
            cnt++;
        }
    }
    int t;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        int n,m,j;
        scanf("%d %d",&n,&m);
        queue<pair<int,int>> q;
        int visit[10000]={0,},ans=-1,now;
        q.push({n,0});
        while(!q.empty()){
            //    _sleep(100);
            now=q.front().first;
            int k;
            ans=q.front().second;
            q.pop();
            //printf("a%d %d\n",now,ans);
            visit[now]=1;
            if(now==m)break;
            for(k=0;k<cnt;k++){
                if(g(now,prime[k])&&visit[prime[k]]==0){
                    q.push({prime[k],ans+1});
                }
            }
        }
        if(now!=m)printf("Impossible");
        else printf("%d\n",ans);
    }
}*/

/*#include<stdio.h>
#define ll long long
ll a[1000010]={0,},prime[1000000];
int main(){

    ll min,max;
    scanf("%lld %lld",&min,&max);
    ll i,ans=0,cnt=0;
    ll hh=(max<=1000001)?max:1000001;
    for(i=2;i<=hh;i++){
        int ch=0;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){ch=1;break;}
        }
        if(ch==0){
            prime[cnt]=i;
            cnt++;
        }
    }
    //printf("%lld\n",prime[cnt-1]);
    //for(i=0;i<10;i++)printf("%d ",prime[i]);
    //printf("\n");
    for(i=0;prime[i]*prime[i]<=max&&i<cnt;i++){
        ll sq=prime[i]*prime[i];
        ll ch=0;
        if(min%sq==0)ch=min;
        else ch=(min/sq+1)*sq;
        for(ll j=ch;j<=max;j+=sq){
            a[j-min]=1;
        }
    }
    for(i=0;i<max-min+1;i++)if(!a[i])ans++;
    printf("%lld",ans);
}
*/

/*#include<stdio.h>
#include<vector>
#define ll long long
using namespace std;
vector<vector<ll>> f(vector<vector<ll>> &a,vector<vector<ll>> &b,ll n){
    int i,j;
    vector<vector<ll>> ans(5,vector<ll> (5));
    for(i=0;i<n;i++){
            for(j=0;j<n;j++)printf("%lld ",b[i][j]%1000);
            printf("\n");
        }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ll imsi=0;
            for(int k=0;k<n;k++){
                imsi+=(a[i][k]*b[k][j]);
                //printf("%d %d %d %d\n",i,k,k,j);
            }
            //printf("a%lld\n",imsi);
            ans[i][j]=(imsi%1000);
        }
    }
    return ans;
}
int main(){
    ll n,bb;
    vector<vector<ll>> base(5,vector<ll> (5));
    vector<vector<ll>> ans(5,vector<ll> (5));
    ans={{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};
    scanf("%lld %lld",&n,&bb);
    int i,j;
    for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%lld",&base[i][j]);
    while(bb){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)printf("%lld ",ans[i][j]%1000);
            printf("\n");
        }
        if(bb%2){
            ans=f(ans,base,n);
        }
        base=f(base,base,n);
        bb/=2;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)printf("%lld ",ans[i][j]%1000);
        printf("\n");
    }
}
*/

/*#include<stdio.h>
#include<stdlib.h>
int f(int n){
    int i,ans[15],cnt=0;
    while(n>0){
        ans[cnt]=n%10;
        cnt++;
        n/=10;
    }
    int ch=1;
    for(i=0;i<cnt/2;i++){
        if(ans[i]!=ans[cnt-i-1])ch=0;
    }
    return ch;
}
int main(){
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=n;i<=1003001;i++){
        int ch=0;
        for(j=2;j*j<=i;j++){
            if(i%j==0){ch=1;break;}
        }
        if(ch==0){
            if(f(i)){printf("%d",i);exit(0);}
        }
    }
}
*/
/*#include<stdio.h>
#define ll long long
#define INF 1000000001
ll a[101][101];
char ans[200];
void f(ll x,ll y,ll k,int turn){
    //printf("\npp%lld %lld\n",x,y);
    if(x==0&&y==0)return;
    if(x==0&&y!=0){
        printf("z");
        f(x,y-1,k-1,turn+1);
    }
    else if(x!=0&&y==0){
        printf("a");
        f(x-1,y,k,turn+1);
    }
    else{
        if(0){
            printf("a");
            f(x-1,y,k,turn+1);
        }
        else{
            if(a[x-1][y]>=k){
                printf("a");
                f(x-1,y,k,turn+1);
            }
            else{
                printf("z");
                f(x,y-1,k-a[x-1][y],turn+1);
            }
        }

    }
}
int main(){
    ll n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    int i,j;
    for(i=0;i<101;i++){
        for(j=0;j<101;j++){
            if(i==0||j==0)a[i][j]=1;
            else a[i][j]=a[i-1][j]+a[i][j-1];
            if(a[i][j]>1000000000)a[i][j]=INF;
        }
    }
    if(a[n][m]<k)printf("-1");
    else f(n,m,k,0);
}
*/

/*#include<stdio.h>
#include<vector>
#define ll long long
using namespace std;
vector<vector<ll>> f(vector<vector<ll>> &a,vector<vector<ll>> &b){
    int n=2;
    int i,j;
    vector<vector<ll>> ans(5,vector<ll> (5));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ll imsi=0;
            for(int k=0;k<n;k++){
                imsi+=(a[i][k]*b[k][j]);
                //printf("%d %d %d %d\n",i,k,k,j);
            }
            //printf("a%lld\n",imsi);
            ans[i][j]=(imsi%1000000007);
        }
    }
    return ans;
}
int main(){
    ll n,bb;
    vector<vector<ll>> base(2,vector<ll> (2));
    vector<vector<ll>> ans(2,vector<ll> (2));
    base={{1,1},{1,0}};
    ans={{1,0},{0,1}};
    scanf("%lld",&n);
    int i,j;
    while(n){
        if(n%2){
            ans=f(ans,base);
        }
        base=f(base,base);
        n/=2;
    }
    printf("%lld",ans[0][1]%1000000007);
}*/

/*#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++){
        int a,b,sum=0;
        scanf("%d %d",&a,&b);
        if(a<1)sum+=0;
        else if(a<2)sum+=500;
        else if(a<4)sum+=300;
        else if(a<7)sum+=200;
        else if(a<11)sum+=50;
        else if(a<16)sum+=30;
        else if(a<22)sum+=10;
        else sum+=0;

        if(b<1)sum+=0;
        else if(b<2)sum+=512;
        else if(b<4)sum+=256;
        else if(b<8)sum+=128;
        else if(b<16)sum+=64;
        else if(b<32)sum+=32;
        else sum+=0;

        printf("%d\n",sum*10000);
    }
}*/

/*#include<stdio.h>
#include<math.h>
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int i,a[500];
    double avg=0,sqavg=0;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        avg+=(double)a[i];
    }
    avg/=(n-k+1);
    double min=0xffffffff;
    for(i=0;i<n-k+1;i++){
        sqavg=0;
        for(int j=0;j<n;j++){
            printf("j%d\n",j);
            if(j==i){
                int sum=0;
                for(int l=j;l<j+k;l++){
                    sum+=a[l];
                }
                sqavg+=(sum*sum);
                j=j+k-1;
                continue;
            }
            sqavg+=(a[j]*a[j]);
        }
        sqavg/=(n-k+1);

        double v=sqavg-(avg*avg);
        printf("v%lf\n",v);
        if(min>v)min=v;
    }
    printf("%.11lf",sqrt(min));
}*/

/*#include<stdio.h>
#include<queue>
#include<vector>
#define uint long long
using namespace std;
int main(){
    uint k,n,a[100];
    scanf("%lld %lld",&k,&n);
    uint i,j;
    for(i=0;i<k;i++)scanf("%lld",&a[i]);
    //priority_queue<uint> ans;
    vector<uint> ans;
    priority_queue<uint,vector<uint>,greater<uint>> q[100];
    for(i=0;i<k;i++){
        q[i].push(a[i]);
    }
    uint index=0;
    ans.push_back(a[0]);
    index++;
    for(i=0;;i++){
        for(auto &l:ans){
            printf("%u ",l);
        }
        //printf("\n");
        if(ans.size()==n)break;
        uint min=2147483649,where=0;
        for(j=0;j<index;j++){
            if(min>(a[j]*q[j].top())){
                min=a[j]*q[j].top();
                where=j;
            }
        }
        if(min>a[index]&&index<k){
            min=a[index];
            where=index;
            index++;
        }
        for(j=0;j<=where;j++){
            q[j].push(min);
        }
        q[where].pop();
        //printf("m%u\n",min);
        ans.push_back(min);
    }
    printf("%lld",ans[n-1]);
}*/
/*#include<stdio.h>
#define ll long long
#define mod 1000000007
ll a[3000001];
ll f(ll n,ll r){
    if(r==0)return 1;
    int i;
    ll A=a[n],B=(a[r]*a[n-r])%mod;
    ll ex=mod-2;
    ll re=1;
    while(ex){
        if(ex%2){
            re*=B;
            re%=mod;
        }
        B*=B;
        B%=mod;
        ex/=2;
    }
    //printf("%lld",(re*A)%mod);
    return (re*A)%mod;
}
ll h(ll n,ll r){
    return f(n+r-1,r);
}
int main(){
    ll n,m,M,k;
    scanf("%lld %lld %lld %lld",&n,&m,&M,&k);
    ll i;
    ll b=1;
    for(i=1;i<=3000000;i++){
        b*=i;
        b%=mod;
        a[i]=b;
    }
    ll all=h(n,k-n*m);
    //printf("b%lld\n",all);
    ll sub=0;
    ll A=M-m+1;
    for(i=0;i<=n;i++){
        //printf("a%d %d\n",n,k-n*m-i*A);
        if(k-n*m-i*A<0)break;
        if(i%2==1)sub-=f(n,i)*h(n,k-n*m-i*A);
        else if(i%2==0||i==0)sub+=f(n,i)*h(n,k-n*m-i*A);
        sub%=mod;
        while(sub<0)sub+=mod;
        //printf("x%lld\n",sub);
    }
    for(i=M-m+1;i<=k-n*m;i++){
        sub+=f(n+k-n*m-i-2,k-n*m-i);
        printf("%lld\n",sub);
        sub=sub%mod;
    }
    sub*=n;
    sub%=mod;
    printf("%lld",sub%mod);
}

*/

/*#include<stdio.h>
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
*/
/*#include<stdio.h>
#include<stdlib.h>
#define ll long long
ll a[10000],b[10000];
ll f(int n){
    return (a[0]*b[n]+a[n]*b[n+1]+a[n+1]*b[0]-a[n]*b[0]-a[n+1]*b[n]-a[0]*b[n+1]);
}
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        scanf("%lld %lld",&a[i],&b[i]);
    }
    ll sum=0;
    for(i=1;i<n-1;i++){
        sum+=f(i);
    }
    sum=abs(sum);
    printf("%.1lf",(double)sum/2);
}*/

/*#include<stdio.h>
#include<math.h>
#include<queue>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,i,x[3000],y[3000],r[3000],v[3000]={0,0,},cnt=0;
        queue<int> q;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d %d %d",&x[i],&y[i],&r[i]);
        }
        for(i=0;i<n;i++){
            if(v[i]==0){
                q.push(i);
                while(!q.empty()){
                    int now=q.front();
                    //printf("now%d - %d\n",i,now);
                    v[now]=1;
                    q.pop();
                    for(int j=0;j<n;j++){
                        //printf("l%d-%d-%d\n",((x[now]-x[j])*(x[now]-x[j])+(y[now]-y[j])*(y[now]-y[j])),(r[now]+r[j])*(r[now]+r[j]));
                        if(v[j]==0&&((x[now]-x[j])*(x[now]-x[j])+(y[now]-y[j])*(y[now]-y[j]))<=(r[now]+r[j])*(r[now]+r[j])){
                            q.push(j);
                            //printf("j%d\n",j);
                        }
                    }
                }
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
}
*/
/*#include<stdio.h>
#define ll long long
int main(){
    ll n,i,aa[50];
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&aa[i]);
    }
    ll max=-1;
    for(i=0;i<n;i++){
        ll cnt=0;
        for(ll j=0;j<n;j++){
            ll x1=i,y1=aa[i],x2=j,y2=aa[j];
            if(j==i)continue;
            ll a=y1-y2;
            ll b=-x1+x2;
            ll c=y1*(x1-x2)-x1*(y1-y2);
            if(b<0){
                a=-a;
                b=-b;
                c=-c;
            }
            ll ch=1;
            //printf("a%d %d %d\n",a,b,c);
            for(ll k=j+1;k<i;k++){
                //printf("1-%d\n",j);
                if(a*k+b*aa[k]+c>=0){ch=0;break;}
            }
            for(ll k=i+1;k<j;k++){
                //printf("2-%d\n",j);
                if(a*k+b*aa[k]+c>=0){ch=0;break;}
            }
            cnt+=ch;
        }
        //printf("cnt-%d\n",cnt);
        if(max<cnt)max=cnt;
    }
    printf("%lld",max);
}*/

/*main(a,b,c,d,e,f){
  scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
  a=(c-a)*(f-b)-(d-b)*(e-a);
  if(a>0)a=1;
  else if(a<0)a=-1;
  else a=0;
  printf("%d",a);
}*/

/*#include<stdio.h>
#include<utility>
#include<stack>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
vector<pair<int,int>> co(200000);
int ccw(int p,int q,int r){
    ll a=(co[q].first-co[p].first)*(co[r].second-co[p].second)-(co[q].second-co[p].second)*(co[r].first-co[p].first);
    if(a>0)a=0;
    else if(a<0)a=1;
    else if(a==0)a=2;
    return a;
}
bool comp1(const pair<int,int> &a,const pair<int,int> &b){
    if(a.second==b.second)return a.first<b.first;
    return a.second<b.second;
}
bool comp2(const pair<int,int> &a,const pair<int,int> &b){
    double reta=0;
    if(a.second==co[0].second){
        if(a.first>co[0].first)reta=0xffffffff;
        else reta=-0xffffffff;
    }
    else reta=(double)(a.first-co[0].first)/(a.second-co[0].second);
    double retb=0;
    if(b.second==co[0].second){
        if(b.first>co[0].first)retb=0xffffffff;
        else retb=-0xffffffff;
    }
    else retb=(double)(b.first-co[0].first)/(b.second-co[0].second);
    //printf("(%d,%d)(%d,%d) - %lf %lf\n",a.first,a.second,b.first,b.second,reta,retb);
    return reta<retb;

}
using namespace std;
int main(){
    int n,i;
    stack<int> cv;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&co[i].first,&co[i].second);
    }

    sort(co.begin(),co.begin()+n,comp1);
    sort(co.begin()+1,co.begin()+n,comp2);
    for(int j=0;j<n;j++){
        printf("0- %d %d\n",co[j].first,co[j].second);
    }
    int st=0;
    cv.push(0);
    cv.push(1);
    for(i=2;i<n;i++){
        while(cv.size()>1){
            int second=cv.top();
            cv.pop();
            int first=cv.top();
        printf("s%d %d\n",first,second);
            if(ccw(first,second,i)==1){
                cv.push(second);
                break;
            }
        }
        cv.push(i);

        //printf("i%d\n",i);
        int second=cv.top();
        cv.pop();
        int first=cv.top();
        cv.pop();
        //printf("ccw(%d,%d,%d) - %d\n",first,second,i,ccw(first,second,i));
        if(ccw(first,second,i)==1){
            cv.push(first);
            cv.push(second);
            cv.push(i);
        }
        else{
            if(ccw(first,second,i)==2){
                cv.push(first);
                cv.push(i);
            }
            else{
            while(ccw(first,second,i)==0){
                second=first;
                first=cv.top();
                cv.pop();
            }
            if(ccw(first,second,i)==1){
                cv.push(first);
                cv.push(second);
                cv.push(i);
            }
            else if(ccw(first,second,i)==2){
                cv.push(first);
                cv.push(i);
            }
            }
        }
    }
    int second=cv.top();
    cv.pop();
    int first=cv.top();
    cv.pop();
    if(ccw(first,second,0)==1){
            cv.push(first);
            cv.push(second);
        }
        else{
            if(ccw(first,second,0)==2){
                cv.push(first);
            }
            else{
            while(ccw(first,second,0)==0){
                second=first;
                first=cv.top();
                cv.pop();
            }
            if(ccw(first,second,0)==1){
                cv.push(first);
                cv.push(second);
            }
            else if(ccw(first,second,0)==2){
                cv.push(first);
            }
            }
        }
    printf("%d",cv.size());
    while(!cv.empty()){
        printf("%d\n",cv.top());
        cv.pop();
    }
    }
    printf("%d",cv.size());
}
*/

/*#include<stdio.h>
#include<math.h>
#include<vector>
#define quotient(a,b) (abs((a)/(float) (b)) < 0.0005 ? 0.000 : (a)/(float) (b))
using namespace std;
int det(vector<vector<int>> &a){
    for(auto &i:a){
        for(auto &j:i)printf("%d ",j);
        printf("\n");
    }
    return a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])-a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])+a[0][2]*(a[1][1]*a[2][1]-a[1][1]*a[2][0]);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        vector<vector<int>> A(3,vector<int> (3));
        vector<int> B(3);
        int i,j;
        for(i=0;i<3;i++){
            //printf("i%d - ",i);
            scanf("%d %d %d %d",&A[i][0],&A[i][1],&A[i][2],&B[i]);
        }
        vector<vector<int>> Ai(3,vector<int> (3));
        int deter[4]={0,};
        for(i=0;i<3;i++){
            Ai=A;
            Ai[0][i]=B[0];
            Ai[1][i]=B[1];
            Ai[2][i]=B[2];
            deter[i]=det(Ai);
            printf("%d ",deter[i]);
        }
        deter[3]=det(A);
        printf("%d\n",deter[3]);
        if(deter[3]==0)printf("No unique solution\n\n");
        else{
            printf("Unique solution: %.3f %.3f %.3f\n\n",quotient(deter[0],deter[3]),quotient(deter[1],deter[3]),quotient(deter[2],deter[3]));
        }
    }
}
*/

/*#include<iostream>
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
}*/

/**#include<stdio.h>
#include<math.h>
#define ll long long
int main(){
    ll a[10][10]={0,},power=1;
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(i==0)a[i][j]++;
            else{
                a[i][j]+=a[i-1][j]*10;
                if(j==0){
                    for(int k=1;k<i;k++){
                        a[i][j]+=k*9*(ll)pow(10.0,(double)(i-k-1));
                    }
                    a[i][j]+=(i-1);
                }
                else a[i][j]+=power;
            }
        }
//        for(j)
        power*=10;
    }
    for(i=0;i<10;i++){
        for(j=0;j<10;j++)printf("%lld ",a[i][j]);
        printf("\n");
    }
    ll digit[10]={0,},ans[10]={0,};
    int d=0,imsin=n;
    while(imsin>0){
        digit[d]=imsin%10;
        imsin/=10;
        d++;
    }

    for(i=d-1;i>0;i--){
        for(j=0;j<10;j++)printf("a%lld ",ans[j]);
        ll ex=pow(10.0,(double)(i));
        printf("\nex%lld %d\n",ex,n);
        for(j=0;j<10;j++){
            ans[j]+=a[i-1][j]*digit[i];
        }
        for(j=1;j<digit[i];j++){
            ans[j]+=ex;
        }
        //if(digit[i]!=0){
            int mul;
            if(i==d-1)mul=digit[i]-1;
            else mul=digit[i];
            for(j=1;j<i;j++){
                ans[0]+=mul*j*9*(ll)pow(10.0,(double)(i-j-1));
            }
            ans[0]+=mul*(i-1);
        //}
        if(i!=d-1){
            ans[0]+=ex;
        }
        ans[digit[i]]+=(n-ex*digit[i]+1);
        n-=ex*digit[i];
    }
    for(i=0;i<=n;i++)ans[i]++;
    ans[0]--;
    for(i=0;i<10;i++)printf("%lld ",ans[i]);
}
**/

/*#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,a[50],aa,bb;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    if(n==1)printf("A");
    else if(n==2){
        if(a[0]==a[1])printf("%d",a[0]);
        else printf("A");
    }
    else{
        if(a[0]==a[1]){
            for(i=2;i<n;i++){
                if(a[i-1]!=a[i]){printf("B");exit(0);}
            }
            printf("%d",a[0]);
        }
        else{
            aa=(a[2]-a[1])/(a[1]-a[0]);
            bb=a[1]-aa*a[0];
            for(i=2;i<n;i++){
                if(a[i]!=aa*a[i-1]+bb){printf("B");exit(0);}
            }
            printf("%d",a[n-1]*aa+bb);
        }
    }
}*/

/*#include<stdio.h>
#define ll long long
int main(){
    int t;
    ll mod=1000000007;
    scanf("%d",&t);
    int i;
    ll a[10001];
    a[0]=1;
    for(i=1;i<=10000;i++){
        a[i]=i*a[i-1];
        a[i]%=mod;
    }
    while(t--){
        int n;
        scanf("%d",&n);
        if(n%2){
            printf("0\n");
            continue;
        }
        ll ex=mod-2;
        ll re=1;
        ll B=(a[n/2]*a[n/2+1])%mod;
        while(ex){
            if(ex%2){
                re*=B;
                re%=mod;
            }
            B*=B;
            B%=mod;
            ex/=2;
        }
        printf("%lld\n",(re*a[n])%mod);
    }

}
*/

/*#include<stdio.h>
#define min(x,y) ((x<y)?x:y)
int n,w[16][16],vis[16][0xffff];
int dp(int now,int visited){
    if(vis[now][visited])return vis[now][visited];
    if(visited==(1<<n)-1){
        if(w[now][0]==0)return 0xfffffff;
        return w[now][0];
    }
//printf("a%d %d %d\n",now,visited,vis[now][visited]);
    int i;
    vis[now][visited]=0xfffffff;
    for(i=0;i<n;i++){
        //printf("x%d %d %d %d %d\n",w[now][i]!=0,visited,1<<i,visited&(1<<i),w[now][i]!=0&&visited&(1<<i)==0);
        if(w[now][i]!=0&&(visited&(1<<i))==0){
            //int a=dp(i,visited|(1<<i))+w[now][i];
            //printf("x%d %d\n",vis[now][visited],a);
            vis[now][visited]=min(vis[now][visited],dp(i,visited|(1<<i))+w[now][i]);

        }
    }
    return vis[now][visited];
}
int main(){
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&w[i][j]);
    int ans=dp(0,1);
    printf("%d",ans);
}*/

/*#include<stdio.h>
#include<iostream>
#include<string>
#define ll long long
using namespace std;
string f(ll n){
    string a;
    while(n>0){
        if(n%2)a.insert(0,"1");
        else a.insert(0,"0");
        n/=2;
    }
    return a;
}
ll g(string a){
    ll n=0,bit=1;
    for(int i=a.size()-1;i>=0;i--){
        n+=(a[i]-'0')*bit;
        bit*=2;
    }
    return n;
}
int main(){
    ll a,b,i;
    scanf("%lld %lld",&a,&b);
    ll cnt[60]={1<<0,};
    for(i=1;i<=56;i++){
        cnt[i]=cnt[i-1]+((ll)1<<i)+((ll)1<<(i-1))*i;
    }
    for(i=0;i<=56;i++){
        printf("%lld\n",cnt[i]);
    }
    string ac=f(a-1);
    string bc=f(b);
    //cout<<ac<<"\n"<<bc<<"\n";
    ll ca=0,cb=0;
    while(!ac.empty()){
        if(ac[0]=='0'){
            ac.erase(ac.begin());
            continue;
        }
        if(ac.size()==1){
            if(ac[0]=='1')ca++;
            break;
        }
        //printf("a%lld %lld\n",ac.size(),cnt[ac.size()-2]);
        ca+=cnt[ac.size()-2];
        ac.erase(ac.begin());
        ca+=(g(ac)+1);
    }
    while(!bc.empty()){
        if(bc[0]=='0'){
            bc.erase(bc.begin());
            continue;
        }
        if(bc.size()==1){
            if(bc[0]=='1')cb++;
            break;
        }
        //printf("b%lld %lld\n",bc.size(),cnt[bc.size()-2]);
        cb+=cnt[bc.size()-2];
        bc.erase(bc.begin());
        cb+=(g(bc)+1);
        //printf("bb%lld\n",cb);
    }
    printf("%lld",cb-ca);
}

*/

/*#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> f(int n){
    if(n==1){
        vector<string> p;
        p.push_back("*");
        return p;
    }
    int i,j,k,l;
    vector<string> a=f(n/3),b(n);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i==1&&j==1){
                string imsi;
                for(k=0;k<n/3;k++)imsi+=" ";
                for(k=n/3*i,l=0;k<n/3*(i+1);k++,l++){
                    b[k]+=imsi;
                }
            }
            else{
                for(k=n/3*i,l=0;k<n/3*(i+1);k++,l++){
                    b[k]+=a[l];
                }
            }
        }
    }
    return b;
}
int main(){
    int n;
    scanf("%d",&n);
    vector<string> a=f(n);
    for(int i=0;i<a.size();i++)cout<<a[i]<<"\n";
}
*/

/*#include<stdio.h>
int n,a[11],max=-0xfffffff,min=0xfffffff;
int cal(int fir,int sec,int oper){
    switch(oper){
    case 0:
        return fir+sec;
    case 1:
        return fir-sec;
    case 2:
        return fir*sec;
    case 3:
        if(fir<0)return -((-fir)/sec);
        else return fir/sec;
    default:
        return 1;
    }
}
void f(int op[],int b[],int cnt){
    //printf("cnt%d\na",cnt);
    int i,ch=1;
    //for(i=0;i<cnt;i++)printf("%d ",op[i]);
    //printf("\n");
    //for(i=0;i<4;i++)printf("%d ",b[i]);
    //printf("\n");

    for(i=0;i<4;i++){
        if(b[i])ch=0;
    }
    if(ch){
        int ans=a[0];
        for(i=1;i<n;i++){
            ans=cal(ans,a[i],op[i-1]);
        }
        //printf("ans%d\n",ans);
        if(max<ans)max=ans;
        if(min>ans)min=ans;
        return;
    }
    for(i=0;i<4;i++){
        if(b[i]){
            //printf("ii%d %d\n",cnt,i);
            b[i]--;
            op[cnt]=i;
            f(op,b,cnt+1);
            b[i]++;
        }
    }
}
int main(){
    int b[4],i,op[10];
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    scanf("%d %d %d %d",&b[0],&b[1],&b[2],&b[3]);
    f(op,b,0);
    printf("%d\n%d",max,min);
}
*/

/*#include<stdio.h>
int abs(int a){
    return a>0?a:-a;
}
int n,a[20][20],min=0xfffffff;
void f(int now,int pers[],int cnt){
    int i,j,who1[n/2],who2[n/2],cnt1=0,cnt2=0;
    if(cnt==n/2-1){
        int ans1=0,ans2=0;
        for(i=0;i<n;i++){
            if(pers[i]==1){
                who1[cnt1++]=i;
            }
            if(pers[i]==0){
                who2[cnt2++]=i;
            }
        }
        for(i=0;i<n/2;i++){
            for(j=0;j<n/2;j++){
                ans1+=a[who1[i]][who1[j]];
            }
        }
        for(i=0;i<n/2;i++){
            for(j=0;j<n/2;j++){
                ans2+=a[who2[i]][who2[j]];
            }
        }
        if(min>abs(ans1-ans2))min=abs(ans1-ans2);
        return;
    }
    for(i=now;i<n;i++){
        if(pers[i]==0){
            pers[i]=1;
            f(i,pers,cnt+1);
            pers[i]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    int i,j,pers[n]={0,};
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)scanf("%d",&a[i][j]);
    }
    pers[0]=1;
    f(0,pers,0);
    printf("%d",min);
}*/

/*#include<stdio.h>
#include<math.h>
#define mod 1000000000
#define ll long long
int main(){
    ll n,i;
    scanf("%lld",&n);
    ll a[10]={1,1,1,1,1,1,1,1,1,1};
    for(i=1;i<n;i++){
        ll j,imsi[10];
        for(j=0;j<10;j++)imsi[j]=a[j];
        a[0]=imsi[1]%mod;
        for(j=1;j<9;j++){
            a[j]=(imsi[j-1]%mod+imsi[j+1]%mod)%mod;
        }
        a[9]=imsi[8]%mod;
    }
    ll ans=0;
    for(i=1;i<10;i++){ans+=(a[i]%mod);ans%=mod;}
    printf("%lld",(ans+mod)%mod);
}*/

/*#include<stdio.h>
#define ll long long
int main(){
    int n,r;
    ll mod=1000000007;
    scanf("%d %d",&n,&r);
    int i;
    ll A=1,B=1;
    for(i=1;i<=n;i++){
        A*=i;
        A%=mod;
    }
    for(i=1;i<=r;i++){
        B*=i;
        B%=mod;
    }
    for(i=1;i<=n-r;i++){
        B*=i;
        B%=mod;
    }
    ll ex=mod-2;
    ll re=1;
    while(ex){
        if(ex%2){
            re*=B;
            re%=mod;
        }
        B*=B;
        B%=mod;
        ex/=2;
    }
    printf("%lld",(re*A)%mod);
}
*/
/*#include<iostream>
using namespace std;
int main(){
    string a;
    long long res=0;
        cin>>a;
        if(a=="black")res+=0;
        if(a=="brown")res+=10;
        if(a=="red")res+=20;
        if(a=="orange")res+=30;
        if(a=="yellow")res+=40;
        if(a=="green")res+=50;
        if(a=="blue")res+=60;
        if(a=="violet")res+=70;
        if(a=="grey")res+=80;
        if(a=="white")res+=90;
        cin>>a;
        if(a=="black")res+=0;
        if(a=="brown")res+=1;
        if(a=="red")res+=2;
        if(a=="orange")res+=3;
        if(a=="yellow")res+=4;
        if(a=="green")res+=5;
        if(a=="blue")res+=6;
        if(a=="violet")res+=7;
        if(a=="grey")res+=8;
        if(a=="white")res+=9;
    cin>>a;
    if(a=="black")res*=1;
        if(a=="brown")res*=10;
        if(a=="red")res*=100;
        if(a=="orange")res*=1000;
        if(a=="yellow")res*=10000;
        if(a=="green")res*=100000;
        if(a=="blue")res*=1000000;
        if(a=="violet")res*=10000000;
        if(a=="grey")res*=100000000;
        if(a=="white")res*=1000000000;

        printf("%lld",res);
}
*/

/*#include<stdio.h>
#include<vector>
#define ll long long
using namespace std;
vector<vector<ll>> f(vector<vector<ll>> &a,vector<vector<ll>> &b,ll n){
    int i,j;
    vector<vector<ll>> ans(5,vector<ll> (5));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ll imsi=0;
            for(int k=0;k<n;k++){
                imsi+=(a[i][k]*b[k][j]);
            }
            ans[i][j]=(imsi%1000000000);
        }
    }
    return ans;
}
int main(){
    ll n=2,bb,aa;
    vector<vector<ll>> base(5,vector<ll> (5));
    vector<vector<ll>> ans(5,vector<ll> (5));
    ans={{1,0},{0,1}};
    scanf("%lld %lld",&aa,&bb);
    int i,j;
    base={{1,1},{1,0}};
    while(bb){
        if(bb%2){
            ans=f(ans,base,n);
        }
        base=f(base,base,n);
        bb/=2;
    }
    ll ans1=(ans[0][0]+ans[0][1])%1000000000;
    ans={{1,0},{0,1}};
    base={{1,1},{1,0}};
    aa--;
    while(aa){
        if(aa%2){
            ans=f(ans,base,n);
        }
        base=f(base,base,n);
        aa/=2;
    }
    ll ans2=(ans[0][0]+ans[0][1])%1000000000;
    printf("%lld",(ans1-ans2+1000000000)%1000000000);
}
*/
/*#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#define ll long long
using namespace std;
vector<vector<ll>> f(vector<vector<ll>> &a,vector<vector<ll>> &b,ll mod){
    int i,j,n=2;
    vector<vector<ll>> ans(2,vector<ll> (2));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ll imsi=0;
            for(int k=0;k<n;k++){
                imsi+=(a[i][k]*b[k][j]);
            }
            ans[i][j]=(imsi%mod);
        }
    }
    return ans;
}
ll fi(ll n,ll mod){
    vector<vector<ll>> base(2,vector<ll> (2));
    vector<vector<ll>> ans(2,vector<ll> (2));
    ans={{1,0},{0,1}};
    int i,j;
    base={{1,1},{1,0}};
    ll ex=n-2;
    while(ex){
        if(ex%2){
            ans=f(ans,base,mod);
        }
        base=f(base,base,mod);
        ex/=2;
    }
    return (ans[0][0]+ans[0][1])%mod;
}
ll b16(string a){
    ll base=1,ans=0;
    while(a.back()!='x'){
        int cnt;
        if(a.back()>='0'&&a.back()<='9')cnt=a.back()-'0';
        else if(a.back()>='a'&&a.back()<='f')cnt=a.back()-'a'+10;
        ans+=cnt*base;
        base*=16;
        a.erase(a.end()-1);
    }
    return ans;
}
int main(){
    char aa[64],bb[64];
    ll mod=9223372036854775807;
    //printf("%lld\n",fi(,mod));
    while(scanf("%s %s",aa,bb)!=EOF){
        string a,b;
        a=aa;
        b=bb;
        ll anum=b16(a),bnum=b16(b);
        if(anum==0&&bnum==0)break;
        if(anum>=bnum)break;
        printf("Range %lld to %lld:\n",anum,bnum);
        int i;
        for(i=0;;i++){
            ll fibo=fi(i,mod);
            if(i==0)fibo=0;
            if(i==1)fibo=1;
            if(fibo>=anum&&fibo<=bnum){
                printf("Fib(%d) = %lld, ",i,fibo);
                if(i==0)printf("lg does not exist\n");
                else{
                    printf("lg is %lf\n",log2(fibo));
                }
            }
            if(fibo>bnum)break;
        }
    }

}*/

/*#include<stdio.h>
#include<queue>
#include<utility>
#define abs(a) a>0?a:-a
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    while(n--){
        int a;
        scanf("%d",&a);
        if(a==0){
            if(q.empty())printf("a0\n");
            else{
                printf("a%d\n",q.top().second);
                q.pop();
            }
        }
        else q.push({abs(a),a});
    }
}*/

/*#include<stdio.h>
#include<queue>
#include<string.h>
#include<utility>
#define INF 0xfffffff
using namespace std;
vector<vector<pair<int,int>>> map(20001);
int dis[20001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> dist;
int main(){
    int v,e,i,j;
    scanf("%d %d",&v,&e);
    for(i=1;i<=v;i++)dis[i]=INF;
    int k;
    scanf("%d",&k);
    for(i=0;i<e;i++){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        map[a].push_back({b,w});
    }
    dist.push({0,k});
    dis[k]=0;
    while(!dist.empty()){
        int now=dist.top().second;
        int until=dist.top().first;
        dist.pop();
        if(until>dis[now])continue;
        for(auto &i:map[now]){
            if(until+i.second<dis[i.first]){
                dis[i.first]=until+i.second;
                dist.push({until+i.second,i.first});
            }
        }
    }
    for(i=1;i<=v;i++){
        if(dis[i]<INF)printf("%d\n",dis[i]);
        else printf("INF\n");
    }
}*/

/*#include<stdio.h>
#include<queue>
#include<string.h>
#include<utility>
#define INF 0xfffffff
using namespace std;
vector<vector<pair<int,int>>> map(20001);
int dis[20001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> dist;
int main(){
    int v,e,i,j;
    scanf("%d %d",&v,&e);
    for(i=1;i<=v;i++)dis[i]=INF;
    int k,x;

    for(i=0;i<e;i++){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        map[a].push_back({b,w});
    }
    scanf("%d %d",&k,&x);
    dist.push({0,k});
    dis[k]=0;
    while(!dist.empty()){
        int now=dist.top().second;
        int until=dist.top().first;
        dist.pop();
        if(until>dis[now])continue;
        for(auto &i:map[now]){
            if(until+i.second<dis[i.first]){
                dis[i.first]=until+i.second;
                dist.push({until+i.second,i.first});
            }
        }
    }
    printf("%d",dis[x]);
}*/

/*#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
#include<utility>
#define INF 0xfffffff

using namespace std;
vector<vector<pair<int,int>>> map(20001);
int main(){
    int v,e,i,j,x;
    scanf("%d %d %d",&v,&e,&x);

    int k;
    int tot[20001]={0,};
    for(i=0;i<e;i++){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        map[a].push_back({b,w});
    }
    for(j=1;j<=v;j++){
        if(j==x){
            tot[j]+=0;
            continue;
        }

        int dis[20001];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> dist;
        for(i=1;i<=v;i++)dis[i]=INF;
        dist.push({0,j});
        dis[j]=0;
        while(!dist.empty()){
            int now=dist.top().second;
            int until=dist.top().first;
            dist.pop();
            if(until>dis[now])continue;
            for(auto &i:map[now]){
                if(until+i.second<dis[i.first]){
                    dis[i.first]=until+i.second;
                    dist.push({until+i.second,i.first});
                }
            }
        }
        tot[j]+=dis[x];
    }
    int dis[20001];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> dist;
    for(i=1;i<=v;i++)dis[i]=INF;
    dist.push({0,x});
    dis[x]=0;
    while(!dist.empty()){
        int now=dist.top().second;
        int until=dist.top().first;
        dist.pop();
        if(until>dis[now])continue;
        for(auto &i:map[now]){
            if(until+i.second<dis[i.first]){
                dis[i.first]=until+i.second;
                dist.push({until+i.second,i.first});
            }
        }
    }
    int max=-1;
    for(i=1;i<=v;i++){
        if(max<tot[i]+dis[i])max=tot[i]+dis[i];
    }
    printf("%d",max);
}

*/

/*#include<iostream>
#include<string>
#define max(a,b) a>b?a:b
using namespace std;
int ch[1001][1001]={0,};
int loc[1001];
int main(){
    string a,b,c;
    cin>>a>>b;
    int i,j,m=0;
    for(i=1;i<=a.size();i++){
        for(j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]){
                ch[i][j]=ch[i-1][j-1]+1;
            }
            else ch[i][j]=max(ch[i-1][j],ch[i][j-1]);
        }
    }
    printf("%d\n",ch[a.size()][b.size()]);
    //for(i=1;i<=b.size();i++)printf("%c ",b[i-1]);
    //printf("\n");
    //for(i=1;i<=a.size();i++,printf(" %c\n",a[i-2]))for(j=1;j<=b.size();j++)printf("%d ",ch[i][j]);
    i=a.size();
    j=b.size();
    while(i>0&&j>0){
        if(ch[i-1][j]>ch[i][j-1]){
            i--;
        }
        else if(ch[i-1][j]<ch[i][j-1]){
            j--;
        }
        else{
            if(ch[i][j]==ch[i-1][j])i--;
            else{
                c+=a[i-1];
                i--;
                j--;
            }
        }
    }
    for(i=c.size()-1;i>=0;i--){
        printf("%c",c[i]);
    }
}*/

/*#include<iostream>
#include<string>
#define max(a,b) a>b?a:b
using namespace std;
int ch[101][101][101]={0,};
int loc[1001];
int main(){
    string a,b,c;
    cin>>a>>b>>c;
    int i,j,m=0,k;
    for(i=1;i<=a.size();i++){
        for(j=1;j<=b.size();j++){
            for(k=1;k<=c.size();k++){
                if(a[i-1]==b[j-1]&&b[j-1]==c[k-1]){
                    ch[i][j][k]=ch[i-1][j-1][k-1]+1;
                }
                else ch[i][j][k]=max(max(ch[i-1][j][k],ch[i][j-1][k]),ch[i][j][k-1]);
            }
        }
    }
    printf("%d\n",ch[a.size()][b.size()][c.size()]);
    //for(i=1;i<=b.size();i++)printf("%c ",b[i-1]);
    //printf("\n");
    //for(i=1;i<=a.size();i++,printf(" %c\n",a[i-2]))for(j=1;j<=b.size();j++)printf("%d ",ch[i][j]);
    i=a.size();
    j=b.size();
    while(i>0&&j>0){
        if(ch[i-1][j]>ch[i][j-1]){
            i--;
        }
        else if(ch[i-1][j]<ch[i][j-1]){
            j--;
        }
        else{
            if(ch[i][j]==ch[i-1][j])i--;
            else{
                c+=a[i-1];
                i--;
                j--;
            }
        }
    }
    for(i=c.size()-1;i>=0;i--){
        printf("%c",c[i]);
    }
}*/

/*#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
bool comp(const pair<int,int> &a,const pair<int,int> &b){
    return a.first<b.first;
}
int main(){
    vector<pair<int,int>> a,b;
    vector<int> aloc;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int p;
        scanf("%d",&p);
        a.push_back({p,i});
    }
    sort(a.begin(),a.end());
    for(i=0;i<n;i++)aloc.push_back(a[i].first);
    for(i=0;i<n;i++){
        int p;
        scanf("%d",&p);
        int loc=lower_bound(aloc.begin(),aloc.end(),p)-aloc.begin();
        b.push_back({a[loc].second,p});
    }
    int ch[100001],cnt=0;
    vector<pair<int,int>> lcs;
    lcs.push_back(b[0]);
    for(i=1;i<n;i++){
        if(b[i].first>lcs.back().first)lcs.push_back(b[i]);
        else{
            int loc=lower_bound(lcs.begin(),lcs.end(),b[i],comp)-lcs.begin();
            lcs[loc]=b[i];
        }
    }
    printf("%d",lcs.size());
}
*/
/*#include<iostream>
#include<string.h>
#define ull unsigned long long
#define max(a,b) a>b?a:b
struct hang{
    char a;
    char b;
    char c;
};
bool operator==(struct hang &a, struct hang &b){
    return (a.a==b.a&&a.b==b.b&&a.c==b.c);
}
using namespace std;
int ch[3001][3001]={0,};
int main(){
    int i,j;
    char a[3000],b[3000];
    struct hang ha[1000],hb[1000];
    scanf("%s\n%s",a,b);
    for(i=0;i<strlen(a);i+=3){
        ha[i/3].a=a[i];
        ha[i/3].b=a[i+1];
        ha[i/3].c=a[i+2];
    }
    for(i=0;i<strlen(b);i+=3){
        hb[i/3].a=b[i];
        hb[i/3].b=b[i+1];
        hb[i/3].c=b[i+2];
    }
    for(i=1;i<=strlen(a)/3;i++){
        for(j=1;j<=strlen(b)/3;j++){
            if(ha[i-1]==hb[j-1])ch[i][j]=ch[i-1][j-1]+1;
            else ch[i][j]=max(ch[i-1][j],ch[i][j-1]);
        }
    }//for(i=1;i<=a.size();i++,printf(" %c\n",a[i-2]))for(j=1;j<=b.size();j++)printf("%d ",ch[i][j]);
    printf("%d",ch[strlen(a)/3][strlen(b)/3]);
}*/

/*#include<iostream>
#include<string>
#define max(a,b) a>b?a:b
using namespace std;
int ch[3][50001];
int main(){
    string a,b;
    int m;
    scanf("%d",&m);
    cin>>a>>b;

    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1])ch[i][j]=ch[i-1][j-1]+1;
            else ch[i][j]=max(ch[i-1][j],ch[i][j-1]);
        }
    }
    printf("%d",ch[a.size()][b.size()]);
}
*/

/*#include<stdio.h>
#include<algorithm>
int a[500][500],b[500][500];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++)scanf("%d",&a[i][j]);
    }
    //b[0][0]=a[0][0];
    for(i=0;i<n-1;i++){
        for(j=0;j<=i;j++){
            if(b[i+1][j]<a[i][j]+b[i][j])b[i+1][j]=a[i][j]+b[i][j];
            if(b[i+1][j+1]<a[i][j]+b[i][j])b[i+1][j+1]=a[i][j]+b[i][j];
        }
    }
    for(i=0;i<n;i++)b[n-1][i]+=a[n-1][i];
    int m=*std::max_element(b[n-1],b[n-1]+n);
    printf("%d",m);
}*/
/*#include<stdio.h>
#define max(a,b) a>b?a:b
int n,a[301],mx=-1,mem[301][3];
int f(int now,int mod){
    if(mem[now][mod])return mem[now][mod];
    if(now>n){
        return -0xffffff;
    }
    if(mod>2){
        if(now==n)return -0xffffff;
        else return 0;
    }
    if(now==n)return a[n];
    return mem[now][mod]=max(f(now+1,mod+1)+a[now],f(now+2,1)+a[now]);
}
int main(){
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    printf("%d",f(0,0));
    for(i=0;i<3;i++){
        for(int j=0;j<=n;j++)printf("%d ",mem[j][i]);
        printf("\n");
    }

}*/
/*#include<stdio.h>
#include<algorithm>
int ch[1000001];
int f(int n,int cnt){
    if(n==1)return ch[n]=0;
    if(ch[n])return ch[n];
    int a=10000001,b=10000001,c=10000001;
    if(n%3==0){
        a=f(n/3,cnt+1);
    }
    if(n%2==0)b=f(n/2,cnt+1);
    c=f(n-1,cnt+1);
    int as=(std::min(std::min(a,b),c));
    return ch[n]=as+1;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",f(n,0));
}*/

/*#include<stdio.h>
#include<algorithm>
#define max(a,b) a>b?a:b
int n,a[10001],mx=-1,mem[10001][3];
int f(int now,int mod){
    if(mem[now][mod]>-1)return mem[now][mod];
    if(now>n){
        return 0;
    }
    if(mod>2){
        return 0;
    }
    if(now==n)return a[n];
    int maxval=f(now+1,mod+1)+a[now];
    for(int i=now+2;i<=n;i++){
        maxval=max(maxval,f(i,1)+a[now]);
    }
    return mem[now][mod]=maxval;
}
int main(){
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=0;i<=n;i++){
        for(int j=0;j<3;j++)mem[i][j]=-1;
    }
    printf("%d\n",f(0,0));
}*/

/*#include<stdio.h>
#define max(a,b) a>b?a:b
int main(){
    int n,a=0,b=0,c=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        int ta=a,tb=b,tc=c;
        a=max(max(ta,tb),tc);
        b=ta+x;
        c=tb+x;
        printf("%d %d %d\n",a,b,c);

    }
    printf("%d",max(max(a,b),c));
}*/

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    scanf("%d",&k);
    while(k--){
        int v,e;
        scanf("%d %d",&v,&e);
        vector<vector<int>> map(v+1);
        int i;
        for(i=0;i<e;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            map[a].push_back(b);
            map[b].push_back(a);
        }
        vector<int> visit(v+1,0);

        int ch=1;
        for(i=1;i<=v;i++){
            if(visit[i]==0){
                visit[i]=1;
                int j;
                queue<pair<int,int>> q;
                vector<int> red,blue;
                q.push({i,0});
                while(!q.empty()){
                    int now=q.front().first;
                    int color=q.front().second;
                    q.pop();
                    printf("x%d %d\n",now,color);
                    if(color)red.push_back(now);
                    else blue.push_back(now);
                    visit[now]=1;
                    for(auto &j:map[now]){
                        if(visit[j]==0){
                            printf("in%d %d\n",now,j);
                            //visit[j]=1;
                            q.push({j,!color});
                        }
                    }
                }
                vector<pair<int,int>> total;
                for(auto &j:red){
                    total.push_back({j,0});
                }
                for(auto &j:blue){
                    total.push_back({j,1});
                }
                sort(total.begin(),total.end());
                for(j=1;j<total.size();j++){
                    if(total[j-1].first==total[j].first){
                        if(total[j-1].second!=total[j].second){
                            ch=0;
                            break;
                        }
                    }
                }
                if(!ch)break;
            }
        }
        if(ch)printf("YES\n");
        else printf("NO\n");
    }
}*/

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,f;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    int y=(c*d-a*f)/(b*d-a*e);
    int x;
    if(a==0){
        x=(f-e*y)/d;
    }
    else x=(c-b*y)/a;
    printf("%d %d",x,y);
}*/

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[100000],i,sum=0,bsum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        bsum+=(a[i]/2);
    }
    if(sum%3!=0){
        printf("NO");
        return 0;
    }
    sum/=3;
    bsum>=sum?printf("YES"):printf("NO");
}*/

/*#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> maps(200001);
int n;
int main(){
    int i;
    scanf("%d",&n);

    vector<int> rumor(n+1,-1);
    for(i=0;i<n;i++){
        int x;
        while(1){
            scanf("%d",&x);
            if(x==0)break;
            maps[i+1].push_back(x);
        }
    }
    int m;
    scanf("%d",&m);
    vector<int> starter(m);
    vector<int> visit(n+1,-1);
    vector<int> ans(n+1,0);
    queue<pair<int,int>> q;
    for(i=0;i<m;i++)scanf("%d",&starter[i]);
    for(auto &i:starter){
        q.push({i,0});

    }
        while(!q.empty()){
            int now=q.front().first;
            int cnt=q.front().second;
            q.pop();

            if(visit[now]!=-1)continue;
            //printf("x%d %d\n",now,cnt);
            visit[now]=cnt;
            for(int j=0;j<maps[now].size();j++){
                ans[maps[now][j]]++;
            }
            for(int j=0;j<maps[now].size();j++){
                if(visit[maps[now][j]]==-1){
                    if(ans[maps[now][j]]>=(maps[maps[now][j]].size()+1)/2){
                        q.push({maps[now][j],cnt+1});
                    }
                }
            }
        }
    for(i=1;i<=n;i++)printf("%d ",visit[i]);
}
*/

/*#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mp;
int t[300001][2];
int main(){
    int n;

    scanf("%d",&n);
    mp.resize(n+1);
    int i;
    for(i=0;i<n-1;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        t[i][0]=a;
        t[i][1]=b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    int d=0,g=0;
    for(i=0;i<n-1;i++){
        d+=(mp[t[i][0]].size()-1)*(mp[t[i][1]].size()-1);
    }
    for(i=1;i<=n;i++){
        int nowsize=mp[i].size();
        if(nowsize>2){
            g+=(nowsize*(nowsize-1)*(nowsize-2))/6;
        }
    }
    //printf("%d %d\n",d,g);
    if(d>g*3)printf("D");
    else if(d<g*3)printf("G");
    else printf("DUDUDUNGA");
}
*/

/*#include<bits/stdc++.h>
#define INF 0xfffffff
#define macro(a,b,c) if(a+dir[c]<0||a+dir[c]>=h||b+dir[c+1]<0||b+dir[c+1]>=w)continue;
using namespace std;
vector<vector<int>> maps(500,vector<int>(500));
vector<vector<int>> units(300000,vector<int>(4));
vector<int> danger(10);
struct cmp{
    bool operator()(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b){
    return a.second>b.second;
}
};

int dir[5]={0,1,0,-1,0};
int main(){
    int n,h,w;
    scanf("%d %d %d",&n,&h,&w);
    int i,j;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++)scanf("%d",&maps[i][j]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&danger[i]);
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++)maps[i][j]=danger[maps[i][j]];
    }
    vector<vector<int>> unitmaps(500,vector<int>(500));
    vector<vector<int>> unitloc(500,vector<int>(500,0));
    unitmaps=maps;
    int m;
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        for(j=0;j<4;j++)scanf("%d",&units[i][j]);
        if(units[i][1]==0)units[i][1]=-1;
        unitloc[units[i][2]][units[i][3]]=units[i][1];
    }
    int k;
    scanf("%d",&k);
    vector<vector<int>> djik(500,vector<int>(500));
    while(k--){
        int u,a,b;
        scanf("%d %d %d",&u,&a,&b);

        int nowx=units[u][2];
        int nowy=units[u][3];
        int nowstamina=units[u][0];
        int nowwho=units[u][1];
        if(maps[a][b]<0)continue;
        if(unitloc[a][b])continue;

        for(i=-21;i<=21;i++){
            for(j=-21;j<=21;j++){
                if(nowx+i<0||nowx+i>=h||nowy+j<0||nowy+j>=w)continue;
                djik[nowx+i][nowy+j]=INF;
            }
        }
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,cmp> q;
        q.push({{nowx,nowy},0});
        djik[nowx][nowy]=0;
        printf("\n");
        for(i=0;i<h;i++){
        for(j=0;j<w;j++)printf("%d ",unitloc[i][j]);
        printf("\n");
    }
    printf("\n");printf("\n");
        for(i=0;i<h;i++){
        for(j=0;j<w;j++)printf("%d ",unitmaps[i][j]);
        printf("\n");
    }
    printf("\n");
        int chd=0;
        while(!q.empty()){
            int x=q.top().first.first;
            int y=q.top().first.second;
            int dis=q.top().second;
            q.pop();
            if(djik[x][y]<dis)continue;


            for(j=0;j<4;j++){
                macro(x,y,j);
                if(unitmaps[x+dir[j]][y+dir[j+1]]==-1)continue;
                if(unitloc[x+dir[j]][y+dir[j+1]]==-(nowwho))continue;
                if(x+dir[j]==a&&y+dir[j+1]==b){
                    djik[a][b]=dis+unitmaps[x+dir[j]][y+dir[j+1]];
                    chd=1;
                    break;
                }
                if(chd)break;
                int chw=1;

                for(int l=0;l<4;l++){
                    macro(x+dir[j],y+dir[j+1],l);
                    if(x==x+dir[j]+dir[l]&&y==y+dir[j+1]+dir[l+1])continue;
                    if(unitloc[x+dir[j]+dir[l]][y+dir[j+1]+dir[l+1]]==-nowwho){
                        chw=0;
                        break;
                    }
                }
                //printf("save2%d %d\n",x+dir[j],y+dir[j+1]);
                if(!chw)continue;
                if(dis+unitmaps[x+dir[j]][y+dir[j+1]]>nowstamina)continue;

                if(djik[x+dir[j]][y+dir[j+1]]>dis+unitmaps[x+dir[j]][y+dir[j+1]]){
                    q.push({{x+dir[j],y+dir[j+1]},dis+unitmaps[x+dir[j]][y+dir[j+1]]});
                    djik[x+dir[j]][y+dir[j+1]]=dis+unitmaps[x+dir[j]][y+dir[j+1]];
                }

            }
            if(chd)break;
        }
        //printf("d%d\n",djik[a][b]);
        if(chd){
            if(djik[a][b]<=nowstamina){
                unitloc[nowx][nowy]=0;
                unitloc[a][b]=nowwho;
                units[u][2]=a;
                units[u][3]=b;
            }
        }
    }
    for(i=1;i<=m;i++){
        printf("%d %d\n",units[i][2],units[i][3]);
    }
    return 0;
}
*/

/**#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<int>> moim(m);
    vector<int> finalstate(n);
    vector<int> firststate(n,1);
    int i,j;
    for(i=0;i<m;i++){
        int k;
        scanf("%d",&k);
        for(j=0;j<k;j++){
            int x;
            scanf("%d",&x);
            moim[i].push_back(x);
        }
    }
    int sum=0;
    for(i=0;i<n;i++){scanf("%d",&finalstate[i]);sum+=finalstate[i];}
    for(i=m-1;i>=0;i--){
        int infection=1;
        for(j=0;j<moim[i].size();j++){
            if(finalstate[moim[i][j]-1]==0){
                infection=0;
                break;
            }
        }
        if(infection==0){
            for(j=0;j<moim[i].size();j++){
                firststate[moim[i][j]-1]=0;
            }
        }
    }
    int firstsum=0;
    for(auto &i:firststate){
        firstsum+=i;
    }
    if(firstsum==0&&sum!=0){
        printf("NO");
        return 0;
    }
    for(i=0;i<n;i++){
        if(firststate[i]==1&&finalstate[i]==0){
            printf("NO");
            return 0;
        }
    }
    vector<int> state(n);
    state=firststate;
    for(i=0;i<m;i++){
        int infection=0;
        for(j=0;j<moim[i].size();j++){
            if(state[moim[i][j]-1]==1){
                infection=1;
                break;
            }
        }
        if(infection){
            for(j=0;j<moim[i].size();j++){
                state[moim[i][j]-1]=1;
            }
        }
    }
    int ch=1;
    for(i=0;i<n;i++){
        if(state[i]!=finalstate[i]){
            ch=0;
            break;
        }
    }
    if(!ch){
        printf("NO");
        return 0;
    }
    else{
        printf("YES\n");
        for(i=0;i<n;i++)printf("%d ",firststate[i]);
    }
}**/

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j;
    vector<pair<int,int>> a;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int p,q;
        scanf("%d %d",&p,&q);
        a.push_back({p,q});
    }
    sort(a.begin(),a.end());
    vector<int> ans;
    ans.push_back(1);
    for(i=1;i<a.size();i++){
        int max=0;
        for(j=0;j<i;j++){
            if(a[j].second<a[i].second&&max<ans[j])max=ans[j];
        }
        ans.push_back(max+1);
    }
    int max=0;
    for(auto &i:ans)if(max<i)max=i;
    printf("%d",n-max);
}
*/

/*#include<stdio.h>
int main(){
    int n,i,sum=0,a,m=-1001,ch=-1001;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        sum+=a;
        if(m<sum)m=sum;
        if(sum<0)sum=0;
        if(a<=0&&ch<a)ch=a;
    }
    if(m<sum)m=sum;
    if(m==0)m=ch;
    printf("%d",m);
}
*/

/*#include<stdio.h>
int main(){
    int n,k,i;
    scanf("%d %d",&n,&k);
    int a[100];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    i=n-1;
    int ans=0;
    while(k>0){
        while(k>=a[i]){k-=a[i];ans++;}
        i--;
    }
    printf("%d",ans);
}
*/

/*#include<stdio.h>
int a[100];
int mem[10001];
int main(){
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mem[0]=1;
    for(i=0;i<n;i++){
        for(j=a[i];j<=k;j++){
            mem[j]=mem[j]+mem[j-a[i]];
        }
    }
    printf("%d",mem[k]);
}*/

/*#include<stdio.h>
#include<algorithm>
#define ll long long
#define INF 9223372036854775807
#define m(a,b) a<b?a:b
int a[100];
ll d[100][100001];
int main(){
    int n,k,i,j;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    std::sort(a,a+n);
    for(i=0;i<n;i++){
        for(j=0;j<=k;j++)d[i][j]=INF;
    }
    for(i=0;i<=k;i+=a[0]){
        d[0][i]=i/a[0];
    }
    for(i=1;i<n;i++){
        for(j=0;j<a[i];j++)d[i][j]=d[i-1][j];
        for(j=a[i];j<=k;j++){
            d[i][j]=m(d[i-1][j],d[i][j-a[i]]+1);
        }
    }
    for(i=0;i<n;i++){
        for(j=1;j<=k;j++)printf("%d ",d[i][j]);
        printf("\n");
    }
    if(d[n-1][k]==INF)printf("-1");
    else printf("%lld",d[n-1][k]);
*/

/*#include<stdio.h>
#define ll long long
int main(){
    ll n;
    scanf("%lld",&n);
    ll len[100000],i;
    for(i=0;i<n-1;i++)scanf("%lld",&len[i]);
    ll price[100000];
    for(i=0;i<n;i++)scanf("%lld",&price[i]);
    ll minprice=price[0];
    ll ans=0;
    for(i=0;i<n-1;i++){
        if(minprice>price[i])minprice=price[i];
        ans+=minprice*len[i];
    }
    printf("%lld",ans);
}
*/

/*#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    n=n%8;
    if(n==0)n=2;
    if(n==7)n=3;
    if(n==6)n=4;
    printf("%d",n);
}
*/

/*#include<stdio.h>
int main(){
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    char a[100][100],b[100][100];
    for(i=0;i<n;i++)scanf("%s",a[i]);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            b[m-j-1][i]=a[i][j];
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            switch(b[i][j]){
            case '-':
                b[i][j]='|';
                break;
            case '|':
                b[i][j]='-';
                break;
            case '/':
                b[i][j]='\\';
                break;
            case '\\':
                b[i][j]='/';
                break;
            case '^':
                b[i][j]='<';
                break;
            case '<':
                b[i][j]='v';
                break;
            case 'v':
                b[i][j]='>';
                break;
            case '>':
                b[i][j]='^';
                break;
            default:
                break;
            }
        }
    }
    for(i=0;i<m;i++,printf("\n"))for(j=0;j<n;j++)printf("%c",b[i][j]);
}*/

/*#include<stdio.h>
#define ll long long
#define abs(a) a>0?a:-a
int n,a[22][22];
ll f(int r,int l){
    int ir=r%5,il=l%5;
    printf("x%d %d\n",r,l);
    if(r+l==n){
        if(a[ir][il])return 1;
    }
    a[r][l]=1;
    return f(r+1,l),f(r,l+1);
}
int main(){
    scanf("%d",&n);
    printf("%lld",f(0,0));
}*/
/*#include<bits/stdc++.h>
using namespace std;
vector<int> getpi(string p){
    int siz=(int)p.size(),i,j=0;
    vector<int> pi(siz,0);
    for(i=1;i<siz;i++){
        while(j>0&&p[i]!=p[j]){
            j=pi[j-1];
        }
        if(p[i]==p[j]){
            pi[i]=j+1;
            j++;
        }
    }
    return pi;
}
vector<int> kmp(string t,string p){
    vector<int> pi=getpi(p);
    vector<int> ans;
    int psiz=(int)p.size(),tsiz=(int)t.size(),i,j=0;
    for(i=0;i<tsiz;i++){
        while(j>0&&t[i]!=p[j]){
            j=pi[j-1];
        }
        if(t[i]==p[j]){
            if(j==psiz-1){
                ans.push_back(i-(psiz-1));
                j=pi[j];
            }
            else j++;
        }
    }
    return ans;
}
int main(){
    while(1){
        string s;
        getline(cin,s);
        if(s==".")break;
        auto pi=getpi(s);
        int siz=(int)s.size();
        int endkmp=pi[siz-1];
        if(siz%2==0){
            if(endkmp<siz/2)printf("1\n");
            else printf("%d\n",siz/(siz-endkmp));
        }
        else{
            if(siz%(siz-endkmp)!=0)printf("1\n");
            else printf("%d\n",siz/(siz-endkmp));
        }
    }
}*/

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    string a;
    cin>>a;
    int s=(int)a.size();
    int i,j=0;
    vector<int> ans(s,0);
    for(i=1;i<n;i++){
        while(j>0&&a[i]!=a[j]){
            j=ans[j-1];
        }
        if(a[i]==a[j]){
            ans[i]=j+1;
            j++;
        }
    }
    printf("%d",s-ans[s-1]);
}*/

/*#include<bits/stdc++.h>
using namespace std;
vector<int> getpi(vector<int> a){
    int asiz=(int)a.size();
    int i,j=0;
    vector<int> ans(asiz,0);
    for(i=1;i<asiz;i++){
        while(j>0&&a[i]!=a[j])j=ans[j-1];
        if(a[i]==a[j]){
            ans[i]=j+1;
            j++;
        }
    }
    return ans;
}
int main(){
    int n,i;
    scanf("%d",&n);
    vector<int> a(n,0);
    vector<int> b(n,0);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int> sa,sb;
    for(i=n-1;i>0;i--){
        sa.push_back(a[i]-a[i-1]);
        sb.push_back(b[i]-b[i-1]);
    }
    sa.push_back(a[0]-a[n-1]+360000);
    vector<int> ssa=sa;
    ssa.insert(ssa.end(),sa.begin(),sa.end());
    sb.push_back(b[0]-b[n-1]+360000);
    vector<int> pib=getpi(sb);
    int j=0;
    int ch=0;
    for(i=1;i<2*n;i++){
        while(j>0&&ssa[i]!=sb[j])j=pib[j-1];
        if(ssa[i]==sb[j]){
            if(j==n-1){
                ch=1;
                break;
            }
            else j++;
        }
    }
    if(ch)printf("possible");
    else printf("impossible");
}
*/

/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f(int a,int b){
    ll ans=b,i=1;
    if(b==0)return a*10;
    while(b>0){
        b/=10;
        i*=10;
    }
    ans+=a*i;
    return ans;
}
bool cmp(const int a,const int b){
    ll aa=f(a,b);
    ll bb=f(b,a);
    return aa>bb;
}
int main(){
    int n;
    scanf("%d",&n);
    vector<int> a(1000);
    vector<pair<ll,int>> b;
    int i,sum=0;
    for(i=0;i<n;i++){scanf("%d",&a[i]);sum+=a[i];}
    if(sum==0){
        printf("0");
        return 0;
    }
    sort(a.begin(),a.begin()+n,cmp);
    for(i=0;i<n;i++)printf("%d",a[i]);
}
*/

/*#include<stdio.h>
#include<math.h>
#include<vector>
#define mod 1000000007
#define ll long long
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
using namespace std;
vector<vector<int>> prime(15000001);
ll exp(int a,int b){
    ll ex=(ll)b;
    ll base=(ll)a;
    ll ans=1;
    while(ex){
        if(ex%2){
            ans*=base;
            ans%=mod;
        }
        base*=base;
        base%=mod;
        ex/=2;
    }
    return ans%mod;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int small=min(m,n);
    int big=max(m,n);
    int mx=sqrt(small);
    int x=2,i;
    while(x<=mx){
        for(i=x;i<=small;i+=x)prime[i].push_back(x);
        while(prime[++x].size()!=1);
    }
    ll ans=1;
    for(i=2;i<=n;i++){
        printf("%d ",prime[i].size());
        for(int j=0;j<prime[i].size();j++){
            ans*=exp(prime[i][j],prime[i][j]/big);
            ans%=mod;
        }
    }
    printf("%lld",ans);
}*/

/*#include<stdio.h>
#define ll long long
int main(){
    ll n,a[100];
    scanf("%lld",&n);
    ll ans=n;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            ans/=i;
            ans*=(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n>1){
        ans/=n;
        ans*=(n-1);
    }
    printf("%lld",ans);
}

*/

/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(ll a,ll b){
    ll a2=0,a3=0,ex=a;
    while(ex%2==0){
        ex/=2;
        a2++;
    }
    ex=a;
    while(ex%3==0){
        ex/=3;
        a3++;
    }
    ll b2=0,b3=0;
    ex=b;
    while(ex%2==0){
        ex/=2;
        b2++;
    }
    ex=b;
    while(ex%3==0){
        ex/=3;
        b3++;
    }
    if(a3>b3)return true;
    else{
        if(a2<b2)return true;
    }
    return false;
}
int main(){
    ll n,i;
    scanf("%lld",&n);
    ll a[100];
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    sort(a,a+n,cmp);
    for(i=0;i<n;i++){
        printf("%lld ",a[i]);
    }
}*/

/*#include<stdio.h>
int main(){
    while(1){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a==0&&b==0)break;
        if(a>b){
            if(a%b==0)printf("multiple\n");
            else printf("neither\n");
        }
        else{
            if(b%a==0)printf("factor\n");
            else printf("neither\n");
        }
    }

}
*/

/*#include<bits/stdc++.h>
using namespace std;
int a[2400][2400];
vector<int> f(int p,int q,int x,int y){
    if(p==x&&q==y){
        vector<int> imsi(3,0);
        imsi[a[p][q]+1]++;
        return imsi;
    }
    int i,j,ch=1;
    for(i=p;i<=x;i++){
        for(j=q;j<=y;j++){
            if(a[p][q]!=a[i][j]){
                ch=0;
                break;
            }
        }
    }
    if(ch){
        vector<int> imsi(3,0);
        imsi[a[p][q]+1]++;
        return imsi;
    }
    vector<int> ans(3,0);
    int seq=(x-p+1)/3;
    for(i=p;i<=x;i+=seq){
        for(j=q;j<=y;j+=seq){
            vector<int> b(3,0);
            b=f(i,j,i+seq-1,j+seq-1);
            for(int k=0;k<3;k++)ans[k]+=b[k];
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
    vector<int> ans(3);
    ans=f(1,1,n,n);
    printf("%d %d %d",ans[0],ans[1],ans[2]);
}
*/

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;
    scanf("%d",&n);
    vector<pair<int,int>> dot;
    for(i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        dot.push_back({a,b});
    }
    sort(dot.begin(),dot.end());
    int fr=dot[0].first,re=dot[0].second,ans=0;
    for(i=1;i<n;i++){
        if(re>=dot[i].first){
            re=max(re,dot[i].second);
        }
        else{
            ans+=re-fr;
            fr=dot[i].first;
            re=dot[i].second;
        }
    }
    printf("%d",ans+(re-fr));
}*/

/*#include<bits/stdc++.h>
#define ll long long
#define INF 1000000001
using namespace std;
int mi(int a,int b){
    return a<b?a:b;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<pair<int,int>>> bridge(n+1);
    vector<int> vis(n+1,0);
    vector<int> dist(n+1,-1);
    int i;
    for(i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        bridge[a].push_back({b,c});
        bridge[b].push_back({a,c});
    }
    int st,en;
    scanf("%d %d",&st,&en);
    priority_queue<pair<int,int>> q;
    q.push({INF,st});
    //dist[st]=INF;
    while(!q.empty()){
        int nowmax=q.top().first;
        int now=q.top().second;
        vis[now]=1;
        //_sleep(200);
        //printf("a%d %d\n",now,nowmax);
        if(now==en){
            break;
        }r
        q.pop();
        if(dist[now]>nowmax)continue;
        for(int i=0;i<bridge[now].size();i++){
            int nextmax=bridge[now][i].second;
            int next=bridge[now][i].first;
            if(dist[next]<mi(nowmax,nextmax)&&vis[next]==0){
                dist[next]=mi(nowmax,nextmax);
                q.push({dist[next],next});
            }
        }
    }
    printf("%d",dist[en]);
}*/

/*#include<bits/stdc++.h>
using namespace std;
vector<int> getpi(string p){
    int psiz=(int)p.size();
    int i,j=0;
    vector<int> pi(psiz,0);
    for(i=1;i<psiz;i++){
        while(j>0&&p[i]!=p[j])j=pi[j-1];
        if(p[i]==p[j]){
            pi[i]=j+1;
            j++;
        }
    }
    return pi;
}
int main(){
    string p,s;
    cin>>p;
    cin>>s;
    vector<int> pi=getpi(p);
    int i,j=0;
    for(i=0;i<p.size();i++){

        while(j>0&&p[i]!=s[j])j=pi[j-1];
        if(p[i]==s[j]){
            if(j==s.size()-1){
                printf("1");
                return 0;
            }
            else j++;
        }
    }
    printf("0");
}
*/

/*#include<stdio.h>
#include<string.h>
int main(){
    char a[100];
    scanf("%s",a);
    if(strlen(a)==1){
        printf("YES");
        return 0;
    }
    int b=(strlen(a)+1)/2,c=0;
    for(int i=0;i<b;i++){
        if(a[i]!=a[strlen(a)-i-1])c++;
    }
    if(c==1)printf("YES");
    else {
        if(strlen(a)%2==1){
            if(c==0)printf("YES");
            else printf("NO");
        }
        else printf("NO");
    }
}
*/

/*#include<bits/stdc++.h>
using namespace std;
vector<int> getpi(string p){
    int psiz=(int)p.size();
    int i,j=0;
    vector<int> pi(psiz,0);
    for(i=1;i<psiz;i++){
        while(j>0&&p[i]!=p[j])j=pi[j-1];
        if(p[i]==p[j]){
            pi[i]=j+1;
            j++;
        }
    }
    return pi;
}
int main(){
    int n;
    scanf("%d",&n);
    int i;
    string a[100];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int stsize=(int)a[0].size();
    string a0=a[0]+a[0];
    vector<int> pi=getpi(a0);
    vector<int> time(n,0);
    for(i=1;i<n;i++){
        int j,k=0,ch=0;
        for(j=0;j<a0.size();j++){
            while(k>0&&a0[j]!=a[i][k])k=pi[k-1];
            if(a0[j]==a[i][k]){
                if(k==(int)stsize-1){
                    time[i]=(2*stsize-j-1)%stsize;
                    ch=1;
                    break;
                }
                else k++;
            }
        }
        if(ch==0){
            printf("-1");
            return 0;
        }
    }
    int mi=0xffffff;
    for(i=0;i<stsize;i++){
        int sum=0;
        for(int j=0;j<n;j++){sum+=(time[j]+i)%stsize;}
        if(mi>sum)mi=sum;
    }
    printf("%d",mi);
}
*/

/*#include<bits/stdc++.h>
using namespace std;
vector<int> getpi(string p){
    int psiz=(int)p.size();
    int i,j=0;
    vector<int> pi(psiz,0);
    for(i=1;i<psiz;i++){
        while(j>0&&p[i]!=p[j])j=pi[j-1];
        if(p[i]==p[j]){
            pi[i]=j+1;
            j++;
        }
    }
    return pi;
}
int main(){
    string a;
    cin>>a;
    int max=-1;
    int asiz=(int)a.size();
    for(int i=0;i<asiz;i++){
        vector<int> pi=getpi(a);

        for(int j=0;j<(int)a.size();j++){
            if(max<pi[j])max=pi[j];
        }
        a.erase(a.begin());
    }
    printf("%d",max);
}*/

/*#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    if(y==0)return x;
    return gcd(y,x%y);
}
vector<int> getpi(string p){
    int psiz=(int)p.size();
    int i,j=0;
    vector<int> pi(psiz,0);
    for(i=1;i<psiz;i++){
        while(j>0&&p[i]!=p[j])j=pi[j-1];
        if(p[i]==p[j]){
            pi[i]=j+1;
            j++;
        }
    }
    return pi;
}
int main(){
    int n,i,j=0;
    scanf("%d",&n);
    string meat,now;
    for(i=0;i<n;i++){
        char a;
        cin>>a;
        meat+=a;
    }
    for(i=0;i<n;i++){
        char a;
        cin>>a;
        now+=a;
    }
    now+=now;
    now.erase(now.end()-1);
    vector<int> pi=getpi(now);
    int ans=0;
    for(i=0;i<2*n;i++){
        while(j>0&&now[i]!=meat[j])j=pi[j-1];
        if(now[i]==meat[j]){
            if(j==n-1){
                ans++;
                j=pi[j];
            }
            else j++;
        }
    }
    int g=gcd(ans,n);
    printf("%d/%d",ans/g,n/g);
}
*/

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> getpi(string p){
    ll psiz=(ll)p.size();
    ll i,j=0;
    vector<ll> pi(psiz,0);
    for(i=1;i<psiz;i++){
        while(j>0&&p[i]!=p[j])j=pi[j-1];
        if(p[i]==p[j]){
            pi[i]=j+1;
            j++;
        }
    }
    return pi;
}
ll kmp(string a,string b){
    ll asiz=(ll)a.size();
    ll bsiz=(ll)b.size();
    vector<ll> pi=getpi(b);
    ll ans=0,i,j=0;
    for(i=0;i<asiz;i++){
        while(j>0&&a[i]!=b[j])j=pi[j-1];
        if(a[i]==b[j]){
            if(j==bsiz-1){
                //printf("jj%d\n",j);
                ans++;
                j=pi[j];
            }
            else j++;
        }
    }
    return ans;
}
int main(){
    ll n;
    string fib[30];
    //ifstream readfile;
    //readfile.open("in.txt");
    fib[0]="0";
    fib[1]="1";
    for(ll i=2;i<30;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    string p;
    ll i=1;
    //if(readfile.is_open()){
    while(!cin.eof()){
        vector<ll> dp(101,0);
        if(cin.eof()==true)break;
        cin>>n;
        if(cin.eof()==true)break;
        cin>>p;
        ll psiz=(ll)p.size();
        //printf("x%lld\n",psiz);
        ll index;
        for(index=0;index<27;index++){
            if((ll)fib[index].size()>=psiz)break;
        }
        //printf("ind%lld\n",index);
        string head=fib[index].substr(0,psiz-1);
        string tail0,tail1;
        if(index%2==0){
            tail0=fib[index].substr(fib[index].size()-psiz+1,psiz-1);
            tail1=fib[index+1].substr(fib[index+1].size()-psiz+1,psiz-1);
        }
        else if(index%2==1){
            tail1=fib[index].substr(fib[index].size()-psiz+1,psiz-1);
            tail0=fib[index+1].substr(fib[index+1].size()-psiz+1,psiz-1);
        }
        dp[index]=kmp(fib[index],p);
        index++;
        dp[index]=kmp(fib[index],p);
        index++;
        //string tail=fib[index].substr(fib[index].size()-psiz,psiz);
        //cout<<head<<endl;
        for(;index<=n;index++){
            dp[index]+=dp[index-1]+dp[index-2];
            string tail=(index%2==0?tail1:tail0);
            string imsi=tail+head;
            //cout<<index<<' '<<tail<<' '<<head<<endl;
            ll sum=kmp(imsi,p);
            //cout<<sum<<endl;
            dp[index]+=sum;
        }
        //for(int j=0;j<=n;j++)printf("%lld ",dp[j]);
        //printf("\n");
        //for(int j=0;j<=20;j++)printf("%lld ",kmp(fib[j],p));
        //printf("\n");
        printf("Case %lld: %lld\n",i,dp[n]);
        i++;
    }
    //}
}*/

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> fib(92);
ll g(ll n,string p){
    //cout<<n<<' '<<p<<endl;
    ll i,ans=0;
    if(n==0){
        if(p=="0")return 1;
        else return 0;
    }
    if(p.size()==1){
        if(p=="1")return fib[n-1];
        else if(p=="0")return fib[n-2];
    }
    int ch0=0,ch1=0,ch=1;
    for(i=0;i<(ll)p.size();i++){
        if(p[i]=='0'){ch0++;ch1=0;}
        if(p[i]=='1'){ch1++;ch0=0;}
        if(ch0==2||ch1==3){ch=0;break;}
    }
    if(ch==0)return 0;
    string imsi;
    for(i=0;i<(ll)p.size();i+=2){
        if(i==0&&p[i]=='0'){imsi+='1';i--;continue;}
        if(p[i]=='1'&&p[i+1]=='0')imsi+='1';
        if(p[i]=='1'&&p[i+1]=='1'){
            imsi+='0';
            i--;
        }
    }
    string imsi1="00";

    if(i==(ll)p.size()+1){
        imsi1=imsi+'0';
        imsi+='1';
    }
    //_sleep(200);
    //cout<<imsi<<endl<<imsi1<<endl;
    ch0=0;ch1=0;ch=1;
    for(i=0;i<(ll)imsi.size();i++){
        if(imsi[i]=='0'){ch0++;ch1=0;}
        if(imsi[i]=='1'){ch1++;ch0=0;}
        if(ch0==2||ch1==3){ch=0;break;}
    }
    if(ch){
        ans+=g(n-1,imsi);
    }
    ch0=0;ch1=0;ch=1;
    for(i=0;i<(ll)imsi1.size();i++){
        if(imsi1[i]=='0'){ch0++;ch1=0;}
        if(imsi1[i]=='1'){ch1++;ch0=0;}
        if(ch0==2||ch1==3){ch=0;break;}
    }
    if(ch){
        ans+=g(n-1,imsi1);
    }
    return ans;
}
int main(){
    //FILE *fp=freopen("in.txt","r",stdin);
    ll i;
    fib[0]=1;
    fib[1]=1;
    for(i=2;i<92;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    ll n;
    i=1;
    while(scanf("%lld",&n)!=EOF){
        string p;
        cin>>p;
        if(n==1&&p=="0"){
            printf("Case %lld: 0\n",i);
            i++;
            continue;
        }
        ll ans=g(n,p);
        printf("Case %lld: %lld\n",i,ans);
    }
}
*/

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> big;
    int mid;
    int n;
    scanf("%d",&n);
    int i,a;
    scanf("%d",&mid);
    printf("%d\n",mid);
    for(i=1;i<n;i++){
        scanf("%d",&a);
        if(a>mid)big.push(a);
        if(a<=mid)small.push(a);
        if(small.size()==big.size()+1){
            big.push(mid);
            mid=small.top();
            small.pop();
        }
        else if(small.size()==big.size()+2){
            big.push(mid);
            mid=small.top();
            small.pop();
        }
        else if(small.size()+2==big.size()){
            small.push(mid);
            mid=big.top();
            big.pop();
        }
        printf("%d\n",mid);
    }
}*/

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<char>> f(int n){
    if(n==3){
        vector<vector<char>> first={{' ',' ','*',' ',' '},{' ','*',' ','*',' '},{'*','*','*','*','*'}};
        return first;
    }
    int i,j;
    vector<vector<char>> sample=f(n/2);

    vector<vector<char>> ans(n,vector<char>(2*n-1,' '));
    for(i=0;i<n/2;i++){
        for(j=n/2;j<3*n/2-1;j++){
            ans[i][j]=sample[i][j-n/2];
        }
    }

    for(i=n/2;i<n;i++){
        for(j=0;j<n-1;j++){
            ans[i][j]=sample[i-n/2][j];
        }
    }
    for(i=n/2;i<n;i++){
        for(j=n;j<2*n-1;j++){
            ans[i][j]=sample[i-n/2][j-n];
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    auto ans=f(n);
    for(auto &i:ans){
        for(auto &j:i)printf("%c",j);
        printf("\n");
    }
}*/

/*#include<stdio.h>
#define ll long long
int main(){
    ll a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    a%=c;
    ll ans=1;
    while(b){
        if(b%2){
            ans*=a;
            ans%=c;
        }
        a*=a;
        a%=c;
        b/=2;
    }
    printf("%lld",ans%c);
}
*/

/*#include<bits/stdc++.h>
using namespace std;
int a,b;
void f(int n,int t){
    if(n>b)return;
    if(n==b){printf("%d",t);exit(0);}
    f(n*2,t+1);f(n*10+1,t+1);
    return;
}
int main(){
    scanf("%d %d",&a,&b);
    queue<pair<int,int>> q;
    q.push({a,1});
    while(!q.empty()){
        int now=q.front().first;
        int time=q.front().second;
        q.pop();
    }
    f(a,1);
    printf("-1");
}*/

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%d\n",(n+1)/10);
    }
}
*/

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        string s,t;
        cin>>s;
        cin>>t;
        queue<pair<int,pair<int,int>>> q;
        int i,now=0,ch=0;
        for(i=0;i<s.size();i++){
            if(s[i]==t[0]){
                now=i;
                ch=1;
                q.push({i,{0,0}});
            }
        }
        if(ch==0){
            printf("NO\n");
            continue;
        }
        int dir=1,check=0;

        while(!q.empty()){
            int noww=q.front().first;
            int dir=q.front().second.first;
            int index=q.front().second.second;
            if(index==t.size()-1){
                check=1;
                break;
            }
            q.pop();
            if(dir==0){
                if(noww+1<s.size()&&s[noww+1]==t[index+1])q.push({noww+1,{1,index+1}});
                if(noww-1>=0&&s[noww-1]==t[index+1])q.push({noww-1,{-1,index+1}});
            }
            else if(dir==1){
                if(noww+1<s.size()&&s[noww+1]==t[index+1])q.push({noww+1,{1,index+1}});
                if(noww-1>=0&&s[noww-1]==t[index+1])q.push({noww-1,{-1,index+1}});
            }
            else if(dir==-1){
                if(noww-1>=0&&s[noww-1]==t[index+1])q.push({noww-1,{-1,index+1}});
            }
        }
        if(check==1)printf("YES\n");
        else printf("NO\n");
    }
}*/

/*#include<bits/stdc++.h>
using namespace std;
int minimum=10;
void f(string a,int n){
    if(n==10){
        //cout<<a<<endl;
            int i;
        int sc1=0,sc2=0,left1=5,left2=5;
        for(i=0;i<10;i++){
            if(i%2==0){
                sc1+=(a[i]-'0');
                left1--;
            }
            else if(i%2==1){
                sc2+=(a[i]-'0');
                left2--;
            }
                if(sc1>sc2+left2){
                    if(minimum>i+1)minimum=i+1;
                    return;
                }
                if(sc2>sc1+left1){
                    if(minimum>i+1)minimum=i+1;
                    return;
                }
        }
        return;
    }
    if(a[n]=='0'||a[n]=='1')f(a,n+1);
    if(a[n]=='?'){
        a[n]='0';
        f(a,n+1);
        a[n]='1';
        f(a,n+1);
    }
    return;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string a;
        cin>>a;
        minimum=10;
        f(a,0);
        printf("%d\n",minimum);
    }
}*/
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        string s,t;
        cin>>s;
        cin>>t;

        int i,idx=(int)t.size()-1,ch=0;
        for(i=(int)s.size()-1;i>=0;i--){

            while(i>=0&&s[i]!=t[idx])i-=2;
            if(s[i]==t[idx]){
                idx--;
            }
            if(idx==-1){
                ch=1;
                break;
            }
            if(i<-1){
                ch=0;
                break;
            }
        }
        if(ch==1){
            printf("YES\n");
        }
        else printf("NO\n");
    }
}

*/

/**#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200001];
ll dp[200001];
ll dp1[200001],dp2[200001];
int main(){
    int n;
    scanf("%d",&n);

    int i;
    for(i=1;i<=n;i++){

        scanf("%d",&a[i]);
        dp1[i]+=dp1[i-1]+a[i];
    }

    dp[1]=0;
    for(i=2;i<=n;i++){
        ll ans=0;
        dp[i]=dp[i-1]+dp1[i]%a[i];
    }
    for(i=1;i<=n;i++)printf("%lld ",dp[i]);
}**/

/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b;
    scanf("%lld %lld",&a,&b);
    queue<pair<ll,ll>> q;
    q.push({a,1});
    ll min=20000000000;
    while(!q.empty()){
        ll now=q.front().first;
        ll time=q.front().second;
        q.pop();
        if(now==b){
            min=time;
            continue;
        }
        if(now>b)continue;
        if(time>=min)continue;
        if(time+1<=min){
            if(now*2<=b)q.push({now*2,time+1});
            if(now*10+1<=b)q.push({now*10+1,time+1});
        }
    }
    printf("%lld",min<20000000000?min:-1);
}
*/
/*int abs(int a){ //#731 A
    if(a<0)return -a;
    return a;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int xa,ya,xb,yb,xf,yf;
        scanf("%d %d %d %d %d %d",&xa,&ya,&xb,&yb,&xf,&yf);
        if(xa==xb&&xb==xf){
            if((ya<yf&&yf<yb)||(ya>yf&&yf>yb))printf("%d\n",abs(ya-yb)+2);
            else printf("%d\n",abs(ya-yb));
        }
        else if(ya==yb&&yb==yf){
            if((xa<xf&&xf<xb)||(xa>xf&&xf>xb))printf("%d\n",abs(xa-xb)+2);
            else printf("%d\n",abs(xa-xb));
        }
        else printf("%d\n",abs(ya-yb)+abs(xa-xb));
    }
}
*/
/*int main(){ //B
    int t;
    scanf("%d",&t);
    while(t--){
        string a;
        cin>>a;
        int ch[27]={0,},i;
        int z=(int)a.size();
        for(i=0;i<z;i++){
            ch[a[i]-'a']++;
        }
        for(i=1;i<=27;i++){
            if(ch[i]==0)break;
        }
        if(i!=z){
            printf("NO\n");
            continue;
        }
        int che=1;
        while(i>0){
            if(a[0]==(i+'a'-1)){
                a.erase(a.begin());
                i--;
            }
            else if(a[i-1]==(i+'a'-1)){
                a.erase(a.end()-1);
                i--;
            }
            else{
                che=0;
                break;
            }
        }
        if(che==0){
            printf("NO\n");
        }
        else printf("YES\n");
    }
}*/

/*#include<bits/stdc++.h>
using namespace std;
int mem[501][501];
vector<int> a(500);
int cmp(int a,int b){
    return a<b?a:b;
}
int f(int fr,int re){
    if(mem[fr][re])return mem[fr][re];
    int asiz=re-fr+1;

    int i,sum=0;
    for(i=fr;i<=re;i++)sum+=a[i];
    if(asiz==1)return mem[fr][re]=0;
    if(asiz==2)return mem[fr][re]=a[fr]+a[re];
    if(asiz==3){
        int p=a[fr],q=a[fr+1],r=a[fr+2];
        int res=cmp(p+q+q+p+r,q+r+q+r+p);
        return mem[fr][re]=res;
    }
    int ans=0xfffffff;
    for(i=0;i<asiz-1;i++){
        ans=cmp(ans,f(fr,fr+i)+f(fr+i+1,re));
    }
    return mem[fr][re]=ans+sum;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int k,i,j;
        scanf("%d",&k);
        int sum=0;
        for(i=0;i<501;i++)for(j=0;j<501;j++)mem[i][j]=0;
        for(i=0;i<k;i++){scanf("%d",&a[i]);sum+=a[i];}
        int ans=f(0,k-1);
        printf("%d\n",ans);
    }
}
*/

/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int,int>> a(500);
int mem[500][500];
ll f(int fr,int re){
    if(mem[fr][re])return mem[fr][re];
    int asiz=re-fr+1;
    if(asiz==1)return 0;
    int i;
    ll ans=0xffffffffff;
    for(i=0;i<asiz-1;i++){
        ans=min(ans,f(fr,fr+i)+f(fr+i+1,re)+a[fr].first*a[fr+i].second*a[re].second);
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    printf("%lld",f(0,n-1));
}
*/
/*#include<bits/stdc++.h>
using namespace std;
int parent[201];
int r[201];
int f(int u){
    if(u==parent[u])return u;
    return parent[u]=f(parent[u]);
}
void uni(int u,int v){
    u=f(u);
    v=f(v);
    if(u==v)return;
    if(r[u]>r[v])swap(u,v);
    parent[u]=v;
    if(r[u]==r[v])r[v]++;
    return;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int i;
    for(i=1;i<=n;i++){parent[i]=i;r[i]=1;}
    for(i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a;
            scanf("%d",&a);
            if(a==1)uni(i,j);
        }
    }
    int trav[1000];
    for(i=0;i<m;i++)scanf("%d",&trav[i]);
    for(i=1;i<=n;i++)printf("%d ",parent[i]);
    printf("\n");
    for(i=1;i<m;i++){
        if(f(trav[i-1])!=f(trav[i])){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}
*/
/*#include<bits/stdc++.h>
using namespace std;
vector<int> parent(200000);
vector<int> r(200000);
map<string,int> change;
int fi(int u){
    if(u==parent[u])return u;
    return parent[u]=fi(parent[u]);
}
void uni(int u,int v){
    u=fi(u);
    v=fi(v);
    if(u==v)return;
    parent[v]=u;
    r[u]+=r[v];
    return;
}
void solve(){
    int f;
    cin>>f;
    for(int i=0;i<=2*f;i++){
        parent[i]=i;
        r[i]=1;
    }
    int i;
    int name=0;
    for(i=0;i<f;i++){
        string a,b;

        cin>>a;
        cin>>b;
        if(change.find(a)==change.end()){
            change[a]=name++;
        }
        if(change.find(b)==change.end()){
            change[b]=name++;
        }
        uni(change[a],change[b]);
        cout<<r[fi(change[a])]<<"\n";
    }
}
int main(){
     ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
*/

/*#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
vi b;
vi c;
vi f(vi a){
    //for(auto &i:a)printf("a%d ",i);
    //printf("\n");
    int i;
    int siz=(int)a.size();
    int mod=(siz+1)/2;
    int n=siz/2;
    //printf("n%d\n",n);
    if(siz==1){
        b[a[0]]=-1;
        return a;
    }

    vi input1,input2,input3;
    for(i=0;i<n;i++){
        input1.push_back(a[i]);
    }
    vi ans1=f(input1);
    for(i=0;i<(int)ans1.size();i++){
        b[ans1[i]]=-1;
    }
    for(i=0;i<siz;i++){
        if((int)input2.size()==n)break;
        if(b[a[i]]!=-1)input2.push_back(a[i]);
    }
    vi ans2=f(input2);
    for(i=0;i<(int)ans1.size();i++){
        b[ans2[i]]=-1;
    }
    for(i=0;i<siz;i++){
        if((int)input3.size()==n)break;
        if(b[a[i]]!=-1)input3.push_back(a[i]);
    }
    vi ans3=f(input3);
    int a1=0,a2=0,a3=0;
    for(i=0;i<(int)ans1.size();i++){
        a1+=c[ans1[i]];
        a2+=c[ans2[i]];
        a3+=c[ans3[i]];
    }//printf("x%d %d %d %d\n",a1,a2,a3,mod);

    if(a1%mod==a2%mod){
        vi ans;
        for(i=0;i<(int)ans1.size();i++){
            ans.push_back(ans1[i]);
        }
        for(i=0;i<(int)ans2.size();i++){
            ans.push_back(ans2[i]);
        }
        for(i=0;i<(int)ans3.size();i++){
            b[ans3[i]]=c[ans3[i]];
        }
        return ans;
    }
    if(a1%mod==a3%mod){
        vi ans;
        for(i=0;i<(int)ans1.size();i++){
            ans.push_back(ans1[i]);
        }
        for(i=0;i<(int)ans3.size();i++){
            ans.push_back(ans3[i]);
        }
        for(i=0;i<(int)ans2.size();i++){
            b[ans2[i]]=c[ans2[i]];
        }
        return ans;
    }
    if(a2%mod==a3%mod){
        vi ans;
        for(i=0;i<(int)ans2.size();i++){
            ans.push_back(ans2[i]);
        }
        for(i=0;i<(int)ans3.size();i++){
            ans.push_back(ans3[i]);
        }
        for(i=0;i<(int)ans1.size();i++){
            b[ans1[i]]=c[ans1[i]];
        }
        return ans;
    }
}
int main(){

    int n;
    scanf("%d",&n);
    int i;
    b.resize(2*n-1);
    c.resize(2*n-1);

    vi a(2*n-1);
    for(i=0;i<2*n-1;i++){scanf("%d",&b[i]);a[i]=i;c[i]=b[i];}

    auto ans=f(a);

    for(auto &i:ans)printf("%d ",c[i]);
}
*/
/*#include<bits/stdc++.h>
#define check(x,y) if(x+d[j]<0||x+d[j]>=m||y+d[j+1]<0||y+d[j+1]>=n)continue
#define piii pair<int,pair<int,int>>
using namespace std;
int d[5]={0,1,0,-1,0},dp[500][500];
bool cmp(const piii &a, const piii &b){
    return a.first>b.first;
}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int i,j,a[500][500];
    vector<piii> seq(m*n);
    for(i=0;i<m;i++)for(j=0;j<n;j++){scanf("%d",&a[i][j]);seq[i*n+j]={a[i][j],{i,j}};}
    sort(seq.begin(),seq.end(),cmp);
    dp[0][0]=1;
    for(i=0;i<m*n;i++){
        int x=seq[i].second.first;
        int y=seq[i].second.second;
        int h=seq[i].first;
    //printf("tt%d %d %d\n",x,y,h);
        for(j=0;j<4;j++){
            check(x,y);
            if(h<a[x+d[j]][y+d[j+1]])dp[x][y]+=dp[x+d[j]][y+d[j+1]];
        }
    }
    printf("%d",dp[m-1][n-1]);
}
*/

/*#include<bits/stdc++.h>
using namespace std;
int i,j,a[2000],dp[2000][2000]={0,};
int main(){
    int n;
    scanf("%d",&n);

    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            if(i==j)dp[j][i]=1;
            else{
                if(a[j]==a[i]){
                    if(j+1>=i-1||dp[j+1][i-1]==1)dp[j][i]=1;
                    else dp[j][i]=0;
                }
                else dp[j][i]=0;
            }
        }
    }
    int m;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        int s,e;
        scanf("%d %d",&s,&e);
        printf("%d\n",dp[s-1][e-1]);
    }
}
*/

/*#include<bits/stdc++.h>
using namespace std;
int ch[40001]={0,};
int i,a[30],dp[30][40001]={0,},sum=0;
int main(){
    int n;
    scanf("%d",&n);

    for(i=0;i<n;i++){scanf("%d",&a[i]);sum+=a[i];}
    int j;

    dp[0][0]=1;
    dp[0][a[0]]=1;
    for(i=1;i<n;i++){
        for(j=1;j<=sum;j++){
            if(dp[i-1][j])dp[i][j]=1;
            else if(j-a[i]>=0&&dp[i-1][j-a[i]]==1)dp[i][j]=1;
            else if(dp[i-1][j+a[i]]==1)dp[i][j]=1;
            else if(a[i]-j>=0&&dp[i-1][a[i]-j]==1)dp[i][j]=1;
            else dp[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        for(j=1;j<=sum;j++){
            if(dp[i][j]==1){ch[j]=1;
            //printf("i-%d j-%d - %d ",i,j,dp[i][j]);
            }
        }
        //printf("\n");
    }
    int m;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        int k;
        scanf("%d",&k);
        if(ch[k]==1)printf("Y ");
        else printf("N ");
    }
}
*/
/*#include<bits/stdc++.h>
using namespace std;
int dp[101][10001];
int main(){
    int n,m,i,a[100],b[100],j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)scanf("%d",&b[i]);


    for(i=1;i<=n;i++){
        for(j=1;j<=10000;j++){
            if(j-b[i-1]>=0)dp[i][j]=max(dp[i-1][j],dp[i-1][j-b[i-1]]+a[i-1]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    for(i=1;i<=10000;i++){
        for(j=1;j<=n;j++){
            if(dp[j][i]>=m){
                printf("%d",i);
                exit(0);
            }
        }
    }
}
*/

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> parent;
vector<ll> r;
vector<pair<ll,pair<ll,ll>>> co;
ll f(ll u){
    if(u==parent[u])return u;
    return parent[u]=f(parent[u]);
}
void uni(ll u,ll v){
    u=f(u);
    v=f(v);
    if(u==v)return;
    if(r[u]>r[v])swap(u,v);
    parent[u]=v;
    if(r[u]==r[v])r[v]++;
    return;
}
int main(){
    ll v,e;
    scanf("%lld %lld",&v,&e);
    ll i;
    parent.resize(v+1);
    r.resize(v+1);
    for(i=1;i<=v;i++){
        parent[i]=i;
        r[i]=1;
    }
    for(i=0;i<e;i++){
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        co.push_back({c,{a,b}});
    }
    sort(co.begin(),co.end());
    //for(auto &i:co)printf("%lld %lld %lld\n",i.first,i.second.first,i.second.second);
    vector<ll> visit(v+1,0);
    ll cnt=0,sum=0;
    for(i=0;i<e;i++){
        if(cnt==v-1)break;
        ll a=co[i].second.first;
        ll b=co[i].second.second;
        ll c=co[i].first;
        if(f(a)==f(b))continue;
        else{
            uni(a,b);
            sum+=c;
            cnt++;
        }
    }
    printf("%lld",sum);
}*/

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,k;
    scanf("%lld %lld",&n,&k);
    ll i;
    vector<pair<ll,ll>> jew(n);
    vector<ll> bag(k);
    for(i=0;i<n;i++)scanf("%lld %lld",&jew[i].first,&jew[i].second);
    sort(jew.begin(),jew.begin()+n);
    for(i=0;i<k;i++)scanf("%lld",&bag[i]);
    sort(bag.begin(),bag.begin()+k);
    priority_queue<pair<ll,ll>> q;
    ll j=0;
    ll sum=0;
    if(bag[k-1]<jew[0].first){
        printf("0");
        exit(0);
    }
    for(i=0;i<k;i++){
        //
        for(;j<n;j++){

            if(jew[j].first>bag[i]){break;}
        //printf("ddd%d\n",j);
            q.push({jew[j].second,jew[j].first});
        }
        //printf("eeee%d\n",q.size());
        if(q.size()!=0){
        sum+=(ll)q.top().first;
        q.pop();
        }
    }
    printf("%lld",sum);
}*/

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> frr,ree;
vector<ll> fr,re;
void f(ll n,string a,vector<ll> ch){
    ll siz;
    siz=a=="fr"?(ll)fr.size():(ll)re.size();
    if(n==siz){

        ll i,sum=0,check=0;
        //if(check==20)cout<<n<<'-'<<a<<' '<<check<<"\n";
        if(a=="fr"){
            for(i=0;i<n;i++){
                if(ch[i]==1)sum+=fr[i];
            }
            frr.push_back(sum);
        }
        else if(a=="re"){
            for(i=0;i<n;i++){
                if(ch[i]==1)sum+=re[i];
            }
            ree.push_back(sum);
        }
        return;
    }
    ch.push_back(0);
    f(n+1,a,ch);
    ch[n]=1;
    f(n+1,a,ch);
    return;
}
bool cmp(ll a,ll b){return a>b;};
int main(){
    ll n,s;
    scanf("%lld %lld",&n,&s);

    ll i,j;
    for(i=0;i<n/2;i++){
        ll a;
        scanf("%lld",&a);
        fr.push_back(a);
    }
    for(i=n/2;i<n;i++){
        ll a;
        scanf("%lld",&a);
        re.push_back(a);
    }
    vector<ll> ch;
    f(0,"fr",ch);
    ch.clear();



    f(0,"re",ch);
    sort(frr.begin(),frr.end());
    sort(ree.begin(),ree.end());
    for(auto &i:frr)printf("%d ",i);
    printf("\n");
    for(auto &i:ree)printf("%d ",i);
    printf("\n");
    ll ans=0;
    i=0,j=0;
    for(i=0;i<(ll)frr.size();i++){
        ll frnow=lower_bound(ree.begin(),ree.end(),s-frr[i])-ree.begin();
        ll renow=upper_bound(ree.begin(),ree.end(),s-frr[i])-ree.begin();
        //printf("%lld %lld %lld\n",frnow,renow,frr[i]);
        ans+=renow-frnow;
    }
    printf("%lld",s==0?ans-1:ans);
}

*/
/*#include<bits/stdc++.h>
#define ch(x,y,j) if(x+d[j]<0||x+d[j]>=r||y+d[j+1]<0||y+d[j+1]>=c)continue;
using namespace std;
int mx=-1,d[5]={0,1,0,-1,0},r,c;
char mp[20][20];
void f(int x,int y,int cnt,vector<int> chk){
    //if(chk[mp[x][y]-'A']==1)return;
    chk[mp[x][y]-'A']=1;
    int i;
    for(i=0;i<4;i++){
        ch(x,y,i);
        if(chk[mp[x+d[i]][y+d[i+1]]-'A']==1)continue;
        f(x+d[i],y+d[i+1],cnt+1,chk);
    }
    if(cnt>mx)mx=cnt;
    return;
}
int main(){
    scanf("%d %d",&r,&c);
    int i,j;
    for(i=0;i<r;i++)scanf("%s",mp[i]);
    vector<int> chk(26,0);
    f(0,0,1,chk);
    printf("%d",mx);
}*/

/*#include<bits/stdc++.h>
using namespace std;
int dp[3][1001],n,p[3][1000],st[3];
int main(){
    int i,j;
    scanf("%d",&n);
    //for(i=0;i<n;i++)for(j=0;j<3;j++)dp[j][i]=0xfffffff;
    for(i=0;i<n;i++)scanf("%d %d %d",&p[0][i],&p[1][i],&p[2][i]);
    //for(i=0;i<3;i++){dp[i][0]=p[i][0];st[i]=i;}
    int mn=0xfffffff;
    for(int k=0;k<3;k++){
    for(i=0;i<n;i++)for(j=0;j<3;j++)dp[j][i]=0xfffffff;
    for(i=0;i<3;i++)st[i]=k;
    dp[k][0]=p[k][0];
    //st[k]=k;
    for(i=1;i<n-1;i++){
        int st0=st[0],st1=st[1],st2=st[2];
        dp[0][i]=min(dp[1][i-1],dp[2][i-1])+p[0][i];
        if(dp[0][i]==dp[1][i-1]-p[0][i])st[0]=st1;
        else st[0]=st2;
        dp[1][i]=min(dp[0][i-1],dp[2][i-1])+p[1][i];
        if(dp[1][i]==dp[2][i-1]-p[1][i])st[0]=st2;
        else st[1]=st0;
        dp[2][i]=min(dp[1][i-1],dp[0][i-1])+p[2][i];
        if(dp[2][i]==dp[1][i-1]-p[2][i])st[0]=st1;
        else st[2]=st0;
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i==j)continue;
            if(i==st[n-1])continue;
            dp[i][n-1]=min(dp[i][n-1],dp[j][n-2]+p[i][n-1]);
        }
    }


    //for(i=0;i<n;i++)printf("%d %d %d\n",dp[0][i],dp[1][i],dp[2][i]);
    for(i=0;i<3;i++){
        //printf("%d\n",st[i]);
        if(mn>dp[i][n-1])mn=dp[i][n-1];
    }

    }
    printf("%d",mn);
}*/

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,m,i,j,t;
    vector<ll> ssa,ssb;
    scanf("%lld",&t);
    scanf("%lld",&n);
    vector<ll> a(n+1,0),sa(n+1,0);
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(i=1;i<=n;i++)sa[i]=sa[i-1]+a[i];
    scanf("%lld",&m);
    vector<ll> b(m+1,0),sb(m+1,0);
    for(i=1;i<=m;i++)scanf("%lld",&b[i]);
    for(i=1;i<=m;i++)sb[i]=sb[i-1]+b[i];
    ll ca=0,cb=0;
    for(i=0;i<=n;i++){
        for(j=i+1;j<=n;j++){
            ssa.push_back(sa[j]-sa[i]);
        }
    }
    for(i=0;i<=m;i++){
        for(j=i+1;j<=m;j++){
            ssb.push_back(sb[j]-sb[i]);
        }
    }
    sort(ssa.begin(),ssa.end());
    sort(ssb.begin(),ssb.end());
    for(auto &i:ssa)printf("%d ",i);
    printf("\n");
    for(auto &i:ssb)printf("%d ",i);
    printf("\n");
    ll ans=0;
    for(i=0;i<ssa.size();i++){
        ll fr=lower_bound(ssb.begin(),ssb.end(),t-ssa[i])-ssb.begin();
        ll re=upper_bound(ssb.begin(),ssb.end(),t-ssa[i])-ssb.begin();
        ans+=re-fr;
    }
    printf("%lld",ans);
}
*/
/*#include<bits/stdc++.h>
#define vvi vector<vector<int>>
#define ch(x,y,j) if(x+d[j]<0||x+d[j]>=n||y+d[j+1]<0||y+d[j+1]>=n)continue;
using namespace std;
int mxw=0,mxb=0,d[5]={0,1,0,-1,0};
void f(int x,int y,vvi vi,int cnt,int wb){
    //printf("x--%d %d %d\n",x,y,cnt);
    vi[x][y]=2;
    int i,j,k;
    int n=vi.size();
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==x&&j==y)continue;
            if(i+j==x+y)vi[i][j]=0;
            if(i-j==x-y)vi[i][j]=0;
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i*n+j<x*n+y)continue;
            if(vi[i][j]==wb)f(i,j,vi,cnt+1,wb);
        }
    }
    printf("x-%d\n",cnt);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",vi[i][j]);
        }
        printf("\n");
    }
    if(wb==1){
        if(mxw<cnt)mxw=cnt;
    }
    else if(mxb<cnt)mxb=cnt;
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    vvi mp(n,vector<int> (n,0));
    vvi vi(n,vector<int> (n,0));
    int t=1;
    int i,j;
    for(i=0;i<n;i++){
        int imsi=t;
        for(j=0;j<n;j++){
            vi[i][j]=imsi;
            imsi=-imsi;
        }
        t=-t;
    }

    for(i=0;i<n;i++)for(j=0;j<n;j++){scanf("%d",&mp[i][j]);if(mp[i][j]==0)vi[i][j]=0;}
    //for(i=0;i<n;i++,printf("\n"))for(j=0;j<n;j++)printf("%d ",vi[i][j]);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(mp[i][j]==1){
                if(vi[i][j]==1)f(i,j,vi,1,1);
                else f(i,j,vi,1,-1);
            }
        }
    }
    printf("%d",mxw+mxb);
}
*/
/*#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int i;
    vector<int> choice(n+1);
    for(i=1;i<=n;i++)scanf("%d",&choice[i]);
    vector<int> team(n+1,0);
    for(i=1;i<=n;i++)if(choice[i]==i)team[i]=10000000;
    int ans=0,turn=1;
    for(i=1;i<=n;i++){
        //printf("%d\n",i);
        if(team[i]==10000000)continue;
        int now=i,cnt=0,ch[100001]={0,};
        while(team[now]==0){
            cnt++;
            ch[now]=cnt;
            team[now]=turn;
            now=choice[now];
        }
        if(team[now]==10000000){
            turn++;
        }
        else if(team[now]==turn){
            int j=choice[now];
            while(j!=now){
                team[j]=10000000;
                j=choice[j];
            }
            team[now]=10000000;
            turn++;
        }
        else{
            turn++;
        }
    }
    for(i=1;i<=n;i++){printf("x%d\n",team[i]);if(team[i]!=10000000)ans++;}
    printf("%d\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
}
*/

/*#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int i;
    vector<int> choice(n+1);
    for(i=1;i<=n;i++)scanf("%d",&choice[i]);
    vector<int> team(n+1,0);
    int ans=n,turn=1;
    for(i=1;i<=n;i++){
        if(team[i]==1)continue;
        int tu=turn,j=i;
        while(!team[j]){
            team[j]=turn++;
            j=choice[j];
        }
        if(team[j]>=tu){
            ans-=turn-team[j];
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
}
*/

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    if(a==0)return b;
    if(b==0)return a;
    return gcd(b,a%b);
}
vector<ll> change(pair<ll,ll> a,pair<ll,ll> b){
    ll p,q,r;
    p=(b.second-a.second);
    q=a.first-b.first;
    r=a.second*(b.first-a.first)-a.first*(b.second-a.second);
    if(p<0){
        p=-p;
        q=-q;
        r=-r;
    }
    vector<ll> ans(3);

    ll g=gcd(gcd(abs(p),abs(q)),abs(r));
    //printf("%d %d %d %d\n",p,q,r,g);
    if(g==0)g=1;
    ans[0]=p/g;
    ans[1]=q/g;
    ans[2]=r/g;
    return ans;
}
ll val(vector<ll> a,pair<ll,ll> b){
    ll ret=(a[0]*b.first+a[1]*b.second+a[2]);
    if(ret<0)return -1;
    else if(ret==0)return 0;
    else return 1;
}
int f(vector<pair<ll,ll>> a){
    auto ans1=change(a[0],a[1]);
    ll val1=val(ans1,a[2]);
    ll val2=val(ans1,a[3]);
    if(val1*val2>0){
        return 0;
    }
    auto ans2=change(a[0],a[2]);
    val1=val(ans2,a[1]);
    val2=val(ans2,a[3]);
    if(val1*val2<0){
        return 0;
    }
    auto ans3=change(a[1],a[2]);
    val1=val(ans3,a[0]);
    val2=val(ans3,a[3]);
    if(val1*val2<0){
        return 0;
    }
    auto ans4=change(a[2],a[3]);
    //for(i=0;i<3;i++)printf("%lld %lld\n",ans1[i],ans4[i]);
    if(ans1[0]==ans4[0]&&ans1[1]==ans4[1]&&ans1[2]==ans4[2]){
        //printf("in\n");
        if((max(a[0].first,a[1].first)<min(a[2].first,a[3].first)||min(a[0].first,a[1].first)>max(a[2].first,a[3].first))){
            return 0;
        }
        if(max(a[0].second,a[1].second)<min(a[2].second,a[3].second)||min(a[0].second,a[1].second)>max(a[2].second,a[3].second))return 0;
    }
    return 1;
}
int main(){
    vector<pair<ll,ll>> a(4);
    ll i;
    for(i=0;i<4;i++)scanf("%lld %lld",&a[i].first,&a[i].second);

    ll ch1=f(a);
    vector<pair<ll,ll>> b(4);
    b[0]=a[2];b[1]=a[3];b[2]=a[0];b[3]=a[1];
    if(!ch1){
        printf("0");
        exit(0);
    }
    ch1=f(b);
    if(!ch1){
        printf("0");
        exit(0);
    }

    printf("1");
}*/

/*#include<stdio.h>
#include<algorithm>
int ch[1000001];
int b[1000001];
int f(int n){
    ch[1]=0;
    b[1]=-1;
    for(int i=2;i<=n;i++){
        ch[i]=ch[i-1]+1;
        b[i]=i-1;
        if(i%2==0&&ch[i]>ch[i/2]+1){
            ch[i]=ch[i/2]+1;
            b[i]=i/2;
        }
        if(i%3==0&&ch[i]>ch[i/3]+1){
            ch[i]=ch[i/3]+1;
            b[i]=i/3;
        }
    }
    return ch[n];
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",f(n));
    while(n!=-1){
        printf("%d ",n);
        n=b[n];
    }
}
*/

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,i,a;
    scanf("%d",&k);
    stack<int> s;
    for(i=0;i<k;i++){
        scanf("%d",&a);
        if(a==0)s.pop();
        else s.push(a);
    }
    int b=0;
    while(!s.empty()){
        b+=s.top();
        s.pop();
    }
    printf("%d",b);
}
*/
/*#include<bits/stdc++.h>
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
}*/

/*#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int d[5]={0,1,0,-1,0};
void f(int x,int y,vector<vector<int>> &mp,int m,int n){
    int i;
    for(i=0;i<4;i++){
        int nx=x+d[i];
        int ny=y+d[i+1];
        if(nx<0||nx>=m||ny<0||ny>=n)continue;
        if(mp[nx][ny]==1){mp[nx][ny]=0;f(nx,ny,mp,m,n);}
    }
    return;
}
void solve(){
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    vector<vector<int>> mp(m,vector<int> (n,0));
    int i,j,cnt=0;
    for(i=0;i<k;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        mp[a][b]=1;
    }
    for(i=0;i<m;i++)for(j=0;j<n;j++){
        if(mp[i][j]==1){
            mp[i][j]=0;
            f(i,j,mp,m,n);
            cnt++;
        }
    }
    printf("%d\n",cnt);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
}
*/

/*#include<bits/stdc++.h>
using namespace std;
int d[5]={0,-1,0,1,0};
int main(){
    int m,n,i,j,mx=-1;
    scanf("%d %d",&m,&n);
    vector<vector<int>> mp(n,vector<int> (m));
    queue<pair<int,pair<int,int>>> q;
    for(i=0;i<n;i++)for(j=0;j<m;j++){scanf("%d",&mp[i][j]);if(mp[i][j]==1)q.push({0,{i,j}});}
    while(!q.empty()){
        int x=q.front().second.first;
        int y=q.front().second.second;
        int time=q.front().first;
        if(mx<time)mx=time;
        q.pop();
        for(j=0;j<4;j++){
            if(x+d[j]<0||x+d[j]>=n||y+d[j+1]<0||y+d[j+1]>=m)continue;
            if(mp[x+d[j]][y+d[j+1]]==0){
                mp[x+d[j]][y+d[j+1]]=1;

                q.push({time+1,{x+d[j],y+d[j+1]}});
            }
        }
    }
    int ch=1;
    for(i=0;i<n;i++)for(j=0;j<m;j++){
        if(mp[i][j]==0)ch=0;
    }
    if(ch==0)printf("-1");
    else printf("%d",mx);
}
*/

/*#include<bits/stdc++.h>
using namespace std;
vector<int> parent,r;
int f(int u){
    if(parent[u]==u)return u;
    return parent[u]=f(parent[u]);
}
void uni(int u,int v){
    u=f(u);
    v=f(v);
    if(u==v)return;
    if(r[u]>r[v])swap(u,v);
    parent[u]=v;
    if(r[u]==r[v])r[v]++;
    return;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    parent.resize(n+1);
    r.resize(n+1);
    int i,ch=-1;
    for(i=1;i<=n;i++){
        parent[i]=i;
        r[i]=1;
    }
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(f(a)==f(b)&&ch==-1){
            ch=printf("%d",i+1);
        }
        else uni(a,b);
    }
    if(ch==-1)printf("0");
}
*/

/*#include<bits/stdc++.h>
using namespace std;
vector<int> parent,r;
int f(int u){
    if(u==-1)return -1;
    if(parent[u]==u)return u;
    return parent[u]=f(parent[u]);
}
void uni(int u,int v){
    u=f(u);
    v=f(v);
    if(u==v)return;
    //if(r[u]>r[v])swap(u,v);
    parent[u]=v;
    //if(r[u]==r[v])r[v]++;
    return;
}
int main(){
    int g,p;
    scanf("%d %d",&g,&p);
    vector<int> gi(g);
    int i,ans=0,ch=-1;
    parent.resize(g+1);
    r.resize(g+1);
    for(i=0;i<=g;i++){
        parent[i]=i;
        r[i]=1;
    }
    //parent[0]=0;
    //parent[1]=0;
    for(i=0;i<p;i++){
        scanf("%d",&gi[i]);
        if(ch!=-1)continue;
        if(f(gi[i])==0){
            ch=printf("%d",ans);
        }
        else {uni(gi[i],f(gi[i])-1);ans++;}
    }
    if(ch==-1)printf("%d",ans);
}
*/

/*#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
int f(int u){
    if(u==-1)return -1;
    if(parent[u]==u)return u;
    return parent[u]=f(parent[u]);
}
void uni(int u,int v){
    u=f(u);
    v=f(v);
    if(u==v)return;
    parent[u]=v;
    return;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    parent.resize(n+1);

    int t,tr[50],i,j,ans=m,b[50][50],a[50];
    for(i=0;i<=n;i++)parent[i]=i;
    scanf("%d",&t);
    for(i=0;i<t;i++){scanf("%d",&tr[i]);}
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
        int ch=0;
        scanf("%d",&b[0][i]);
        for(j=1;j<a[i];j++){
            scanf("%d",&b[j][i]);
            uni(b[j][i],b[0][i]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<t;j++){
            if(f(b[0][i])==f(tr[j])){
                ans--;
                break;
            }
        }
    }
    printf("%d",ans);
}
*/

/*#include<bits/stdc++.h>
using namespace std;
vector<int> parent,money;
int f(int u){
    if(parent[u]==u)return u;
    return parent[u]=f(parent[u]);
}
void uni(int u,int v){
    u=f(u);
    v=f(v);
    if(u==v)return;
    if(money[u]<money[v])parent[v]=u;
    else parent[u]=v;
    return;
}
int main(){
    int n,m,k,i,j;
    scanf("%d %d %d",&n,&m,&k);
    vector<int> ch(n+1,0);
    parent.resize(n+1);
    money.resize(n+1);
    for(i=1;i<=n;i++){
        scanf("%d",&money[i]);
        parent[i]=i;
    }
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        uni(a,b);
    }
    int charge=0;
    for(i=1;i<=n;i++){
        if(ch[f(i)]==0){
            charge+=money[f(i)];
            ch[f(i)]=1;
        }
    }
    if(charge<=k)printf("%d",charge);
    else printf("Oh no");
}
*/
/**#include<bits/stdc++.h>
#define pii pair<int,int>
#define ch(x,y,j) if(x+d[j]<0||x+d[j]>=rr||y+d[j+1]<0||y+d[j+1]>=c)continue;
using namespace std;
int d[5]={0,1,0,-1,0},rr,c;
vector<vector<pii>> parent;
vector<vector<int>> r;
vector<string> mp;
pii f(pii u){
    if(parent[u.first][u.second]==u)return u;
    else{
        pii v=f(parent[u.first][u.second]);
        parent[u.first][u.second]=v;
        return v;
    }
    //return parent[u.first][u.second]=f(parent[u.first][u.second]);
}
void uni(pii u){
    mp[u.first][u.second]='.';
    pii x=f(u),y;
    for(int i=0;i<4;i++){
        int nx=u.first+d[i],ny=u.second+d[i+1];
        ch(u.first,u.second,i);
        if(mp[nx][ny]=='.'||mp[nx][ny]=='L'){
            y=f({nx,ny});
            if(x.first!=y.first||x.second!=y.second){parent[y.first][y.second]=x;}
        }
    }
    return;
}
int main(){
    int i,j,k;
    ifstream in;
    ofstream out;
    out.open("out.txt");
    in.open("in.txt");
    cin>>rr>>c;
    parent.resize(rr);
    r.resize(rr);
    mp.resize(rr);
    for(i=0;i<rr;i++){
        parent[i].resize(c);
        r[i].resize(c);
        for(j=0;j<c;j++){
            parent[i][j]={i,j};
            r[i][j]=1;
        }
    }
    for(i=0;i<rr;i++){
        cin>>mp[i];
    }
    vector<pii> sw;
    for(i=0;i<rr;i++){
        for(j=0;j<c;j++){
            if(mp[i][j]=='L')sw.push_back({i,j});
        }
    }
    vector<vector<int>> check(rr,vector<int> (c));
    queue<pii> imq;
    vector<vector<pii>> nextmelt;
    vector<pii> forunion;
    for(i=0;i<rr;i++){
        for(j=0;j<c;j++){
            if((mp[i][j]=='.'||mp[i][j]=='L')&&check[i][j]==0){
                int urg=0;
                if(mp[i][j]=='L')urg=1;
                imq.push({i,j});
                forunion.push_back({i,j});
                pii now={i,j};
                nextmelt.push_back({{-1,-1}});
                check[i][j]=1;
                while(!imq.empty()){
                    int nowx=imq.front().first;
                    int nowy=imq.front().second;
                    imq.pop();
                    uni({nowx,nowy});
                    for(k=0;k<4;k++){
                        ch(nowx,nowy,k);
                        if(urg&&(nowx==i&&nowy==j)){
                            if((mp[nowx+d[k]][nowy+d[k+1]]=='.'||mp[nowx+d[k]][nowy+d[k+1]]=='L')){
                            imq.push({nowx+d[k],nowy+d[k+1]});
                            check[nowx+d[k]][nowy+d[k+1]]=1;
                        }
                        if(mp[nowx+d[k]][nowy+d[k+1]]=='X'){
                            //if(check[nowx+d[k]][nowy+d[k+1]]==0){
                                nextmelt.back().push_back({nowx+d[k],nowy+d[k+1]});
                                check[nowx+d[k]][nowy+d[k+1]]=1;
                            //}
                        }
                        }
                        else{if(check[nowx+d[k]][nowy+d[k+1]]!=0)continue;
                        if((mp[nowx+d[k]][nowy+d[k+1]]=='.'||mp[nowx+d[k]][nowy+d[k+1]]=='L')){
                            imq.push({nowx+d[k],nowy+d[k+1]});
                            check[nowx+d[k]][nowy+d[k+1]]=1;
                        }
                        if(mp[nowx+d[k]][nowy+d[k+1]]=='X'){
                            //if(check[nowx+d[k]][nowy+d[k+1]]==0){
                                nextmelt.back().push_back({nowx+d[k],nowy+d[k+1]});
                                check[nowx+d[k]][nowy+d[k+1]]=1;
                            //}
                        }}
                    }
                }
            }
        }
    }
    //for(auto &i:forunion)printf("\nforunion - %d %d\n",i.first,i.second);
    int day=0;
    while(1){


        _sleep(500);
        for(i=0;i<rr;i++)cout<<mp[i]<<"\n";
        for(i=0;i<rr;i++){
            for(j=0;j<c;j++)printf("(%d %d) ",f({i,j}).first,f({i,j}).second);
            printf("\n");
        }
        //printf("\n");
        printf("x-%d %d %d %d\n",f(sw[0]).first,f(sw[0]).second,f(sw[1]).first,f(sw[1]).second);

        int siz=(int)nextmelt.size();
        printf("size - %d\n\n",siz);
        for(auto &i:nextmelt){
            for(auto &j:i)cout<<"next - "<<j.first<<' '<<j.second<<"\n";//{printf("next - %d %d\n",j.first,j.second);}
        }
//cout<<day<<" - check\n";


        if(f(sw[0])==f(sw[1]))break;

        vector<vector<pii>> nm=nextmelt;
        nextmelt.clear();
        for(i=0;i<nm.size();i++){
            nextmelt.push_back({{-1,-1}});
            pii now=forunion[i];
            for(auto &j:nm[i]){
                int nowx=j.first;
                int nowy=j.second;
                if(nowx==-1&&nowy==-1)continue;

                uni({nowx,nowy});
                //if(mp[nowx][nowy]=='.')continue;
                //mp[nowx][nowy]='.';
                for(k=0;k<4;k++){
                    ch(j.first,j.second,k);
                    if(check[nowx+d[k]][nowy+d[k+1]]!=0)continue;
                    if(mp[nowx+d[k]][nowy+d[k+1]]=='X'){
                        nextmelt.back().push_back({nowx+d[k],nowy+d[k+1]});
                        check[nowx+d[k]][nowy+d[k+1]]=1;
                    }
                }
            }
        }

        day++;
    }
    for(i=0;i<rr;i++){
        for(j=0;j<c;j++){
            //printf("%d",check[i][j]);
        }
        //printf("\n");
    }

    cout<<day;
}
**/

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> parent,rnk;
ll fi(ll u){
    if(parent[u]==u)return u;
    return parent[u]=fi(parent[u]);
}
void uni(ll u,ll v){
    u=fi(u);
    v=fi(v);
    if(u==v)return;
    if(rnk[u]>rnk[v]){
        parent[v]=u;
        rnk[u]+=rnk[v];
    }
    else{
        parent[u]=v;
        rnk[v]+=rnk[u];
    }
    return;
}
*/
/*ll gcd(ll a,ll b){
    if(a==0)return b;
    if(b==0)return a;
    return gcd(b,a%b);
}

vector<ll> change(pair<ll,ll> a,pair<ll,ll> b){
    ll p,q,r;
    p=(b.second-a.second);
    q=a.first-b.first;
    r=a.second*(b.first-a.first)-a.first*(b.second-a.second);
    if(p<0){
        p=-p;
        q=-q;
        r=-r;
    }
    vector<ll> ans(3);

    //ll g=gcd(gcd(abs(p),abs(q)),abs(r));
    //printf("%d %d %d %d\n",p,q,r,g);
    //if(g==0)g=1;
    ans[0]=p;
    ans[1]=q;
    ans[2]=r;
    return ans;
}
ll val(vector<ll> a,pair<ll,ll> b){
    ll ret=(a[0]*b.first+a[1]*b.second+a[2]);
    if(ret<0)return -1;
    else if(ret==0)return 0;
    else return 1;
}
ll f(vector<pair<ll,ll>> a){
    vector<ll> ans1=change(a[0],a[1]);
    ll val1=val(ans1,a[2]);
    ll val2=val(ans1,a[3]);
    if(val1*val2>0){
        return 0;
    }
    vector<ll> ans2=change(a[0],a[2]);
    val1=val(ans2,a[1]);
    val2=val(ans2,a[3]);
    if(val1*val2<0){
        return 0;
    }
    vector<ll> ans3=change(a[1],a[2]);
    val1=val(ans3,a[0]);
    val2=val(ans3,a[3]);
    if(val1*val2<0){
        return 0;
    }
    vector<ll> ans4=change(a[2],a[3]);
    //for(i=0;i<3;i++)printf("%lld %lld\n",ans1[i],ans4[i]);
    if(ans1[0]==ans4[0]&&ans1[1]==ans4[1]&&ans1[2]==ans4[2]){
        //printf("in\n");
        if((max(a[0].first,a[1].first)<min(a[2].first,a[3].first)||min(a[0].first,a[1].first)>max(a[2].first,a[3].first))){
            return 0;
        }
        if(max(a[0].second,a[1].second)<min(a[2].second,a[3].second)||min(a[0].second,a[1].second)>max(a[2].second,a[3].second))return 0;
    }
    return 1;
}
ll check(vector<pair<ll,ll>> p, vector<pair<ll,ll>> q){
    vector<pair<ll,ll>> a(4);
    a[0]=p[0];
    a[1]=p[1];
    a[2]=q[0];
    a[3]=q[1];
    ll i;

    ll ch1=f(a);
    vector<pair<ll,ll>> b(4);
    b[0]=a[2];b[1]=a[3];b[2]=a[0];b[3]=a[1];
    if(!ch1){
        return 0;
    }
    ch1=f(b);
    if(!ch1){
        return 0;
    }

    return 1;
}*/
/*ll CCW(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3)
{
	ll temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;

	temp = temp - p1.second * p2.first - p2.second * p3.first - p3.second * p1.first;

	if (temp > 0) return 1; // 반시계
	else if (temp == 0) return 0; // 일직선
	else if (temp < 0) return -1; // 시계
}

ll check(vector<pair<ll,ll>> a,vector<pair<ll,ll>> b) {


	pair<ll, ll> A;
	pair<ll, ll> B;
	pair<ll, ll> C;
	pair<ll, ll> D;
	A=a[0];
	B=a[1];
	C=b[0];
	D=b[1];

	//ABC
	ll abc = CCW(A,B,C);
	//ABD
	ll abd = CCW(A,B,D);
	//CDA
	ll cda = CCW(C,D,A);
	//CDB
	ll cdb = CCW(C,D,B);

	if (abc * abd == 0 && cda * cdb == 0)
	{
		if (A > B)swap(A, B);
		if (C > D)swap(C, D);
		//first 비교가 아닌 것은 x가 같고 y가 달라서 일직선일 수 있으므로..
		if (A <= D && C <= B)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		return 0;
	}


	if (abc * abd <= 0 && cda * cdb <= 0)
	{
		return 1;
	}
	else
		return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    ll n;
    cin>>n;
    ll i,j;
    parent.resize(n);
    rnk.resize(n);
    for(i=0;i<n;i++){parent[i]=i;rnk[i]=1;}
    vector<vector<pair<ll,ll>>> dot(n,vector<pair<ll,ll>> (2));
    for(i=0;i<n;i++){
        //scanf("%lld %lld %lld %lld",&dot[i][0].first,&dot[i][0].second,&dot[i][1].first,&dot[i][1].second);
        cin>>dot[i][0].first>>dot[i][0].second>>dot[i][1].first>>dot[i][1].second;
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(check(dot[i],dot[j])==1){
                //if(fi(dot[i])))
                //cout<<i<<' '<<j<<"\n";
                uni(i,j);
            }
        }
    }

    vector<ll> p(n,0);
    for(i=0;i<n;i++)ll imsi=fi(i);
    for(i=0;i<n;i++){
        //cout<<parent[i]<<"\n";
        p[fi(i)]++;
    }
    ll mx=-1,cnt=0;
    for(i=0;i<n;i++){
        if(parent[i]==i)cnt++;
        if(mx<p[i])mx=p[i];
    }
    cout<<cnt<<"\n"<<mx;
}*/

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    if(a==0)return b;
    if(b==0)return a;
    return gcd(b,a%b);
}
vector<ll> change(pair<ll,ll> a,pair<ll,ll> b){
    ll p,q,r;
    p=(b.second-a.second);
    q=a.first-b.first;
    r=a.second*(b.first-a.first)-a.first*(b.second-a.second);
    if(p<0){
        p=-p;
        q=-q;
        r=-r;
    }
    else if(p==0){
        if(q<0){
            q=-q;
            r=-r;
        }
    }
    vector<ll> ans(3);

    ll g=gcd(gcd(abs(p),abs(q)),abs(r));
    if(g==0)g=1;
    ans[0]=p/g;
    ans[1]=q/g;
    ans[2]=r/g;
    return ans;
}
ll val(vector<ll> a,pair<ll,ll> b){
    ll ret=(a[0]*b.first+a[1]*b.second+a[2]);
    if(ret<0)return -1;
    else if(ret==0)return 0;
    else return 1;
}
int f(vector<pair<ll,ll>> a){
    auto ans1=change(a[0],a[1]);
    ll val1=val(ans1,a[2]);
    ll val2=val(ans1,a[3]);
    if(val1*val2>0){
        return 0;
    }
    auto ans2=change(a[0],a[2]);
    val1=val(ans2,a[1]);
    val2=val(ans2,a[3]);
    if(val1*val2<0){
        return 0;
    }
    auto ans3=change(a[1],a[2]);
    val1=val(ans3,a[0]);
    val2=val(ans3,a[3]);
    if(val1*val2<0){
        return 0;
    }
    auto ans4=change(a[2],a[3]);
    //for(ll i=0;i<3;i++)printf("%lld %lld\n",ans1[i],ans4[i]);
    if(ans1[0]==ans4[0]&&ans1[1]==ans4[1]&&ans1[2]==ans4[2]){
        //printf("in - %lld %lld %lld %lld\n",a[2].first,a[2].second,a[3].first,a[3].second);
        if((max(a[0],a[1])<min(a[2],a[3])||min(a[0],a[1])>max(a[2],a[3]))){
            return 0;
        }
        //if(max(a[0].second,a[1].second)<min(a[2].second,a[3].second)||min(a[0].second,a[1].second)>max(a[2].second,a[3].second))return 0;
    }
    return 1;
}
pair<double,double> eq(vector<ll> v1, vector<ll> v2)
{
    int i;
    vector<double> var1(3);
    vector<double> var2(3);
    vector<double> t_var1(3);
    vector<double> t_var2(3);
    for(i=0;i<3;i++){
        var1[i]=(double)v1[i];
        var2[i]=(double)v2[i];
    }
    double x, y;
    for(int i = 0; i < 3; i++)
    {
        t_var1[i] = var1[i] * var2[0];
        t_var2[i] = var2[i] * var1[0];
    }
    if(var1[0] != 0)
    {
        y = (t_var2[2] - t_var1[2]) / (t_var2[1] - t_var1[1]);
        x = (var1[2] - var1[1] * y) / var1[0];
    }
    else
    {
        y = var1[2] / var1[1];
        x = (var2[2] - var2[1] * y) / var2[0];
    }
    return {x,y};
}
int main(){
    vector<pair<ll,ll>> a(4);
    ll i;
    for(i=0;i<4;i++)scanf("%lld %lld",&a[i].first,&a[i].second);

    ll ch1=f(a);
    vector<pair<ll,ll>> b(4);
    b[0]=a[2];b[1]=a[3];b[2]=a[0];b[3]=a[1];
    if(!ch1){
        printf("0");
        exit(0);
    }
    ll ch2=f(b);
    if(!ch2){
        printf("0");
        exit(0);
    }
    printf("1");
    auto cmp1=change(a[0],a[1]);
    auto cmp2=change(a[2],a[3]);
    if(cmp1!=cmp2){
        cmp1[2]*=-1;
        cmp2[2]*=-1;
        auto ans=eq(cmp1,cmp2);
        printf("\n%.9lf %.9lf",ans.first,ans.second);
    }
    else{
        if((max(a[0],a[1])==min(a[2],a[3]))){
            pair<int,int> ans=max(a[0],a[1]);
            printf("\n%lld %lld",ans.first,ans.second);
            exit(0);
        }
        else if(min(a[0],a[1])==max(a[2],a[3])){
            pair<int,int> ans=min(a[0],a[1]);
            printf("\n%lld %lld",ans.first,ans.second);
            exit(0);
        }
        else exit(0);
    }

}*/


/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    if(a==0)return b;
    if(b==0)return a;
    return gcd(b,a%b);
}
vector<ll> change(pair<ll,ll> a,pair<ll,ll> b){
    ll p,q,r;
    p=(b.second-a.second);
    q=a.first-b.first;
    r=a.second*(b.first-a.first)-a.first*(b.second-a.second);
    if(p<0){
        p=-p;
        q=-q;
        r=-r;
    }
    else if(p==0){
        if(q<0){
            q=-q;
            r=-r;
        }
    }
    vector<ll> ans(3);

    ll g=gcd(gcd(abs(p),abs(q)),abs(r));
    if(g==0)g=1;
    ans[0]=p/g;
    ans[1]=q/g;
    ans[2]=r/g;
    return ans;
}
ll val(vector<ll> a,pair<ll,ll> b){
    ll ret=(a[0]*b.first+a[1]*b.second+a[2]);
    if(ret<0)return -1;
    else if(ret==0)return 0;
    else return 1;
}
int f(vector<pair<ll,ll>> a){
    auto ans1=change(a[0],a[1]);
    ll val1=val(ans1,a[2]);
    ll val2=val(ans1,a[3]);
    if(val1*val2>0){
        return 0;
    }
    auto ans2=change(a[0],a[2]);
    val1=val(ans2,a[1]);
    val2=val(ans2,a[3]);
    if(val1*val2<0){
        return 0;
    }
    auto ans3=change(a[1],a[2]);
    val1=val(ans3,a[0]);
    val2=val(ans3,a[3]);
    if(val1*val2<0){
        return 0;
    }
    auto ans4=change(a[2],a[3]);
    if(ans1[0]==ans4[0]&&ans1[1]==ans4[1]&&ans1[2]==ans4[2]){
        if((max(a[0],a[1])<min(a[2],a[3])||min(a[0],a[1])>max(a[2],a[3]))){
            return 0;
        }

    }
    return 1;
}
ll solve(vector<pair<ll,ll>> a){
    ll ch1=f(a);
    vector<pair<ll,ll>> b(4);
    b[0]=a[2];b[1]=a[3];b[2]=a[0];b[3]=a[1];
    if(!ch1){
        return 0;
    }
    ll ch2=f(b);
    if(!ch2){
        return 0;
    }
    return 1;
}
ll in(pair<ll,ll> line, vector<pair<ll,ll>> a){
    ll minx=min(a[0].first,a[2].first);
    ll maxx=max(a[0].first,a[2].first);
    ll miny=min(a[0].second,a[2].second);
    ll maxy=max(a[0].second,a[2].second);

    if(line.first>=minx&&line.first<=maxx){
        if(line.second>=miny&&line.second<=maxy)return 1;
    }
    return 0;
}
//ifstream iin;

void answer(){
    //vector<pair<ll,ll>> a(4);
    ll i,j;

    //for(i=0;i<4;i++)scanf("%lld %lld",&a[i].first,&a[i].second);
    vector<pair<ll,ll>> line(4);
    for(i=2;i<4;i++)cin>>line[i].first>>line[i].second;//scanf("%lld %lld",&line[i].first,&line[i].second);
    vector<pair<ll,ll>> a(4);
    cin>>a[0].first>>a[0].second>>a[2].first>>a[2].second;
    //scanf("%lld %lld %lld %lld",&a[0].first,&a[0].second,&a[2].first,&a[2].second);
    a[1].first=a[0].first;a[1].second=a[2].second;
    a[3].first=a[2].first;a[3].second=a[0].second;


    //for(i=0;i<4;i++)printf("aa - %lld %lld\n",a[i].first,a[i].second);
    for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            line[j]=a[(i+j)%4];
        }

        if(solve(line)==1){
            printf("T\n",i);
            return;
        }
    }
    if(in(line[2],a)==1&&in(line[3],a)==1){
        printf("T\n");
        return;
    }
    printf("F\n");
}
int main(){
    int t;
    //iin.open("in.txt");
    cin>>t;
    while(t--){
        answer();
    }

}
*/


/**#include <stdio.h>
#include <assert.h>


#define TRUE 1
#define FALSE 0

typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	Point p1;
	Point p2;
} Line;

typedef struct {
	Point topLeft;
	Point bottomRight;
} Rectangle;


int ccw( Point p0, Point p1, Point p2 );
bool intersect( Line l1, Line l2 );
bool intersectRect( Rectangle r, Line l );



int ccw( Point p0, Point p1, Point p2 )
{
	int dx1, dx2, dy1, dy2;

	dx1 = p1.x - p0.x; dy1 = p1.y - p0.y;
	dx2 = p2.x - p0.x; dy2 = p2.y - p0.y;

	if (dx1*dy2 > dy1*dx2)
		return +1;
	if (dx1*dy2 < dy1*dx2)
		return -1;
	if ((dx1*dx2 < 0) || (dy1*dy2 < 0))
		return -1;
	if ((dx1*dx1 + dy1*dy1) < (dx2*dx2 + dy2*dy2))
		return +1;
	return 0;
}




bool intersect( Line line1, Line line2 )
{
	return (( ccw(line1.p1, line1.p2, line2.p1)
			* ccw(line1.p1, line1.p2, line2.p2)) <= 0)
		&& (( ccw(line2.p1, line2.p2, line1.p1)
			* ccw(line2.p1, line2.p2, line1.p2)) <= 0);
}


bool intersectRect( Rectangle rect, Line line )
{
	Line line1, line2, line3, line4;
	int tmp;

	line1.p1 = rect.topLeft;
	line1.p2 = line1.p1; line1.p2.x = rect.bottomRight.x;

	line2.p1 = line1.p2;
	line2.p2 = rect.bottomRight;

	line3.p1 = line2.p2;
	line3.p2 = rect.topLeft; line3.p2.y = rect.bottomRight.y;

	line4.p1 = line3.p2;
	line4.p2 = line1.p1;

	if (intersect(line1, line) || intersect(line2, line)
				|| intersect(line3, line) || intersect(line4, line))
		return TRUE;
	if (rect.bottomRight.x < rect.topLeft.x) {
		tmp = rect.bottomRight.x;
		rect.bottomRight.x = rect.topLeft.x;
		rect.topLeft.x = tmp;
	}
	if (rect.bottomRight.y < rect.topLeft.y) {
		tmp = rect.bottomRight.y;
		rect.bottomRight.y = rect.topLeft.y;
		rect.topLeft.y = tmp;
	}

	return (line.p1.x >= rect.topLeft.x && line.p1.x <= rect.bottomRight.x
		&& line.p1.y >= rect.topLeft.y && line.p1.y <= rect.bottomRight.y);
}


int main( int argc, char* argv[] )
{
	FILE*	fin;
	FILE*	fout;
	int		n, dummy, i;
	Rectangle	rect;
	Line		line;

	fin = fopen("intersection.in", "r");
	assert( fin != 0 );
	fout = fopen("intersection.out", "w");
	assert( fout != 0 );

	dummy = fscanf( fin, "%d", &n );
	assert( dummy == 1 );

	for (i=0; i < n; i++) {
		dummy = fscanf( fin, "%d %d %d %d",
			&line.p1.x, &line.p1.y,
			&line.p2.x, &line.p2.y );
		assert( dummy == 4 );

		dummy = fscanf( fin, "%d %d %d %d",
			&rect.topLeft.x, &rect.topLeft.y,
			&rect.bottomRight.x, &rect.bottomRight.y );
		assert( dummy == 4 );

		fprintf( fout, "%c\n",
			intersectRect( rect, line ) ? 'T' : 'F' );
	}

	fclose( fin );
	fclose( fout );

	return 0;
}
**/
/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    if(a==0)return b;
    if(b==0)return a;
    return gcd(b,a%b);
}
vector<ll> change(pair<ll,ll> a,pair<ll,ll> b){
    ll p,q,r;
    p=(b.second-a.second);
    q=a.first-b.first;
    r=a.second*(b.first-a.first)-a.first*(b.second-a.second);
    if(p<0){
        p=-p;
        q=-q;
        r=-r;
    }
    vector<ll> ans(3);

    ll g=gcd(gcd(abs(p),abs(q)),abs(r));
    //printf("%d %d %d %d\n",p,q,r,g);
    if(g==0)g=1;
    ans[0]=p/g;
    ans[1]=q/g;
    ans[2]=r/g;
    return ans;
}
ll val(vector<ll> a,pair<ll,ll> b){
    ll ret=(a[0]*b.first+a[1]*b.second+a[2]);
    if(ret<0)return -1;
    else if(ret==0)return 0;
    else return 1;
}
int f(vector<pair<ll,ll>> a){
    auto ans1=change(a[0],a[1]);
    ll val1=val(ans1,a[2]);
    ll val2=val(ans1,a[3]);
    if(val1*val2>0){
        return 0;
    }
    auto ans2=change(a[0],a[2]);
    val1=val(ans2,a[1]);
    val2=val(ans2,a[3]);
    if(val1*val2<0){
        return 0;
    }
    auto ans3=change(a[1],a[2]);
    val1=val(ans3,a[0]);
    val2=val(ans3,a[3]);
    if(val1*val2<0){
        return 0;
    }
    auto ans4=change(a[2],a[3]);
    //for(i=0;i<3;i++)printf("%lld %lld\n",ans1[i],ans4[i]);
    if(ans1[0]==ans4[0]&&ans1[1]==ans4[1]&&ans1[2]==ans4[2]){
        //printf("in\n");
        if((max(a[0].first,a[1].first)<min(a[2].first,a[3].first)||min(a[0].first,a[1].first)>max(a[2].first,a[3].first))){
            return 0;
        }
        if(max(a[0].second,a[1].second)<min(a[2].second,a[3].second)||min(a[0].second,a[1].second)>max(a[2].second,a[3].second))return 0;
    }
    return 1;
}
int main(){
    vector<pair<ll,ll>> a(4);
    ll i;
    for(i=0;i<4;i++)scanf("%lld %lld",&a[i].first,&a[i].second);

    ll ch1=f(a);
    vector<pair<ll,ll>> b(4);
    b[0]=a[2];b[1]=a[3];b[2]=a[0];b[3]=a[1];
    if(!ch1){
        printf("0");
        exit(0);
    }
    ch1=f(b);
    if(!ch1){
        printf("0");
        exit(0);
    }

    printf("1");
}
*/

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    if(a==0)return b;
    if(b==0)return a;
    return gcd(b,a%b);
}
vector<ll> change(pair<ll,ll> a,pair<ll,ll> b){
    ll p,q,r;
    p=(b.second-a.second);
    q=a.first-b.first;
    r=a.second*(b.first-a.first)-a.first*(b.second-a.second);
    if(p<0){
        p=-p;
        q=-q;
        r=-r;
    }
    else if(p==0){
        if(q<0){
            q=-q;
            r=-r;
        }
    }
    vector<ll> ans(3);

    ll g=gcd(gcd(abs(p),abs(q)),abs(r));
    if(g==0)g=1;
    ans[0]=p/g;
    ans[1]=q/g;
    ans[2]=r/g;
    return ans;
}
ll val(vector<ll> a,pair<ll,ll> b){
    ll ret=(a[0]*b.first+a[1]*b.second+a[2]);
    if(ret<0)return -1;
    else if(ret==0)return 0;
    else return 1;
}
int f(vector<pair<ll,ll>> a){
    auto ans1=change(a[0],a[1]);
    ll val1=val(ans1,a[2]);
    ll val2=val(ans1,a[3]);
    if(val1*val2>0){
        return 0;
    }
    auto ans2=change(a[0],a[2]);
    val1=val(ans2,a[1]);
    val2=val(ans2,a[3]);
    if(val1*val2<0){
        return 0;
    }
    auto ans3=change(a[1],a[2]);
    val1=val(ans3,a[0]);
    val2=val(ans3,a[3]);
    if(val1*val2<0){
        return 0;
    }
    auto ans4=change(a[2],a[3]);
    if(ans1[0]==ans4[0]&&ans1[1]==ans4[1]&&ans1[2]==ans4[2]){
        if((max(a[0],a[1])<min(a[2],a[3])||min(a[0],a[1])>max(a[2],a[3]))){
            return 0;
        }

    }
    return 1;
}
ll solve(vector<pair<ll,ll>> a){
    ll ch1=f(a);
    vector<pair<ll,ll>> b(4);
    b[0]=a[2];b[1]=a[3];b[2]=a[0];b[3]=a[1];
    if(!ch1){
        return 0;
    }
    ll ch2=f(b);
    if(!ch2){
        return 0;
    }
    return 1;
}
ll in(pair<ll,ll> line, vector<pair<ll,ll>> a){
    ll minx=min(a[0].first,a[2].first);
    ll maxx=max(a[0].first,a[2].first);
    ll miny=min(a[0].second,a[2].second);
    ll maxy=max(a[0].second,a[2].second);

    if(line.first>=minx&&line.first<=maxx){
        if(line.second>=miny&&line.second<=maxy)return 1;
    }
    return 0;
}
//ifstream iin;

void answer(){
    ll i,j;
    ll cnt=0;
    vector<pair<ll,ll>> line(4);
    vector<pair<ll,ll>> a(4);
    cin>>a[0].first>>a[0].second>>a[2].first>>a[2].second;

    a[1].first=a[0].first;a[1].second=a[2].second;
    a[3].first=a[2].first;a[3].second=a[0].second;
    for(i=2;i<4;i++)cin>>line[i].first>>line[i].second;

    //for(i=0;i<4;i++)printf("aa - %lld %lld\n",a[i].first,a[i].second);
    for(i=0;i<4;i++){
        for(j=0;j<2;j++){
            line[j]=a[(i+j)%4];
        }

        if(solve(line)==1){
        auto cmp1=change(line[0],line[1]);
        auto cmp2=change(line[2],line[3]);
        if(cmp1!=cmp2){
            cnt++;
        }
        else{
            if((max(line[0],line[1])==min(line[2],line[3]))){
            cnt++;
        }
        else if(min(line[0],line[1])==max(line[2],line[3])){
            cnt++;
        }
        else{printf("4\n");return;}
        }
        }
    }
    auto ans=change(line[2],line[3]);
    for(i=0;i<4;i++){
        ll ret=(ans[0]*a[i].first+ans[1]*a[i].second+ans[2]);
        if(ret==0){
            if(a[i]>=min(line[2],line[3])&&a[i]<=max(line[2],line[3])){
                cnt--;
            }
        }
    }
    printf("%lld\n",cnt<0?0:cnt);
}
int main(){
    int t;
    cin>>t;
    while(t--)answer();
}*/

/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isStair(int n){
    string a=to_string(n);
    int i;
    for(i=1;i<a.size();i++){
        if(a[i-1]==a[i])return false;
    }
    return true;
}
int digit(int n){
    int d=0;
    while(n>0){
        n/=10;
        d++;
    }
    return d;
}
int main(){
    string c;

    cin>>c;
    ll ans=0,siz=(ll)c.size(),i,j;
    vector<ll> dp1(siz,0);
    vector<ll> dp2(siz,0);
    dp1[0]=(ll)(c[0]-'0')+1;
    dp2[0]=9-(ll)(c[0]-'0');
    for(i=1;i<siz-1;i++){
        dp1[i]=dp1[i-1]*9
        dp2[i]=
    }
    cout<<ans;
}*/

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,z[90]={1,},o[90]={1,},i;
    scanf("%lld",&n);
    for(i=1;i<n;i++){
        z[i]=z[i-1]+o[i-1];
        o[i]=z[i-1];
    }
    printf("%lld",o[n-1]);
}
*/
/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>> a;
bool ans=false;
int nx,len;
void f(int n,int cnt,vector<int> ch){
    if(cnt==4){ans=true;return;}
    if(cnt>len){
        nx=n;
        len=cnt;
    }
    for(int i=0;i<a[n].size();i++){
        if(ch[a[n][i]]==0){
            ch[a[n][i]]=1;
            f(a[n][i],cnt+1,ch);
            ch[a[n][i]]=0;
        }
    }
    return;
}
int main(){
    int n,m,i;
    cin>>n>>m;
    a.resize(n);
    for(i=0;i<m;i++){
        int p,q;
        cin>>p>>q;
        a[p].push_back(q);
        a[q].push_back(p);
    }
        vector<int> ch(n,0);
        ch[0]=1;
        f(0,0,ch);
    if(!ans){
        fill(ch.begin(),ch.end(),0);
        ch[nx]=1;
        f(nx,0,ch);
    }
    cout<<ans;
}
*/
/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> a;
int f(int st,int en,int node,int check,vector<int> &tree){
    if(st==en)return tree[node-1]=a[st];
    int mid=(st+en)/2;
    if(check==1)return tree[node-1]=max(f(st,mid,node*2,check,tree),f(mid+1,en,node*2+1,check,tree));
    else if(check==2)return tree[node-1]=min(f(st,mid,node*2,check,tree),f(mid+1,en,node*2+1,check,tree));
}
int findm(int st,int en,int node,int l,int r,int check,vector<int> &tree){
    if(l>en||r<st)return -1;
    if(l<=st&&en<=r)return tree[node-1];
    int mid=(st+en)/2;
    if(check==1){
        return max(findm(st,mid,node*2,l,r,check,tree),findm(mid+1,en,node*2+1,l,r,check,tree));
    }
    else if(check==2){
        int a=findm(st,mid,node*2,l,r,check,tree);
        int b=findm(mid+1,en,node*2+1,l,r,check,tree);
        if(a==-1)return b;
        else if(b==-1)return a;
        else return min(a,b);
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    a.resize(n);
    vector<int> xtree(4*n,0);
    vector<int> ntree(4*n,0);
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    f(0,n-1,1,1,xtree);
    f(0,n-1,1,2,ntree);
    for(auto &i:xtree)printf("%d ",i);
    printf("\n");
    for(auto &i:ntree)printf("%d ",i);
    printf("\n");
    for(i=0;i<m;i++){
        int p,q;
        scanf("%d %d",&p,&q);
        int ansx=findm(0,n-1,1,p-1,q-1,1,xtree);
        int ansn=findm(0,n-1,1,p-1,q-1,2,ntree);
        printf("%d %d\n",ansn,ansx);
    }
}
*/

/*#include<stdio.h>
#include<vector>
#include<math.h>
#define ll long long
#define vll vector<ll>
#define mod 1000000007
using namespace std;
ll p(ll a,ll b){
    ll ex=mod-2,ans=1;
    while(ex){
        if(ex%2){
            ans*=a;
            ans%=mod;
        }
        ex/=2;
        a*=a;
        a%=mod;
    }
    return (ans*b)%mod;
}
ll f(vll &arr,vll &t,int node,int st,int en){

    if(st==en){
        return t[node]=arr[st];
    }

    int mid=(st+en)/2;
    return t[node]=(f(arr,t,node*2,st,mid)*f(arr,t,node*2+1,mid+1,en))%mod;
}
void f1(vll &arr,vll &t,int node,int st,int en,int goal,ll nw){
//printf("s%d %d %d\n",node,st,en);
     //if(goal<st||goal>en)return t[node];
     //if(st==en)return t[node]=arr[goal]=nw;
    if(goal<st||goal>en)return;
     if(st==en){
        int mold=arr[goal];
        if(mold==0)mold=1;
        int mt=t[node];
        if(mt==0)mt=1;
        t[node]=mt*p(mold,nw)%mod;
     }

     if(st!=en){
        int mid=(st+en)/2;
        f1(arr,t,node*2,st,mid,goal,nw);
        f1(arr,t,node*2+1,mid+1,en,goal,nw);
     t[node]=t[node*2]*t[node*2+1];

     }
     //
     //return t[node]=(f1(arr,t,node*2,st,mid,goal,nw)*f1(arr,t,node*2+1,mid+1,en,goal,nw))%mod;
}
ll f2(vll &t, int node, int st, int en, int start, int end){
    int mid=(st+en)/2;
    if(en<start)return 1;
    if(end<st)return 1;
    if(start<=st&&en<=end){
        return t[node];
    }
    return (f2(t,node*2,st,mid,start,end)*f2(t,node*2+1,mid+1,en,start,end))%mod;
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int i;
    vll arr(n),t(4*n,0);
    ll sum=0;
    for(i=0;i<n;i++){
        ll imsi;
        scanf("%lld",&arr[i]);
    }
    sum=f(arr,t,1,0,n-1);
for(auto &i:t)printf("%lld ",i);
    printf("\n");
    for(i=0;i<m+k;i++){
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);

        if(a==1){
            f1(arr,t,1,0,n-1,b-1,c);
            arr[b-1]=c;
        }
        if(a==2)printf("%lld\n",(f2(t,1,0,n-1,b-1,c-1)+mod)%mod);
for(auto &i:t)printf("%lld ",i);
    printf("\n");
    }//for(auto &j:arr)printf("a%lld\n",j);
}
*/
/*#include<bits/stdc++.h>
#define ll long long
#define MX 1000000001
#define pii pair<int,int>
using namespace std;
vector<int> a;
pii f(int st,int en,int node,int check,vector<pii> &tree){
    if(st==en)return tree[node-1]={a[st],st};
    int mid=(st+en)/2;
    return tree[node-1]=min(f(st,mid,node*2,check,tree),f(mid+1,en,node*2+1,check,tree));
}
pii findm(int st,int en,int node,int l,int r,int check,vector<pii> &tree){
    if(l>en||r<st)return {MX,-1};
    if(l<=st&&en<=r)return tree[node-1];
    int mid=(st+en)/2;
        pii a=findm(st,mid,node*2,l,r,check,tree);
        pii b=findm(mid+1,en,node*2+1,l,r,check,tree);
        if(a.second==-1)return b;
        else if(b.second==-1)return a;
        else return min(a,b);
}
pii f1(vector<int> &arr,vector<pii> &t,int node,int st,int en,int goal,ll nw){
//printf("s%d %d %d\n",node,st,en);
     if(goal<st||goal>en)return t[node-1];
     if(st==en){arr[goal]=nw;return t[node-1]={nw,goal};}
     int mid=(st+en)/2;
     return t[node-1]=min(f1(arr,t,node*2,st,mid,goal,nw),f1(arr,t,node*2+1,mid+1,en,goal,nw));
}
int main(){
    int n,m;
    scanf("%d",&n);
    a.resize(n);
    vector<pii> ntree(4*n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    f(0,n-1,1,2,ntree);
    for(auto &i:ntree)printf("%d ",i);
    printf("\n");
    for(i=0;i<m;i++){
        int o,p,q;
        scanf("%d %d %d",&o,&p,&q);
        if(o==2){pii ansn=findm(0,n-1,1,p-1,q-1,2,ntree);
        printf("%d\n",ansn.second+1);}
        if(o==1){
            f1(a,ntree,1,0,n-1,p-1,q);
        }
    }
}*/

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[1001]={0,1,3},n,i;
    scanf("%d",&n);
    for(i=3;i<=n;i++)a[i]=(2*a[i-2]+a[i-1])%10007;
    printf("%d",a[n]);
}*/

/*#include<stdio.h>
#include<vector>
#include<math.h>
#define ll long long
#define vll vector<ll>
using namespace std;
ll f(vll &arr,vll &t,int node,int st,int en){

    if(st==en){
        return t[node]=arr[st];
    }

    int mid=(st+en)/2;
    return t[node]=f(arr,t,node*2,st,mid)+f(arr,t,node*2+1,mid+1,en);
}
void f1(vll &arr,vll &t,int node,int st,int en,int goal,ll ch){
//printf("s%d %d %d\n",node,st,en);
     if(st==en){
        t[node]+=ch;
        arr[st]+=ch;
        return;
     }
     int mid=(st+en)/2;
     if(goal<=mid){
        t[node]+=ch;
        f1(arr,t,node*2,st,mid,goal,ch);
        return;
     }
     else{
        t[node]+=ch;
        f1(arr,t,node*2+1,mid+1,en,goal,ch);
        return;
     }
}
ll f2(vll &t, int node, int st, int en, int start, int end){
    int mid=(st+en)/2;
    if(en<start)return 0;
    if(end<st)return 0;
    if(start<=st&&en<=end){
        return t[node];
    }
    return f2(t,node*2,st,mid,start,end)+f2(t,node*2+1,mid+1,en,start,end);
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int i;
    vll arr(n),t(4*n);
    ll sum=0;
    for(i=0;i<n;i++){
        ll imsi;
        scanf("%lld",&arr[i]);

    }
    sum=f(arr,t,1,0,n-1);

    for(i=0;i<m+k;i++){
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a==1)f1(arr,t,1,0,n-1,b-1,c-arr[b-1]);
        if(a==2)printf("%lld\n",f2(t,1,0,n-1,b-1,c-1));

    }//for(auto &j:arr)printf("a%lld\n",j);
}*/

/*#include<bits/stdc++.h>
#define pii pair<int,int>
#define MX 1000000001
using namespace std;
vector<pii> c;
vector<vector<int>> distance;
vector<vector<int>> near;
int dist(pii a,pii b){
    return abs(a.first-b.first)+abs(b.second-a.second);
}
int f(int n,int car){
    if(n==0)return 0;
    int x=c[n].first;
    int y=c[n].second;
    int i,mn=MX;
    for(i=0;i<near[n].size();i++){
        int next=near[n][i];
        int ndist=
    }
}
int main(){
    int n,w,i,j;
    scanf("%d %d",&n,&w);
    c.resize(w+3);
    distance.resize(w+1);
    near.resize(w+1);
    for(i=1;i<=w;i++){
        scanf("%d %d",&c[i].first,&c[i].second);
    }
    c[w+1]={1,1};
    c[w+2]={n,n};
    for(i=1;i<=w;i++){
        int mn=MX;
        for(j=1;j<=w+3;j++){
            if(i==j)continue;
            if(mn>dist(c[i],c[j])){
                near[i].clear();

            }
        }
    }
    pii fi={1,1},se={n,n};
    printf("%d",min(f(w,1),f(w,2)));
}
*/

/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,m,k,s,t,i,j,l;
    scanf("%lld %lld %lld %lld %lld",&n,&m,&k,&s,&t);
    vector<vector<pair<ll,ll>>> mp(n+1);
    vector<vector<ll>> dist(n+1,vector<ll>(k+1,-1));
    for(i=0;i<m;i++){
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        mp[a].push_back({b,c});
        mp[b].push_back({a,c});
    }
    for(i=0;i<=k;i++){
        for(j=1;j<=n;j++){
            if(i==0&&j<s)continue;
            else if(i==0&&j==s){dist[j][i]=0;continue;}
            ll mxa=-1,mxb=-1;
            for(auto &l:mp[j]){
                if(l.first<j){
                    //printf("small - %d %d %d\n",dist[l.first][i],l.first,l.second);
                    if(dist[l.first][i]==-1)continue;
                    else mxa=max(mxa,l.second+dist[l.first][i]);
                }
                else if(l.first>j){
                    if(i==0){mxb=-1;continue;}
                    if(dist[l.first][i-1]==-1)continue;

                    else mxb=max(mxb,dist[l.first][i-1]);
                    //printf("big - %d %d %d\n",dist[l.first][i-1],l.first,l.second);
                }
            }
            dist[j][i]=max(mxa,mxb);
        }
    }
    printf("%lld",dist[t][k]);
}
*/
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,a,b,j,k,ch=0;
    scanf("%d %d",&n,&a);
    stack<int> s;
    vector<char> ans;
    for(k=1;k<=a;k++){s.push(k);ans.push_back('+');}
    s.pop();ans.push_back('-');
    for(i=1;i<n;i++){
        scanf("%d",&a);
        int top;
        if(s.size()==0)top=-1;
        else top=s.top();
        if(a==top){
            s.pop();
            ans.push_back('-');
        }
        else if(a>top){
            for(;k<=a;k++){s.push(k);ans.push_back('+');}
            s.pop();
            ans.push_back('-');
        }
        else{
            ch=1;
        }
    }
    if(ch)printf("NO");
    else for(auto &i:ans)printf("%c\n",i);
}
*/
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,a;
    scanf("%d",&n);
    stack<pair<int,int>> s;
    vector<int> ans(n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
            while(!s.empty()&&s.top().first<a){
                ans[s.top().second]=a;
                s.pop();
            }

        s.push({a,i});

    }
    while(!s.empty()){
        ans[s.top().second]=-1;
        s.pop();
    }
    for(auto &i:ans)printf("%d ",i);
}*/

/*#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using lint = long long;
lint ipow(lint x, lint p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}
vector<int> berlekamp_massey(vector<int> x){
	vector<int> ls, cur;
	int lf, ld;
	for(int i=0; i<x.size(); i++){
		lint t = 0;
		for(int j=0; j<cur.size(); j++){
			t = (t + 1ll * x[i-j-1] * cur[j]) % mod;
		}
		if((t - x[i]) % mod == 0) continue;
		if(cur.empty()){
			cur.resize(i+1);
			lf = i;
			ld = (t - x[i]) % mod;
			continue;
		}
		lint k = -(x[i] - t) * ipow(ld, mod - 2) % mod;
		vector<int> c(i-lf-1);
		c.push_back(k);
		for(auto &j : ls) c.push_back(-j * k % mod);
		if(c.size() < cur.size()) c.resize(cur.size());
		for(int j=0; j<cur.size(); j++){
			c[j] = (c[j] + cur[j]) % mod;
		}
		if(i-lf+(int)ls.size()>=(int)cur.size()){
			tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % mod);
		}
		cur = c;
	}
	for(auto &i : cur) i = (i % mod + mod) % mod;
	return cur;
}
int get_nth(vector<int> rec, vector<int> dp, lint n){
	int m = rec.size();
	vector<int> s(m), t(m);
	s[0] = 1;
	if(m != 1) t[1] = 1;
	else t[0] = rec[0];
	auto mul = [&rec](vector<int> v, vector<int> w){
		int m = v.size();
		vector<int> t(2 * m);
		for(int j=0; j<m; j++){
			for(int k=0; k<m; k++){
				t[j+k] += 1ll * v[j] * w[k] % mod;
				if(t[j+k] >= mod) t[j+k] -= mod;
			}
		}
		for(int j=2*m-1; j>=m; j--){
			for(int k=1; k<=m; k++){
				t[j-k] += 1ll * t[j] * rec[k-1] % mod;
				if(t[j-k] >= mod) t[j-k] -= mod;
			}
		}
		t.resize(m);
		return t;
	};
	while(n){
		if(n & 1) s = mul(s, t);
		t = mul(t, t);
		n >>= 1;
	}
	lint ret = 0;
	for(int i=0; i<m; i++) ret += 1ll * s[i] * dp[i] % mod;
	return ret % mod;
}
int guess_nth_term(vector<int> x, lint n){
	if(n < x.size()) return x[n];
	vector<int> v = berlekamp_massey(x);
	if(v.empty()) return 0;
	return get_nth(v, x, n);
}
struct elem{int x, y, v;}; // A_(x, y) <- v, 0-based. no duplicate please..
vector<int> get_min_poly(int n, vector<elem> M){
	// smallest poly P such that A^i = sum_{j < i} {A^j \times P_j}
	vector<int> rnd1, rnd2;
	mt19937 rng(0x14004);
	auto randint = [&rng](int lb, int ub){
		return uniform_int_distribution<int>(lb, ub)(rng);
	};
	for(int i=0; i<n; i++){
		rnd1.push_back(randint(1, mod - 1));
		rnd2.push_back(randint(1, mod - 1));
	}
	vector<int> gobs;
	for(int i=0; i<2*n+2; i++){
		int tmp = 0;
		for(int j=0; j<n; j++){
			tmp += 1ll * rnd2[j] * rnd1[j] % mod;
			if(tmp >= mod) tmp -= mod;
		}
		gobs.push_back(tmp);
		vector<int> nxt(n);
		for(auto &i : M){
			nxt[i.x] += 1ll * i.v * rnd1[i.y] % mod;
			if(nxt[i.x] >= mod) nxt[i.x] -= mod;
		}
		rnd1 = nxt;
	}
	auto sol = berlekamp_massey(gobs);
	reverse(sol.begin(), sol.end());
	return sol;
}
lint det(int n, vector<elem> M){
	vector<int> rnd;
	mt19937 rng(0x14004);
	auto randint = [&rng](int lb, int ub){
		return uniform_int_distribution<int>(lb, ub)(rng);
	};
	for(int i=0; i<n; i++) rnd.push_back(randint(1, mod - 1));
	for(auto &i : M){
		i.v = 1ll * i.v * rnd[i.y] % mod;
	}
	auto sol = get_min_poly(n, M)[0];
	if(n % 2 == 0) sol = mod - sol;
	for(auto &i : rnd) sol = 1ll * sol * ipow(i, mod - 2) % mod;
	return sol;
}
int main(){
    long long t,n;
    cin>>t;
    while(t--){cin>>n;cout<<guess_nth_term({0,1,1,1,2,2,3,4,5,7,9},n)<<"\n";}
}
*/
/*#include<bits/stdc++.h>
#define ll long long
constexpr ll mod=1e9+7;
using namespace std;
ll power(ll b,ll ex){
    ll A=1;
    while(ex){
        if(ex%2){
            A=A*b%mod;
        }
        b=b*b%mod;
        ex/=2;
    }
    return A%mod;
}
int main(){
    ll k,n,i,j;
    scanf("%lld %lld",&k,&n);
    ll A=1,B=1;
    for(i=1;i<k+2;i++){
        A=A*i%mod;
        B=B*(n+i-1)%mod;
    }
    ll ans=B*power(A,mod-2)%mod;
    printf("%lld",ans);
}*/

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int dp[1001][110]={0,},i,j;
    for(i=0;i<10;i++)dp[1][i]=i+1;
    for(i=2;i<=n;i++){
        int sum=0;
        for(j=0;j<10;j++){
            sum+=dp[i-1][j];
            dp[i][j]+=sum;
            dp[i][j]%=10007;
        }
    }
    printf("%d",dp[n][9]%10007);
}
*/

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        int n,i;
        cin>>n;
        int a[2][n+1];
        a[0][0]=a[1][0]=0;
        for(i=1;i<=n;i++)scanf("%d",&a[0][i]);
        for(i=1;i<=n;i++)scanf("%d",&a[1][i]);
        int dp[2][n+1];
        dp[0][0]=a[0][0];
        dp[1][0]=a[1][0];
        dp[0][1]=a[0][1];
        dp[1][1]=a[1][1];
        for(i=2;i<=n;i++){
            dp[0][i]=max(dp[1][i-1]+a[0][i],max(dp[1][i-2]+a[0][i],dp[0][i-2]+a[0][i]));
            dp[1][i]=max(dp[0][i-1]+a[1][i],max(dp[1][i-2]+a[1][i],dp[0][i-2]+a[1][i]));
        }
        printf("%d\n",max(dp[0][n],dp[1][n]));
    }
}
*/
/*#include<bits/stdc++.h>
int main(){
    int n,a[1000],i,ch[1000],j;
    scanf("%d",&n);
    for(i=0;i<n;i++){scanf("%d",&a[i]);ch[i]=0;}
    ch[0]=1;
    for(i=1;i<n;i++){
            int max=0;
            for(j=0;j<i;j++){
                if(a[j]>a[i]){
                    if(max<ch[j])max=ch[j];
                }

            }
            ch[i]=max+1;
    }
    int m=0;
    for(i=0;i<n;i++){
        if(m<ch[i])m=ch[i];

    }
    printf("%d",m);
}
*/
/*#include<bits/stdc++.h>
using namespace std;
constexpr int INF=1<<27;
typedef pair<int,int> pii;
vector<vector<pii>> mp;
int n;
struct cmp{
    bool operator()(pii a,pii b){
        return a.second>b.second;
    }
};

int djik(int a,int b){
    vector<int> dist(n+1,INF);
    vector<int> ch(n+1,0);
    ch[a]=1;
    dist[a]=0;
    int i,j;
    priority_queue<pii,vector<pii>,cmp> q;
    q.push({a,0});
    while(!q.empty()){
        int now=q.top().first;
        int d=q.top().second;
        q.pop();
        if(d>dist[now])continue;
        for(auto &i:mp[now]){
            if(d+i.second<dist[i.first]){
                q.push({i.first,i.second+d});
                dist[i.first]=i.second+d;
            }
        }
    }
    return dist[b];
}
int main(){
    int e;
    scanf("%d %d",&n,&e);
    int i;
    mp.resize(n+1);
    for(i=0;i<e;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        mp[a].push_back({b,c});
        mp[b].push_back({a,c});
    }
    int v1,v2;
    scanf("%d %d",&v1,&v2);
    int f1=djik(1,v1);
    int f2=djik(v1,v2);
    int f3=djik(1,v2);
    int f4=djik(v1,n);
    int f5=djik(v2,n);
    //printf("%d %d %d %d %d\n",f1,f2,f3,f4,f5);
    int c1=f1+f2+f5;
    int c2=f3+f2+f4;
    int ans=min(c1,c2);
    if(ans>=INF)printf("-1");
    else printf("%d",ans);
}
*/

/*#include<bits/stdc++.h>
#define ch(x,y) if(x<0||x>=n||y<0||y>=m)continue;
#define pii pair<int,int>
constexpr int INF=1<<27;
using namespace std;
vector<string> mp;
vector<vector<pii>> gr;
int d[5]={0,1,0,-1,0},n,m;
int loc(int i,int j){
    return m*i+j;
}
struct cmp{
    bool operator()(pii a,pii b){
        return a.second>b.second;
    }
};
int main(){
    int i,j,k;
    cin>>m>>n;
    mp.resize(n);
    for(i=0;i<n;i++)cin>>mp[i];
    gr.resize(n*m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            for(k=0;k<4;k++){
                int ni=i+d[k],nj=j+d[k+1];
                ch(ni,nj);
                if(mp[ni][nj]=='1')gr[loc(i,j)].push_back({loc(ni,nj),1});
                else if(mp[ni][nj]=='0')gr[loc(i,j)].push_back({loc(ni,nj),0});
            }
        }
    }
    vector<int> dist(n*m,INF);
    priority_queue<pii,vector<pii>,cmp> q;
    q.push({0,0});
    dist[0]=0;
    while(!q.empty()){
        int now=q.top().first;
        int d=q.top().second;
        q.pop();
        if(dist[now]<d)continue;
        for(auto &i:gr[now]){
            if(d+i.second<dist[i.first]){
                q.push({i.first,d+i.second});
                dist[i.first]=d+i.second;
            }
        }
    }
    printf("%d",dist[n*m-1]);
}*/

/*#include<bits/stdc++.h>
constexpr int INF=1<<27;
using namespace std;
typedef pair<int,int> pii;
int main(){

    int n,m,k,i,j;

    scanf("%d %d %d",&n,&m,&k);
    vector<vector<pii>> mp(n+1);
    for(i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        mp[a].push_back({b,c});
    }
    vector<priority_queue<int>> dist(n+1);
    dist[1].push(0);
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,1});
    while(!q.empty()){
        int d=q.top().first;
        int now=q.top().second;
        q.pop();
        for(auto &i:mp[now]){
            if(dist[i.first].size()<k){
                q.push({(d+i.second),i.first});
                dist[i.first].push(d+i.second);
            }
            else if(dist[i.first].top()>d+i.second){
                dist[i.first].pop();
                q.push({(d+i.second),i.first});
                dist[i.first].push(d+i.second);

            }
        }
    }

    for(i=1;i<=n;i++){
        if(dist[i].size()!=k)printf("-1\n");
        else printf("%d\n",dist[i].top());
    }
}
*/
/*#include<bits/stdc++.h>
#define pv pair<pii,vector<int>>
constexpr int INF=1<<27;
using namespace std;
typedef pair<int,int> pii;
struct cmp{
    bool operator()(pv a,pv b){
        return a.first>b.first;
    }
};
//ifstream in;
//ofstream out;
void solve(int n,int m){
    int s,d,i,j;
    cin>>s>>d;
    vector<vector<int>> mp2(n,vector<int> (n,INF));
    vector<vector<pii>> mp(n);
    for(i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mp[a].push_back({b,c});
        mp2[a][b]=c;
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;
    vector<set<pii>> del(n);
    vector<int> dist(n,INF);
    q.push({0,s});
    dist[s]=0;
    while(!q.empty()){
        int now=q.top().second;
        int dst=q.top().first;
        q.pop();
        if(dst>dist[now])continue;
        if(now==d){
            continue;
        }
        for(auto &i:mp[now]){
            int nd=i.second+dst;
            int nn=i.first;
            if(nd>dist[nn])continue;
            else if(nd==dist[nn]){
                for(auto &j:del[now]){
                    del[nn].insert(j);
                }
                del[nn].insert({now,nn});
            }
            else{
                del[nn].clear();
                for(auto &j:del[now]){
                    del[nn].insert(j);
                }
                del[nn].insert({now,nn});
                q.push({nd,nn});
                dist[nn]=nd;
            }
        }
    }
    //printf("aaa\n");
    for(auto &i:del[d]){
        mp2[i.first][i.second]=INF;
    }
    vector<vector<pii>> mp3(n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            //printf("%d ",mp2[i][j]);
            if(mp2[i][j]!=INF)mp3[i].push_back({j,mp2[i][j]});
        }
        //printf("\n");
    }
    priority_queue<pii,vector<pii>,greater<pii>> qq;
    qq.push({0,s});
    vector<int> distt(n,INF);
    while(!qq.empty()){
        int now=qq.top().second;
        int dst=qq.top().first;
        qq.pop();
        if(dst>distt[now])continue;
        for(auto &i:mp3[now]){
            int nd=i.second+dst;
            int nn=i.first;
            if(nd<distt[nn]){
                qq.push({nd,nn});
                distt[nn]=nd;
            }
        }
    }
    if(distt[d]==INF)cout<<"-1\n";
    else cout<<distt[d]<<"\n";
}
int main(){
    int n,m;
    //in.open("in.txt");
    //out.open("out.txt");
    while(cin>>n>>m){
        if(n==0&&m==0)break;
        solve(n,m);
    }
}*/

/*#include<bits/stdc++.h>
#define ch(x,y) if(x<0||x>=hh||y<0||y>=ww)continue;
constexpr int INF=1<<27;
using namespace std;
typedef pair<int,int> pii;
int d[5]={0,1,0,-1,0},hh,ww;
vector<string> mp;
vector<vector<pii>> gr;
vector<int> prisoner;
vector<int> goal;
int loc(int i,int j){
    return ww*i+j;
}
vector<int> djik(int loc){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    vector<int> dist(hh*ww,INF);
    q.push({0,loc});
    dist[loc]=0;
    while(!q.empty()){
        int now=q.top().second;
        int d=q.top().first;
        q.pop();
        if(d>dist[now])continue;
        for(auto &i:gr[now]){
            int nn=i.first;
            int nd=i.second+d;
            if(nd<dist[nn]){
                q.push({nd,nn});
                dist[nn]=nd;
            }
        }
    }
    return dist;
}*/
/*int bfs(int gl){
    int dd[4]={-1,+1,-w,+w};

    vector<vector<pii>> imsi=gr;
    queue<pii> q;
    q.push({prisoner[0],0});
    vector<int> check(h*w,0);
    check[prisoner[0]]=1;
    int ret=0;
    while(!q.empty()){
        int now=q.front().first;
        int wall=q.front().second;
        q.pop();
        if(now==gl){
            ret+=wall;
            break;
        }
        for(auto &i:imsi[now]){
            if(check[i.first]==0){
                if(i.second==1){
                    q.push({i.first,wall+1});
                    check[i.first]=1;
                }
                else if(i.second==0){
                    q.push({i.first,wall});
                    check[i.first]=1;
                }
            }
        }
    }
    queue<pii> qq;
    qq.push({prisoner[1],0});
    vector<int> ccheck(h*w,0);
    ccheck[prisoner[1]]=1;
    while(!qq.empty()){
        int now=qq.front().first;
        int wall=qq.front().second;
        qq.pop();
        if(now==gl){
            ret+=wall;
            break;
        }
        for(auto &i:imsi[now]){
            if(ccheck[i.first]==0){
                if(i.second==1){
                    qq.push({i.first,wall+1});
                    ccheck[i.first]=1;
                }
                else if(i.second==0){
                    qq.push({i.first,wall});
                    ccheck[i.first]=1;
                }
            }
        }
    }
    printf("%d - %d\n",gl,ret);
    return 0;
}*/
/*void solve(){
    int i,j,k;
    int h,w;
    cin>>h>>w;
    mp.clear();
    prisoner.clear();
    gr.clear();
    goal.clear();
    mp.resize(h+2);
    hh=h+2;ww=w+2;
    for(i=1;i<=h;i++)cin>>mp[i];
    for(i=0;i<w+2;i++){mp[0]+='.';mp[h+1]+='.';}
    for(i=1;i<=h;i++){
        mp[i].insert(0,1,'.');
        mp[i]+='.';
    }
    //for(i=0;i<hh;i++)cout<<mp[i]<<"\n";
    for(i=0;i<hh;i++){
        for(j=0;j<ww;j++){
            if(mp[i][j]=='$'){
                prisoner.push_back(loc(i,j));
            }
        }
    }
    //printf("\n");
    int siz=(int)goal.size();
    gr.resize(hh*ww);
    for(i=0;i<hh;i++){
        for(j=0;j<ww;j++){
            for(k=0;k<4;k++){
                int ni=i+d[k],nj=j+d[k+1];
                ch(ni,nj);
                if(mp[ni][nj]=='#')gr[loc(i,j)].push_back({loc(ni,nj),1});
                else if(mp[ni][nj]=='.'||mp[ni][nj]=='$')gr[loc(i,j)].push_back({loc(ni,nj),0});
                else if(mp[ni][nj]=='*')gr[loc(i,j)].push_back({loc(ni,nj),INF});
            }
        }
    }
    auto ans1=djik(prisoner[0]);
    auto ans2=djik(prisoner[1]);
    auto ans3=djik(0);
    int mn=INF;
    for(i=0;i<hh*ww;i++){
        int x=ans1[i]+ans2[i]+ans3[i];
        if(mp[i/ww][i%ww]=='#')x-=2;
        mn=min(mn,x);
        //printf("(%d %d %d) ",ans1[i]==INF?-1:ans1[i],ans2[i]==INF?-1:ans2[i],ans3[i]==INF?-1:ans3[i]);
        //if(i%ww==ww-1)printf("\n");
    }
    printf("%d\n",mn);
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        solve();

    }


}
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<vector<int>> mp,rmp;
vector<int> nums;
stack<pii> s;
vector<int> vis;
int num;
void dfs(int node){
    if(!vis[node]){
        vis[node]=1;
        for(auto &i:mp[node])dfs(i);
        s.push({num,node});
        nums[node]=num;
        num++;
    }
}
void scc(pii p,vector<int> &ans){
    if(!vis[p.second]){
        vis[p.second]=1;
        ans.push_back(p.second);
        for(auto &i:rmp[p.second])scc({nums[i],i},ans);
        return;
    }
}
void MAIN(){
    int v,e;
    cin>>v>>e;

    nums.clear();
    mp.clear();
    rmp.clear();
    vis.clear();

    nums.resize(v+1);
    mp.resize(v+1);
    rmp.resize(v+1);
    vis.assign(v+1,0);

    vector<vector<int>> answer;
    int i,j;
    for(i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        rmp[b].push_back(a);
    }
    for(i=1;i<=v;i++){
        if(!vis[i])dfs(i);
    }
    vis.clear();
    vis.assign(v+1,0);
    while(!s.empty()){
        vector<int> ans;
        scc(s.top(),ans);
        while(!s.empty()&&vis[s.top().second]==1){
            s.pop();
        }
        sort(ans.begin(),ans.end());
        answer.push_back(ans);
    }
    sort(answer.begin(),answer.end());
    /*printf("%d\n",answer.size());
    for(auto &i:answer){
        for(auto &j:i)printf("%d ",j);
        printf("-1\n");
    }*/
    vector<int> node(v+1);
    for(int i=0; i<answer.size();i++){
        for(int j=0;j<answer[i].size();j++){
            node[answer[i][j]]=i;
        }
    }
    vector<vector<int>> nmp(answer.size());
    for(i=1;i<=v;i++){
        for(j=0;j<mp[i].size();j++){
            if(node[i]==node[mp[i][j]])continue;
            nmp[node[i]].push_back(node[mp[i][j]]);
        }

    }
    for(i=0;i<nmp.size();i++){
        sort(nmp[i].begin(),nmp[i].end());
        nmp[i].erase(unique(nmp[i].begin(),nmp[i].end()),nmp[i].end());
    }

    vector<vector<int>> rnmp(answer.size());
    for(i=0;i<nmp.size();i++){
        for(j=0;j<nmp[i].size();j++){
            rnmp[nmp[i][j]].push_back(i);
        }
    }/*for(i=0;i<rnmp.size();i++){
        printf("%d - ",i);
        for(j=0;j<rnmp[i].size();j++){
            printf("%d ",rnmp[i][j]);
        }
        printf("\n");
    }*/
    int c=0;
    for(i=0;i<rnmp.size();i++){
        if(rnmp[i].size()==0)c++;
    }
    printf("%d\n",c);
}
int main(){
    int tt;
    cin>>tt;
    while(tt--){
        MAIN();
    }
}

