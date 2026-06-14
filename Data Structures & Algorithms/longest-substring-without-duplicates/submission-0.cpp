class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        int n = s.size();
        int i=0,ans=1;
        vector<int>alpha(256,-1);
        for(int j=i;j<n;j++){
            if(alpha[(unsigned char)s[i]]!=-1){
                i = max(alpha[(unsigned char)s[j]]+1,i);
            }
            alpha[(unsigned char)s[j]]=j;
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};
