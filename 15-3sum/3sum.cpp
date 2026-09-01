class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> map;
        vector<int> neg;
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
        }

        for(auto& [val,count] : map) {
            if (val > 0) {
                pos.push_back(val);
            }
            if (val < 0) {
                neg.push_back(val);
            }
        }

        vector<vector<int>> res;

        vector<int> ans;

        if(map[0] >= 3){
            res.push_back({0,0,0});
        }

        if(map[0] >= 1)
        {
            for(int i : pos)
            {
                if(map.count(-i)){
                    res.push_back({i , 0 ,-i});
                }
            }
        }

        for(int i = 0; i < neg.size(); i++){
            for(int j = i; j < neg.size(); j++){
                int n1 = neg[i];
                int n2 = neg[j];
                int target = -(n1+n2);

                if(n1==n2){
                    if(map[n1] < 2)
                    {
                        continue;
                    }
                }

                if(map.count(target)){
                    res.push_back({n1,n2,target});
                }
            }
        }
        
        for(int i = 0; i < pos.size(); i++){
            for(int j = i; j < pos.size(); j++){
                int n1 = pos[i];
                int n2 = pos[j];
                int target = -(n1+n2);

                if(n1==n2){
                    if(map[n1] < 2)
                    {
                        continue;
                    }
                }

                if(map.count(target)){
                    res.push_back({n1,n2,target});
                }
            }
        }

        return res;
    }
};