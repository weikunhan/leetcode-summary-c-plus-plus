class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> value_list = nums;
        sort(value_list.begin(), value_list.end());
        vector<vector<int>> res;
        
        for (int i = 0; i < value_list.size(); i++) {
            int left = i + 1;
            int right = value_list.size() - 1;
            
            if (i > 0 && value_list[i] == value_list[i - 1]) {
                continue;
            } 
            
            while (left < right) {
                int sum_value = value_list[i] + value_list[left] + value_list[right];
                
                if (sum_value == 0) {
                    res.push_back(vector<int> {value_list[i], value_list[left], value_list[right]});
                    left++;
                    right--;
                    
                    while (left < right && value_list[left] == value_list[left - 1]) {
                        left++;
                    }
                    
                    while (left < right && value_list[right] == value_list[right + 1]) {
                        right--;
                    }
                } else if (sum_value < 0) {
                    left++;
                } else {
                    right--;
                }        
            }
            
        }
        
        return res;   
    }
};