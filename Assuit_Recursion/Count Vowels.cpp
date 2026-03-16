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
string s;
int Count_Vowels(int index){
    if(index == sz(s)){
        return 0;
    }
    char c = tolower(s[index]);
    if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
        return 1 + Count_Vowels(index + 1);
    else
        return Count_Vowels(index + 1);
}
void solve() {
    getline(cin, s);
    cout << Count_Vowels(0);
}
signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
