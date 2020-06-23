class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 1;
        unordered_set<char> value_dict;
        int res = 0;
        
        while (right < s.size() + 1) {
            char temp_value = s[right - 1];
            
            while (value_dict.find(temp_value) != value_dict.end()) {
                value_dict.erase(s[left]);
                left++;
            }
            
            value_dict.insert(temp_value);
            res = max(res, right - left);
            right++;
        }
        
        return res;
    }
};