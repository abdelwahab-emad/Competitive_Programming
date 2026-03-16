#include <bits/stdc++.h>
using namespace std;
void file(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
#define Code_By_Abdelwabab ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"
#define int long long
#define ll long long
#define ld long double
#define sz(s) (int)(s).size()

const int N = 1e5 + 3;
vector<vector<int>> adj(N);
int n, m;
int dp[N];
int go(int idx) {
    if (idx > n)return 0;
    int &ret = dp[idx];
    if (~ret)return ret;
    ret = 0;
    for (auto chil: adj[idx]) {
        ret = max(ret, solve(chil) + 1);
    }
    return ret;
}
void solve() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    memset(dp, -1, sizeof dp);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, go(i));
    }
    cout << mx;
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
