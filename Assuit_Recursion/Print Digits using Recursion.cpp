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
void print_Digits(int n){
    if(n == 0)return;
    print_Digits(n / 10);
    cout << n % 10 << " ";
}
void solve() {
    int n;
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return;
    }
    print_Digits(n);
    cout << endl;
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
