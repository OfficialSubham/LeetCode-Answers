#include<bits/stdc++.h>

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> doubleArrayNums;
        doubleArrayNums.insert(doubleArrayNums.end(), nums.begin(), nums.end());
        doubleArrayNums.insert(doubleArrayNums.end(), nums.begin(), nums.end());
        
        stack<int> st;

        vector<int> ans(nums.size());
        
        for(int i = doubleArrayNums.size() - 1; i >= 0; i--) {
            if(i >= nums.size()) {
                while(!st.empty() && st.top() <= doubleArrayNums[i]) st.pop();
                st.push(doubleArrayNums[i]);
            }
            else {
                while(!st.empty() && st.top() <= doubleArrayNums[i]) st.pop();
                if(st.empty()) ans[i] = -1;
                else ans[i] = st.top();
                st.push(doubleArrayNums[i]);
            }
        }

        return ans;

    }
};