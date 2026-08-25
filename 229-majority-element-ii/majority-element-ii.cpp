class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();

        unordered_map<int,int> map;

        for(int i = 0; i < n; i++)
        {
            map[nums[i]]++;
        }

        vector<int> ans;

        for(auto x: map)
        {
            int k = n/3;

            int i = x.first;
            int j = x.second;

            if(j > k)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};