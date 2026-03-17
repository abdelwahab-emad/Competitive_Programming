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

const int N = 1e6 + 5;
const int MAX_N = 50005;

vector<bool> isPrime(N, 1);
vector<int> divide(N);
int frq[N];
int mxfrq[MAX_N];

void sieve()
{
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            divide[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = 0;
                if (divide[j] == 0)
                    divide[j] = i;
            }
        }
    }
}

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

    Mo(const vector<int> &v)
    {
        a = v;
        n = v.size();
        block = sqrt(n) + 1;
    }

    void add_query(int l, int r, int idx)
    {
        qs.push_back({l, r, idx});
    }

    void add(int i)
    {
        int x = a[i];
        while (x > 1)
        {
            int p = divide[x];
            mxfrq[frq[p]]--;
            frq[p]++;
            mxfrq[frq[p]]++;
            cur = max(cur, frq[p]);
            while (x % p == 0)
                x /= p;
        }
    }

    void remove_(int i)
    {
        int x = a[i];
        while (x > 1)
        {
            int p = divide[x];
            mxfrq[frq[p]]--;
            if (cur == frq[p] && mxfrq[cur] == 0)
                cur--;
            frq[p]--;
            mxfrq[frq[p]]++;
            while (x % p == 0)
                x /= p;
        }
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
        cur = 0;

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
        while (l <= r) remove_(l++);
        cur = 0;
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
        mo.add_query(l - 1, r - 1, i);
    }

    mo.process();

    for (int i = 0; i < q; i++)
        cout << mo.ans[i] << endl;
}

int main()
{
    Code_By_Abdelwabab
    file();
    sieve();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
