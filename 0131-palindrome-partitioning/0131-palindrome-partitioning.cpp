class Solution {
public:

    bool checkPalindrome(string s, int start, int end) {
        int i = start;
        int j = end;

        while(i <=j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    void solve(string s, vector<string> &eachAns, int idx, vector<vector<string>> &ans) {
        if(idx == s.size()) {
            ans.push_back(eachAns);
            return;
        }
        
        for(int i = idx; i < s.size(); i++) {
            if(checkPalindrome(s, idx, i)) {
                eachAns.push_back(s.substr(idx, i - idx + 1));
                solve(s, eachAns, i+1, ans);
                eachAns.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> eachAns;
        solve(s, eachAns, 0, ans);
        return ans;
    }
};