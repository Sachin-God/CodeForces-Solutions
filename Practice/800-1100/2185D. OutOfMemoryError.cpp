// 15 mins
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(i, s, n) for(int i = s; i < n; i++)
#define FORS(i, s, n, st) for(int i = s; i < n; i += st) 
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
    int n, m, h; cin >> n >> m >> h;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    int b, c;
    vi val(n, 0);
    uset<int> set;
    FOR(i, 0, m) {
        cin >> b >> c;
        b--;
        if (a[b] + c + val[b] > h) { 
            // O(k) average and k is no. of elements in set
            for(auto& x : set) {
                val[x] = 0;
            }
            set.clear(); 
        } else {
            val[b] += c;
            set.insert(b);
        }
    }
    FOR(i, 0, n) a[i] += val[i];
    print_vector(a);    
    // T.C. is O(K*n)
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        Solve();               
    }
}