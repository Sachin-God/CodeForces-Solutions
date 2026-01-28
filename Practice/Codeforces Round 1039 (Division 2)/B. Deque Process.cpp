#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
#define f(s, n) for(int i = s; i < n; i++)

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a(n);
        f(0, n) cin >> a[i];
        string ans = "";
        int i = 0, j = n-1;
        bool flip = true;
        while (i <= j) {
            if (flip) {
                if (a[i] >= a[j]) {
                    ans += 'L'; i++;
                } else {
                    ans += 'R'; j--;
                }
            } else {
                if (a[i] < a[j]) {
                    ans += 'L'; i++;
                } else {
                    ans += 'R'; j--;
                }
            }
            flip = !flip;
        }
        cout << ans << "\n";
    }
}