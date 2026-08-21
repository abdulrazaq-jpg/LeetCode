#include<iostream>
#include<vector>
#include<set>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        set<int> s;

        for(int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
        }

        int size = s.size();
        
        if(size == 0)
        {
            return 0;
        }

        int cnt = 1;
        int best = 1;

        for(auto it = s.begin(); it != s.end(); it++)
        {
            auto next_it = next(it);

            if(next_it != s.end() && (*next_it - *it == 1))
            {
                cnt ++;
                best = max(cnt , best);
            }
            else
            {
                cnt = 1;
            }
        }

        return best;
    }
};