class Solution {
public:
    int myAtoi(string str) {
        bool sign = true;
        int res = 0;
        int count = 0;
        
        while (count < str.size()) {
            if (isspace(str[count])) {
                count++;
            } else {
                break;
            }
        }
        
        if (str[count] == '+') {
            count++;
        } else if (str[count] == '-') {
            sign = false;
            count++;
        }
        
        while (count < str.size() && isdigit(str[count])) {
            int temp_value = str[count] - 48;
            
            if (res > (INT_MAX - temp_value) / 10 || res < (INT_MIN + temp_value) / 10) {
                if (sign) {
                    res = INT_MAX;
                } else {
                    res = INT_MIN;
                }
                
                return res;
            }
            
            if (sign) {
                res = res * 10 + temp_value;
            } else {
                res = res * 10 - temp_value;
            }
            
            count++;
        }
        
        return res;
    }
};