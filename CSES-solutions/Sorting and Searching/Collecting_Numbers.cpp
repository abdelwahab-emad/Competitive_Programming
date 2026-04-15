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
    int a; cin >> a; vector<int>v(a);
    for(int i = 0;i < a;i++)cin >> v[i];
    map<int, int>m;
    vector<ll>re;
    re.push_back(v[0] + 1); m[v[0] + 1]++;
    for (int i = 1; i < a; i++) {
        if (m[v[i]] == 0)re.push_back(v[i] + 1);
        m[v[i] + 1]++;
    }
    cout << re.size();
}
signed main() {
    go();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}