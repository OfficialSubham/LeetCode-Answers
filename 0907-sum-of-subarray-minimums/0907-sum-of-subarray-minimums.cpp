class Solution {
public:
    vector<int> findNse(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> hashStack;
        for(int i = n - 1; i >= 0; i--) {
            while(!hashStack.empty() && arr[hashStack.top()] >= arr[i]) hashStack.pop();
            if(hashStack.empty()) ans[i] = n;
            else ans[i] = hashStack.top();
            hashStack.push(i);
        }
        return ans;
    }

    vector<int> findPse(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> hashStack;
        for(int i = 0; i < n; i++) {
            while(!hashStack.empty() && arr[hashStack.top()] > arr[i]) hashStack.pop();
            if(hashStack.empty()) ans[i] = -1;
            else ans[i] = hashStack.top();
            hashStack.push(i);
        }
        return ans;
    }


    long long MOD = 1000000007;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSE = findNse(arr);
        vector<int> PSEE = findPse(arr);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int left = i - PSEE[i];
            int right = NSE[i] - i;
            long long freq = left * right * 1LL;
            long long val = (freq*arr[i]*1LL) % MOD;
            sum = (sum + val) % MOD;
        }
        return sum;

    }
};