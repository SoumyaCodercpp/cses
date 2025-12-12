#include <bits/stdc++.h>
using namespace std;
 
#define INF (long long)1e18 + 5 //Infinity
#define MOD 1000000007
// #define M_PI 3.141592653589793
#define f(j,n,k) for(int i=j;i<n;i=i+k)
#define read(a) for(auto &i: a) cin >> i
#define print(a) for(auto &i: a) cout << i << " "; cout << "\n"
#define read2(a, n, m) for (int i = 0; i < (n); ++i) for (int j = 0; j < (m); ++j) cin >> (a)[i][j]
#define print2(a, n, m) for (int i = 0; i < (n); ++i) { for (int j = 0; j < (m); ++j) cout << (a)[i][j] << " "; cout << endl; }
#define int2(n,k) int n, k; cin >> n >> k
#define int3(n,x,y) int n, x, y; cin >> n >> x >> y
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define ss second
#define ff first
#define pii pair<int, int>
#define pll pair<ll, ll>
#define sz(a) (ll)a.size()
#define all(a) a.begin(), a.end()
#define tri pair<ll, pll>
#define vii vector<pii>
#define vll vector<pll>
#define vlll vector<tri>
#define vvi vector<vi>
#define vvl vector<vl>
// #define clear(arr) memset(arr, 0, sizeof (arr))
#define YES cout<<"yes\n"
#define NO cout<<"no\n"
#define modulo 998244353 
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x);cerr<<endl;
#else
#define debug(x)
#endif
 
void _print(int a){
    cerr<<a;
}
void _print(long long a){
    cerr<<a;
}
void _print(bool a){
    cerr<<a;
}
void _print(string a){
    cerr<<a;
}
void _print(char a){
    cerr<<a;
}
template<class T> void _print(vector<T>v){
    cerr<<"[ ";
    for(T i:v){
        _print(i);
        cerr<<" ";
    }
    cerr<<"]";
}
template<class T> void _print(set<T>s){
    cerr<<"[ ";
    for(T i:s){
        _print(i);
        cerr<<" ";
    }
    cerr<<"]";
}
 
 
 
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
 
 
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b; 
}
 
ll pow2(ll a, ll b ) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a ;
        a = a * a ;
        b >>= 1;
    }
    return res;
}
 
ll pow(ll a, ll b, ll m ) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
ll fact(ll o, ll m){
    if(o==0||o==1){
        return 1;
    }
    return (o*fact(o-1,m))%m;
}
bool isPrime(ll n) {
    if (n <= 1) return false;         // 0 and 1 are not prime
    if (n <= 3) return true;          // 2 and 3 are prime
 
    if (n % 2 == 0 || n % 3 == 0) return false;  // Eliminate multiples of 2 and 3
 
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
 
 
ll bexpo(ll a,ll b,ll mod){
 
    if(b<0) return 0;
 
    ll res=1ll;
    while(b>0){
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
 
    return res;
 
 
}
 
 
 
bool perf(ll n) {
    if (n < 0) return false;     
    ll root = sqrt(n);
    return (root * root == n);
}
 
 
 
 
vector<ll>segTree;
 
void build(vector<long long> &arr, int start, int end, int index) {
    if (start==end) {
        segTree[index]=arr[start];
        return;
    }
    int mid = (start+end)/2;
    int left=2*index+1;
    int right=2*index+2;
    build(arr, start, mid, left);
    build(arr, mid+1,end, right);
    segTree[index]=max(segTree[left],segTree[right]);
}
 
void update(vector<long long> &arr, int start, int end, int index,int pos ,ll value) {
   if (start==end) {
       arr[pos]=value;
        segTree[index]=arr[pos];
        return;
    }
    int mid = (start+end)/2;
    if (pos<=mid) update(arr, start, mid,2*index+1,pos,value);
    else update(arr,mid+1,end,2*index+2,pos,value);
    segTree[index]=max(segTree[2*index+1],segTree[2*index+2]);
}
 
void query(int start, int end,int index,ll value) {
 
    if(start==end){
        //element found
        segTree[index]-=value;
        cout<<start+1<<" ";
        return;
    }
    int mid = (start+end)/2;
    int left=2*index+1;
    int right=2*index+2;
    if(segTree[left]>=value) query(start,mid,left,value);
    else query(mid+1,end,right,value);
 
    // ***update after value found***
    segTree[index]=max(segTree[left],segTree[right]);
 
}
 
 
 
 
 
 
 
 
int main(){
     ios::sync_with_stdio(false);
    cin.tie(NULL);
    
  
 
 
 
 
    ll n,m;
    cin>>n>>m;
    segTree.resize(4*n);
    vl h(n);
    read(h);
    vl r(m);
    read(r);
 
    build(h,0,n-1,0);
 
    f(0,m,1){
        if(segTree[0]<r[i]) cout<<0<<" ";
        else{
            //always possible
            query(0,n-1,0,r[i]);
        }
    }
    cout<<endl;
 
    
 
 
 
 
   
 
  
 
 
return 0;
 
 
}