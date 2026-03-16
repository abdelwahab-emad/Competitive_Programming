#include <bits/stdc++.h>
using namespace std;

void file() {
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

// for n = 1e9 in 0.5s

vector<int32_t> sieve(const int32_t _n, const int32_t Q = 17, const int32_t L = 1 << 15) {
    static const int32_t rs[] = {1, 7, 11, 13, 17, 19, 23, 29};
    struct P {
        P(int32_t p) : p(p) {}
        int32_t p; int32_t pos[8];
    };
    auto approx_prime_count = [] (const int32_t x) -> int32_t {
        return x > 60184 ? x / (log(x) - 1.1)
                         : max(1.0, x / (log(x) - 1.11)) + 1;
    };

    const int32_t v = sqrt(_n), vv = sqrt(v);
    vector<bool> isp(v + 1, true);
    for (int32_t i = 2; i <= vv; ++i) if (isp[i]) {
            for (int32_t j = i * i; j <= v; j += i) isp[j] = false;
        }

    const int32_t rsize = approx_prime_count(_n + 30);
    vector<int32_t> primes = {2, 3, 5}; int32_t psize = 3;
    primes.resize(rsize);

    vector<P> sprimes; size_t pbeg = 0;
    int32_t prod = 1;
    for (int32_t p = 7; p <= v; ++p) {
        if (!isp[p]) continue;
        if (p <= Q) prod *= p, ++pbeg, primes[psize++] = p;
        auto pp = P(p);
        for (int32_t t = 0; t < 8; ++t) {
            int32_t j = (p <= Q) ? p : p * p;
            while (j % 30 != rs[t]) j += p << 1;
            pp.pos[t] = j / 30;
        }
        sprimes.push_back(pp);
    }

    vector<unsigned char> pre(prod, 0xFF);
    for (size_t pj = 0; pj < pbeg; ++pj) {
        auto pp = sprimes[pj]; const int32_t p = pp.p;
        for (int32_t t = 0; t < 8; ++t) {
            const unsigned char m = ~(1 << t);
            for (int32_t i = pp.pos[t]; i < prod; i += p) pre[i] &= m;
        }
    }

    const int32_t block_size = (L + prod - 1) / prod * prod;
    vector<unsigned char> block(block_size); unsigned char* pblock = block.data();
    const int32_t M = (_n + 29) / 30;

    for (int32_t beg = 0; beg < M; beg += block_size, pblock -= block_size) {
        int32_t end = min(M, beg + block_size);
        for (int32_t i = beg; i < end; i += prod) {
            copy(pre.begin(), pre.end(), pblock + i);
        }
        if (beg == 0) pblock[0] &= 0xFE;
        for (size_t pj = pbeg; pj < sprimes.size(); ++pj) {
            auto& pp = sprimes[pj];
            const int32_t p = pp.p;
            for (int32_t t = 0; t < 8; ++t) {
                int32_t i = pp.pos[t]; const unsigned char m = ~(1 << t);
                for (; i < end; i += p) pblock[i] &= m;
                pp.pos[t] = i;
            }
        }
        for (int32_t i = beg; i < end; ++i) {
            for (int32_t m = pblock[i]; m > 0; m &= m - 1) {
                primes[psize++] = i * 30 + rs[__builtin_ctz(m)];
            }
        }
    }
    assert(psize <= rsize);
    while (psize > 0 && primes[psize - 1] > _n) --psize;
    primes.resize(psize);
    return primes;
}

vector<int32_t> all_primes;
void solve() {
    int n;
    cin >> n;
    // n is prime or not
    if (binary_search(all_primes.begin(), all_primes.end(), n)) {
        cout << n << " is prime" << endl;
    } else {
        cout << n << " is not prime" << endl;
    }
}
signed main() {
    Code_By_Abdelwabab
    all_primes = sieve(1000000000);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}