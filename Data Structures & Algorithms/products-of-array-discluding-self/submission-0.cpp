class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pre=1, post=1;
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]*=pre;
            ans[n-i-1]*=post;
            pre*=nums[i];
            post*=nums[n-i-1];
        }
        return ans;
    }
};
