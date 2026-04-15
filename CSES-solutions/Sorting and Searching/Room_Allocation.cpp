#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

#define endl "\n"
#define int long long
#define ll long long
#define ld long double

void solve () {
    int n;cin >> n;
    vector<pair<pair<int,int>,int>>v(n);
    for(int i = 0;i < n;i++){
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    map<int,int>m;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int rooms = 0;
    for(int i = 0;i < n;i++){
        if(pq.empty()){
            rooms++;
            m[v[i].second] = rooms;
            pq.push({v[i].first.second + 1, rooms});
        }
        else{
            if(pq.top().first <= v[i].first.first){
                m[v[i].second] = pq.top().second;
                int x = pq.top().second;
                pq.pop();
                pq.push({v[i].first.second + 1, x});
            }
            else{
                rooms++;
                m[v[i].second] = rooms;
                pq.push({v[i].first.second + 1, rooms});
            }
        }
    }
    cout << rooms << endl;
    for(auto it : m){
        cout << it.second << " ";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //   cin >> t;
    while(t--){
        solve();
    }
}