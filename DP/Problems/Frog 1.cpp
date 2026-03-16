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
const int N = 1e5 + 3;
int n;
vector<ll>v, dp;
ll solve(int idx) {
    if (idx >= n-1)return 0;
    ll& ret = dp[idx];
    if (~ret)return ret;
    ll op1 = abs(v[idx] - v[idx + 1]) + solve(idx + 1);
    ll op2 = abs(v[idx] - v[idx + 2]) + solve(idx + 2);
    return ret = min(op1, op2);
}
void solve() {
    cin >> n;
    v.resize(n + 2, 0);
    dp.resize(n + 2, -1);
    for(int i = 0;i < n;i++)
    {
        cin >> v[i];
    }
    if (n == 2)cout << abs(v[0] - v[1]);
    else
        cout << solve(0);
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
