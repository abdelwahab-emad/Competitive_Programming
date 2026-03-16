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
    return ((a%mod)+(b%mod))%mod;
}
vector<int>dp;
int n;
int go(int sum) {
    if (sum == n)return 1;
    if (sum > n)return 0;
    int &ret = dp[sum];
    if (~ret)return ret;
    ret = 0;
    for (int i = 1; i <= 6; i++) {
        ret = add(ret, go(sum + i));
    }
    return ret;
}
void solve() {
    cin >> n;
    dp.resize(n + 1, -1);
    cout << go(0);
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
