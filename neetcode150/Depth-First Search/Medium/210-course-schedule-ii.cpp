// ═══════════════════════════════════════════════════════
// Problem: 210. Course Schedule II
// Difficulty: Medium
// Topics: Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
// Runtime: 9 ms (Beats 16.7%)
// Memory: 19 MB (Beats 21.0%)
// Submitted: Sep 1, 2026
// Link: https://leetcode.com/problems/course-schedule-ii/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prereq(numCourses);
        vector<int> res;
        vector<int> state (numCourses, 0);

        for (auto arr : prerequisites){
            prereq[arr[1]].push_back(arr[0]);
        }
        for (int i = 0; i < numCourses; ++i){
            if(state[i] == 0) {
                if (isCyclic(i, prereq, state, res)) {
                    return{};
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isCyclic(int num, vector<vector<int>>& prereq, vector<int>& state, vector<int>& res){
        state[num] = 1;
        for (int neighbor : prereq[num]) {
            if (state[neighbor] == 1) return true;
            if (state[neighbor] == 0) {
                if (isCyclic(neighbor, prereq, state, res)) return true;
            }
        }

        state[num] =2;
        res.push_back(num);

        return false;        
    }
};
