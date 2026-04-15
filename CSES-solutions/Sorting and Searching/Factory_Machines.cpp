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

ll a, b;
ll  can(vector<ll>&v, ll mid) {
    ll sum = 0;
    for (int i = 0; i < a; i++) {
        sum += mid / v[i];
    }
    return sum;
}
void solve() {
    cin >> a >> b;
    vector<ll>v(a);
    for (int i = 0; i < a; i++)cin >> v[i];
    sort(v.begin(),v.end());
    ll l = v[0], r = v[0]*2*b, ans;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll re = can(v, mid);
        if (re >= b) {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
}
signed main() {
    go();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
