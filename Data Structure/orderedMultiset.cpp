#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template<typename key>
using ordered_multiset = tree<key, null_type, less_equal<key>, rb_tree_tag, tree_order_statistics_node_update>;

struct orderedMultiset {
    ordered_multiset<int> st;

    // Adds an element (duplicates allowed) O(log N)
    void insert(int val) {
        st.insert(val);
    }

    // Check existence of val O(log N)
    bool exist(int val) {
        int idx = st.order_of_key(val);
        return idx < st.size() && *st.find_by_order(idx) == val;
    }

    // Erase only one instance of val O(log N)
    void erase_one(int val) {
        auto it = st.upper_bound(val);
        if (it != st.end() && *it == val) {
            st.erase(it);
        }
    }

    // return the first 0-index position of val O(log N)
    int index(int val) {
        if (!exist(val)) return -1;
        return st.order_of_key(val);
    }

    // return the last 0-index position of val O(log N)
    int LastIdx(int val) {
        if (!exist(val)) return -1;
        return st.order_of_key(val + 1) - 1;
    }

    // return the value of first element >= val O(log N)
    int lower_bound(int val) {
        auto it = st.upper_bound(val);
        return (it == st.end() ? -1 : *it);
    }

    // return the value of first element > val O(log N)
    int upper_bound(int val) {
        auto it = st.lower_bound(val);
        return (it == st.end() ? -1 : *it);
    }

    // Access by index O(log N) st[0]
    int operator[](int idx) {
        if (idx < 0 || idx >= (int)st.size()) return -1;
        return *st.find_by_order(idx);
    }

    // number of elements strictly less than x O(log N)
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