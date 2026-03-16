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
const int N = 10000 + 2,mod = 1e9 + 7;
int add(int a,int b){
    return ((a % mod) + (b % mod)) % mod;
}
string k;int d;
int dp[N][2][102];
int go(int idx,bool tight,int sum) {
    if (idx == k.size()) {
        return sum % d == 0;
    }
    int &ret = dp[idx][tight][sum];
    if (~ret)return ret;
    ret = 0;
    int end = tight == 1 ? k[idx] - '0' : 9;
    for (int i = 0; i <= end; i++) {
        ret = add(ret, go(idx + 1, tight and i == end, (sum + i) % d));
    }
    return ret;
}
void solve() {
    cin >> k >> d;
    memset(dp,-1,sizeof(dp));
    cout << (go(0,1,0) - 1 + mod) % mod;
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
