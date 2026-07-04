class Solution {
    void solve(int i, string digits, vector<vector<char>>& temp, vector<string>& ans, string str){
        if(i==digits.size()){
            ans.push_back(str);
            return;
        }
        int num = digits[i]-'0';
        for(int j=0;j<temp[num].size();j++){    
            str.push_back(temp[num][j]);
            solve(i+1,digits,temp,ans,str);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<vector<char>>temp(10);
        vector<string> ans;
        string str = "";
        temp[2] = {'a','b','c'};
        temp[3] = {'d','e','f'};
        temp[4] = {'g','h','i'};
        temp[5] = {'j','k','l'};
        temp[6] = {'m','n','o'};
        temp[7] = {'p','q','r','s'};
        temp[8] = {'t','u','v'};
        temp[9] = {'w','x','y','z'};
        solve(0,digits,temp,ans,str);
        return ans;
    }
};