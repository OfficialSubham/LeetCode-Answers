class Solution {
public:
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

    int myAtoi(string s)  {
        int i = 0;
        long long ans = 0;
        bool isNegative = false;
        //Ignoring all leading spaces
        while(s[i] == ' ') i++;

        //Now i have the pointer which is not in space
        if(s[i] == '-' || s[i] == '+') {
            if(s[i] == '-') isNegative = true;
            i++;
        }
        while(i < s.size() && isdigit(s[i])) {
            int digit = (s[i] - '0');
            if(ans*10 + digit > INT_MAX) {
                return isNegative ? INT_MIN : INT_MAX;

            }
            ans *= 10;
            ans += digit;
            i++;
        }

        return isNegative ? -ans : ans;

    }

};