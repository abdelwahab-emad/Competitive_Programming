/* problem statement text */
/*
CSES - Counting Rooms

Time limit: 1.00 s
Memory limit: 512 MB

You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n×mn \times mn×m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
Input
The first input line has two integers nnn and mmm: the height and width of the map.
Then there are nnn lines of mmm characters describing the map. Each character is either . (floor) or # (wall).
Output
Print one integer: the number of rooms.
Constraints

1≤n,m≤10001 \le n,m \le 10001≤n,m≤1000

Example
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3
*/

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
const int N = 1001;
int dx [] = {1,-1,0,0};
int dy [] = {0,0,1,-1};
char grid[N][N];
bool vis[N][N];
int n,m;
bool valid(int i,int j){
    return (i>=0 and i < n and j >=0 and j<m and grid[i][j] == '.');
}
void dfs(int i,int j){
    vis[i][j] = 1;
    for(int k = 0;k < 4;k++){
        int ii = i + dx[k];
        int jj = j + dy[k];
        if(!vis[ii][jj] and valid(ii,jj)){
            dfs(ii,jj);
        }
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++)cin >> grid[i][j];
    }
    int counter = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(!vis[i][j] and grid[i][j] == '.'){
                dfs(i,j);
                counter++;
            }
        }
    }
    cout << counter;
}
signed main() {
    Code_By_Abdelwabab
    //  file();
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
