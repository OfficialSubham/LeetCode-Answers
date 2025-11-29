class Solution {
public:

    void solve(vector<string> &ans, string digits, map<int, string> &hashMap, string eachAns, int idx) {
        if(eachAns.size() == digits.size()) {
            ans.push_back(eachAns);
            return;
        }
        string eachString = hashMap[digits[idx] - '0'];
        for(int i = 0; i < eachString.size(); i++) {
            solve(ans, digits, hashMap, eachAns + eachString[i], idx + 1);
        } 
    }

    vector<string> letterCombinations(string digits) {
        map<int, string> hashMap;
        hashMap[2] = "abc";
        hashMap[3] = "def";
        hashMap[4] = "ghi";
        hashMap[5] = "jkl";
        hashMap[6] = "mno";
        hashMap[7] = "pqrs";
        hashMap[8] = "tuv";
        hashMap[9] = "wxyz";
        vector<string> ans;
        if(digits.size() == 1) {
            string ansString = hashMap[digits[0] - '0'];
            for(int i = 0; i < ansString.size(); i++) {
                string eachLetter = "";
                eachLetter += ansString[i];
                ans.push_back(eachLetter);
            }
            return ans;
        }
        solve(ans, digits, hashMap, "", 0);
        return ans;
    }
};