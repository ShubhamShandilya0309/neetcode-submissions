class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false}, col[9][9] = {false}, sub[9][9] ={false};
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c] == '.')continue;
                else{
                    int val = board[r][c]-'0'-1;
                    int sec = (r/3)*3 + (c/3);
                    if(row[r][val] || col[c][val] || sub[sec][val]){
                        return false;
                    }
                    row[r][val]=true;
                    col[c][val]=true;
                    sub[sec][val]=true;
                }
            }
        }
        return true;
    }
};