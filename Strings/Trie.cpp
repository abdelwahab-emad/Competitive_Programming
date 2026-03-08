#include <bits/stdc++.h>
using namespace std;


struct Trie{
    struct Node{
        Node *child[26];
        int IsEnd, Prefix;
        Node(){
            memset(child, 0, sizeof child);
            IsEnd = Prefix = 0;
        }
    };

    Node *root = new Node();
    void insert(string &s){
        Node *cur = root;
        for(auto ch : s){
            int idx = ch - 'a';
            if(cur->child[idx] == 0){
                cur->child[idx] = new Node();
            }
            cur = cur->child[idx];
            cur->Prefix++;
        }
        cur->IsEnd++;
    }

    Node* find(string &s) {
        Node *cur = root;
        for (auto ch : s) {
            int idx = ch - 'a';
            if (cur->child[idx] == nullptr) return nullptr;
            cur = cur->child[idx];
        }
        return cur;
    }

    int CountWord(string &s) {
        Node* res = find(s);
        return (res ? res->IsEnd : 0);
    }

    int CountPrefix(string &s) {
        Node* res = find(s);
        return (res ? res->Prefix : 0);
    }

    void erase(string &s) {
        if (CountWord(s) == 0) return;
        Node *cur = root;
        for (auto ch : s) {
            int idx = ch - 'a';
            cur = cur->child[idx];
            cur->Prefix--;
        }
        cur->IsEnd--;
    }
};