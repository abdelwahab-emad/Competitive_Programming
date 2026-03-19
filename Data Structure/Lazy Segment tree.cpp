#include <bits/stdc++.h>
using namespace std;

#define mid ((lx + rx) / 2)
#define lNode (ni * 2 + 1)
#define rNode (ni * 2 + 2)

struct Node {
    int val, lazy;
    bool isLazy;
    Node() {
        val = 0;
        lazy = 0;
        isLazy = 0;
    }
    Node(int x) {
        val = x;
        lazy = 0;
        isLazy = 0;
    }
    void update(int x, int lx, int rx) {
        val += x * (rx - lx);
        lazy += x;
        isLazy = 1;
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
        Node ans;
        ans.val = lf.val + ri.val;
        return ans;
    }

    void propagate(int ni, int lx, int rx) {
        if (rx - lx == 1 || !SegData[ni].isLazy) return;

        SegData[lNode].update(SegData[ni].lazy, lx, mid);
        SegData[rNode].update(SegData[ni].lazy, mid, rx);

        SegData[ni].lazy = 0;
        SegData[ni].isLazy = 0;
    }

    void update(int l, int r, int val, int ni, int lx, int rx) {
        propagate(ni, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            SegData[ni].update(val, lx, rx);
            return;
        }

        update(l, r, val, lNode, lx, mid);
        update(l, r, val, rNode, mid, rx);

        SegData[ni] = merge(SegData[lNode], SegData[rNode]);
    }

    void update(int l, int r, int val) {
        update(l, r, val, 0, 0, tree_size);
    }

    Node get(int l, int r, int ni, int lx, int rx) {
        propagate(ni, lx, rx);
        if (lx >= r || rx <= l) return Node();
        if (lx >= l && rx <= r) return SegData[ni];

        Node lf = get(l, r, lNode, lx, mid);
        Node ri = get(l, r, rNode, mid, rx);

        return merge(lf, ri);
    }

    Node get(int l, int r) {
        return get(l, r, 0, 0, tree_size);
    }

    void inti(vector<int>& v, int ni, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)v.size())
                SegData[ni] = Node(v[lx]);
            return;
        }
        inti(v, lNode, lx, mid);
        inti(v, rNode, mid, rx);
        SegData[ni] = merge(SegData[lNode], SegData[rNode]);
    }

    void inti(vector<int>& v) {
        inti(v, 0, 0, tree_size);
    }
};
