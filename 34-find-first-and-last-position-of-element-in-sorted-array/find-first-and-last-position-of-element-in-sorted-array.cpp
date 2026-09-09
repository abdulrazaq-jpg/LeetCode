class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        vector<int> str(2);
        int first = -1, last = -1;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid]==target){
                first = mid;
                high = mid-1;
            }
            else if(nums[mid] > target) high = mid-1;
            else low = mid + 1;
        }

        str[0] = first;

        int low1= 0, high1 = nums.size()-1;

        while(low1 <= high1){
            int mid1 = (low1 + high1)/2;

            if(nums[mid1]==target){
                last = mid1;
                low1 = mid1+1;
            }
            else if(nums[mid1] < target) low1 = mid1+1;
            else high1 = mid1 - 1;
        }

        str[1] = last;

        return str;
    }
};