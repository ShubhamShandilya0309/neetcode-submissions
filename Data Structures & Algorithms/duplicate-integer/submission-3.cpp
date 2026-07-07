class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>temp;
        for(auto it : nums){
            temp.insert(it);
        }
        return temp.size()!=nums.size();
    }
};