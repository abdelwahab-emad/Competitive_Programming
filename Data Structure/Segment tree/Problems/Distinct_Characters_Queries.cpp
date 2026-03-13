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
    bitset<26> b;
    Node() {
        b = bitset<26>(0);
    }
    Node(int x) {
        b[x] = 1;
    }
    void change(int x) {
        b[x] = 1;
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

    Node merge(Node& lf, Node& ri) {
        Node ans = Node();
        for (int i = 0; i < 26; i++) {
            ans.b[i] = (lf.b[i] | ri.b[i]);
        }
        return ans;
    }

    void inti(vector<int>& v, int ni, int lx, int rx) {
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

    void inti(vector<int>& v) {
        inti(v, 0, 0, tree_size);
    }

    void set(int idx, int val, int pre, int ni, int lx, int rx) {
        if (rx - lx == 1) {
            SegData[ni].b[pre] = 0;
            SegData[ni].change(val);
            return;
        }
        int mid = (rx + lx) / 2;
        if (idx < mid) {
            set(idx, val, pre, 2 * ni + 1, lx, mid);
        } else {
            set(idx, val, pre, 2 * ni + 2, mid, rx);
        }
        SegData[ni] = merge(SegData[2 * ni + 1], SegData[2 * ni + 2]);
    }

    void set(int idx, int val, int pre) {
        set(idx, val, pre, 0, 0, tree_size);
    }

    Node get(int l, int r, int ni, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return Node();
        }
        if (lx >= l && rx <= r) {
            return SegData[ni];
        }
        int mid = (rx + lx) / 2;
        Node lf = get(l, r, 2 * ni + 1, lx, mid);
        Node ri = get(l, r, 2 * ni + 2, mid, rx);
        return merge(lf, ri);
    }

    int get(int l, int r) {
        return __builtin_popcountl(get(l, r, 0, 0, tree_size).b.to_ulong());
    }
};

void solve() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = s[i] - 'a';
    }
    SegTree st(n);
    st.inti(v);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int idx;
            char val;
            cin >> idx >> val;
            idx--;
            st.set(idx, val - 'a', s[idx] - 'a');
            s[idx] = val;
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << st.get(l, r) << endl;
        }
    }
}
signed main() {
    Code_By_Abdelwabab
    file();
    int t = 1;
 //   cin >> t;
    while(t--){
        solve();
    }
}