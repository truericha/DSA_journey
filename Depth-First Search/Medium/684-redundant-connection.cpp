// ═══════════════════════════════════════════════════════
// Problem: 684. Redundant Connection
// Difficulty: Medium
// Topics: Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
// Runtime: 5 ms (Beats 22.2%)
// Memory: 14.3 MB (Beats 23.5%)
// Submitted: Oct 30, 2026
// Link: https://leetcode.com/problems/redundant-connection/
// ═══════════════════════════════════════════════════════

class Solution{
    vector<bool> visited;
    vector<vector<int>> adj;
    int start;
    unordered_set<int> cycle;
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int n = edges.size();
        adj.resize(n + 1);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        visited.resize(n + 1, false);
        start = -1;
        dfs(1, -1);

        for (int i = edges.size() - 1; i >= 0; i--){
            int u = edges[i][0], v = edges[i][1];
            if (cycle.count(u) && cycle.count(v)){
                return {u, v};
            }
        }
        return {};
    }

private:
    bool dfs(int node, int par){
        if (visited[node]){
            start = node;
            return true;
        }
        visited[node] = true;
        for(int nei : adj[node]){
            if(nei == par) continue;
            if(dfs(nei, node)) {
                if(start != -1) cycle.insert(node);
                if(node == start) {
                    start = -1;
                }
                return true;
            }
        }
        return false;
    }
};
