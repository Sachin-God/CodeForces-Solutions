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

ll dp(const vpll& coordinates, int prev_x, int prev_y, int Bx, int By, int n, int i, umap<string, ll>& memo) {
    if (i >= n) return 1LL*(Bx-prev_x + abs(prev_y - By));
    ll x = coordinates[i].first, y1 = coordinates[i].second;
    string key = to_string(x) + '-' + to_string(prev_y);
    if (FIND(memo, key)) return memo[key];
    while (i < n-1 && coordinates[i].first == coordinates[i+1].first) i++;
    ll y2 = coordinates[i].second;
    ll ans = (y2-y1) + (x-prev_x);
    ans += min(dp(coordinates, x, y1, Bx, By, n, i+1, memo) + abs(prev_y-y2), dp(coordinates, x, y2, Bx, By, n, i+1, memo) + abs(prev_y-y1));
    return memo[key] = ans;
}

void Solve() {
    ll n, Ax, Ay, Bx, By; cin >> n >> Ax >> Ay >> Bx >> By;
    vpll coordinates(n);
    FOR(i, 0, n) cin >> coordinates[i].first;
    FOR(i, 0, n) cin >> coordinates[i].second;
    sort(all(coordinates));

    umap<string, ll> memo;
    print(dp(coordinates, Ax, Ay, Bx, By, n, 0, memo));
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        Solve();               
    }
}