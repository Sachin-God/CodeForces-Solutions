#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;
 
int main () {
    ios :: sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m, x, y; cin >> n >> m >> x >> y;
        vector<int> Y(n), X(m);
        for (int i = 0; i < n; i++) cin >> Y[i];
        for (int i = 0; i < m; i++) cin >> X[i];
        cout << n+m << "\n";
    }
}