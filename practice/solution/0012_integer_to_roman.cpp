class Solution {
public:
    string intToRoman(int num) {
        vector<string> m_value_list = {"", "M", "MM", "MMM"};
        vector<string> c_value_list = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> x_value_list = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> i_value_list = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string res = "";
        
        res += m_value_list[num / 1000];
        res += c_value_list[(num % 1000) / 100];
        res += x_value_list[(num % 100) / 10];
        res += i_value_list[num % 10];
        
        return res;
    }
};