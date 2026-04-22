#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n,q;cin >> n >> q;
    vector<int>v(n + 1),prf(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> v[i];
        prf[i] = v[i];
    }
    for(int i = 2;i <= n;i++){
        prf[i] += prf[i - 1];
    }
    while(q--){
        int l,r;cin >> l >> r;
        cout << prf[r] - prf[l - 1] << endl;
    }
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