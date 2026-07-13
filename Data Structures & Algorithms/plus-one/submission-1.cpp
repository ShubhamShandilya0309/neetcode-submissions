class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        int sum=0, carry=1;
        for(int i=n-1;i>=0 || carry >0;i--){
            sum = carry;
            if(i>=0)sum += digits[i];
            carry = sum/10;
            sum%= 10;
            if(sum || carry || i){
                ans.push_back(sum);
            }
        } 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};