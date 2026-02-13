// 22 mins
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(i, s, n) for(int i = s; i < n; i++) // including i is better bcz nested loop will overwrite upper one
#define ROF(i, n, s) for(int i = n; i >= s; --i)
#define FIND(set, target) (set.find(target) != set.end())
#define ent '\n'
#define LSOne(S) ((S) & -(S))

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

template <typename T> 
void print(T x) {cout << x << ent;}

class DSU {
private:
    vi parent, rnk;
public:
    DSU(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        rnk.resize(n, 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void _union(int x, int y) {
        int px = find(x), py = find(y);
        int rx = rnk[px], ry = rnk[py];
        if (px == py) return;
        if (rx < ry) parent[px] = py;
        else if (rx > ry) parent[py] = px;
        else {
            parent[py] = px;
            rnk[px]++;
        }
    }
};

void Solve() {
    int n; cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    sort(all(a));
    int ans = 1, curr = 1;
    FOR(i, 1, n) {
        if (a[i] == a[i-1]) continue;
        if (a[i] == a[i-1]+1) {
            curr++;
            ans = max(ans, curr);
        } else {
            curr = 1;
        }
    }
    print(ans);
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        Solve();               
    }
}