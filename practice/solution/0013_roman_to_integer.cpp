class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> value_dict = {{'I', 1},
                                               {'V', 5},
                                               {'X', 10},
                                               {'L', 50},
                                               {'C', 100},
                                               {'D', 500},
                                               {'M', 1000}};
        int res = 0;
        
        for (int i = 0 ; i < s.size() - 1; i++) {
            if (value_dict[s[i]] >= value_dict[s[i + 1]]) {
                res += value_dict[s[i]];
            } else {
                res -= value_dict[s[i]];
            }
        }
        
        res += value_dict[s[s.size() - 1]];
        
        return res;
    }
};