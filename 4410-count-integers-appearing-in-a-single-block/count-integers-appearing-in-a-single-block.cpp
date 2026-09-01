class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> map;

        map[nums[0]]++;

        for(int i = 1; i < n; i++)
        {
            if(nums[i-1] != nums[i])
            {
                map[nums[i]]++;
            }
        }

        int cnt = 0;

        for(auto x : map)
        {
            int p = x.second;

            if(p == 1) 
            {
                cnt++;
            }
        }
        
        return cnt;
    }
};