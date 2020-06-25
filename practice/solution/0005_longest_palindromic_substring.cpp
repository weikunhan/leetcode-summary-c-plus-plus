class Solution {
public:
    string longestPalindrome(string s) {
        int row_end = s.size();
        int col_end = s.size();
        int max_length = 0;
        string res = "";
        vector<vector<bool>> dp_list(row_end, vector<bool>(col_end, false));
        
        for (int i = 0; i < row_end; i++) {
            dp_list[i][i] = true;

            if (i < row_end - 1 && s[i] == s[i + 1]) {
                dp_list[i][i + 1] = true;
            }
        }
        

        for (int i = row_end - 2; i >= 0; i--) {
            for(int j = i + 2; j < col_end; j++){
                dp_list[i][j] = (dp_list[i + 1][j - 1] && s[i] == s[j]);     
            }
        }
        
        for (int i = 0; i < row_end; i++) {
            for (int j = i; j < col_end; j++) {
                int temp_value = j - i + 1;
                
                if (dp_list[i][j] && max_length < temp_value) {
                    max_length = temp_value;
                    res = s.substr(i, max_length);
                }
            }
        }

        return res;
    }
};