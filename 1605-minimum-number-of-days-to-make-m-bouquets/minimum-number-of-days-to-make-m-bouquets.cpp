class Solution {
public:
    bool possible(vector<int>& bloomDay, int val, int m, int k) {
        int cnt = 0;
        int bouqets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= val){
                cnt++;

                if(cnt == k)
                {
                    bouqets++;
                    cnt = 0;
                }
            }
            else {
                cnt = 0;
            }
        }

        if (bouqets >= m)
            return true;

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if (1LL * m * k > bloomDay.size())
            return -1;

        int low = bloomDay[0];
        int high = bloomDay[0];
        int ans = -1;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] < low)
                low = bloomDay[i];
            if (bloomDay[i] > high)
                high = bloomDay[i];
        }

        while (high >= low) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }
};