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
 
 
 
 
 
 
 
 
 
bool check(ll i,vl &a){
    for(auto j:a){
        if(i%j!=0){
            return false;
        }
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
 
// vector<ll> sieve(ll n){
//     vl prime2(n+1,1);
 
//     f(1,n+1,1){
//         if(prime[i]){
//             for(ll j=i*i;j<=n;j+=i){
//                 prime[j]=0;
//             }
//         }
//     }
 
//     return prime2;
 
// }
 
 
bool perf(ll n) {
    if (n < 0) return false;     
    ll root = sqrt(n);
    return (root * root == n);
}
 
 
 
 
ll sol(vl a){
    ll n=a.size();
    if(n==0) return 0;
 
    ll med=a[n/2];
    ll ans=0;
    f(0,n,1){
        ans+=(abs(med-a[i])-abs(n/2-i));
    }
    return ans;
 
}
 
 
 
 
 
 
int main(){
     ios::sync_with_stdio(false);
    cin.tie(NULL);
    
  
 
 
   ll n,m;
   cin>>n>>m;
 
   vector<vll>adj(n+1);
    vector<vll>adj2(n+1);
   vvl edges;
 
   f(0,m,1){
    ll l,r,c;
    cin>>l>>r>>c;
    adj[l].pb({c,r});
    adj2[r].pb({c,l});
    edges.pb({l,r,c});
    
   }
 
   vl ans(n+1,LLONG_MAX);
   vl ans2(n+1,LLONG_MAX);
 
   set<pll>s;
   set<pll>s2;
   s.insert({0,1});
   s2.insert({0,n});
   
   ans[1]=0;
   ans2[n]=0;
   while(!s.empty()){
 
        auto t=*(s.begin());
        ll d=t.ff;
        ll e=t.ss;
        s.erase(s.begin());
        for(auto j:adj[e]){
            ll w=j.ff;
            ll m=j.ss;
            if(ans[m]>(w+d)){
                
                auto r=s.find({ans[m],m});
                if(r!=s.end()) s.erase(r);
                ans[m]=d+w;
                s.insert({ans[m],m});
            }
        }
 
 
 
   }
   while(!s2.empty()){
 
        auto t=*(s2.begin());
        ll d=t.ff;
        ll e=t.ss;
        s2.erase(s2.begin());
        for(auto j:adj2[e]){
            ll w=j.ff;
            ll m=j.ss;
            if(ans2[m]>(w+d)){
                
                auto r=s2.find({ans2[m],m});
                if(r!=s2.end()) s2.erase(r);
                ans2[m]=d+w;
                s2.insert({ans2[m],m});
            }
        }
 
 
 
   }
 
   ll sol=LLONG_MAX;
 
   f(0,m,1){
    ll l=edges[i][0];
    ll r=edges[i][1];
    ll c=edges[i][2];
    if(ans[l]!=LLONG_MAX&&ans2[r]!=LLONG_MAX) sol=min(sol,ans[l]+ans2[r]+c/2);
    
   }
 
   cout<<sol<<endl;
 
 
 
   
 
 
 
 
 
 
 
 
 
 
return 0;
}