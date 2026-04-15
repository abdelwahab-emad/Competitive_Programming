#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int a,b;cin >> a >> b;
    int x = (-a + 2 * b) / 3;
    int y = (2 * a - b) / 3;
    if(x < 0 or y < 0){
        cout << "NO" << endl;
        return;
    }
    int aa = x + 2 * y;
    int bb = 2 * x + y;
    if(aa != a or bb != b){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
