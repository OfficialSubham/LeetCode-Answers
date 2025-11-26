class Solution {
public:
    void solve(string currString, int size, int depth, int currPair, vector<string> &ans) {
        if(currString.size() == size) {
            ans.push_back(currString);
            return;
        }
        if((currPair + depth) == size/2) {
            solve(currString + ')', size, depth - 1, currPair + 1, ans);
        }
        else {
            solve(currString + '(', size, depth + 1, currPair, ans);
            if(depth > 0) {
            solve(currString + ')', size, depth-1, currPair + 1, ans);
            }
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("(", 2*n, 1, 0, ans);
        return ans;
    }
};