#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int n;cin >> n;
    map<int,int>m;
    for(int i = 0;i < n - 1;i++){
        int x;cin >> x;
        m[x]++;
    }
    int i = 1;
    while(i <= n){
        if(m[i] == 0){
            cout << i;
            return;
        }
        i++;
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
}
