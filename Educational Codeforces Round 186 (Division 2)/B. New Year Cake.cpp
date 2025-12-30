#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define f(s, n) for(int i = s; i < n; i++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

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

int count(int a, int b) {
    int layer = 0;
    int curr = 1;
    while (a >= curr) {
        a -= curr;
        layer++;
        curr *= 2;
        if (b >= curr) {
            b -= curr;
            layer++;
            curr *= 2;
        } else break;
    }
    return layer;
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        cout << max(count(a,b), count(b, a)) << "\n";
    }
}