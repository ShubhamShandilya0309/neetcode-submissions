class Solution {
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(int i,int n, vector<int>& nums){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,n,nums);
        temp.pop_back();
        solve(i+1,n,nums);
    }    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        solve(0,n,nums);
        return ans;
    }
};
