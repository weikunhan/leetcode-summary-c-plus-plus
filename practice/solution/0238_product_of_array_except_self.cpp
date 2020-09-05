class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int temp_value = 1;
        vector<int> res(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            res[i] = temp_value;
            temp_value *= nums[i];
        }
        
        temp_value = 1;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= temp_value;
            temp_value *= nums[i];
        }
        
        return res;
    }
};