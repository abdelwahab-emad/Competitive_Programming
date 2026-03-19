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
string a, b;
vector<vector<int>> dp;
int go(int i, int j) {
    if (i == sz(a)) return sz(b) - j;
    if (j == sz(b)) return sz(a) - i;
    int &ret = dp[i][j];
    if (~ret)return ret;
    ret = 1e18;
    if (a[i] == b[j]) {
        ret = min(ret, go(i + 1, j + 1));
    } else {
        ret = min(ret, 1 + go(i, j + 1));
        ret = min(ret, 1 + go(i + 1, j));
        ret = min(ret, 1 + go(i + 1, j + 1));
    }
    return ret;
}
void solve() {
    cin >> a >> b;
    dp = vector<vector<int>>(sz(a) + 1, vector<int>(sz(b) + 1, -1));
    int ans = go(0, 0);
    cout << ans;
}
signed main() {
    Code_By_Abdelwabab
    //file();
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
