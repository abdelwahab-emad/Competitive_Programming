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

int n, k;vector<ll>v;
bool can(ll mid) {
    ll sum = 0;
    ll x = 1;
    for(int i = 0;i < n;i++) {
        if (sum + v[i] <= mid) {
            sum += v[i];
        }
        else {
            x++;
            sum = v[i];
        }
    }
    return x <= k;
}
void solve() {
    cin >> n >> k;
    v.resize(n);
    ll sum = 0,ma=0;
    for(int i = 0;i < n;i++)cin >> v[i], sum += v[i], ma = max(ma, v[i]);
    ll l = ma, r = sum, ans = ma;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
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
