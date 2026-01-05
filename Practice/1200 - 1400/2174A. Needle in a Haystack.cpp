// 25 Minutes

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(i, s, n) for(int i = s; i < n; i++)
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

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        string s, t; cin >> s >> t;
        vi chr(26, 0);
        bool impossible = false;
        for (auto& x : t) chr[x-'a']++;       
        for (auto& x : s) {
            chr[x-'a']--;
            if (chr[x-'a'] < 0) impossible = true;
        }

        if (impossible) {
            cout << "Impossible" << '\n';
            continue;
        }

        string ans = "";
        int j = 0, n = s.length();
        FOR(i, 0, 26) {
            char a = char(i + 'a');
            while (j < n && s[j] <= a) {
                ans += s[j++];
            }
            FOR(k, 0, chr[i]) ans += a;
            chr[i] = 0;
        }
        cout << ans << '\n';
    }
}