#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,int> m;

        for(int i = 0 ; i < n; i++)
        {
            m[nums[i]]++;
        }

        for(auto x : m)
        {
            int f = x.first;
            int s = x.second;

            if(s>n/2) return f;
        }

        return -1;

    }
};