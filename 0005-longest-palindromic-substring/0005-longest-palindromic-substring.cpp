class Solution {
public:
    // string longestPalindrome(string s) {
    //     int n = s.size();
    //     string ans = "";
    //     for(int i = 0; i < s.size(); i++) {
    //         int j = i;
    //         int k = i;
    //         while(j >= 0 && k < n && s[j] == s[k]) {
    //             j--;
    //             k++;
    //         }
    //         if(ans.size() < (k - j - 1)) {
    //             ans = s.substr(j + 1, k - j - 1);
    //         }

    //         int l = i;
    //         int m = i+1;
    //         while(l >= 0 && m < n && s[l] == s[m]) {
    //             l--;
    //             m++;
    //         }
    //         if(ans.size() < (m - l - 1)) {
    //             ans = s.substr(l + 1, m - l - 1);
    //         }

    //     }
    //     return ans;

    // }

    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++) {
            int j = i;
            int k = i;
            while(j >= 0 && k < n && s[j] == s[k]) {
                j--;
                k++;
            }
            if(ans.size() < (k - j - 1)){
                ans = s.substr(j + 1, (k - j - 1));
            }

            int l = i;
            int m = i + 1;
            while(l >= 0 && m < n && s[l] == s[m]) {
                l--;
                m++;
            }

            if(ans.size() < (m - l - 1)){
                ans = s.substr(l + 1, (m - l - 1));
            }
        }

        return ans;

    }

};