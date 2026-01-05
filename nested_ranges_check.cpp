#include <bits/stdc++.h>
using namespace std;
 
#define INF (long long)1e18 + 5 //Infinity
#define MOD 1000000009
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
 
 
 
 
int dx[2]={1,0};
int dy[2]={0,1};
 
vi ans;
set<int>s;
int n;
bool build(){
    if(ans.size()==n){
        print(ans);
        return true;
    }
    
    for(int i:s){
        if(ans.empty()||abs(ans.back()-i)>1){
            ans.pb(i);
            s.erase(i);
            bool next=build();
            if(next) return true;
            s.insert(i);
            ans.pop_back();
 
        }
    }
    return false;
}
 
 
string show(ll k,ll n){
    string ans="";
    f(0,n,1){
 
        ans.pb('0'+k%2);
        k=k/2;
 
 
    }
    reverse(all(ans));
    return ans;
}
 
bool comp(pll a,pll b){
    if(a.ff==b.ff){
        return a.ss>b.ss;
    }
    return a.ff<b.ff;
}
 
int main(){
     ios::sync_with_stdio(false);
    cin.tie(NULL);
    
 
  ll n;
  cin>>n;
  vll p;
  ll t=n;
  while(t--){
    ll l,r;
    cin>>l>>r;
    p.pb({l,r});
  }
 
 
 
  map<pll,ll>m;
  vll b=p;
  sort(all(b),comp);
 
  ll r=b[0].ss;
  f(1,n,1){
    if(b[i].ss<=r){
        m[b[i]]=1;
    }
    r=max(b[i].ss,r);
  }
  map<pll,ll>m1;
 
  r=b[n-1].ss;
  for(int i=n-2;i>=0;i--){
    if(b[i].ss>=r){
        m1[b[i]]=1;
    }
    r=min(b[i].ss,r);
  }
 
f(0,n,1){
    cout<<m1[p[i]]<<" ";
  }
  cout<<endl;
 
 f(0,n,1){
    cout<<m[p[i]]<<" ";
  }
  cout<<endl;
 
 
 
 
 
 
return 0;
 
 
}
