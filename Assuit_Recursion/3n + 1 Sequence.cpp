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

int Sequence(int n){
    if(n == 1){
        return 1;
    }
    if(n % 2 != 0){
        return 1 + Sequence(3 * n + 1);
    }else{
        return 1 + Sequence(n / 2);
    }
}
void solve() {
    int n;
    cin >> n;
    cout << Sequence(n);
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
