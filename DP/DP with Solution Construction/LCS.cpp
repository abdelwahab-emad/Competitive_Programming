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
string s, t;
const int N = 3001;
int memo[N][N];
int dp(int i, int o) {
    if (i == s.size() || o == t.size())return 0;
    int &ret = memo[i][o];
    if (~ret)return ret;
    if (s[i] == t[o]) {
        return ret = dp(i + 1, o + 1) + 1;
    }
    return ret = max(dp(i + 1, o), dp(i, o + 1));
}
void print(int i, int o) {
    if (i == s.size() || o == t.size())return;
    int &ret = memo[i][o];
    if (s[i] == t[o]) {
        cout << s[i];
        print(i + 1, o + 1);
        return;
    }
    if (ret == dp(i + 1, o))print(i + 1, o);
    else if (ret == dp(i, o + 1))print(i, o + 1);
}
void solve() {
    cin >> s >> t;
    for (int i = 0; i < 3001; i++) {
        for (int j = 0; j < 3001; j++)
            memo[i][j] = -1;
    }
    dp(0, 0);
    print(0, 0);
}
signed main() {
    Code_By_Abdelwabab
    int te = 1;
    //cin >> te;
    while(te--){
        solve();
    }
}