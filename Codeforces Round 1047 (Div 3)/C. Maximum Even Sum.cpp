#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

#define all(x) begin(x), end(x)

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        bool even = (b%2 == 0);
        if (even && ((a*b / 2) + 2) % 2 == 0) cout << (a*b / 2) + 2;
        else if (!even && (a*b + 1) % 2 == 0) cout << (a*b + 1);
        else cout << -1;
        cout << "\n";
    }
}