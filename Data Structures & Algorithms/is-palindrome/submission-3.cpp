class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                str.push_back(s[i]);
            }
            else if(s[i]>='a' && s[i]<='z'){
                str.push_back(s[i]);
            }
            else if(s[i]>='A' && s[i]<='Z'){
                char temp = 'a'+s[i]-'A';
                str.push_back(temp);
            }
        }
        int m = str.size();
        int i=0,j=m-1;
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};