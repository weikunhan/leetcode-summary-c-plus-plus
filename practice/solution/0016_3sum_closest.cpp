class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> value_list = nums;
        sort(value_list.begin(), value_list.end());
        int temp_value = INT_MAX;
        int res = 0;
        
        for (int i = 0; i < value_list.size(); i++) {
            int left = i + 1;
            int right = value_list.size() - 1;
            
            if (i > 0 && value_list[i] == value_list[i - 1]) {
                continue;
            }
            
            while (left < right) {
                int sum_value = value_list[i] + value_list[left] + value_list[right];
                
                if (sum_value - target == 0) {
                    res = target;
                    
                    return res;
                } else if (sum_value - target < 0) {
                    left++;
                } else {
                    right--;
                }
                
                if (abs(sum_value - target) < abs(temp_value)) {
                    temp_value = sum_value - target;
                    res = sum_value;
                }
            }
        }
        
        return res;
    }
};