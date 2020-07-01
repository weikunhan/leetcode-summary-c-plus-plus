class Solution {
public:
    bool isMatch(string s, string p) {
        int row_end = p.size();
        int col_end = s.size();
        vector<vector<bool>> dp_list(row_end + 1, vector<bool>(col_end + 1, false));
        dp_list[0][0] = true;
        bool res = false;
        
        for (int i = 1; i < row_end; i++) {
            dp_list[i + 1][0] = (p[i] == '*' && dp_list[i - 1][0]);
        }
                                     
        for (int i = 0; i < row_end; i++) {
            for (int j = 0; j < col_end; j++) {
                if (p[i] != '*') {
                    if (dp_list[i][j] && (p[i] == s[j] || p[i] == '.')) {
                        dp_list[i + 1][j + 1] = true;
                    }
                } else {
                    dp_list[i + 1][j + 1] = (dp_list[i - 1][j + 1] || dp_list[i][j + 1]);
                    
                    if (dp_list[i + 1][j] && (p[i - 1] == s[j] || p[i - 1] == '.')) {
                        dp_list[i + 1][j + 1] = true;
                    }
                }
            }
        }
        
        res = dp_list[row_end][col_end];
                                     
        return res;
        
    }
};