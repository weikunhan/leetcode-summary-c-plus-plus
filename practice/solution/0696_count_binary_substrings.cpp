class Solution {
public:
    int countBinarySubstrings(string s) {
        int left = 0;
        int right = 1;
        int res = 0;
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                right++; 
            } else {
                res += min(left, right);
                left = right;
                right = 1;
            }
        }
        
        res += min(left, right);
        
        return res;
    }
};