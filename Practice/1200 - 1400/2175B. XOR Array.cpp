// 1.5 hours + editorial -- first attemp still not solved
// attempt 2 -- 50 min + editorial
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(i, s, n) for(int i = s; i < n; i++)
#define ROF(i, n, s) for(int i = n-1; i >= s; --i)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;

template <typename T> using maxHeap = priority_queue<T>;
template <typename T> using minHeap = priority_queue<T, vector<T>, greater<T>>;

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
        int n, l, r; cin >> n >> l >> r;
        vi b(n), a(n);
        FOR(i, 0, n) b[i] = i+1;
        b[r-1] = l-1; 
        a[0] = 1;
        FOR(i, 1, n) a[i] = b[i] ^ b[i-1];
        print_vector(a);
    }
}