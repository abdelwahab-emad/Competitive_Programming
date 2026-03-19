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
const int N = 1e6 + 2;
vector<int> dp;
int go(int cur){
    if(cur == 0)return 0;
    int &ret = dp[cur];
    if(~ret)return ret;
    string s = to_string(cur);
    ret = 1e18;
    for(auto c : s){
        ret = min(ret, 1 + go(cur - (c - '0')));
    }
    return ret;
}
void solve() {
    int n;cin >> n;
    dp = vector<int>(n + 5, -1);
    cout << go(n);
}
signed main() {
    Code_By_Abdelwabab
    //file();
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}