// ═══════════════════════════════════════════════════════
// Problem: 684. Redundant Connection
// Difficulty: Medium
// Topics: Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
// Runtime: 5 ms (Beats 21.8%)
// Memory: 14.7 MB (Beats 19.8%)
// Submitted: Nov 3, 2026
// Link: https://leetcode.com/problems/redundant-connection/
// ═══════════════════════════════════════════════════════

class Solution{
    vector<vector<int>> neighbour;
    vector<bool> visited;
    unordered_set<int> cycle;
    int start;

    bool dfs(int node, int parent){
        if(visited[node-1]){
            start = node;
            return true;
        }
        visited[node-1] = true;

        for(int n : neighbour[node-1]){
            if(n == parent) continue;

            if(dfs(n, node)){
                if (start != -1) cycle.insert(node);
                if(node == start) start = -1;
                return true;
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int size = edges.size();
        neighbour.resize(size);
        visited.assign(size, false);
        start = -1; 

        for(auto e : edges){
            neighbour[e[0]-1].push_back(e[1]);
            neighbour[e[1]-1].push_back(e[0]);

        }

        dfs(1, -1);

        for(int i = size-1; i >= 0; i--){
            int a = edges[i][0];
            int b = edges[i][1];
            if(cycle.count(a) && cycle.count(b)){
                return {a,b};
            }
        }
        return {};
    }
};
