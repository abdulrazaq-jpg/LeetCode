#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,int> map;

        for(int i = 0; i < n; i++)
        {
            map[nums[i]]++;
        }

        for(auto x : map)
        {
            int num = x.first;
            int freq = x.second;

            if(freq > n/2)
            {
                return num;
            }
        }

        return -1;
    }
};