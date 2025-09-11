#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;

int main () {
    ios :: sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        unordered_map<int, pair<int, queue<int>>> count; // current count, last index queue
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> dp(n+1, 0);
        for (int i = n-1; i >= 0; i--) {
            if (a[i] == 1) dp[i] = 1 + dp[i+1];
            else {
                count[a[i]].first += 1;
                count[a[i]].second.push(i);
                if (count[a[i]].second.size() == a[i]) {
                    int last_idx = count[a[i]].second.front(); count[a[i]].second.pop();
                    dp[i] = max(dp[i+1], dp[last_idx+1] + a[i]);
                } else dp[i] = dp[i+1];
            }
        }
        cout << dp[0] << "\n";
    }
}