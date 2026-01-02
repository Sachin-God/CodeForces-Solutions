// 22 minutes
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(s, n) for(int i = s; i < n; i++)
#define ROF(n, s) for(int i = n; i >= s; --i)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef priority_queue<int> max_pqi;
typedef priority_queue<int> min_pqi;

template <typename T>
void print_vector(const vector<T>& vec) {
    for (const auto& x : vec) cout << x << ' ';
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

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        max_pqi alice, bob;
        
        int elem;
        FOR(0, n) {
            cin >> elem; alice.push(elem);
        }
        FOR(0, m) {
            cin >> elem; bob.push(elem);
        }

        while (!alice.empty() && !bob.empty()) {
            int x = alice.top();
            int y = bob.top(); bob.pop();
            if (y > x) bob.push(y-x);
            if (!bob.empty()) {
                y = bob.top();
                alice.pop();
                if (x > y) alice.push(x-y);
            }
        }
        if (alice.empty()) cout << "Bob" << "\n";
        else cout << "Alice" << "\n";
    }
}