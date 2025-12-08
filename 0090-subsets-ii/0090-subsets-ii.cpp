class Solution {
public:
    //29/11/25

    void findSubset(vector<int> &nums, int idx, vector<vector<int>> &ans, vector<int> &eachSubset) {
        ans.push_back(eachSubset);
        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[i - 1]) continue;
            eachSubset.push_back(nums[i]);
            findSubset(nums, i + 1, ans, eachSubset);
            eachSubset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> eachSubset;
        sort(nums.begin(), nums.end());
        findSubset(nums, 0, ans, eachSubset);
        return ans;
    }
};