class Solution {
private:
    int bs(vector<int>& nums, int target, int low, int high) {
        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, min = nums[0], min_ind = 0;

        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }

            min_ind = low;
        }

        if (nums[min_ind] == target)
            return min_ind;

        int ans1 = bs(nums, target, 0, min_ind - 1);
        int ans2 = bs(nums, target, min_ind, nums.size() - 1);

        if (ans1 != -1) {
            return ans1;
        } else if (ans2 != -1) {
            return ans2;
        } else {
            return -1;
        }
    }
};