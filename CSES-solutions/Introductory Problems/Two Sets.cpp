#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n;
    cin >> n;
    int x = n * (n + 1) / 2;
    if (x % 2 == 1) {
        cout << "NO";
        return;
    }
    cout << "YES" << endl;
    vector<int> re(n + 1);
    int tar = x / 2;
    int cnt = 0;
    for (int i = n; i >= 1; i--) {
        if (i <= tar) {
            tar -= i;
            re[i] = 1;
            cnt++;
        }
        if (tar == 0)break;
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
        if (re[i] == 1)cout << i << " ";
    }
    cout << endl;
    cout << n - cnt << endl;
    for (int i = 1; i <= n; i++) {
        if (re[i] == 0)cout << i << " ";
    }
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
