#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;

int main () {
    ios :: sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int mc = c-a, md = d-b;
        int ans = (min(a, b) * 2 + 2 >= max(a, b)) && (min(mc, md) * 2 + 2 >= max(mc, md));
        cout << (ans ? "YES" : "NO") << "\n";
    }
}