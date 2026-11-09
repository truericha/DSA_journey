// ═══════════════════════════════════════════════════════
// Problem: 744. Network Delay Time
// Difficulty: Medium
// Topics: Depth-First Search, Breadth-First Search, Graph Theory, Heap (Priority Queue), Shortest Path, Dijkstra's Algorithm
// Runtime: 109 ms (Beats 7.2%)
// Memory: 48.8 MB (Beats 7.5%)
// Submitted: Nov 9, 2026
// Link: https://leetcode.com/problems/network-delay-time/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for(auto t : times){
            edges[t[0]].push_back({t[1], t[2]});
        }

        int time = 0;
        vector<int> visited(n+1, 0);

        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.push({0, k});

        while(!min_heap.empty()){
            auto curr = min_heap.top();
            min_heap.pop();

            int w1 = curr.first, n1 = curr.second;
            if(visited[n1] == 1) continue;
            time = w1;
            visited[n1] = 1;

            for(auto edge : edges[n1]){
                int n2 = edge.first, w2 = edge.second;
                if(visited[n2] == 1) continue;
                min_heap.push({w1+w2, n2});
            }
        }
        for(int i=1; i<=n; i++){
            if(visited[i] == 0) return -1;
        }
        return time;
    }
};
