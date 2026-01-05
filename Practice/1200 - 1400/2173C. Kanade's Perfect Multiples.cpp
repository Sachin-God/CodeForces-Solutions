// 1.5 hr + very little help, only one observation that is that i didn't need to deque
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(i, s, n) for(int i = s; i < n; i++) // including i is better bcz nested loop will overwrite upper one
#define ROF(i, n, s) for(int i = n; i >= s; --i)

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

int Solution1() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;      
        vi a(n), b;
        FOR(i, 0, n) cin >> a[i];
        sort(all(a));     
        deque<int> dq(all(a));
        unordered_set<int> set(all(a));

        bool valid = true;
        while (!dq.empty() && valid) {
            int m = dq.size();
            int num = dq.front();
            b.pb(num);
            FOR(i, 0, m) {
                int x = dq.front(); dq.pop_front();
                if (x % num != 0) dq.push_back(x);
            }

            int sz = k / num + 1;
            FOR(i, 1, sz) {
                if (set.find(i*num) == set.end()) {valid = false; break;}
            }
        }

        if (valid) {
            cout << b.size() << "\n";
            print_vector(b);
        } else {
            cout << -1 << '\n';
        }
    }
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;      
        vi a(n), b;
        FOR(i, 0, n) cin >> a[i];
        sort(all(a));
        unordered_set<int> set(all(a)), visited;

        bool valid = true;
        for (auto& x : a) {
            if (!valid) break;
            if (visited.find(x) == visited.end()) {
                b.pb(x);
                int sz = k / x + 1;
                FOR(i, 1, sz) {
                    if (set.find(i*x) == set.end()) {valid = false; break;}
                    visited.insert(i*x);
                }
            }
        }

        if (valid) {
            cout << b.size() << "\n";
            print_vector(b);
        } else {
            cout << -1 << '\n';
        }
    }
}