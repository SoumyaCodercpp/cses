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
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n;
    cin>>n;
    vl a(n);
    read(a);
    sort(all(a));
    ll sum=0;
    f(0,n,1){
        sum+=a[i];
    }
    vvl dp(n,vector<ll>(sum+1,0));
 
    dp[0][a[0]]=1;
 
f(0,n,1){
 
    dp[i][0]=1;
 
 
 
}
 
    f(1,sum+1,1){
        
        
 
 
 
        for(int j=1;j<n;j++){
            if(dp[j-1][i]){
                debug(i)
                dp[j][i]=1;
            }
            if(i>=a[j]&&dp[j-1][i-a[j]]){
                debug(i)
                dp[j][i]=1;
 
            }
            
        }
 
    }
 
 
    vl ans;
    f(1,sum+1,1){
        if(dp[n-1][i]){
            ans.pb(i);
        }
    }
 
    cout<<ans.size()<<endl;
    print(ans);
 
 
 
   
 
   
 
}