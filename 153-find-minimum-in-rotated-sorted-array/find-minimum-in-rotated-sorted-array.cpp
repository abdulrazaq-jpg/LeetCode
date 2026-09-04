class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0,high = nums.size()-1,min_ind = 0;

        while(low < high){
            int mid = (low + high)/2;

            if(nums[mid] >= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid;
            }

            min_ind = low;
        }

        return nums[min_ind];
    }
};