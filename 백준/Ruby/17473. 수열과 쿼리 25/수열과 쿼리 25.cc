#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-05-06
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout. (mmap ver.)
 */
constexpr int SZ = 1 << 20;

class INPUT {
private:
    char* p;
    bool __END_FLAG__, __GETLINE_FLAG__;
public:
    explicit operator bool() { return !__END_FLAG__; }
    INPUT() {
        struct stat st; fstat(0, &st);
        p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
    }
    bool IsBlank(char c) { return c == ' ' || c == '\n'; }
    bool IsEnd(char c) { return c == '\0'; }
    char _ReadChar() { return *p++; }
    char ReadChar() {
        char ret = _ReadChar();
        for (; IsBlank(ret); ret = _ReadChar());
        return ret;
    }
    template<typename T> T ReadInt() {
        T ret = 0; char cur = _ReadChar(); bool flag = 0;
        for (; IsBlank(cur); cur = _ReadChar());
        if (cur == '-') flag = 1, cur = _ReadChar();
        for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
        if (IsEnd(cur)) __END_FLAG__ = 1;
        return flag ? -ret : ret;
    }
    string ReadString() {
        string ret; char cur = _ReadChar();
        for (; IsBlank(cur); cur = _ReadChar());
        for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
        if (IsEnd(cur)) __END_FLAG__ = 1;
        return ret;
    }
    double ReadDouble() {
        string ret = ReadString();
        return stod(ret);
    }
    string getline() {
        string ret; char cur = _ReadChar();
        for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
        if (__GETLINE_FLAG__) __END_FLAG__ = 1;
        if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
        return ret;
    }
    friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
    char write_buf[SZ];
    int write_idx;
public:
    ~OUTPUT() { Flush(); }
    explicit operator bool() { return 1; }
    void Flush() {
        write(1, write_buf, write_idx);
        write_idx = 0;
    }
    void WriteChar(char c) {
        if (write_idx == SZ) Flush();
        write_buf[write_idx++] = c;
    }
    template<typename T> int GetSize(T n) {
        int ret = 1;
        for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
        return ret;
    }
    template<typename T> void WriteInt(T n) {
        int sz = GetSize(n);
        if (write_idx + sz >= SZ) Flush();
        if (n < 0) write_buf[write_idx++] = '-', n = -n;
        for (int i = sz; i --> 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
        write_idx += sz;
    }
    void WriteString(string s) { for (auto& c : s) WriteChar(c); }
    void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) {
    if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
    else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in; }

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) {
    if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
    else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out; }

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
/////////////////////////////////////////////////////////////////////////////////////////////
typedef long long ll;
constexpr ll INF=1e10;
constexpr ll all1=33554431;
struct val{
    ll mx;
    ll mn;
    ll ands;
    ll ors;
};
class lazySegtree{
private:
    vector<val> _tree;
    vector<ll> _lazy_and;
    vector<ll> _lazy_or;

    int _sz;
    void update_lazy(int st,int en, int node){
        _tree[node].mn=(_lazy_and[node]&_tree[node].mn)|_lazy_or[node];
        _tree[node].mx=(_lazy_and[node]&_tree[node].mx)|_lazy_or[node];
        _tree[node].ors=(_lazy_and[node]&_tree[node].ors)|_lazy_or[node];
        _tree[node].ands=(_lazy_and[node]&_tree[node].ands)|_lazy_or[node];
        if(st!=en){
            _lazy_or[node*2]=(_lazy_or[node*2]&_lazy_and[node])|_lazy_or[node];
            _lazy_and[node*2]=(_lazy_and[node*2]&_lazy_and[node]);
            _lazy_or[node*2+1]=(_lazy_or[node*2+1]&_lazy_and[node])|_lazy_or[node];
            _lazy_and[node*2+1]=(_lazy_and[node*2+1]&_lazy_and[node]);

        }
        _lazy_or[node]=0;
        _lazy_and[node]=all1;
        return;
    }
    val mer(val a,val b){
        return {max(a.mx,b.mx),min(a.mn,b.mn),a.ands&b.ands,a.ors|b.ors};
    }
    val init(int st, int en, int node,vector<ll>& a){
        if(st==en){
            return this->_tree[node]={a[st],a[st],a[st],a[st]};
        }
        int mid=(st+en)/2;
        auto a1=init(st,mid,node*2,a);
        auto a2=init(mid+1,en,node*2+1,a);
        return this->_tree[node]=mer(a1,a2);
    }
    ll calc_d(ll x,ll d,ll r){
        ll z=x;
        while(z%2==r){
            d<<=1;
            z>>=1;
        }
        return d;
    }

public:
    lazySegtree(vector<ll>& other){
        this->_sz=other.size();
        this->_tree.resize(_sz*4);
        this->_lazy_or.resize(_sz*4,0);
        this->_lazy_and.resize(_sz*4,all1);
        init(0,_sz-1,1,other);
    }
    ll mx(int st,int en, int node,int l,int r){
        update_lazy(st,en,node);
        if(l>en||r<st)return -INF;
        if(l<=st&&en<=r)return _tree[node].mx;
        int mid=(st+en)/2;
        return max(mx(st,mid,node*2,l,r),mx(mid+1,en,node*2+1,l,r));
    }
    ll mn(int st,int en, int node,int l,int r){
        update_lazy(st,en,node);
        if(l>en||r<st)return INF;
        if(l<=st&&en<=r)return _tree[node].mn;
        int mid=(st+en)/2;
        return min(mn(st,mid,node*2,l,r),mn(mid+1,en,node*2+1,l,r));
    }
    val update_or(int st,int en,int node,int l,int r,ll x){
        update_lazy(st,en,node);
        if(st==en)assert(_tree[node].ors==_tree[node].ands);
        if(l>en||r<st)return _tree[node];
        ll u=(x&_tree[node].ors&~_tree[node].ands);
        if(l<=st&&en<=r&&u==0){
            _lazy_or[node]|=x;
            update_lazy(st,en,node);
            return _tree[node];
        }
        int mid=(st+en)/2;
        return this->_tree[node]=mer(update_or(st,mid,node*2,l,r,x),update_or(mid+1,en,node*2+1,l,r,x));
    }
    val update_and(int st,int en,int node,int l,int r,ll x){
        update_lazy(st,en,node);
        if(st==en)assert(_tree[node].ors==_tree[node].ands);
        if(l>en||r<st)return _tree[node];
        ll u=(~x&_tree[node].ors&~_tree[node].ands);
        if(l<=st&&en<=r&&u==0){
            _lazy_and[node]&=x;
            _lazy_or[node]&=x;
            update_lazy(st,en,node);
            return _tree[node];
        }
        int mid=(st+en)/2;
        return this->_tree[node]=mer(update_and(st,mid,node*2,l,r,x),update_and(mid+1,en,node*2+1,l,r,x));
    }
    vector<val>& tree(){
        return _tree;
    }
};
int main(){
    int n,q;
    cin>>n;
    vector<ll> a(n);
    int i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    lazySegtree seg(a);
    cin>>q;
    for(i=0;i<q;i++){
        int inst;
        cin>>inst;
        if(inst==1){
            ll x,y,z;
            cin>>x>>y>>z;
            seg.update_and(0,n-1,1,x-1,y-1,z);
        }
        if(inst==2){
            ll x,y,z;
            cin>>x>>y>>z;
            seg.update_or(0,n-1,1,x-1,y-1,z);
        }
        if(inst==3){
            ll x,y,z;
            cin>>x>>y;
            cout<<seg.mx(0,n-1,1,x-1,y-1)<<"\n";

        }
    }
}
