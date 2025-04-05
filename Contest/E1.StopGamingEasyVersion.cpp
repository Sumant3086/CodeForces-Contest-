#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<int>> b(n, vector<int>(m));

        // Read the original arrays
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        // Read the desired arrays
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> b[i][j];
            }
        }

        // Map to store the positions of elements in b
        map<int, pair<int, int>> pos;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pos[b[i][j]] = {i, j};
            }
        }

        // Vector to store the number of operations for each array
        vector<int> ops(n, 0);

        // Process arrays from last to first
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (a[i][j] != b[i][j]) {
                    // Calculate the number of operations needed
                    ops[i]++;
                }
            }
        }

        // Calculate the total number of operations
        int total_ops = 0;
        for (int i = 0; i < n; ++i) {
            total_ops += ops[i];
        }

        cout << total_ops << '\n';
    }

    return 0;
}