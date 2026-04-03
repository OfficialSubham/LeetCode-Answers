class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashMap;

        int lastPtr = 0;
        int i = 0;
        int n = s.size();
        int ans = 0;
        while(i < n) {
            if(hashMap.count(s[i])) {
                while(lastPtr <= i && hashMap.count(s[i])) {
                    hashMap[s[lastPtr]]--;
                    if(hashMap[s[lastPtr]] == 0) hashMap.erase(s[lastPtr]);
                    lastPtr++;
                }
            }
            ans = max(ans, i-lastPtr+1);
            hashMap[s[i]]++;
            i++;
        }
        return ans;
    }
};