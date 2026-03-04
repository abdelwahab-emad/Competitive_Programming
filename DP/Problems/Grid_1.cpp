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
const int mod = 1e9+7;
int add(int a,int b) {
    return ((a % mod) + (b % mod)) % mod;
}
void solve() {
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#'){
                continue;
            }
            if (i > 0) dp[i][j] = add(dp[i][j], dp[i - 1][j]);
            if (j > 0) dp[i][j] = add(dp[i][j], dp[i][j - 1]);
        }
    }
    cout << dp[n - 1][m - 1] << endl;
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
