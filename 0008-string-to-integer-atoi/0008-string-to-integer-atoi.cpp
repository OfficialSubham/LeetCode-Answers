class Solution {
public:
    long long solve(string s, int i, long long curr) {
        if(i == s.size() || !isdigit(s[i])) return curr;
        int digit = s[i] - '0';
        if(curr > INT_MAX - digit) return (long long)INT_MAX + 1;
        long long nextValue = curr * 10 + digit; 
        return solve(s, i+1, nextValue);
    }


    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        bool isNegative = false;
        while(i < n && s[i] == ' ') i++;

        if(s[i] == '+' || s[i] == '-') {
            if(s[i] == '-') isNegative = true;
            i++;
        }

        long long ans = solve(s, i, 0);
        if(ans > INT_MAX) {
            return isNegative ? INT_MIN : INT_MAX;
        }
        return isNegative ? -ans : ans;
    }

};