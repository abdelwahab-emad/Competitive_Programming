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

const int mod = 1e9 + 7;
int n, x;
vector<int>v,dp;
int go(int cur_sum) {
    if (cur_sum <= 0)return cur_sum == 0;
    int &ret = dp[cur_sum];
    if (~ret)return ret;
    ret = 0;
    for (int i = 0; i < n; i++) {
        if (cur_sum >= v[i]) {
            ret += go(cur_sum - v[i]);
            if (ret >= mod)ret -= mod;
        }
    }
    return ret;
}
void solve() {
    cin >> n >> x;
    v.resize(n);
    dp.resize(x + 1, -1);
    for (int i = 0; i < n; i++)cin >> v[i];
    cout << go(x);
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}