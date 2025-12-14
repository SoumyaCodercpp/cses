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
 
 
 
 
 
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char dir[4]={'D','U','R','L'};
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
 
 
ll n,m;
cin>>n>>m;
 
 
vvl a(n+2,vl(m+2,0));
vvl dist(n+2,vl(m+2,-1));
 
vector<vector<char>>way(n+1,vector<char>(m+1));
vector<vector<pll>>par(n+1,vector<pll>(m+1));
 
 
queue<pll>q;
 
pll src;
pll tar;
f(1,n+1,1){
    for(int j=1;j<=m;j++){
        char c;
        cin>>c;
        if(c=='A'){
            dist[i][j]=0;
            
            src={i,j};
            
            par[i][j]={-1,-1};
        }
        else if(c=='B'){
            tar={i,j};
        }
        else if(c=='#'){
            a[i][j]=-1;
        }
 
    }
}
 
q.push(src);
while(!q.empty()){
    pll t=q.front();
    q.pop();
    f(0,4,1){
        ll x=t.ff+dx[i];
        ll y=t.ss+dy[i];
 
        if(x<1||y<1||x>n||y>m){
            continue;
        }
        if(a[x][y]==-1){
            continue;
        }
 
        if(dist[x][y]!=-1){
 
            continue;
 
        }
        dist[x][y]=1+dist[t.ff][t.ss];
        par[x][y]=t;
        way[x][y]=dir[i];
        q.push({x,y});
    }
 
 
}
 
 
if(dist[tar.ff][tar.ss]==-1){
    cout<<"NO"<<endl;
}
else{
    cout<<"YES"<<endl;
    cout<<dist[tar.ff][tar.ss]<<endl;
    pll t=tar;
    string ans="";
    pll p={-1,-1};
    while(par[t.ff][t.ss]!=p){
 
        ans.pb(way[t.ff][t.ss]);
        t=par[t.ff][t.ss];
 
    }
    reverse(all(ans));
    cout<<ans<<endl;
}
 
 
 
 
 
    
 
 
 
 
 
 
 
}
