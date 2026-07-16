class Solution {
    void solve(int i, int n, int target, vector<int>& candidates, vector<vector<int>>& ans,
               vector<int>& temp) {
        if (i == n) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }
        if (candidates[i] <= target) {
            temp.push_back(candidates[i]);
            solve(i, n, target - candidates[i], candidates, ans, temp);
            temp.pop_back();
        }
        solve(i + 1, n, target, candidates, ans, temp);
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        solve(0, n, target, candidates, ans, temp);
        return ans;
    }
};

