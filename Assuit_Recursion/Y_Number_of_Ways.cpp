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
int Number_of_Ways(int cur, int e){
    if(cur >= e){
        return cur == e;
    }
    return Number_of_Ways(cur + 1, e) + Number_of_Ways(cur + 2, e) + Number_of_Ways(cur + 3, e);
}
void solve() {
    int s, e;
    cin >> s >> e;
    cout << Number_of_Ways(s, e);
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}