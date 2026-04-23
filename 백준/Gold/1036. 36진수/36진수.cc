#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string rev(string a){
    string ret;
    for(int i=a.size()-1;i>=0;i--){
        ret+=a[i];
    }
    return ret;
}
class int36{
public:
    string s;

    int36(){}
    int36(string s){
        this->s=s;
        s=rev(s);
    }
    int val(char a){
        if('0'<=a&&a<='9')return a-'0';
        else{
            return a-'A'+10;
        }
    }
    char cha(int a){
        if(0<=a&&a<=9)return a+'0';
        else{
            return a-10+'A';
        }
    }
    int36 operator+(int36 a){
        int rem=0;
        int36 ret;
        string w=a.s;
        if(w.size()>s.size())swap(w,s);
        for(int i=0;i<s.size();i++){
            //cout<<s[i]<<" "<<w[i]<<"\n";
            int ss=val(s[i]),aa;
            if(i>=w.size())aa=0;
            else aa=val(w[i]);
            int x=rem+ss+aa;
            //cout<<cha(x%36)<<"\n";
            ret.s+=cha(x%36);
            rem=x/36;
        }
        if(rem)ret.s+=cha(rem);
        return ret;
    }
    string value(){
        return rev(s);
    }
    bool operator<(int36& a){
        if(a.s.size()!=s.size())return s.size()<a.s.size();
        else{
            for(int i=s.size()-1;i>=0;i--){
                if(val(a.s[i])!=val(s[i]))return val(s[i])<val(a.s[i]);
            }
        }
        return false;
    }
    bool operator>(const int36& a){
        if(a.s.size()!=s.size())return s.size()>a.s.size();
        else{
            for(int i=s.size()-1;i>=0;i--){
                if(val(a.s[i])!=val(s[i]))return val(s[i])>val(a.s[i]);
            }
        }
        return false;
    }
    size_t size(){
        return s.size();
    }
};
int main(){
    int n;
    cin>>n;
    int i,j;
    vector<int36> a(n);
    for(i=0;i<n;i++){
        string s;
        cin>>s;
        a[i].s=rev(s);
    }
    int k;
    cin>>k;
    sort(a.begin(),a.end());
    for(i=0;i<k;i++){
        int36 mx("0");
        int timing=0;
        for(j=0;j<36;j++){
            vector<int36> b=a;
            for(int l=0;l<n;l++){
                for(int z=0;z<b[l].size();z++){
                    if(b[l].s[z]==b[l].cha(j))b[l].s[z]='Z';
                }
            }
            int36 sum("0");
            for(auto& x:b){
                sum=sum+x;
            }
            if(mx<sum){timing=j;mx=sum;}
        }
        vector<int36> b=a;
        j=timing;
        for(int l=0;l<n;l++){
            for(int z=0;z<b[l].size();z++){
                if(b[l].s[z]==b[l].cha(j))b[l].s[z]='Z';
            }
        }
        int36 sum("0");
        for(auto& x:b){
            sum=sum+x;
        }
        swap(a,b);
    }
    int36 ans("0");
    for(auto& x:a){
        ans=ans+x;
        //cout<<ans.value()<<"\n";
    }
    cout<<ans.value();
}


