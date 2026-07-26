class Solution {
    vector<string> ans;
    void solve(int n, int op, int cl, string temp){
        if(op==n && cl==n){
            ans.push_back(temp);
            return;
        }
        if(op<n){
            solve(n,op+1,cl,temp+'(');
        }
        if(cl<op){
            solve(n,op,cl+1,temp+')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        solve(n,0,0,"");
        return ans;
    }
};