class Solution {
public:
    int reverse(int x) {
        const int MAX = 2e31 - 1;
        const int MIN = -2e31;
        int res = 0;
        
        while(x) {
            if((res > MAX / 10) || (res < MIN / 10)) {
                
                return 0;
            }

            res = res * 10 + x % 10;
            x /= 10;
        }
        
        return res;
    }     
};
        