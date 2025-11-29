class Solution {
public:
    void findCombination(vector<vector<int>> &ans, vector<int> &eachCombo, int idx, int k, int n, int sum) {
        if(eachCombo.size() > k || sum > n || idx > 9) return;
        if(eachCombo.size() == k) {
            if(sum == n) ans.push_back(eachCombo);
            return;
        }
        sum += idx;
        eachCombo.push_back(idx);
        findCombination(ans, eachCombo, idx + 1, k, n, sum);
        sum-= idx;
        eachCombo.pop_back();
        findCombination(ans, eachCombo, idx + 1, k, n, sum);
 

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> eachCombo;
        findCombination(ans, eachCombo, 1, k, n, 0);
        return ans;
    }
};