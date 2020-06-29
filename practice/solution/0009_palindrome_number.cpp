class Solution {
public:
    bool isPalindrome(int x) {
        long temp_value = 0;
        long count = x;
        bool res = false;
        
        if (x < 0) {
            
            return res;
        }
        
        while (count) {
            temp_value = temp_value * 10 + count % 10;
            count /= 10;
        }
        
        if (x == temp_value) {
            res = true;
        }
        
        return res;
    }
};