#include <bits/stdc++.h>
using namespace std;

void go() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

#define endl "\n"
#define ll long long
#define int long long


void solve(){
    ll a, b;
    cin >> a >> b;
    vector <ll>v(a);
    vector<pair<ll, ll>>v1;
    for(int i = 0;i < a;i++) {
        cin >> v[i];
        v1.push_back({ v[i],i });
    }
    sort(v1.begin(),v1.end());
    ll x;
    for (int i = 0; i < a; i++) {
        int l = i+1, r = a - 1;
        x = v1[i].second + 1;
        ll ans = b - v1[i].first;
        while (l < r) {
            if (v1[l].first + v1[r].first > ans)
                r--;
            else if (v1[l].first + v1[r].first < ans)
                l++;
            else if(v1[l].first + v1[r].first==ans&& v1[l].second + 1!=x&& v1[r].second + 1!=x){
                cout << v1[l].second + 1 << " " << v1[r].second + 1 << " " << x;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
signed main() {
    go();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
