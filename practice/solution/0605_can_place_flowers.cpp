class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        vector<int> value_list = flowerbed;
        value_list.insert(value_list.begin(), 0);
        value_list.push_back(0);
        bool res = false;
        
        for (int i = 1; i < value_list.size() - 1; i++) {
            if (value_list[i - 1] == 0 && value_list[i] == 0 && value_list[i + 1] == 0) {
                value_list[i] = 1;
                count++;
            }
        }
        
        if (count >= n) {
            res = true;
        }
        
        return res;
    }
};