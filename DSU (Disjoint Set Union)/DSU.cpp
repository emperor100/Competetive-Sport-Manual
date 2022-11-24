#include <bits/stdc++.h>
using namespace std;

/*
    Find more details [here](https://cp-algorithms.com/data_structures/disjoint_set_union.html#union-by-size-rank)
*/
template <class T> class DSU {

    unordered_map<T, T> parent;
    unordered_map<T, int> size;

    public:
        void clear() {
            parent.clear();
            size.clear();
        }

        T findParent(T x) {
            if (parent.find(x) == parent.end()) {
                parent[x] = x;
                size[x] = 1;
            }
            if (parent[x] == x) {
                return x;
            }
            return parent[x] = findParent(parent[x]);
        }

        bool performUnion(T x, T y) {
            x = findParent(x);
            y = findParent(y);

            if (x == y) {
                return false;
            }

            if (size[x] < size[y]) {
                swap(x, y);
            }
            parent[y] = x;
            size[x] += size[y];
            return true;
        }
};
