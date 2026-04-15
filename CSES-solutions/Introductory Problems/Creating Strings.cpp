#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
string s;
string re;
int n;
vector<bool>v;
set<string>ans;
void go(int cnt){
    if(cnt == n){
        ans.insert(re);
    }
    for(int i = 0;i < n;i++){
        if(v[i] == 0){
            re+=s[i];
            v[i] = 1;
            go(cnt + 1);
            re.pop_back();
            v[i] = 0;
        }
    }
}
void solve() {
    cin >> s;
    n = s.size();
    v.resize(s.size());
    go(0);
    cout << ans.size() << endl;
    for(auto it = ans.begin();it != ans.end();it++){
        cout << *it << endl;
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
