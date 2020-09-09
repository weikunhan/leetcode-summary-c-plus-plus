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
        
        for (auto c : s) {
            value_list[count] += c;
            
            if (count == 0) {
                sign = 1;
            }
                    
            if (count == numRows - 1) {
                sign = -1;
            }
            
            count += sign;
        }
        
        for (auto s : value_list) {
            res += s;
        }
        
        return res;
    }
};