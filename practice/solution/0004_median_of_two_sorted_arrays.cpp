class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int low = 0;
        int high = nums1.size();
        double res = -1;
            
        while (low <= high) {
            int a_mid = (low + high) / 2;
            int b_mid = (nums1.size() + nums2.size()) / 2 - a_mid;
            int a_low = a_mid ? nums1[a_mid - 1] : INT_MIN;
            int b_low = b_mid ? nums2[b_mid - 1] : INT_MIN;
            int a_high = (a_mid != nums1.size()) ? nums1[a_mid] : INT_MAX;
            int b_high = (b_mid != nums2.size()) ? nums2[b_mid] : INT_MAX;
            
            if (a_low > b_high) {
                high = a_mid -1;
            } else if (b_low > a_high) {
                low = a_mid + 1;
            } else {
                if ((nums1.size() + nums2.size()) % 2) {
                    res = min(a_high, b_high) / 1.0;
                } else {
                    res = (max(a_low, b_low) + min(a_high, b_high)) / 2.0;
                }
                
                return res;
            }
        }
        
        return res;
        
    }
};