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
int n, x;
bool Creating_Expressoin1(int index, int cur_sum, const vector<int>& v){
    if(index == n){
        return cur_sum == x;
    }
    return Creating_Expressoin1(index + 1, cur_sum - v[index], v) or Creating_Expressoin1(index + 1, cur_sum + v[index], v);
}
void solve() {
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    cout << (Creating_Expressoin1(1, v[0], v) ? "YES" : "NO");
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}