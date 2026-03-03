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
const int Size = 30;
int w[Size], v[Size];
int N, W;
int Knapsack(int index, int cur_w){
    if(index == N){
        return 0;
    }
    int leave = Knapsack(index + 1, cur_w);
    int take = 0;
    if(cur_w >= w[index]){
        take = Knapsack(index + 1, cur_w - w[index]) + v[index];
    }
    return max(leave, take);
}
void solve() {
    cin >> N >> W;
    for(int i = 0;i < N;i++){
        cin >> w[i] >> v[i];
    }
    cout << Knapsack(0, W);
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}