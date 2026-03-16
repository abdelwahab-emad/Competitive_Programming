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

const int N = 18;
int dp[N + 3][3][12][3];
string s;
int solve(int idx, bool tight, int last, bool allZeros) {
    if (idx == s.size())return 1;
    int& ret = dp[idx][tight][last][allZeros];
    if (~ret)return ret;
    int ans = 0;
    int end = tight == 1 ? s[idx] - '0' : 9;
    for (int i = 0; i <= end; i++) {
        if (allZeros != 1 && i == last)continue;
        ans += solve(idx + 1, tight && (i == end), i, allZeros && !i);
    }
    return ret = ans;
}
void solve() {
    int l, r; cin >> l >> r;
    s = to_string(r);
    memset(dp, -1, sizeof dp);
    int ans = solve(0, 1, 0, 1);
    s = to_string(l - 1);
    memset(dp, -1, sizeof dp);
    ans -= solve(0, 1, 0, 1);
    cout << ans << endl;
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
