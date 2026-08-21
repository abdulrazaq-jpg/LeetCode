class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        bool freq_i[200] = {false};
        bool freq_j[200] = {false};

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    freq_i[i] = true;
                    freq_j[j] = true;
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(freq_i[i] || freq_j[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};