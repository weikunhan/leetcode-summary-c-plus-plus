class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count = 1;
        int row_start = 0;
        int row_end = n;
        int col_start = 0;
        int col_end = n;
        vector<vector<int>> res(n, vector<int>(n, 0));
        
        while (count <= n * n) {
            for (int i = col_start; i < col_end; i++) {
                res[row_start][i] = count;
                count++;
            }
            
            row_start++;
            
            for (int i = row_start; i < row_end; i++) {
                res[i][col_end - 1] = count;
                count++;
            }
            
            col_end--;
            
            if (row_start < row_end) {
                for (int i = col_end - 1; i >= col_start; i--) {
                    res[row_end - 1][i] = count;
                    count++;
                }
            }
            
            row_end--;
            
            if (col_start < col_end) {
                for (int i = row_end - 1; i >= row_start; i--) {
                    res[i][col_start] = count;
                    count++;
                }
            }
            
            col_start++;
        }
        
        return res;
    }
};