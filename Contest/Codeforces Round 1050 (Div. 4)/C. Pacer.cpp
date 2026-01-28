#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;
 
int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int count = 0;
        int t = 0, side = 0;
        int nt, ns;
 
        for (int i = 0; i < n; i++) {
            cin >> nt >> ns;
            int s = nt - t;
            if (s % 2 == 0) {
                if (ns == side) count += s;
                else if (s > 0) count += s - 1;
            } else {
                if (ns == side) count += s - 1;
                else count += s;
            }
            t = nt;
            side = ns;
        }
        count += m - t;
        cout << count << "\n";
    }
}