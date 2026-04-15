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
    int n, k; cin >> n >> k;
    vector<int>v(n);
    for(int i = 0;i < n;i++)cin >> v[i];
    map<int,int>m;
    int l = 0, r = 0;
    int sub = 0;
    while (r < n) {
        m[v[r]]++;
        while (m.size() > k) {
            m[v[l]]--;
            if(m[v[l]] == 0)m.erase(v[l]);
            l++;
        }
        sub += (r - l + 1);
        r++;
    }
    cout << sub;
}
signed main() {
    go();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}