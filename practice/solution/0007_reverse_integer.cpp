class Solution {
public:
    int reverse(int x) {
        const int MAX = 2e31 - 1;
        const int MIN = -2e31;
        int res = 0;
        
        while (x) {
            if((res > MAX / 10) || (res < MIN / 10)) {
                res = 0;
                
                return res;
            }

            res = res * 10 + x % 10;
            x /= 10;
        }
        
        return res;
    }     
};
        