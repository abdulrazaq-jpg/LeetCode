#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int ans = sum;

        for(int i = 1; i < nums.size(); i++)
        {
            int prev = ans;
            sum += nums[i];

            if(nums[i] > sum)
            {
                sum = nums[i];
            }

            ans = max(sum , prev);
        }

        return ans;
    }
};