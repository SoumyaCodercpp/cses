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
 
 
 
void dfs(ll k,vl &vis,vvl &adj){
 
    vis[k]=1;
    for(auto j:adj[k]){
        if(!vis[j]){
            dfs(j,vis,adj);
        }
    }
   
}
 
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
 
ll n,m;
cin>>n>>m;
vvl adj(n+1);
vl dist(n+1,-1);
vl par(n+1,-1);
f(0,m,1){
 
    ll l,r;
    cin>>l>>r;
    adj[l].pb(r);
    adj[r].pb(l);
 
 
}
 
dist[1]=0;
 
queue<ll>q;
q.push(1);
while(!q.empty()){
    ll t=q.front();
    q.pop();
 
    for(auto j:adj[t]){
        if(dist[j]!=-1) continue;
 
        dist[j]=1+dist[t];
        par[j]=t;
        q.push(j);
 
    }
 
 
}
 
if(dist[n]==-1){
    cout<<"IMPOSSIBLE"<<endl;
}
else{
    vl ans;
    ll curr=n;
    ans.pb(curr);
    while(par[curr]!=-1){
        curr=par[curr];
        ans.pb(curr);
    }
    cout<<ans.size()<<endl;
    reverse(all(ans));
    print(ans);
}
 
 
 
 
 
 
 
 
}