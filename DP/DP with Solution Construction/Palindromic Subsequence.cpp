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
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int N = 1000 + 2;
string s; int dp[N][N];
int go(int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == r)return 1;
    int& ret = dp[l][r];
    if (~ret)return ret;
    int op1 = go(l, r - 1);
    int op2 = go(l + 1, r);
    int op3 = 0;
    if (s[l] == s[r])op3 = 2 + go(l + 1, r - 1);
    return ret = max({ op1,op2,op3 });
}
string dp2[N][N];
bool vis[N][N];
string build(int l, int r) {
    if (l > r)return "";
    if (l == r)return s.substr(l, 1);
    string& ret = dp2[l][r];
    if (vis[l][r])return ret;
    vis[l][r] = 1;
    int op1 = go(l, r - 1);
    int op2 = go(l + 1, r);
    int op3 = 0;
    if (s[l] == s[r])op3 = 2 + go(l + 1, r - 1);
    int ans = go(l, r);
    string mi = "{";
    if (op1 == ans) {
        mi = min(mi, build(l, r - 1));
    }
    if (op2 == ans) {
        mi = min(mi, build(l + 1, r));
    }
    if (op3 == ans) {
        mi = min(mi, s.substr(l, 1) + build(l + 1, r - 1) + s.substr(r, 1));
    }
    return ret = mi;
}
void solve() {
    while (cin >> s) {
        memset(dp, -1, sizeof dp);
        memset(vis, 0, sizeof vis);
        cout << build(0, s.size() - 1) << endl;
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

