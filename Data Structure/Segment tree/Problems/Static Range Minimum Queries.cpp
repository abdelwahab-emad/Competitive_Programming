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
    int mi;
    Node(){
        mi = 1e15;
    }
    Node(int x){
        mi = x;
    }
    void change(int x){
        mi = x;
    }
};

struct SegTree{
    int tree_size;
    vector<Node> SegData;

    SegTree(int n){
        tree_size = 1;
        while(tree_size < n) tree_size *= 2;
        SegData.assign(2 * tree_size,Node());
    }

    // change
    Node merge(Node & lf, Node & ri){
        Node ans = Node();
        ans.mi = min(lf.mi, ri.mi);
        return ans;
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

        int mid = (rx + lx) / 2;
        if(idx < mid){
            set(idx,val,2 * ni + 1,lx ,mid);
        }
        else{
            set(idx,val,2 * ni + 2,mid,rx);
        }

        SegData[ni] = merge(SegData[2 * ni + 1],SegData[2 * ni + 2]);
    }

    void set(int idx, int val){
        set(idx,val,0,0,tree_size);
    }

    Node get(int l, int r, int ni, int lx, int rx){
        if(lx >= l and rx <= r){
            return SegData[ni];
        }
        if(lx >= r or rx <= l){
            return Node();
        }

        int mid = (rx + lx) / 2;
        Node lf = get(l,r,2 * ni + 1,lx,mid);
        Node ri = get(l,r,2 * ni + 2,mid,rx);

        return merge(lf,ri);
    }

    int get(int l,int r){
        return get(l,r,0,0,tree_size).mi;
    }
};
void solve() {
    int n,q;cin >> n >> q;
    vector<int>v(n + 1);
    for(int i = 1;i <= n;i++)cin >> v[i];
    SegTree seg(n + 1);
    seg.inti(v);
    while(q--){
        int l,r;cin >> l >> r;
        r++;
        cout << seg.get(l,r) << endl;
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
