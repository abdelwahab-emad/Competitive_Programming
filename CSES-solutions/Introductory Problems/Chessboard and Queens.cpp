#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
char board[10][10];int re = 0;
bool col[10], dia_l[21], dia_r[21];
void n_queens(int r) {
    if (r == 8) {
        re++;
        return;
    }
    for (int c = 0; c < 8; c++) {
        if (board[r][c]!='*'&&!col[c] && !dia_l[8 + r - c] && !dia_r[r + c]) {
            board[r][c] = 'Q';
            col[c] = dia_l[8 + r - c] = dia_r[r + c] = 1;
            n_queens(r + 1);
            board[r][c] = '.';
            col[c] = dia_l[8 + r - c] = dia_r[r + c] = 0;
        }
    }
}
void solve() {
    for(int i = 0;i < 8;i++) {
        for(int j = 0;j < 8;j++) {
            cin >> board[i][j];
        }
    }
    n_queens(0);
    cout << re;
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
