#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, L;
    cin >> n >> m >> L;

    // Read hurdles
    vector<pair<int, int>> hurdles(n);
    for (int i = 0; i < n; i++) {
        cin >> hurdles[i].first >> hurdles[i].second;
    }

    // Read power-ups
    vector<pair<int, int>> powerUps(m);
    for (int i = 0; i < m; i++) {
        cin >> powerUps[i].first >> powerUps[i].second;
    }

    // BFS state: {position, jump power, number of power-ups collected}
    queue<tuple<int, int, int>> q;
    q.push({1, 1, 0}); // Start at position 1 with jump power 1

    // Visited states: {position, jump power}
    set<pair<int, int>> visited;
    visited.insert({1, 1});

    while (!q.empty()) {
        auto [pos, jump, cnt] = q.front();
        q.pop();

        // Check if we reached the end
        if (pos >= L) {
            cout << cnt << endl;
            return;
        }

        // Collect power-ups at the current position
        for (auto it = lower_bound(powerUps.begin(), powerUps.end(), make_pair(pos, 0));
             it != powerUps.end() && it->first == pos; ++it) {
            int newJump = jump + it->second;
            if (!visited.count({pos, newJump})) {
                visited.insert({pos, newJump});
                q.push({pos, newJump, cnt});
            }
        }

        // Jump to the next positions
        for (int nextPos = pos + 1; nextPos <= pos + jump; nextPos++) {
            // Check if nextPos is within a hurdle
            bool inHurdle = false;
            for (auto& hurdle : hurdles) {
                if (nextPos >= hurdle.first && nextPos <= hurdle.second) {
                    inHurdle = true;
                    break;
                }
            }
            if (inHurdle) continue;

            // Check if nextPos is already visited with the same or better jump power
            if (!visited.count({nextPos, jump})) {
                visited.insert({nextPos, jump});
                q.push({nextPos, jump, cnt});
            }
        }
    }

    // If we exhaust the queue without reaching L, output -1
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}