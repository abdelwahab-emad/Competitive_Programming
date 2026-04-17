/* problem statement text */
/*
CSES - Labyrinth

Time limit: 1.00 s
Memory limit: 512 MB

You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.
Input
The first input line has two integers nnn and mmm: the height and width of the map.
Then there are nnn lines of mmm characters describing the labyrinth. Each character is . (floor), # (wall), A (start), or B (end). There is exactly one A and one B in the input.
Output
First print "YES", if there is a path, and "NO" otherwise.
If there is a path, print the length of the shortest such path and its description as a string consisting of characters L (left), R (right), U (up), and D (down). You can print any valid solution.
Constraints

1≤n,m≤10001 \le n,m \le 10001≤n,m≤1000

Example
Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9
LDDRRRRRU
*/

include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define Code_By_Abdelwabab_Emad ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0);
#define fori(n) for(int i = 0; i < n; i++)
#define forj(n) for(int j = 0; j < n; j++)
#define fork(n) for(int k = 0; k < n; k++)
#define gmx(x, y) ((x) = max((x), (y)))
const int N = 1009;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dir[] = {'D', 'U', 'R', 'L'};
int n, m;
char grid[N][N];
vector<vector<char>> op(N, vector<char>(N, '.'));
vector<vector<int>> dis(N, vector<int>(N, INT_MAX));
 
bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#');
}
 
void BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    dis[x][y] = 0;
 
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
 
        for (int o = 0; o < 4; o++) {
            int ii = i + dx[o], jj = j + dy[o];
            if (valid(ii, jj) && dis[ii][jj] > dis[i][j] + 1) {
                dis[ii][jj] = dis[i][j] + 1;
                q.push({ii, jj});
                op[ii][jj] = dir[o];
            }
        }
    }
}
 
void solve() {
    cin >> n >> m;
    pair<int, int> start, end;
 
    fori(n) {
        forj(m) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }
 
    int x_s = start.first, y_s = start.second;
    int x_e = end.first, y_e = end.second;
 
    BFS(x_s, y_s);
 
    if (dis[x_e][y_e] == INT_MAX) {
        cout << "NO" << endl;
        return;
    }
 
    cout << "YES" << endl << dis[x_e][y_e] << endl;
 
    deque<char>path;
    int x = x_e, y = y_e;
 
    while (x != x_s || y != y_s) {
        path.push_front(op[x][y]);
        if (op[x][y] == 'R') y--;
        else if (op[x][y] == 'L') y++;
        else if (op[x][y] == 'U') x++;
        else x--;
    }
    for (char ch : path) cout << ch;
}
 
int main() {
    Code_By_Abdelwabab_Emad
    solve();
    return 0;
}
