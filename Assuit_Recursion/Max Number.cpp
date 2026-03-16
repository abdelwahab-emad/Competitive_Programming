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
int Max_Number(int index, const vector<int>& v){
    if(index == sz(v)){
        return -1e18;
    }
    return max(Max_Number(index + 1, v), v[index]);
}
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    cout << Max_Number(0, v);
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
