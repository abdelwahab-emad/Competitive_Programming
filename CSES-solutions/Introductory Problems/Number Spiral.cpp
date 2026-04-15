#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int x,y;cin >> x >> y;
    int n = max(x, y);
    int val;
    if (n % 2 == 0) {
        if (x == n)
            val = n * n - y + 1;
        else
            val = (n - 1) * (n - 1) + x;
    } else {
        if (y == n){
            val = n * n - x + 1;
        }
        else
            val = (n - 1) * (n - 1) + y;
    }
    cout << val << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
