#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(i, s, n) for(int i = s; i < n; i++) // including i is better bcz nested loop will overwrite upper one
#define ROF(i, n, s) for(int i = n; i >= s; --i)
#define FIND(set, target) (set.find(target) != set.end())
#define ent '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

typedef deque<int> dqi;
typedef deque<ll> dqll;
typedef deque<pii> dqii;
typedef deque<string> dqs;

typedef queue<int> qi;
typedef queue<ll> qll;
typedef queue<pii> qii;
typedef queue<string> qs;

template <typename T> using maxHeap = priority_queue<T>;
template <typename T> using minHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename S, typename T> using umap = unordered_map<S, T>;
template <typename T> using uset = unordered_set<T>;

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

// class FenwickTree {
//     vi tree;
//     int n;

// public:
//     FenwickTree(int n) : n(n) {
//         tree.assign(n + 1, 0);
//     }

//     void update(int i, int v) {
//         while (i <= n) {
//             tree[i] += v;
//             i += i & (-i);
//         }
//     }

//     int query(int i) {
//         int sum = 0;
//         while (i > 0) {
//             sum += tree[i];
//             i -= i & (-i);
//         }
//         return sum;
//     }

//     int rangeQuery(int l, int r) {
//         return query(r) - query(l - 1);
//     }
// };

// vi countGreaterOrEqualRight(vi& nums) {
//     int n = nums.size();
//     vi result(n);

//     vi sorted = nums;
//     sort(sorted.begin(), sorted.end());
//     sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

//     FenwickTree ft(sorted.size());

//     for (int i = n - 1; i >= 0; i--) {
//         int rank = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1;
//         result[i] = ft.rangeQuery(rank, sorted.size());
//         ft.update(rank, 1);
//     }

//     return result;
// }

void Solve() {
    int n; cin >> n;
    vi a(n), b(n);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, n) {
        cin >> b[i];
        if (i > 0) b[i] += b[i-1];
    }
    sort(all(a));
    ll score = 0;
    FOR(i, 0, n) {
        if (a[i] == a[i-1]) continue;
        int idx = upper_bound(all(b), n-i) - b.begin();
        score = max(score, 1LL*idx*a[i]);
    }
    cout << score << ent;
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        Solve();               
    }
}