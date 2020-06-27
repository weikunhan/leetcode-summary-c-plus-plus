class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> value_list(numRows, "");
        int count = 0;
        int sign = 1;
        string res = "";
        
        if (numRows == 1 || numRows >= s.size()) {
            res = s;
                
            return res;
        } 
        
        for (int i = 0; i < s.size(); i++) {
            value_list[count] += s[i];
            
            if (count == 0) {
                sign = 1;
            }
            
            if (count == numRows - 1) {
                sign = -1;
            }
            
            count += sign;
        }
        
        for (int i = 0; i < value_list.size(); i++) {
            res += value_list[i];
        }
            
        return res;
    }
};