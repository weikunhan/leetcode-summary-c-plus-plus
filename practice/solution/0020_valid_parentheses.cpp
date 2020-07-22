class Solution {
public:
    bool isValid(string s) {
        stack<char> value_stack;
        unordered_map<char, char> value_dict = {{']', '['}, {'}', '{'}, {')', '('}};
        bool res = false;
        
        for (char& c : s) {
            if (value_dict.find(c) == value_dict.end()) {
                value_stack.push(c);
            } else {
                if (value_stack.empty()) {
                    
                    return res;
                }
                
                if (value_dict[c] != value_stack.top()) {
                    
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