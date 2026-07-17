class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(int i, int n, int target, vector<int>& candidates){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<n;j++){
            if(j>i && candidates[j]==candidates[j-1])continue;
            if(candidates[j] > target)break;
            temp.push_back(candidates[j]);
            solve(j+1,n,target-candidates[j],candidates);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        solve(0,n,target,candidates);
        return ans;
    }
};