#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        string s;
        cin >> s;
        int n = (int)s.size();

        // adjacency list of internal edges (0..n-1 -> 0..n-1)
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        vector<int> leadsToShore(n, 0); // 1 if the node has an outgoing move that goes directly to shore

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '<') {
                if (i - 1 >= 0) {
                    adj[i].push_back(i - 1);
                    indeg[i - 1] += 1;
                } else {
                    leadsToShore[i] = 1;
                }
            } else if (c == '>') {
                if (i + 1 < n) {
                    adj[i].push_back(i + 1);
                    indeg[i + 1] += 1;
                } else {
                    leadsToShore[i] = 1;
                }
            } else { // '*'
                // can move left
                if (i - 1 >= 0) {
                    adj[i].push_back(i - 1);
                    indeg[i - 1] += 1;
                } else {
                    leadsToShore[i] = 1;
                }
                // can move right
                if (i + 1 < n) {
                    adj[i].push_back(i + 1);
                    indeg[i + 1] += 1;
                } else {
                    leadsToShore[i] = 1;
                }
            }
        }

        // Kahn's algorithm to detect cycle and produce topological order
        queue<int> q;
        for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);

        vector<int> topo;
        topo.reserve(n);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (int v : adj[u]) {
                indeg[v]--;
                if (indeg[v] == 0) q.push(v);
            }
        }

        if ((int)topo.size() < n) {
            // cycle exists -> infinite sailing
            cout << -1 << '\n';
            continue;
        }

        // DAG: compute longest distance (number of moves) to shore starting from each node.
        // dp[u] = max over neighbors v in [0..n-1] of (dp[v] + 1), and if node has direct move to shore, consider 1.
        vector<int> dp(n, 0);
        // process in reverse topological order
        for (int idx = n - 1; idx >= 0; --idx) {
            int u = topo[idx];
            int best = 0;
            if (leadsToShore[u]) best = max(best, 1);
            for (int v : adj[u]) {
                // v is an internal node
                best = max(best, dp[v] + 1);
            }
            dp[u] = best;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
        cout << ans << '\n';
    }

    return 0;
}
