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
    int val[5];
    Node(){
        for(int i = 0;i < 5;i++)
            val[i] = 0;
    }
    Node(const vector<int>& m){
        for(int i = 0;i < sz(m);i++)
            val[i] = m[i];
    }
};

struct SegTree{
    int tree_size;
    vector<Node> SegData;
    int siz;
    SegTree(int n, int m){
        tree_size = 1;
        siz = m;
        while(tree_size < n) tree_size *= 2;
        SegData.assign(2 * tree_size,Node());
    }

    // change
    Node merge(Node & lf, Node & ri){
        Node ans = Node();
        for(int i = 0;i < 5;i++){
            ans.val[i] = max(lf.val[i], ri.val[i]);
        }
        return ans;
    }

    void inti(vector<vector<int>> & v, int ni, int lx, int rx){
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
    void inti(vector<vector<int>>&v){
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
    Node get(int l, int r){
        return get(l, r, 0, 0, tree_size);
    }
    int get_sum(int l, int r){
        Node ans = get(l, r);
        int sum = 0;
        for(int i = 0;i < siz;i++)sum += ans.val[i];
        return sum;
    }
};
void solve() {
    int n, m, k;cin >> n >> m >> k;
    vector<vector<int>>v(n, vector<int>(m));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++)
            cin >> v[i][j];
    }
    SegTree seg(n, m);
    seg.inti(v);
    int L = -1, R = -1,mx = 0;
    for(int i = 0;i < n;i++){
        int l = i, r = n - 1,ans = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(seg.get_sum(i, mid + 1) <= k){
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if(ans - i + 1 > mx and ans != -1){
            L = i, R = ans;
            mx = ans - i + 1;
        }
    }
    if(L == -1){
        for(int i = 0;i < m;i++)
            cout << 0 << " ";
        return;
    }
    Node ans = seg.get(L, R + 1);
    for(int i = 0;i < m;i++)
        cout << ans.val[i] << " ";
}

signed main() {
    Code_By_Abdelwabab
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
