#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node(){
        val = 1e18;
    }
    Node(int a){
        val = a;
    }
};

struct SparseTable {
    vector<vector<Node>> SP;
    int n;

    SparseTable(const vector<int>& v) {
        n = v.size();
        int max_log = __lg(n) + 1;
        SP.assign(max_log, vector<Node>(n));

        for (int i = 0; i < n; ++i)
            SP[0][i] = Node(v[i]);

        for (int mask = 1; (1 << mask) <= n; ++mask) {
            for (int i = 0; i + (1 << mask) <= n; ++i) {
                SP[mask][i] = merge(
                        SP[mask - 1][i],
                        SP[mask - 1][i + (1 << (mask - 1))]
                );
            }
        }
    }

    Node query01(int l, int r) {
        int mask = __lg(r - l + 1);
        return merge(
                SP[mask][l],
                SP[mask][r - (1 << mask) + 1]
        );
    }

    Node query(int l, int r) {
        Node res;
        int len = r - l + 1;
        for (int mask = 0; l <= r; ++mask) {
            if ((len >> mask) & 1) {
                res = merge(res, SP[mask][l]);
                l += (1 << mask);
            }
        }
        return res;
    }

    Node merge(const Node& a, const Node& b) {
        return Node(
                min(a.val, b.val)
        );
    }
};