#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n;cin >> n;
    int re = 0;
    int x = 5;
    while (x <= n) {
        re += n / x;
        x *= 5;
    }
    cout << re;
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
