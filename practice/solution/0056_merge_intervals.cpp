class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> value_ilst = intervals;
        sort(value_ilst.begin(), value_ilst.end());
        vector<vector<int>> res;
        
        if (value_ilst.size() == 0) {
            
            return res;
        }
        
        res.push_back(value_ilst[0]);
        
        for (int i = 1; i < value_ilst.size(); i++) {
            if (res.back()[1] >= value_ilst[i][0]) {
                res.back()[1] = max(res.back()[1], value_ilst[i][1]);
            } else {
                res.push_back(value_ilst[i]);
            }
        }
        
        return res;
    }
};