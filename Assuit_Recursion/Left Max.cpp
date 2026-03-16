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
void Left_Max(int index, int mx, const vector<int>& v){
    if(index == sz(v)){
        return;
    }
    cout << max(mx, v[index]) << " ";
    Left_Max(index + 1, max(mx, v[index]), v);
}
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    Left_Max(0, -1e18, v);
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
