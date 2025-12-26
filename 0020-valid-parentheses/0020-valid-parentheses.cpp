class Solution {
public:
    bool isValid(string s) {
        stack<char> hashStack;
        map<char, char> hashMap;
        hashMap['('] = ')';
        hashMap['{'] = '}';
        hashMap['['] = ']';
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') hashStack.push(s[i]);
            else {
                if(hashStack.empty()) return false;
                char lastParenthese = hashStack.top();
                hashStack.pop();
                if(hashMap[lastParenthese] != s[i]) return false;
            }
        }
        if(hashStack.size() > 0) return false;
        return true;
    }
};