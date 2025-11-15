class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int end = 1;
        for(int i = 0; i < n; i++) {
            int j = i;
            int k = i;
            while(j >= 0 && k < n && s[j] == s[k]) {
                j--;
                k++;
            }
            if((end - start) < (k - j - 1)){
                end = k;
                start = j + 1;
            }

            int l = i;
            int m = i + 1;
            while(l >= 0 && m < n && s[l] == s[m]) {
                l--;
                m++;
            }

            if((end - start) < (m - l - 1)){
                end = m;
                start = l + 1;

            }
        }

        return s.substr(start, end - start);

    }

};