class Solution {
public:
    bool isValid(char ch){
        return isalnum(ch);
    }
    bool check(char a,char b){
        if(tolower(a)!=tolower(b))return false;
        return true;
    }
    bool isPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            if(!isValid(s[i])){
                i++;
                continue;
            }
            if(!isValid(s[j])){
                j--;
                continue;
            }
            else if(check(s[i],s[j])==false)return false;
            i++;
            j--;
        }
        return true;
    }
};
