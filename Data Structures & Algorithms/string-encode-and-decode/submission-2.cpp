class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(int i=0;i<strs.size();i++){
            ans += to_string(strs[i].size()) + '#' + strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp = "";
        int n = s.size();
        int i = 0;
        while(i<n){
            int j =  i;
            string st = "";
            while(s[j]!='#'){
                st +=s[j];
                j++;
            }
            int len = stoi(st);
            st = "";
            temp = s.substr(j+1,len);
            ans.push_back(temp);
            i = j+len+1;
        }
        return ans;
    }
};
