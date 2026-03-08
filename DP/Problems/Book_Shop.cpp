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
    int n, max_p;
    cin >> n >> max_p;
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++)cin >> price[i];
    for (int i = 0; i < n; i++)cin >> pages[i];
    vector<int> dp(max_p + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = max_p; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }
    cout << dp[max_p];
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}