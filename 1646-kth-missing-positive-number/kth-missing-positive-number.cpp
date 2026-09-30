class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int>track;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            track[arr[i]]++;
        }

        for(int i = 1; i <= arr[n-1]; i++){
            if(track[i]!=1)ans.push_back(i);
        }

        if(ans.size() >= k)return ans[k-1];
        else{
            return arr[n-1]+(k-ans.size());
        }
    }
};