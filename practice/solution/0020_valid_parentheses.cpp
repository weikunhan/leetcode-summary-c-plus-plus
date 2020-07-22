class Solution {
public:
    bool isValid(string s) {
        stack<char> value_stack;
        unordered_map<char, char> value_dict = {{']', '['}, {'}', '{'}, {')', '('}};
        bool res = false;
        
        for (int i = 0; i < s.size(); i++) {
            if (value_dict.find(s[i]) == value_dict.end()) {
                value_stack.push(s[i]);
            } else {
                if (value_stack.empty()) {
                    
                    return res;
                }
                
                if (value_dict[s[i]] != value_stack.top()) {
                    
                    return res;
                }
                
                value_stack.pop();
            }
        }
        
        if (value_stack.empty()) {
            res = true;
        }
        
        return res;
    }
};