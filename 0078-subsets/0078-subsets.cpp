class Solution {
public:
    //26/11/25
    void generate(int idx, vector<int> &nums, vector<int> &current, vector<vector<int>> &ans) {
        ans.push_back(current);
        for(int i = idx; i < nums.size(); i++) {
            current.push_back(nums[i]);
            generate(i + 1, nums, current, ans);
            current.pop_back();
        }
    }

    void generateUsingBits(vector<int> &nums, vector<vector<int>> &ans) {
        int n = 1 << nums.size();
        for(int i = 0; i < n; i++) {
            vector<int> eachAns;
            for(int j = 0; j < nums.size(); j++) {
                if((i >> j) & 1) eachAns.push_back(nums[j]);
            }
            ans.push_back(eachAns);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> everySubset;
        generateUsingBits(nums, everySubset);
        return everySubset;
    }
};