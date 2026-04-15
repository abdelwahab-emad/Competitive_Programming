#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int mod = 1e9 + 7;
    int n;cin >> n;
    int res = 1;
    while(n--){
        res = (res * 2) % mod;
    }
    cout << res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
