class Solution {
    int solve(int n){
        int res = 0;
        while(n!=0){
            res += n%2;
            n/=2;
        }
        return res;
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++){
            ans[i]=solve(i);
        }
        return ans;
    }
};
