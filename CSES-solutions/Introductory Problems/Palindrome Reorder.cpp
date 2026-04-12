#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    string s;cin >> s;
    map<char,int>m;
    for(int i = 0;i < s.size();i++)m[s[i]]++;
    char c = '.';
    for(auto it : m){
        if(it.second % 2 == 1){
            if(c != '.'){
                cout << "NO SOLUTION";
                return;
            }
            c = it.first;
        }
    }
    string re;
    for(auto it : m){
        if(it.second % 2 == 1)it.second--;
        it.second/=2;
        while(it.second--)re+=it.first;
    }
    cout << re;
    if(c != '.')cout << c;
    reverse(re.begin(),re.end());
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
