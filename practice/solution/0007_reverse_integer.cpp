class Solution {
public:
    int reverse(int x) {
        long int res = 0;
        
        while(x) {
            if((res > INT_MAX / 10) || (res < INT_MIN / 10)) {
                res = 0;
                
                return res;
            }

            res = res * 10 + x % 10;
            x /= 10;
        }
        
        return res;
    }     
};
        