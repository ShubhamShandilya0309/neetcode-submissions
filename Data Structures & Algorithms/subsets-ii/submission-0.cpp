class Solution {
    vector<vector<int>>ans;
    vector<int>temp;
    set<vector<int>>st;
    void solve(int i, vector<int>& nums){
        if(i==nums.size()){
            st.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums);
        temp.pop_back();
        solve(i+1,nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(0,nums);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};