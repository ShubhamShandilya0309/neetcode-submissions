class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0;
        int maxi=0,ans=0;
        vector<int>count(26);
        while(j<s.size()){
            count[s[j]-'A']++;
            maxi = max(maxi,count[s[j]-'A']);
            if(j-i+1-maxi > k){
                count[s[i]-'A']--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
