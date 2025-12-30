#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

template <typename T>
void print_vector(const vector<T>& vec) {
    for (const auto& x : vec) {
        if (x == -1) break;
        cout << x << ' ';
    }
    cout << '\n';
}

template <typename T>
void print_grid(const vector<vector<T>>& grid) {
    for (const auto& row : grid) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << '\n';
    }
}

// Solution 1
// we will find best array index for all index starting from back 
// as prefix with smaller length is better in case of tie

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vvi arr(n), rel;
        int max_k = 0;
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            arr[i].resize(k);
            max_k = max(max_k, k);
            for (int j = 0; j < k; j++) {
                cin >> arr[i][j];
                if (rel.size() == j) rel.pb({});
                rel[j].pb(i);
            }
        }

        vector<int> lex_min(max_k), rank(n, -1);
        for (int i = max_k-1; i >= 0; --i) {
            vector<array<int, 3>> curr;
            for (auto& j : rel[i]) curr.pb({arr[j][i], rank[j], j});
            sort(all(curr));
            lex_min[i] = curr[0][2];
            int rk = 0;
            for (auto& x : curr) rank[x[2]] = rk++;
        }

        vector<int> ans;
        while (ans.size() < max_k) {
            int st = ans.size();
            for (int i = st; i < arr[lex_min[st]].size(); i++) ans.pb(arr[lex_min[st]][i]);
        }

        print_vector(ans);
    }
}

// Solution 2