class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> right_value_list;
        vector<vector<int>> left_value_list;
        int start = newInterval[0];
        int end = newInterval[1];
        vector<vector<int>> res;
        
        for (auto interval : intervals) {
            if (interval[0] > end) {
                right_value_list.push_back(interval);
            } else if (interval[1] < start) {
                left_value_list.push_back(interval);
            } else {
                start = min(start, interval[0]);
                end = max(end, interval[1]);
            }
        }
        
        res.insert(res.end(), left_value_list.begin(), left_value_list.end());
        res.push_back(vector<int>{start, end});
	    res.insert(res.end(), right_value_list.begin(), right_value_list.end());
        
        return res;
    }
};