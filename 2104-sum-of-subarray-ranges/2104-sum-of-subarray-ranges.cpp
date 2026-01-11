class Solution {
public:
    vector<int> nextSmallerElm(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> hashStack;
        for(int i = n-1; i >= 0; i--) {
            while(!hashStack.empty() && nums[hashStack.top()] >= nums[i]) hashStack.pop();
            if(hashStack.empty()) ans[i] = n;
            else ans[i] = hashStack.top();
            hashStack.push(i);
        }
        return ans;
    }

    vector<int> nextGreaterElm(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> hashStack;
        for(int i = n-1; i >= 0; i--) {
            while(!hashStack.empty() && nums[hashStack.top()] <= nums[i]) hashStack.pop();
            if(hashStack.empty()) ans[i] = n;
            else ans[i] = hashStack.top();
            hashStack.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElm(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> hashStack;
        for(int i = 0; i < n; i++) {
            while(!hashStack.empty() && nums[hashStack.top()] > nums[i]) hashStack.pop();
            if(hashStack.empty()) ans[i] = -1;
            else ans[i] = hashStack.top();
            hashStack.push(i);
        }
        return ans;
    }

    vector<int> prevGreaterElm(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> hashStack;
        for(int i = 0; i < n; i++) {
            while(!hashStack.empty() && nums[hashStack.top()] < nums[i]) hashStack.pop();
            if(hashStack.empty()) ans[i] = -1;
            else ans[i] = hashStack.top();
            hashStack.push(i);
        }
        return ans;
    }

    long long sumOfSubArrMins(vector<int> &nums) {
        vector<int> NSElm = nextSmallerElm(nums);
        vector<int> PSElm = prevSmallerElm(nums);
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            int left = i - PSElm[i];
            int right = NSElm[i] - i;

            long long freq = left*right*1LL;
            long long val = freq*nums[i]*1LL;
            sum += val;
        }
        return sum;
    }

    long long sumOfSubArrMax(vector<int> &nums) {
        vector<int> NGElm = nextGreaterElm(nums);
        vector<int> PGElm = prevGreaterElm(nums);
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            int left = i - PGElm[i];
            int right = NGElm[i] - i;

            long long freq = left*right*1LL;
            long long val = freq*nums[i]*1LL;
            sum += val;
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return (sumOfSubArrMax(nums) - sumOfSubArrMins(nums));
    }
};