#include <bits/stdc++.h>
using namespace std;

void go() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

#define endl "\n"
#define ll long long
#define int long long

void solve(){
    ll n,x;cin>>n>>x;
    map<ll,int>m;
    ll ans=0,sum=0;
    m[0]=1;
    for(int i=0;i<n;i++)
    {
        ll w;cin>>w;
        sum+=w;
        ans+=m[sum-x];
        m[sum]++;
    }
    cout<<ans;
}
signed main() {
    go();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
