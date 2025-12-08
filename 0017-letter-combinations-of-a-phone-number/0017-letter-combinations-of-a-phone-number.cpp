class Solution {
public:
    //29/11/25
    void solve(vector<string> &ans, string digits, vector<string> &hashMap, string eachAns, int idx) {
        if(eachAns.size() == digits.size()) {
            ans.push_back(eachAns);
            return;
        }
        int index = digits[idx] - '0';
        string eachString = hashMap[index];
        for(int i = 0; i < eachString.size(); i++) {
            solve(ans, digits, hashMap, eachAns + eachString[i], idx + 1);
        } 
    }

    vector<string> letterCombinations(string digits) {
        vector<string> hashMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        solve(ans, digits, hashMap, "", 0);
        return ans;
    }
};