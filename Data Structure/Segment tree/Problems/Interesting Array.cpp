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
        val = -1;
    }
    Node(int x){
        val = x;
    }
    void change(int x){
        val = x;
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
        ans.val = lf.val & ri.val;
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
        return get(l,r,0,0,tree_size).val;
    }
};
struct query{
    int l, r,val;
};
void solve() {
    int n, q;cin >> n >> q;
    vector<int>v(n);
    vector<query>qu(q);
    for(int i = 0;i < q;i++){
        int l, r, val;cin >> l >> r >> val;
        --l;
        qu[i] = {l, r, val};
    }
    for(int bit = 0;bit < 32;bit++){
        vector<int>pre(n + 2);
        for(int i = 0;i < q;i++){
            if(qu[i].val & (1ll << bit)){
                pre[qu[i].l]++;
                pre[qu[i].r]--;
            }
        }
        for(int i = 0;i < n;i++){
            if(i > 0)
                pre[i] += pre[i - 1];
            if(pre[i] > 0)
                v[i] |= (1ll << bit);
        }
    }
    SegTree seg(n);
    seg.inti(v);
    for(auto &[l, r, val] : qu){
        if(seg.get(l, r) != val){
            cout << "NO";
            return;
        }
    }
    cout << "YES\n";
    for(auto val : v)
        cout << val << " ";
}
signed main() {
    Code_By_Abdelwabab
    // file();
    int t = 1;
    while (t--) {
        solve();
    }
}
