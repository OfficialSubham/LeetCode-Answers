class Solution {
public:

    void findCombination(vector<int> &candidates, vector<int> &ans, set<vector<int>> &ansSet, int target, int sum, int idx) {
        if(sum > target) return;
        if(sum == target) {
            ansSet.insert(ans);
            return;
        }
        if(idx == candidates.size()) {
            if(sum == target) ansSet.insert(ans);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i - 1]) continue;
            ans.push_back(candidates[i]);
            sum += candidates[i];
            findCombination(candidates, ans, ansSet, target, sum, i + 1);
            ans.pop_back();
            sum -= candidates[i];
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ansSet;
        vector<int> tempAnswers;
        sort(candidates.begin(), candidates.end());
        findCombination(candidates, tempAnswers, ansSet, target, 0, 0);
        vector<vector<int>> ans;
        for(auto it : ansSet) {
            ans.push_back(it);
        }
        return ans;
    }
};