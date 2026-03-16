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


struct Node{
    int mx;

    Node (){
        mx = 0;
    }

    Node(int val){
        mx = val;
    }

    void change(int val){
        mx -= val;
    }
};

struct SegTree{
    int tree_size;
    vector<Node>SegData;

    SegTree(int n){
        tree_size = 1;
        while(tree_size < n)tree_size *= 2;
        SegData.assign(tree_size * 2, Node());
    }

    Node merge(Node &lf , Node &ri){
        Node res;
        res.mx = max(lf.mx, ri.mx);
        return res;
    }

    void inti(vector<int> & v, int ni, int lx, int rx){
        if(rx - lx == 1){
            if(lx < v.size())
                SegData[ni] = Node(v[lx]);
            return;
        }
        int mid = (lx + rx) / 2;
        inti(v,2 * ni + 1,lx ,mid);
        inti(v,2 * ni + 2,mid ,rx);

        SegData[ni] = merge(SegData[2 * ni + 1],SegData[2 * ni + 2]);
    }
    void inti(vector<int>&v){
        inti(v,0,0,tree_size);
    }

    void set(int idx, int val, int ni, int lx, int rx){
        if(rx - lx == 1){
            SegData[ni].change(val);
            return;
        }
        int mid = (lx + rx) / 2;

        if(idx < mid){
            set(idx, val, 2 * ni + 1, lx, mid);
        }
        else{
            set(idx, val, 2 * ni + 2, mid, rx);
        };

        SegData[ni] = merge(SegData[2 * ni + 1], SegData[2 * ni + 2]);
    }

    void set(int idx, int val){
        set(idx, val,0, 0, tree_size);
    }

    int get(int val, int ni, int lx, int rx){
        if(rx - lx == 1)return lx;
        int mid = (lx + rx) / 2;
        int mx_left = SegData[2 * ni + 1].mx;
        if(mx_left >= val){
            return get(val, 2 * ni + 1, lx, mid);
        }
        return get(val, 2 * ni + 2, mid, rx);
    }
    int get(int val){
        return get(val, 0, 0, tree_size);
    }
};
void solve() {
    int n, m;cin >> n >> m;
    vector<int>h(n), r(m);
    for(int i = 0;i < n;i++)cin >> h[i];
    for(int i = 0;i < m;i++)cin >> r[i];

    SegTree seg(n);

    seg.inti(h);

    for(int i = 0;i < m;i++){
        if(seg.SegData[0].mx < r[i]){
            cout << 0 << " ";
        }
        else{
            int ans = seg.get(r[i]);
            cout << ans + 1 << " ";
            seg.set(ans, r[i]);
        }
    }
}

signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
