class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> m;

        m[0] = 1;

        int cur_sum = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++)
        {
            cur_sum += nums[i];

            if(m[cur_sum - k] != 0)
            {
                cnt += m[cur_sum - k];
            }
            
            m[cur_sum]++;
        }

        return cnt;
    }
};