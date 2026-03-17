#include <bits/stdc++.h>
using namespace std;

struct Mo {
    struct Query {
        int l, r, idx;
    };

    int n, block;
    vector<int> a;
    vector<Query> qs;
    vector<int> ans;
    int cur = 0;

    Mo(const vector<int>& v) {
        a = v;
        n = v.size();
        block = sqrt(n) + 1;
    }

    void add_query(int l, int r, int idx) {
        qs.push_back({l, r, idx});
    }

    void add(int i) {
        cur += a[i];
    }

    void remove_(int i) {
        cur -= a[i];
    }

    void process() {
        sort(qs.begin(), qs.end(), [&](const Query& x, const Query& y) {
            if (x.l / block != y.l / block)
                return x.l / block < y.l / block;
            return ((x.l / block) & 1) ? (x.r < y.r) : (x.r > y.r);
        });

        ans.assign(qs.size(), 0);

        int l = 0, r = -1;
        for (auto &q : qs) {
            while (l > q.l) add(--l);
            while (r < q.r) add(++r);
            while (l < q.l) remove_(l++);
            while (r > q.r) remove_(r--);
            ans[q.idx] = cur;
        }
    }
};

int main (){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Mo mo(v);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        mo.add_query(l - 1, r - 1, i);
    }

    mo.process();

    for (int i = 0; i < q; i++)
    {
        cout << mo.ans[i] << endl;
    }
}
