#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> v;

        for(int i = 0; i < n; i++)
        {
            int x = nums[i];

            v.push_back(x);
        }

        sort(v.begin(),v.end());

        while(n--)
        {
            rotate(v.begin(),v.begin()+1,v.end());

            if(v==nums)
            {
                return true;
            }
        }

        return false;
        
    }

};