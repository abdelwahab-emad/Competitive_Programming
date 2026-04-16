#include <bits/stdc++.h>
using namespace std;
void file(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
#define Code_By_Abdelwabab ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"
#define int long long
#define ll long long
#define ld long double
#define sz(s) (int)(s).size()

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 0});
        v.push_back({b, 1});
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (auto &val: v) {
        if (val.second == 0)cnt++;
        else cnt--;
        res = max(res, cnt);
    }
    cout << res << endl;
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
}
