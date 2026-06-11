class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n,0),right(n,0);
        int leftMax=0,rightMax=0;
        for(int i=0;i<n;i++){
            leftMax = max(leftMax,height[i]);
            rightMax = max(rightMax,height[n-i-1]);
            left[i] = leftMax;
            right[n-i-1] = rightMax;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += min(left[i],right[i]) - height[i];
        }
        return ans;
    }
};