class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0;
        vector<string> value_list = strs;
        sort(value_list.begin(), value_list.end());
        string res = "";
        
        if (value_list.size() == 0) {
            
            return res;
        }
        
        while (count < value_list[0].size() && value_list[0][count] == value_list.back()[count]) {
            count++;
        }
        
        res = value_list[0].substr(0, count);
        
        return res;
    }
};