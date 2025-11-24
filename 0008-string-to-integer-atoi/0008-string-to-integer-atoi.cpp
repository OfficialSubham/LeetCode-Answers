class Solution {
public:
/*
    // int myAtoi(string s) {
    //     long long ans = 0;
    //     int n = s.size();
    //     bool started = false;
    //     char sign = '+';
    //     for(int i = 0; i < n; i++) {
    //         if(s[i] == ' ' && !started) continue;
    //         else if(s[i] == ' ' && started) break;
    //         if((s[i] == '-' || s[i] == '+') && !started) {
    //             sign = s[i];
    //             started = true;
    //             continue;
    //         }
    //         else if((s[i] == '-' || s[i] == '+') && started) break;
    //         if(!isdigit(s[i])) break;
    //         started = true;
    //         int digit = s[i] - '0';
    //         if(ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > (sign == '-' ? 8 : 7))) {
    //             return sign == '-' ? INT_MIN : INT_MAX;
    //         }
    //         ans *= 10;
    //         ans += digit;
    //     }
    //     return sign == '-' ? -ans : ans;
        
    // }
    //15/11/25
    // int myAtoi(string s)  {
    //     int i = 0;
    //     long long ans = 0;
    //     bool isNegative = false;
    //     //Ignoring all leading spaces
    //     while(s[i] == ' ') i++;

    //     //Now i have the pointer which is not in space
    //     if(s[i] == '-' || s[i] == '+') {
    //         if(s[i] == '-') isNegative = true;
    //         i++;
    //     }
    //     while(isdigit(s[i])) {
    //         int digit = (s[i] - '0');
    //         if(ans*10 + digit > INT_MAX) {
    //             return isNegative ? INT_MIN : INT_MAX;

    //         }
    //         ans *= 10;
    //         ans += digit;
    //         i++;
    //     }

    //     return isNegative ? -ans : ans;

    // }

    long long parse(string s, int i, long long curr) {
        if(i >= s.size() || !isdigit(s[i])) return curr;
        long long digit = s[i] - '0';
        if(curr > (INT_MAX - digit)) {
            return (long long)INT_MAX + 1; 
        }
        long long nextVal = curr * 10 + digit;
        return parse(s, i+1, nextVal);
    }

    int myAtoi(string s) {
        int i = 0;
        while(i < s.size() && s[i] == ' ') i++;
        if(i >= s.size()) return 0;
        bool isNegative = false;
        if(s[i] == '-' || s[i] == '+') {
            if(s[i] =='-') isNegative = true;
            i++;
        }
        long long ans = parse(s, i, 0);
        if(ans > INT_MAX) return isNegative ? INT_MIN : INT_MAX;
        return isNegative ? -ans : ans;
    }
*/
    long long findAns(string s, int i, long long curr) {
        if(i >= s.size() || !isdigit(s[i])) return curr;
        int digit = s[i] - '0';
        if(curr > (INT_MAX - digit)) return (long long)INT_MAX + 1;
        long long nextVal = curr * 10 + digit;
        return findAns(s, i + 1, nextVal);
    }

    int myAtoi(string s) {
        int i = 0;
        bool isNegative = false;
        while(s[i] == ' ') i++;
        if(s[i] == '+' || s[i] == '-') {
            if(s[i] == '-') isNegative = true;
            i++;
        }
        long long ans = findAns(s, i, 0);
        if(ans > INT_MAX) return isNegative ? INT_MIN : INT_MAX;
        return isNegative ? -ans : ans;
    }

};