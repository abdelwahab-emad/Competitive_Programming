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
string s, t;
vector<vector<int>> dp;
int go(int cur_s, int cur_t) {
    if (cur_s == s.size()) return t.size() - cur_t;
    if (cur_t == t.size()) return s.size() - cur_s;

    int &ret = dp[cur_s][cur_t];
    if (~ret) return ret;

    if (s[cur_s] == t[cur_t]) return ret = go(cur_s + 1, cur_t + 1);

    int res1 = 1 + go(cur_s, cur_t + 1);
    int res2 = 1 + go(cur_s + 1, cur_t);
    int res3 = 1 + go(cur_s + 1, cur_t + 1);

    return ret = min({res1, res2, res3});
}
void print(int cur_s, int cur_t, int pos) {
   if(cur_s == sz(s) and cur_t == sz(t))return;

    if (cur_s < sz(s) and cur_t < sz(t) and s[cur_s] == t[cur_t]) {
        print(cur_s + 1, cur_t + 1, pos);
        return;
    }
   if(cur_s == sz(s)){
       cout << "INSERT " << cur_s + pos + 1 << " " << t[cur_t] << endl;
       print(cur_s, cur_t + 1, pos + 1);
       return;
   }
    if(cur_t == sz(t)){
        cout << "DELETE " << cur_s + pos + 1 << endl;
        print(cur_s + 1, cur_t, pos - 1);
        return;
    }

    int ret = go(cur_s, cur_t);
    if(ret == 1 + go(cur_s, cur_t + 1)){
        cout << "INSERT " << cur_s + pos + 1 << " " << t[cur_t] << endl;
        print(cur_s, cur_t + 1, pos + 1);
    }
    else if (ret == 1 + go(cur_s + 1, cur_t)) {
        cout << "DELETE " << cur_s + pos + 1 << endl;
        print(cur_s + 1, cur_t, pos - 1);
    }
    else {
        cout << "REPLACE " << cur_s + pos + 1 << " " << t[cur_t] << endl;
        print(cur_s + 1, cur_t + 1, pos);
    }
}
void solve() {
    cin >> s >> t;
    dp = vector<vector<int>>(sz(s) + 1, vector<int>(sz(t) + 1, -1));
    cout << go(0, 0) << endl;
    print(0, 0, 0);
}
signed main() {
    Code_By_Abdelwabab
    int te = 1;
    //cin >> te;
    while(te--){
        solve();
    }
}
