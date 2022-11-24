#include <bits/stdc++.h>
using namespace std;

class DSU {

    unordered_map<int, int> parent;
    unordered_map<int, int> size;

    public:
        void clear() {
            parent.clear();
            size.clear();
        }

        int findParent(int x) {
            if (parent.find(x) == parent.end()) {
                parent[x] = x;
                size[x] = 1;
            }
            if (parent[x] == x) {
                return x;
            }
            return parent[x] = findParent(parent[x]);
        }

        bool performUnion(int x, int y) {
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
