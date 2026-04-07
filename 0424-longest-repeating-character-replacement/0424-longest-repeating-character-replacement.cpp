class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int lastPtr = 0;
        int i = 0;
        
        unordered_map<char, int> hashMap;
        int ans = 0;
        int maxFreq = 1;
        while(i < n) {
            hashMap[s[i]]++;
            maxFreq = max(maxFreq, hashMap[s[i]]);
            int windowSize = i - lastPtr + 1;
            int changesNeed = windowSize - maxFreq;
            if(changesNeed > k) {
                hashMap[s[lastPtr]]--;
                lastPtr++;
            }
            ans = max(ans, i - lastPtr + 1);
            i++;
        }

        return ans;
    }
};