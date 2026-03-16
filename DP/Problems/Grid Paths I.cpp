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

const int N = 1000 + 5,mod = 1e9 + 7;
int n;
char grid[N][N];
int dp[N][N];
int go(int i,int j) {
    if (grid[i][j] == '*')return 0;
    if (i == n - 1 and j == n - 1)return 1;
    int &ret = dp[i][j];
    if (~ret)return ret;
    ret = 0;
    if (i + 1 < n)
        ret = (ret + go(i + 1, j)) % mod;
    if (j + 1 < n)
        ret = (ret + go(i, j + 1)) % mod;
    return ret;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << go(0, 0);
}

signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
