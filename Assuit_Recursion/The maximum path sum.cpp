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
int n, m;
int Max_path(int row, int col, const vector<vector<int>>& grid){
    if(row == n - 1 and col == m - 1){
        return grid[row][col];
    }
    int right = -1e18, down = -1e18;
    if(col + 1 < m){
        right = max(right, Max_path(row, col + 1, grid));
    }
    if(row + 1 < n){
        down = max(down, Max_path(row + 1, col, grid));
    }
    return max(right, down) + grid[row][col];
}
void solve() {
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> grid[i][j];
        }
    }
    cout << Max_path(0, 0, grid);
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
