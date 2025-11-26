class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> everySubset;
        int totalSubset = 1 << n;
        for(int i = 0; i < totalSubset; i++) {
            vector<int> subset;
            for(int j = 0; j < n; j++) {
                if((i >> j) & 1) {
                    subset.push_back(nums[j]);
                }
            }
            everySubset.push_back(subset);
        }

        return everySubset;
    }
};