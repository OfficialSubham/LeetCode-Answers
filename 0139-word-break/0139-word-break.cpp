class Solution {
public:
    //1/12/25
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> setDict(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        int maxWordLen = 0;
        
        for(string word : setDict) {
            maxWordLen = max(maxWordLen, (int)word.size());
        }

        for(int i = 1; i <= n; i++) {
            for(int j = max(0, i - maxWordLen); j < i; j++) {
                if(dp[j] && setDict.find(s.substr(j, i - j)) != setDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};