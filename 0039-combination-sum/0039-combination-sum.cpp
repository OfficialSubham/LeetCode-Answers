class Solution {
public:

    void solve(vector<int> &candidates, int target, int idx, set<vector<int>> &ansSet , vector<int> &ans, int sum) {
        if(sum > target) return;
        if(sum == target) {
            ansSet.insert(ans);
            return;
        }
        if(idx == candidates.size()) {
            if(sum == target) ansSet.insert(ans);
            return;
        }
     
            //Pick
            ans.push_back(candidates[idx]);
            sum += candidates[idx];
            solve(candidates, target, idx, ansSet, ans, sum);
            
            //Not pick
            ans.pop_back();
            sum -= candidates[idx];
            solve(candidates, target, idx+1, ansSet, ans, sum);
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ansSet;
        vector<int> temp;

        solve(candidates, target, 0, ansSet, temp, 0);
        vector<vector<int>> ans;

        for(auto it : ansSet) {
            ans.push_back(it);
        }
        return ans;
    }
};