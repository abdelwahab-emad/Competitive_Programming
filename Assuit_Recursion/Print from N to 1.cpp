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

void print_from_n_to_1(int n){
    if(n == 0)return;
    cout << n;
    if(n > 1)cout << " ";
    print_from_n_to_1(n - 1);
}
void solve() {
    int n;
    cin >> n;
    print_from_n_to_1(n);
}

signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
