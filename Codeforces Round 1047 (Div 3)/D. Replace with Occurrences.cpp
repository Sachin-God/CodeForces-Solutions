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
        int n, x; cin >> n;
        unordered_map<int, vector<int>> b;
        for (int i = 0; i < n; i++) {
            cin >> x;
            b[x].push_back(i);
        }

        vector<int> a(n);
        int label = 1; bool possible = true;
        for (auto& pair : b) {
            int num = pair.first; auto& idx = pair.second;
            if (idx.size() % num != 0) possible = false;
            else {
                for (int i = 0; i < idx.size(); i += num) {
                    for (int j = i; j < i+num; j++) {
                        a[idx[j]] = label;
                    }
                    label++;
                }
            }
        }

        if (!possible) cout << -1;
        else {
            for (int x : a) cout << x << " ";
        }
        cout << "\n";
    }
}