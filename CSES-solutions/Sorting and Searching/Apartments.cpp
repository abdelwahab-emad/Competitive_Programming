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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n), v1(m);
    for (int i = 0; i < n; i++)cin >> v[i];
    for (int i = 0; i < m; i++)cin >> v1[i];
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    sort(v1.begin(), v1.end());
    reverse(v1.begin(), v1.end());
    int count = 0, j = 0;
    for (int i = 0; i < m;) {
        if (j == n)break;
        if (abs(v[j] - v1[i]) <= k) {
            count++;
            j++;
            i++;
        } else if (v[j] > v1[i]) {
            j++;
        } else if (v[j] < v1[i]) {
            i++;
        }
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