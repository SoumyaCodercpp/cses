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
 
 
 
ll fact2(ll n){
    return (n*(n-1))/2;
}
 
 
 ll fact(ll o, ll m){
    if(o==0||o==1){
        return 1;
    }
    return (o*fact(o-1,m))%m;
}
 
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
 
 
        
// x&(x-1)-removes least significant 1;
// ctz- count trailing zeros
// clz-count leading zeros
   
 
   ll n,k;
   cin>>n>>k;
 
   ll  x,a,b,c;
     cin>>x>>a>>b>>c;
 
 
     vl arr(n+1,0);
     arr[1]=x;
     f(2,n+1,1){
        arr[i]=(arr[i-1]*a+b)%c;
     }
debug(arr)
 
if(k==1){
    ll ans=0;
    f(1,n+1,1){
        ans^=(arr[i]);
    }
    cout<<ans<<endl;
 
}
 
else{
 
     vl pre(n+1);
 
     f(1,n+1,1){
        if(i%k==1) pre[i]=arr[i];
        else pre[i]=pre[i-1]|arr[i];
     }
 
     vl suff(n+1,0);
     suff[n]=arr[n];
     for(int i=n-1;i>=1;i--){
        if(i%k==0) suff[i]=arr[i];
        else suff[i]=suff[i+1]|arr[i];
     }
 
     ll ans=0;
 
     f(k,n+1,1){
 
        ans^=(pre[i]|suff[i-k+1]);
 
     }
 
     cout<<ans<<endl;
 
 
 
} 
 
     
    
 
 
 
 
 
 
 
}