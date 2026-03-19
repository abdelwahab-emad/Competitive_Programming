#include <bits/stdc++.h>


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename key>
using ordered_set = tree<key, null_type, less<key>, rb_tree_tag, tree_order_statistics_node_update>;


//zero based
struct orderedSet {
    ordered_set<int> st;

    // Add element O(log N)
    void insert(int val) {
        st.insert(val);
    }

    //check existence O(log N)
    bool exist(int val) {
        return st.find(val) != st.end();
    }

    //erase by value O(log N)
    void erase(int val) {
        auto it = st.find(val);
        if (it != st.end()) st.erase(it);
    }

    // return 0-index position O(log N)
    int index(int val) {
        if (!exist(val)) return -1;
        return st.order_of_key(val);
    }

    // Returns the value of lower_bound (>= val) O(log N)
    int lower_bound(int val) {
        auto it = st.lower_bound(val);
        return (it == st.end() ? -1 : *it);
    }

    // Returns the value of upper_bound (> val) O(log N)
    int upper_bound(int val) {
        auto it = st.upper_bound(val);
        return (it == st.end() ? -1 : *it);
    }

    // Access by index O(log N) st[0]
    int operator[](int idx) {
        if (idx < 0 || idx >= (int) st.size()) return -1;
        return *st.find_by_order(idx);
    }

    // Number of elements strictly less than x O(log N)
    int order_of_key(int x) {
        return st.order_of_key(x);
    }

    int size() {
        return st.size();
    }

    void clear() {
        st.clear();
    }
};
