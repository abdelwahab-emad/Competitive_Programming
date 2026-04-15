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
    int n, m;
    cin >> n >> m;
    vector<int> v(n), v1(m);
    for (int i = 0; i < n; i++)cin >> v[i];
    for (int i = 0; i < m; i++)cin >> v1[i];
    multiset<int> st;
    for (int i = 0; i < n; i++)st.insert(v[i]);
    for (int i = 0; i < m; i++) {
        auto it = st.upper_bound(v1[i]);
        if (it == st.begin())cout << -1 << endl;
        else {
            it--;
            cout << *it << endl;
            st.erase(it);
        }
    }
}
signed main() {
    go();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
