class Solution {
public:

    void findSubset(vector<int> &nums, set<vector<int>> &ansSet, int idx, vector<int> &eachSubset) {
        ansSet.insert(eachSubset);
        for(int i = idx; i < nums.size(); i++) {
            eachSubset.push_back(nums[i]);
            findSubset(nums, ansSet, i + 1, eachSubset);
            eachSubset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ansSet;
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        findSubset(nums, ansSet, 0, temp);
        for(auto it : ansSet) {
            ans.push_back(it);
        }
        return ans;
    }
};