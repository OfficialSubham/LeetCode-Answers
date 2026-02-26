#include<bits/stdc++.h>
class Solution {
public:
    bool isValid(string s) {

        if(s.size()%2 == 1) return false;

        stack<char> st;
        unordered_map<char, char> hashMap;
        hashMap['('] = ')';
        hashMap['{'] = '}';
        hashMap['['] = ']';

        for(int i = 0; i < s.size(); i++) {
            if(hashMap.count(s[i])) {
                st.push(s[i]);
            }
            else {
                if(!st.size() || hashMap[st.top()] != s[i]) return false;
                st.pop();
            }
        }
        if(st.size()) return false;

        return true;
    }
};