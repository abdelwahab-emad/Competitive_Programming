#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
void solve() {
    int n;cin >> n;vector<int>v(n);
    int sum = 0;
    for(int i = 0;i < n;i++){
        cin >> v[i];
        sum += v[i];
    }
    int mi = sum;
    for(int mask = 1;mask < (1 << n);mask++) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                cur += v[i];
            }
        }
        int rem = sum - cur;
        mi = min(mi, abs(rem - cur));
    }
    cout << mi;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
