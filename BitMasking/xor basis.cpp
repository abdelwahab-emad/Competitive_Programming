#include <bits/stdc++.h>
using namespace std;

const int Bit = 30;

struct XorBasis {
    array<int, Bit> basis;
    int size;

    void init() {
        size = 0;
        for (int i = 0; i < Bit; i++) {
            basis[i] = 0;
        }
    }

    bool have(int x, int bit) {
        return (x >> bit & 1);
    }

    void add(int x) {
        for (int i = Bit - 1; i >= 0; i--) {
            if (not have(x, i))continue;
            if (basis[i] == 0) {
                basis[i] = x;
                size++;
                return;
            }
            x = (x ^ basis[i]);
        }
    }

    int distinct_subsets() {
        return 1ll << size;
    }

    int getMaxXor() {
        int ans = 0;
        for (int i = Bit - 1; i >= 0; i--) {
            if (basis[i] == 0)continue;
            if(have(ans, i)) continue;
            ans ^= basis[i];
        }
        return ans;
    }

    int getKthUnique(int k) { // 1 based
        if (k > (1LL << size)) return -1;
        int ans = 0, c = size;
        for (int i = Bit - 1; i >= 0; i--) {
            if (basis[i] == 0)continue;
            --c;
            if (have(ans, i)) {
                if ((1LL << c) >= k) ans ^= basis[i];
                else k -= (1LL << c);
            } else if ((1LL << c) < k) {
                k -= (1LL << c);
                ans ^= basis[i];
            }
        }
        return ans;
    }

    int getKth(int k, int n) {
        int useless = n - size;
        int block = 1LL << useless;

        int idx = (k - 1) / block + 1;
        return getKthUnique(idx);
    }
};
