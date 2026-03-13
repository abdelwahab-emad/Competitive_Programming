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
    int close, open, valid;
    Node(){
        close = open = valid = 0;
    }
    Node(char c){
        close = open = valid = 0;
        if(c == '(')
            open = 1;
        else
            close = 1;
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
        int valid = min(lf.open, ri.close);
        ans.valid = lf.valid + ri.valid + valid;
        ans.open = lf.open + ri.open - valid;
        ans.close = lf.close + ri.close - valid;
        return ans;
    }

    void inti(string & v, int ni, int lx, int rx){
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
    void inti(string &v){
        inti(v,0,0,tree_size);
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
        return get(l,r,0,0,tree_size).valid;
    }
};
void solve() {
    string s;cin >> s;
    SegTree seg(sz(s));
    seg.inti(s);
    int q;cin >> q;
    while(q--){
        int l, r;cin >> l >> r;
        --l;
        cout << seg.get(l, r) * 2 << endl;
    }
}
signed main() {
    Code_By_Abdelwabab
    // file();
    int t = 1;
    while(t--){
        solve();
    }
}