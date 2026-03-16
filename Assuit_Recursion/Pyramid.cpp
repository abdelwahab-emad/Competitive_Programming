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

void Pyramid(int cur_row, int height) {
    if (cur_row > height) {
        return;
    }

    for (int i = 0; i < height - cur_row; i++) {
        cout << " ";
    }

    for (int i = 0; i < 2 * cur_row - 1; i++) {
        cout << "*";
    }
    cout << endl;

    Pyramid(cur_row + 1, height);
}
void solve() {
    int n;
    cin >> n;
    Pyramid(1, n);
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
