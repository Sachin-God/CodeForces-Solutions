#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, rnk;
public:
    DSU(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        rnk.resize(n, 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void _union(int x, int y) {
        int px = find(x), py = find(y);
        int rx = rnk[px], ry = rnk[py];
        if (px == py) return;
        if (rx < ry) parent[px] = py;
        else if (rx > ry) parent[py] = px;
        else {
            parent[py] = px;
            rnk[px]++;
        }
    }
};
