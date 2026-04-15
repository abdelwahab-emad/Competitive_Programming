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
    int a; cin >> a; vector<ll>v(a);
    for(int i = 0;i < a;i++)cin >> v[i];
    ll sum = 0; ll re = v[0];
    for(int i = 0;i < a;i++) {
        sum += v[i];
        re = max(re, sum);
        if (sum < 0) {
            re = max(re, sum);
            sum = 0;
        }
    }
    cout << re;
}
signed main() {
    go();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
