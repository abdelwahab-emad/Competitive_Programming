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
    int a, b;
    Node(){
        a = 0, b = 0;
    }
    Node(int val1, int val2){
        a = val1, b = val2;
    }
    void change(int val1, int val2){
        a = val1, b = val2;
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
        ans.a = lf.a + ri.a;
        ans.b = lf.b + ri.b;
        return ans;
    }

    void inti(vector<pair<int,int>> & v, int ni, int lx, int rx){
        if(rx - lx == 1){
            if(lx < v.size())
                SegData[ni] = Node(v[lx].first, v[lx].second);
            return;
        }

        int mid = (lx + rx) / 2;
        inti(v,2 * ni + 1,lx ,mid);
        inti(v,2 * ni + 2,mid ,rx);

        SegData[ni] = merge(SegData[2 * ni + 1],SegData[2 * ni + 2]);
    }
    void inti(vector<pair<int,int>>&v){
        inti(v,0,0,tree_size);
    }
    void set(int idx, int val1, int val2,  int ni, int lx, int rx){
        if(rx - lx == 1){
            SegData[ni].change(val1, val2);
            return;
        }

        int mid = (rx + lx) / 2;
        if(idx < mid){
            set(idx,val1, val2,2 * ni + 1,lx ,mid);
        }
        else{
            set(idx,val1, val2, 2 * ni + 2,mid,rx);
        }

        SegData[ni] = merge(SegData[2 * ni + 1],SegData[2 * ni + 2]);
    }

    void set(int idx, int val1, int val2){
        set(idx,val1, val2, 0,0,tree_size);
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

    Node get(int l,int r){
        return get(l,r,0,0,tree_size);
    }
};
void solve() {
    int n, k, a, b, q;cin >> n >> k >> a >> b >> q;
    vector<pair<int,int>>v(n, {0, 0});
    SegTree seg(n);
    seg.inti(v);
    while(q--){
        int ope;cin >> ope;
        if(ope == 1){
            int idx, val;cin >> idx >> val;
            --idx;
            v[idx].first = min(a, v[idx].first + val);
            v[idx].second = min(b, v[idx].second + val);
            seg.set(idx, v[idx].first, v[idx].second);
        }
        else{
            int idx;cin >> idx;
            --idx;
            int l = idx - 1,r = idx + k;
            int sum = 0;
            if(l >= 0){
                sum += seg.get(0, l + 1).b;
            }
            sum += seg.get(r, n).a;
            cout << sum << endl;
        }
    }
}
signed main() {
    Code_By_Abdelwabab
    //  file();
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
