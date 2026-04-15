#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n;cin >> n;
    while(n != 0){
        cout << n << " ";
        if(n == 1)break;
        if(n % 2 == 1){
            n*=3;
            n++;
        }
        else
            n/=2;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
