class Solution {
public: 
    vector<string> value_list = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> res;
    
    vector<string> letterCombinations(string digits) {
        res = dfs(digits);
        
        return res;
    }

    vector<string> dfs(string digits) {
        vector<string> temp_list;
        
        if (digits.size() == 0) {
            
            return temp_list;
        }
        
        if (digits.size() == 1) {
            string temp_value = value_list[digits[0] - 48];
            
            for (char& c : temp_value) {
                string s(1, c);
                temp_list.push_back(s);
            }
        
            return temp_list;
        }
        
        string temp_value = value_list[digits[0] - 48];
        
        for (char& c : temp_value) {
            for (string value: dfs(digits.substr(1))) {
                string s(1, c);
                temp_list.push_back(s + value);
            }
        }
        
        return temp_list;
    }
};