class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();

        int cand_1 = -1e9;
        int cand_2 = -1e9;

        int cnt_1 = 0;
        int cnt_2 = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == cand_1)
            {
                cnt_1++;
            }
            else if(nums[i] == cand_2)
            {
                cnt_2++;
            }
            else if(cnt_1 == 0)
            {
                cnt_1 = 1;
                cand_1 = nums[i];
            }
            else if(cnt_2 == 0)
            {
                cnt_2 = 1;
                cand_2 = nums[i];
            }
            else
            {
                cnt_1--;
                cnt_2--;
            }
        }

        cnt_1 = 0;
        cnt_2 = 0;

        for(int  i = 0 ; i < n ;i++)
        {
            if(nums[i] == cand_1)
            {
                cnt_1++;
            }

            else if(nums[i] == cand_2)
            {
                cnt_2++;
            }
        }

        vector<int> ans;

        if(cnt_1 > n/3) ans.push_back(cand_1);
        if(cnt_2 > n/3) ans.push_back(cand_2);

        return ans;
    }
};