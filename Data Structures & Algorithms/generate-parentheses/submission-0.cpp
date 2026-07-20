class Solution {
    vector<string> ans;
    void generate(int n, int op, int cl, string str){
        if(op == n && cl == n){
            ans.push_back(str);
            return;
        }
        if(op<n){
            generate(n,op+1,cl,str+"(");
        }
        if(op>cl){
            generate(n,op,cl+1,str+")");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        generate(n,0,0,"");
        return ans;
    }
};
