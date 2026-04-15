#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n;cin >> n;vector<int>v(n);
    for(int i = 0;i < n;i++)cin >> v[i];
    int sum = 0;
    for(int i = 0;i < n - 1;i++){
        if(v[i] > v[i + 1]){
            sum+=v[i] - v[i + 1];
            v[i + 1] = v[i];
        }
    }
    cout << sum;
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
