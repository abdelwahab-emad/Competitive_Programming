#include <bits/stdc++.h>
using namespace std;
void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
#define Code_By_Abdelwabab       \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl "\n"
#define int long long
#define ll long long
#define ld long double
#define sz(s) (int)(s).size()
const int N = 1e6 + 1;
struct Mo
{
    struct Query
    {
        int l, r, idx;
    };

    int n, block;
    vector<int> a;
    vector<Query> qs;
    vector<int> ans;
    int cur = 0;
    vector<int> frq;
    vector<int> mxfrq;
    Mo(const vector<int> &v)
    {
        a = v;
        n = v.size();
        block = sqrt(n) + 1;
        frq = vector<int>(N);
        mxfrq = vector<int>(n + 1);
    }

    void add_query(int l, int r, int idx)
    {
        qs.push_back({l, r, idx});
    }

    void add(int i)
    {
        mxfrq[frq[a[i]]]--;
        frq[a[i]]++;
        mxfrq[frq[a[i]]]++;
        cur = max(cur, frq[a[i]]);
    }

    void remove_(int i)
    {
        mxfrq[frq[a[i]]]--;
        if(cur == frq[a[i]] and mxfrq[cur] == 0)cur--;
        frq[a[i]]--;
        mxfrq[frq[a[i]]]++;
    }

    void process()
    {
        sort(qs.begin(), qs.end(), [&](const Query &x, const Query &y)
        {
            if (x.l / block != y.l / block)
                return x.l / block < y.l / block;
            return ((x.l / block) & 1) ? (x.r < y.r) : (x.r > y.r); });

        ans.assign(qs.size(), 0);

        int l = 0, r = -1;
        for (auto &q : qs)
        {
            while (l > q.l)
                add(--l);
            while (r < q.r)
                add(++r);
            while (l < q.l)
                remove_(l++);
            while (r > q.r)
                remove_(r--);
            ans[q.idx] = cur;
        }
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    Mo mo(v);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        mo.add_query(l, r, i);
    }

    mo.process();

    for (int i = 0; i < q; i++)
        cout << mo.ans[i] << endl;
}

signed main()
{
    Code_By_Abdelwabab
    file();
    solve();
}
