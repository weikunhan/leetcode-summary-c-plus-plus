class Solution {
public:
    bool isMatch(string s, string p) {
        int row_end = p.size();
        int col_end = s.size();
        vector<vector<bool>> dp_list(row_end + 1, vector<bool>(col_end + 1, false));
        dp_list[row_end][col_end] = true;
        bool res = false;
        
        for (int i = row_end - 1; i >= 0; i--) {
            if (p[i] != '*') {
                break;
            }
            
            dp_list[i][col_end] = true;
        }
        
        for (int i = row_end - 1; i >= 0; i--) {
            for (int j = col_end - 1; j >= 0; j--) {
                if (p[i] != '*') {
                    if (dp_list[i + 1][j + 1] && (p[i] == s[j] || p[i] == '?')) {
                        dp_list[i][j] = true;
                    }
                } else {
                    dp_list[i][j] = (dp_list[i + 1][j] || dp_list[i][j + 1]);
                }
            }
        }
        
        res = dp_list[0][0];
        
        return res;
    }
};