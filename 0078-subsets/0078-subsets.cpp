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

    void generateUsingBits(vector<int> &arr, vector<vector<int>> &ans) {
        int n = 1 << arr.size();
        for(int i = 0; i < n; i++) {
            vector<int> temp;
            for(int j = 0; j < arr.size(); j++) {
                if((i >> j )&1) temp.push_back(arr[j]);
            }
            ans.push_back(temp);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> everySubset;
        // vector<int> temp;
        // generate(0, nums, temp, everySubset);
        generateUsingBits(nums, everySubset);
        return everySubset;
    }
};