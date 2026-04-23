#include<bits/stdc++.h>
using namespace std;
int main(){
    const auto now=chrono::system_clock::now();
    time_t x=chrono::system_clock::to_time_t(now);
    struct tm tstruct=*gmtime(&x);
    char temp[128];
    snprintf(temp,sizeof(temp),"%04d\n%02d\n%02d",tstruct.tm_year+1900,tstruct.tm_mon+1,tstruct.tm_mday);
    cout<<string(temp);
}