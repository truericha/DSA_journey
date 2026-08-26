// ═══════════════════════════════════════════════════════
// Problem: 207. Course Schedule
// Difficulty: Medium
// Topics: Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort, Directed Acyclic Graph
// Runtime: 8 ms (Beats 35.1%)
// Memory: 22.1 MB (Beats 5.0%)
// Submitted: Aug 26, 2026
// Link: https://leetcode.com/problems/course-schedule/
// ═══════════════════════════════════════════════════════

class Solution {
private:
    unordered_map<int, vector<int>> prerequ;
    set<int> visited; 
    int curr;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(auto a : prerequisites){
            prerequ[a[0]].push_back(a[1]);
        }

        for(int i = 0; i < numCourses; i++){
            if(!dfs(i)) return false;
            
        }
        return true;
    }

    bool dfs(int c){

        if(prerequ[c].empty()) return true;
        if(visited.contains(c)) return false;
        visited.insert(c);

        for(auto element : prerequ[c]){
            if(!dfs(element)) return false;
        }
        visited.erase(c);
        prerequ[c].clear();
        return true;
    }
}; 
