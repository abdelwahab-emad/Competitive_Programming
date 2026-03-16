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
int nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 or r == n) return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}
void solve() {
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r);
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
