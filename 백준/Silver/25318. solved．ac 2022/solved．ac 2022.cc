#include<bits/stdc++.h>
using namespace std;
time_t calc_time(string a,string b){
    std::tm t{};
    std::istringstream ss(a+b);

    ss >> std::get_time(&t, "%Y/%m/%d%H:%M:%S");
    if (ss.fail()) {
        throw std::runtime_error{"failed to parse time string"};
    }
    std::time_t time_stamp = mktime(&t);
    return time_stamp;
}
int main(){
    time_t t_N=calc_time(string("2022/07/01"),string("23:59:59"));
    int n;
    cin>>n;
    int i,l[1000];
    time_t t[1000];
    for(i=0;i<n;i++){
        string a,b;
        cin>>a>>b>>l[i];
        t[i]=calc_time(a,b);
    }
    double p[1000];
    for(i=0;i<n;i++){
        p[i]=max(pow(0.5,(double)(t[n-1]-t[i])/31536000),pow(0.9,(double)(n-i-1)));
        //cout<<p[i]<<"s\n";
    }
    double x=0,y=0;
    for(i=0;i<n;i++){
        x+=(p[i]*(double)l[i]);
        y+=p[i];
    }
    //printf("%.10lf\n",x/y);
    if(n!=0)cout<<round(x/y);
    else cout<<"0";
}