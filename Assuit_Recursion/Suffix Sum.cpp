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
int Suffix_sum(int index, int rem, const vector<int>& v) {
    if (index < 0) {
        return 0;
    }
    if (rem == 0) {
        return Suffix_sum(index - 1, rem, v);
    } else {
        return v[index] + Suffix_sum(index - 1, rem - 1, v);
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << Suffix_sum(n - 1, m, v);
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
