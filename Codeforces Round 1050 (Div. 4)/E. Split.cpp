#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
 
int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vi d(n);
        unordered_map<int, int> f;
        for (int i = 0; i < n; i++) {
            cin >> d[i];
            f[d[i]]++;
        }
        bool valid = true;
        for (auto& freq : f) {
            if (freq.second % k != 0) {
                valid = false;
                break;
            }
        }
 
        if (!valid) cout << 0 << "\n";
        else {
            deque<int> window;
            unordered_map<int, int> new_f;
            ll count = 0;
            for (auto& x : d) {
                window.push_back(x);
                new_f[x]++;
                while (new_f[x] > (f[x] / k)) {
                    new_f[window.front()]--;
                    window.pop_front();
                }
                count += 1LL * window.size();
            }
            cout << count << "\n";
        }
    }
}