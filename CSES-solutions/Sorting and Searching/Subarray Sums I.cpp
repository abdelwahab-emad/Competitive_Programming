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

void solve(){
    ll a,x; cin >> a >> x; vector<ll>v(a);
    for(int i = 0;i < a;i++)cin >> v[i];
    ll sum = 0;
    int l = 0, r = 0; int count = 0;
    while (l < a) {
        if (sum > x) {
            sum -= v[l];
            l++;
        }
        else if (r<a&&sum <= x) {
            sum += v[r];
            r++;
        }
        if (sum == x)count++;
        if (r == a) {
            sum -= v[l];
            l++;
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
