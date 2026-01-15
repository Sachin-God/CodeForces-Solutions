#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(i, s, n) for(int i = s; i < n; i++) 
#define ROF(i, n, s) for(int i = n; i >= s; --i)
#define FIND(set, target) (set.find(target) != set.end())

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

// super Greedy Wrong Approach
void WrongSolution() {
    int n, m; cin >> n >> m;
    vi a(n), b(m), c(m);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, m) cin >> b[i];
    FOR(i, 0, m) cin >> c[i];
    
    dqi x; vi y; // x is with c greater than 0, y with 0
    FOR(i, 0, m) {
        if (c[i] == 0) y.pb(b[i]);
        else x.pb(i);
    }

    int ans = 0; sort(all(a)); 
    while (true) {
        int l = x.size();
        FOR(k, 0, l) {
            int i = x.front(); x.pop_front();
            if (a[0] >= b[i]) {
                a[0] = max(a[0], c[i]);
                ans++;
            } else x.pb(i);
        }

        if (l == x.size()) break;
    }

    sort(all(y)); reverse(all(y));
    int i = 0;
    FOR(j, 0, y.size()) {
        if (y[j] <= a[i]) {
            i++;
            ans++;
        }
    }

    cout << ans << "\n";
}

void Solve() {
    int n, m; cin >> n >> m;
    vi a(n), b(m), c(m);
    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, m) cin >> b[i];
    FOR(i, 0, m) cin >> c[i];
    int ans = 0;

    minHeap<int> stage1(all(a)), stage2;
    vpi st1; vi st2;

    FOR(i, 0, m) {
        if (c[i] == 0) st2.pb(b[i]);
        else st1.pb({b[i], c[i]});
    }

    sort(all(st1));
    sort(all(st2));
    FOR(i, 0, st1.size()) {
        while (!stage1.empty() && stage1.top() < st1[i].first) {
            stage2.push(stage1.top());
            stage1.pop();
        }

        if (stage1.empty()) break;
        int x = stage1.top(); stage1.pop();
        x = max(x, st1[i].second);
        stage1.push(x);
        ans++;
    }

    while (!stage1.empty()) {
        stage2.push(stage1.top());
        stage1.pop();
    }

    FOR(i, 0, st2.size()) {
        while (!stage2.empty() && stage2.top() < st2[i]) stage2.pop();
        if (stage2.empty()) break;
        ans++;
        stage2.pop();
    }

    cout << ans << "\n";
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        Solve();               
    }
}