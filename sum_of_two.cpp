#include<bits/stdc++.h>
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
 
 
 ll solve(ll i,vl &a,ll l,ll r){
    if(i==a.size()){
        return abs(l-r);
    }
    ll op1=solve(i+1,a,l+a[i],r);
    ll op2=solve(i+1,a,l,r+a[i]);
 
    return min(op1,op2);
 }
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n,x;
    cin>>n>>x;
    vl a(n);
    read(a);
 
    vll p;
    f(0,n,1){
        p.pb({a[i],i+1});
    }
sort(all(p));
 
bool f=false;
int i=0,j=n-1;
while(i<j){
    if(p[i].ff+p[j].ff==x){
        f=true;
        cout<<p[i].ss<<" "<<p[j].ss<<endl;
        break;
    }
    else if(p[i].ff+p[j].ff>x){
        j--;
    }
    else{
        i++;
    }
}
if(!f) cout<<"IMPOSSIBLE"<<endl;
 
    
    
 
 
}