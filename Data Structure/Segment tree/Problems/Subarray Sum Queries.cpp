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


struct Node {
    int pre, suf, sum, best;

    Node() {
        pre = suf = best = 0;
        sum = 0;
    }

    Node(int x) {
        pre = suf = sum = best = x;
    }

    void change(int x) {
        pre = suf = sum = best = x;
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

    Node merge(Node &lf, Node &ri) {
        Node ans = Node();
        ans.sum = lf.sum + ri.sum;
        ans.best = max({lf.best, ri.best, lf.suf + ri.pre});
        ans.pre = max(lf.pre, lf.sum + ri.pre);
        ans.suf = max(ri.suf, ri.sum + lf.suf);
        return ans;
    }

    void inti(vector<int> &v, int ni, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size())
                SegData[ni] = Node(v[lx]);
            return;
        }
        int mid = (lx + rx) / 2;
        inti(v, 2 * ni + 1, lx, mid);
        inti(v, 2 * ni + 2, mid, rx);
        SegData[ni] = merge(SegData[2 * ni + 1], SegData[2 * ni + 2]);
    }

    void inti(vector<int> &v) {
        inti(v, 0, 0, tree_size);
    }

    void set(int idx, int val, int ni, int lx, int rx) {
        if (rx - lx == 1) {
            SegData[ni].change(val);
            return;
        }
        int mid = (rx + lx) / 2;
        if (idx < mid) {
            set(idx, val, 2 * ni + 1, lx, mid);
        } else {
            set(idx, val, 2 * ni + 2, mid, rx);
        }
        SegData[ni] = merge(SegData[2 * ni + 1], SegData[2 * ni + 2]);
    }

    void set(int idx, int val) {
        set(idx, val, 0, 0, tree_size);
    }

    Node get(int l, int r, int ni, int lx, int rx) {
        if (lx >= l and rx <= r) return SegData[ni];
        if (lx >= r or rx <= l) return Node();
        int mid = (rx + lx) / 2;
        Node lf = get(l, r, 2 * ni + 1, lx, mid);
        Node ri = get(l, r, 2 * ni + 2, mid, rx);
        return merge(lf, ri);
    }

    int get(int l, int r) {
        return get(l, r, 0, 0, tree_size).best;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    SegTree seg(n);
    seg.inti(v);
    while (q--) {
        int idx, val;
        cin >> idx >> val;
        seg.set(idx - 1, val);
        cout << max(0ll, seg.SegData[0].best) << endl;
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
