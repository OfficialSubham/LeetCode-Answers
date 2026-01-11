class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()) return "0";
        string ans = "";
        stack<char> hashStack;

        for(int i = 0; i < num.size(); i++) {
            while(!hashStack.empty() && k && (hashStack.top() - '0') > (num[i] - '0')) {
                k--;
                hashStack.pop();
            }
            hashStack.push(num[i]);
        }
        while(!hashStack.empty()) {
            char s = hashStack.top();
            hashStack.pop();
            ans = s + ans;
        }
        if(k > 0) ans = ans.substr(0, ans.size() - k);
        int i = 0;
        while(i < ans.size() && ans[i] == '0') {
            i++;
        }
        if(i < ans.size()) return ans.substr(i, ans.size());
        return "0";
    }
};