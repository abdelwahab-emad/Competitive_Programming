#include <bits/stdc++.h>
using namespace std;

void go() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

#define endl "\n"
#define ll long long
#define int long long

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    int count = 0;
    while (i <= j) {
        if (v[i] + v[j] <= x)i++;
        j--;
        count++;
    }
    cout << count;
}
signed main() {
    go();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
