#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n;
    cin >> n;
    int total = 1 << n;
    for (int i = 0; i < total; i++) {
        int gray = i ^ (i >> 1);
        bitset<16> b(gray);
        cout << b.to_string().substr(16 - n) << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
