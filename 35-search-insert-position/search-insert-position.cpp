class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int low = 0, high = nums.size()-1;

        while(low<=high){
            int mid = (low + high)/2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] < target){
                i = mid+1;
                low = mid + 1;
            }
            else{
                i = mid;
                high = mid - 1;
            }
        }

        return i;
    }
};