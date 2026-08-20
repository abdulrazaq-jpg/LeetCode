#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int bp = -1;
        int sp = -1;

        for(int i = n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                bp = i;
                break;
            }
        }

        if(bp == -1)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(int i = n-1; i>=0; i--)
            {
                if(nums[i] > nums[bp])
                {
                    sp = i;
                    break;
                }
            }

            swap(nums[bp] , nums[sp]);

            reverse(nums.begin() + bp + 1 ,nums.end());
        }
};
};