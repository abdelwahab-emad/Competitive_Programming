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
int r, c;
void Sum_of_a_Matrix(int row, int col, const vector<vector<int>>& a, vector<vector<int>>& b) {
    if (row == r) {
        return;
    }

    cout << a[row][col] + b[row][col] << (col == c - 1 ? "" : " ");

    if (col + 1 < c) {
        Sum_of_a_Matrix(row, col + 1, a, b);
    } else {
        cout << endl;
        Sum_of_a_Matrix(row + 1, 0, a, b);
    }
}
void solve() {
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    vector<vector<int>> b(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> b[i][j];
        }
    }
    Sum_of_a_Matrix(0, 0, a, b);
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
