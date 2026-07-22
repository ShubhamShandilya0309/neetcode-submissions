class Solution {
    vector<vector<string>> ans;
    vector<string> temp;
    bool isPal(int l, int r,string s){
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }return true;
    }
    void solve(int i, string s){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(isPal(i,j,s)){
                temp.push_back(s.substr(i,j-i+1));
                solve(j+1,s);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        solve(0,s);
        return ans;
    }
};
