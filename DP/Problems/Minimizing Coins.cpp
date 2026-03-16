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

vector<int>dp;
int n,k;int v[101];
int go(int sum) {
    if (sum == 0)return 0;
    if (sum < 0)return 1e18;
    int &ret = dp[sum];
    if (~ret)return ret;
    ret = 1e18;
    for (int i = 0; i < n; i++) {
        ret = min(ret, go(sum - v[i]) + 1);
    }
    return ret;
}
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)cin >> v[i];
    dp.resize(k + 1, -1);
    int re = go(k);
    if (re == 1e18)re = -1;
    cout << re << endl;
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
