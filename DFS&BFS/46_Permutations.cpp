//Given a collection of distinct integers, return all possible permutations.
//
//Example:
//
//Input: [1, 2, 3]
//Output :
//    [
//        [1, 2, 3],
//        [1, 3, 2],
//        [2, 1, 3],
//        [2, 3, 1],
//        [3, 1, 2],
//        [3, 2, 1]
//    ]


//use DFS
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out, visited(nums.size(), 0);
        DFS(nums, visited, out, res, 0);
        return res;
    }
    void DFS(vector<int> nums, vector<int>& visited, vector<int>& out, vector<vector<int>>& res, int level) {
        if (level == nums.size()) { res.push_back(out); return; }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == 1) continue;
            visited[i] = 1;
            out.push_back(nums[i]);
            DFS(nums, visited, out, res, level + 1);
            out.pop_back();
            visited[i] = 0;
        }
    }
};