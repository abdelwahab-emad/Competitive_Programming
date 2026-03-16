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
    int val;
    Node(){
        val = 0;
    }
    Node(int x){
        val = x;
    }
    void change(int x){
        val = x;
    }
};

struct SegTree {
    int tree_size;
    vector<Node> SegData;

    SegTree(int n) {
        tree_size = 1;
        while (tree_size < n) tree_size *= 2;
        SegData.assign(2 * tree_size, Node());
    }

    // change
    Node merge1(Node &lf, Node &ri) {
        Node ans = Node();
        ans.val = lf.val | ri.val;
        return ans;
    }

    Node merge2(Node &lf, Node &ri) {
        Node ans = Node();
        ans.val = lf.val ^ ri.val;
        return ans;
    }

    void inti(vector<int> &v, int n, int ni, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size())
                SegData[ni] = Node(v[lx]);
            return;
        }

        int mid = (lx + rx) / 2;
        inti(v, n - 1, 2 * ni + 1, lx, mid);
        inti(v, n - 1, 2 * ni + 2, mid, rx);
        if (n % 2 != 0)
            SegData[ni] = merge1(SegData[2 * ni + 1], SegData[2 * ni + 2]);
        else
            SegData[ni] = merge2(SegData[2 * ni + 1], SegData[2 * ni + 2]);

    }

    void inti(vector<int> &v, int n) {
        inti(v, n, 0, 0, tree_size);
    }

    void set(int idx, int val, int n, int ni, int lx, int rx) {
        if (rx - lx == 1) {
            SegData[ni].change(val);
            return;
        }

        int mid = (rx + lx) / 2;
        if (idx < mid) {
            set(idx, val, n - 1, 2 * ni + 1, lx, mid);
        } else {
            set(idx, val, n - 1, 2 * ni + 2, mid, rx);
        }
        if (n % 2 != 0)
            SegData[ni] = merge1(SegData[2 * ni + 1], SegData[2 * ni + 2]);
        else
            SegData[ni] = merge2(SegData[2 * ni + 1], SegData[2 * ni + 2]);
    }
    void set(int idx, int val, int n){
        set(idx,val,n,0,0,tree_size);
    }

    int get(){
        return SegData[0].val;
    }
};
void solve() {
    int n, q;cin >> n >> q;
    int siz = 1ll << n;
    vector<int>v(siz);
    for(int i = 0;i < siz;i++)
        cin >> v[i];

    SegTree seg(siz);
    seg.inti(v, n);
    while(q--){
        int idx, val;cin >> idx >> val;
        --idx;
        seg.set(idx, val, n);
        cout << seg.get() << endl;
    }
}
signed main() {
    Code_By_Abdelwabab
//    file();
    int t = 1;
    while(t--){
        solve();
    }
}
