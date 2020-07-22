class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> value_list = nums;
        sort(value_list.begin(), value_list.end());
        vector<vector<int>> res;
        
        for (int i = 0; i < value_list.size(); i++) {
            if (i > 0 && value_list[i] == value_list[i - 1]) {
                continue;
            }
            
            for (int j = i + 1; j < value_list.size(); j++) {
                int left = j + 1;
                int right = value_list.size() - 1;
                
                if (j > i + 1 && value_list[j] == value_list[j - 1]) {
                    continue;
                }
                
                while (left < right) {
                    int sum_value = value_list[left] + value_list[right] + value_list[i] + value_list[j];
                    
                    if (sum_value == target) {
                        res.push_back(vector<int> {value_list[i], value_list[j], value_list[left], value_list[right]});
                        left++; 
                        right--;
                        
                        while (left < right && value_list[left] == value_list[left - 1]) {          
                            left++;
                        }
                        
                        while (left < right && value_list[right] == value_list[right + 1]) {
                            right--;
                        }
                    } else if (sum_value < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        
        return res;
    }
};