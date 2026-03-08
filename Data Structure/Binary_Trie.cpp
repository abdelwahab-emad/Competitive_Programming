#include <bits/stdc++.h>
using namespace std;

const int Bits = 30;

struct BinaryTrie {
    struct Node {
        Node *child[2];
        int cnt;
        Node() {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };

    Node *root = new Node();

    void insert(int n) {
        Node *cur = root;
        for (int i = Bits; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (!cur->child[bit]) {
                cur->child[bit] = new Node();
            }
            cur = cur->child[bit];
            cur->cnt++;
        }
    }

    void del(int n) {
        Node *cur = root;
        for (int i = Bits; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (cur->child[bit]) {
                cur = cur->child[bit];
                cur->cnt--;
            }
        }
    }

    int Max_Xor(int num) {
        Node *cur = root;
        int ans = 0;
        for (int i = Bits; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int toggled = bit ^ 1;
            if (cur->child[toggled] and cur->child[toggled]->cnt > 0) {
                ans |= (1 << i);
                cur = cur->child[toggled];
            } else if (cur->child[bit] and cur->child[bit]->cnt > 0) {
                cur = cur->child[bit];
            } else {
                break;
            }
        }
        return ans;
    }

    int Min_Xor(int num) {
        Node *cur = root;
        int ans = 0;
        for (int i = Bits; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (cur->child[bit] and cur->child[bit]->cnt > 0) {
                cur = cur->child[bit];
            } else if (cur->child[bit ^ 1] and cur->child[bit ^ 1]->cnt > 0) {
                ans |= (1 << i);
                cur = cur->child[bit ^ 1];
            } else {
                break;
            }
        }
        return ans;
    }
};