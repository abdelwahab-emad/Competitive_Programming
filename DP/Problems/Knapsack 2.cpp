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

void solve() {
    int n, max_w;
    cin >> n >> max_w;
    int sum = 0;
    vector<int> w(n + 1, 0), v(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
        sum += v[i];
    }
    vector<int> dp(sum + 1, 1e18);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = sum; j >= v[i]; --j) {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    for (int j = sum; j >= 0; --j) {
        if (dp[j] <= max_w) {
            cout << j << endl;
            return;
        }
    }
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
