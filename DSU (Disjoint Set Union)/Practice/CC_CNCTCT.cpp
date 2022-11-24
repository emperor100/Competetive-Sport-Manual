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

int main() {
	// your code goes here

	int test;
	cin>>test;

	int n, A[111111] = {}, total = 0;
	DSU d;

	while(test--) {

	    cin>>n;
	    total = 0;

	    vector<int> B[32];
	    d.clear();

	    for (int i=0;i<n;i++) {
	        cin>>A[i];

	        for (int j=0;j<31;j++) {
	            if (A[i] & (1<<j)) {
	                B[j].push_back(i);
	            }
	        }
	    }

	    long ans=0;

	    for (int j=0;j<31;j++) {

	        int length = B[j].size() - 1;
	        for(int i=0;i<length; i++) {
	            if (d.performUnion(B[j][i], B[j][i+1])) {
	                total++;
	                ans += (1<<j);
	            }

	        }
	    }

	    if (total != n-1) ans = -1;

	    cout<<ans<<endl;

	}
	return 0;
}
