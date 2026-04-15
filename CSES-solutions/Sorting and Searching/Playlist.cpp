#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <iomanip>
#include <cstring>
using namespace std;
#define ll long long
#define endl "\n"
#define speed ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);
#define fori(n) for(int i =0;i<n;i++)
#define forj(n) for(int j =0;j<n;j++)
#define fork(n) for(int k =0;k<n;k++)
#define sortv sort(v.begin(),v.end())
#define sortv1 sort(v1.begin(),v1.end())
#define sortv2 sort(v2.begin(),v2.end())
#define reversev reverse(v.begin(),v.end())
#define reversev1 reverse(v1.begin(),v1.end())
#define reversev2 reverse(v2.begin(),v2.end())
int main() {
    speed;
    int a; cin >> a; vector<int>v(a); fori(a)cin >> v[i];
    map<int, int>m;
    int count = 0, re = 0;
    int l = 0, r = 0;
    while (r < a) {
        if (m[v[r]] == 0) {
            m[v[r]]++;
            r++;
            count++;
        }
        else {
            m[v[l]]--;
            l++; count--;
        }
        re = max(re, count);
    }
    cout << re;
}