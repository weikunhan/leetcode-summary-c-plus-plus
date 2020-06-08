class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value_dict;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            int temp_value = target - nums[i];
            
            if (value_dict.find(nums[i]) == value_dict.end()) {
                value_dict[temp_value] = i;
            } else {
			    res.push_back(value_dict[nums[i]]);
			    res.push_back(i);			
			    
                return res;
            }
        }
             
        return res;
    }
};