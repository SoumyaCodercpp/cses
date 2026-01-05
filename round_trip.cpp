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
 
 
vl vis;
vl parent;
vvl adj;
 
bool dfs(ll k,ll p,ll &v1,ll &v2){
 
    vis[k]=true;
    parent[k]=p;
    for(auto j:adj[k]){
        if(j!=p){
            if(vis[j]){
 
                v1=j;
                v2=k;
                return true;
 
            }
            else{
                bool ans=dfs(j,k,v1,v2);
                if(ans) return true;
            }
        }
    }
    return false;
 
 
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
 ll n,m;
 cin>>n>>m;
 vis.resize(n+1);
 parent.resize(n+1);
 adj.resize(n+1);
 f(0,m,1){
    ll u,v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
 }
bool ans=false;
ll v1=-1,v2=-1;
f(1,n+1,1){
    if(!vis[i]){
        ans=dfs(i,-1,v1,v2);
        if(ans) break;
    }
}
 
if(!ans){
    cout<<"IMPOSSIBLE"<<endl;
}
else{
    debug(v1)
    debug(v2)
    ll j=v2;
    vl res;
    while(j!=v1){
        debug(j)
        res.pb(j);
        j=parent[j];
    }
 
    res.pb(j);
    
    reverse(all(res));
    cout<<sz(res)+1<<endl;
    for(auto i:res){
        cout<<i<<" ";
    }
    cout<<res[0]<<endl;
}
 
 
 
 
 
 
 
 
 
}