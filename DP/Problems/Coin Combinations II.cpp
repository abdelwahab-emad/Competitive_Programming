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
    int n, x;
    cin >> n >> x;
    int coins[n];
    for (int i = 0; i < n; i++)cin >> coins[i];
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (auto coin: coins) {
        for (int i = 1; i <= x; i++) {
            if (i - coin >= 0) {
                dp[i] += dp[i - coin];
                if (dp[i] >= 1e9 + 7)dp[i] -= 1e9 + 7;
            }
        }
    }
    cout << dp[x];
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
