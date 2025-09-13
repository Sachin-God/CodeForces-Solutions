#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;
 
int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> d;
        ll count = 0, field;
        for (int i = 0; i < n; i++) {
            cin >> field;
            if (field % 2 == 0) count += field;
            else d.push_back(field);
        }
 
        if (d.size() == 0) {
            cout << 0 << "\n";
            continue;
        }
        sort(all(d));
        int l = d.size();
        for (int i = l/2; i < l; i++) count += d[i];
        cout << count << "\n";
    }
}