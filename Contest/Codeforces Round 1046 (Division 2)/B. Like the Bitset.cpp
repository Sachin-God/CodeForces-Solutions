#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;

int main () {
    ios :: sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int l = 0, st = 1, e = n;
        vector<int> a;
        bool valid = true;
        for (int i = 0; i < n && valid; i++) {
            if (s[i] == '1') {
                l++;
                if (l >= k) {
                    valid = false;
                }
                a.push_back(st++);
            } else {
                l = 0;
                a.push_back(e--);
            }
        }

        if (valid) {
            cout << "YES" << "\n";
            for (int x : a) cout << x << " ";
        } else cout << "NO";
        cout << "\n";
    }
}