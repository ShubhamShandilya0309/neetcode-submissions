class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(int i, int n, vector<int>& nums){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,n,nums);
        temp.pop_back();
        int j=i;
        while(j+1<n && nums[j+1]==nums[i])j++;
        solve(j+1,n,nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        solve(0,n,nums);
        return ans;
    }
};