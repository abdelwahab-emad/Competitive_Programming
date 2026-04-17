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

void solve() {
    int n;cin >> n;
    vector<int> v(n);
    for(int i = 0;i < n;i++)cin >> v[i];
    stack<int> st;
    cout << 0 << " ";
    st.push(0);
    for(int i = 1;i < n;i++){
        while(!st.empty() and v[st.top()] >= v[i])st.pop();
        if(!st.empty()){
            cout << st.top() + 1 << " ";
        }else {
            cout << 0 << " ";
        }
        st.push(i);
    }
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
