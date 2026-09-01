class Solution {
private:
    long long power(long long x , long long y, long long MOD = 1e9 + 7){
        long long res = 1;
        x %= MOD;

        while(y > 0){
            if(y & 1)
            {
                res = (res * x) % MOD;
            }

            x = (x*x) % MOD;

            y >>= 1;
        }

        return res;
    }

public:
    long long sumDecoded(vector<long long>& nums) {
        long long n = nums.size();

        long long ans = 0;
        const long long MOD = 1e9 + 7;

        for(long long i = 0; i < n; i++){
            long long width = nums[i] % 10;

            long long d = floor((nums[i])/10);

            string s = to_string(d);

            int l = s.length();

            int val = power(10,l-width);

            int x = floor(d / val);

            int y = floor(d % val);

            ans += power(x,y);
        }

        return ans % MOD;
    }
};