class Solution {
private:
    void help(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    int count(vector<int>& nums, int low, int mid, int high) {
        int j = mid + 1;
        int c = 0;

        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > (2LL * nums[j])) {
                j++;
            }
            c += (j - (mid + 1));
        }

        return c;
    }

    int algo(vector<int>& nums, int low, int high) {
        if (low >= high)
            return 0;

        int mid = (low + high) / 2;
        int cnt = 0;

        cnt += algo(nums, low, mid);
        cnt += algo(nums, mid + 1, high);
        cnt += count(nums, low, mid, high);
        help(nums, low, mid, high);

        return cnt;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        return algo(nums, 0, n - 1);
    }
};