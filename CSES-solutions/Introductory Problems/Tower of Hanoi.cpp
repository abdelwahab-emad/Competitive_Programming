#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
void hanoi(int n, int a,int b,int c) {
    if (n == 0) return;
    hanoi(n - 1,a,c,b);
    cout << a << " " << c << endl;
    hanoi(n - 1,b,a,c);
}

void solve() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    hanoi(n,1,2,3);
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
